#include <iostream>
#include <cstdio>

#include "RegisterMapCommon.hh"
#include "network.hh"
#include "UDPRBCP.hh"
#include "FPGAModule.hh"
#include "FlashMemoryProgrammer.hh"
#include "SitcpController.hh"
#include "rbcp.hh"

using namespace HUL;
int main(int argc, char* argv[])
{
  if(1 == argc){
    std::cout << "Usage\n";
    std::cout << "set_sitcpreg [IP address]" << std::endl;
    return 0;
  }// usage
  
  // body ------------------------------------------------------
  std::string board_ip = argv[1];
  RBCP::WriteSiTCP(board_ip, 0x40, 0x17);
  RBCP::WriteSiTCP(board_ip, 0x41, 0x10);
  
  return 0;

}// main
