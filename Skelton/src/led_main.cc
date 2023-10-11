#include <iostream>
#include <iomanip>
#include <ios>
#include <cstdio>

#include "RegisterMap.hh"
#include "network.hh"
#include "FPGAModule.hh"
#include "UDPRBCP.hh"
#include "rbcp.hh"

using namespace HUL;
int main(int argc, char* argv[])
{
  if(1 == argc){
    std::cout << "Usage\n";
    std::cout << "led [IP address] [Register (4bit)]" << std::endl;
    return 0;
  }// usage
  
  // body ------------------------------------------------------
  std::string board_ip = argv[1];
  uint32_t reg = atoi(argv[2]);

  RBCP::UDPRBCP udp_rbcp(board_ip, RBCP::gUdpPort, RBCP::UDPRBCP::kNoDisp);
  HUL::FPGAModule fpga_module(udp_rbcp);
  fpga_module.WriteModule(CIRASAME::Skelton::LED::kAddrLED, reg);

  return 0;

}// main
