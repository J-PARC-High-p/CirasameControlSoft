#include <iostream>
#include <iomanip>
#include <ios>
#include <cstdio>

#include "RegisterMapCommon.hh"
#include "network.hh"
#include "FPGAModule.hh"
#include "UDPRBCP.hh"
#include "rbcp.hh"
#include "Utility.hh"
#include "BitDump.hh"
#include "Uncopyable.hh"

// Main ___________________________________________________________________________
using namespace HUL;
int main(int argc, char* argv[])
{
  if(1 == argc || 2 == argc){
    std::cout << "Usage\n";
    std::cout << "debug [IP address] [parameter]" << std::endl;
    return 0;
  }// usage
  
  // body ------------------------------------------------------
  std::string board_ip = argv[1];
  int set_parameter = atoi(argv[2]);
  
  RBCP::UDPRBCP udp_rbcp(board_ip, RBCP::gUdpPort, RBCP::UDPRBCP::kNoDisp);
  HUL::FPGAModule fpga_module(udp_rbcp);

  fpga_module.WriteModule(CIRASAME::BIAS::kAddrTxd, set_parameter, 1);
  fpga_module.WriteModule(CIRASAME::BIAS::kAddrExecWrite, 0, 1);

  return 0;

}// main
