#include <iostream>
#include <iomanip>
#include <ios>
#include <cstdio>
#include <stdint.h>

#include "RegisterMapCommon.hh"
#include "network.hh"
#include "FPGAModule.hh"
#include "UDPRBCP.hh"
#include "rbcp.hh"
#include "Utility.hh"
#include "BitDump.hh"


// Main ___________________________________________________________________________
using namespace HUL;
int main(int argc, char* argv[])
{
  if(1 == argc || 2 == argc){
    std::cout << "Usage\n";
    std::cout << "set_hgddelay [IP address] [parameter]" << std::endl;
    return 0;
  }// usage
  
  // body ------------------------------------------------------
  std::string board_ip = argv[1];
  uint32_t value = atoi(argv[2]);
  uint32_t reg   = 1 << (value-1);
  
  RBCP::UDPRBCP udp_rbcp(board_ip, RBCP::gUdpPort, RBCP::UDPRBCP::kNoDisp);
  HUL::FPGAModule fpga_module(udp_rbcp);

  fpga_module.WriteModule(CIRASAME::HGD::kAddrMask, reg, 4);

  return 0;

}// main
