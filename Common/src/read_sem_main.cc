#include <iostream>
#include <cstdio>

#include "RegisterMapCommon.hh"
#include "network.hh"
#include "UDPRBCP.hh"
#include "FPGAModule.hh"
#include "FlashMemoryProgrammer.hh"
#include "rbcp.hh"

using namespace HUL;
void set_error_injection_address(HUL::FPGAModule& fpga_module,
				 uint32_t command,
				 uint32_t addr_lniear_frame,
				 uint32_t addr_word,
				 uint32_t addr_bit
				 );

int main(int argc, char* argv[])
{
  if(1 == argc){
    std::cout << "Usage\n";
    std::cout << "read_sem [IP address]" << std::endl;
    return 0;
  }// usage
  
  // body ------------------------------------------------------
  std::string board_ip = argv[1];

  RBCP::UDPRBCP udp_rbcp(board_ip, RBCP::gUdpPort, RBCP::UDPRBCP::kNoDisp);
  HUL::FPGAModule fpga_module(udp_rbcp);

  const uint32_t sem_correction_count
    = fpga_module.ReadModule(SDS::kAddrSemCorCount, 2);

  const uint32_t status
    = fpga_module.ReadModule(SDS::kAddrSdsStatus, 1);

  printf("Num. correction. : %d \n", sem_correction_count);
  printf("\n");

  printf("SEM error status (0:nomarl, 1:error)\n");
  printf(" - Sem watchdog      : %d\n", (status & SDS::kSemWatchdogAlarm) >> 4);
  printf(" - Sem uncorrectable : %d\n", (status & SDS::kSemUncorrectableAlarm) >> 5);
  
  return 0;

}// main

void
set_error_injection_address(HUL::FPGAModule& fpga_module,
			    uint32_t command,
			    uint32_t addr_linear_frame,
			    uint32_t addr_word,
			    uint32_t addr_bit
			    )
{
  // command              :  4bit
  // linear frame address : 17bit
  // word address         :  7bit
  // bit address          :  5bit
  const uint32_t mask_linear = 0x1ffff;
  const uint32_t mask_word   = 0x7f;
  const uint32_t mask_bit    = 0x1f;

  const uint32_t shift_word   = 5;
  const uint32_t shift_linear = 7 + shift_word;

  // For command (5th byte)
  const uint32_t mask_command  = 0xf;
  const uint32_t shift_command = 4;

  uint32_t reg_1st_4th = addr_bit & mask_bit;
  reg_1st_4th = reg_1st_4th | ((addr_word & mask_word) << shift_word);
  reg_1st_4th = reg_1st_4th | ((addr_linear_frame & mask_linear) << shift_linear);
  fpga_module.WriteModule(SDS::kAddrSemErrAddr, reg_1st_4th, 4);

  uint32_t reg_5th = (command & mask_command) << shift_command;
  fpga_module.WriteModule(SDS::kAddrSemErrAddr+0x40000, reg_5th, 1);
}
