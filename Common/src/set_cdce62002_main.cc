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
#include "CDCE62002Funcs.hh"

namespace CDCE62002{

#if 0
  // ----------------------------------------------------------
  // Input freq: 100 MHz
  // Output freq
  // - OUT0: 500 MHz
  // - OUT1: 100 MHz
  // ----------------------------------------------------------
  
  namespace Reg0{
    // GenReg0Txd ____________________________________________________
    uint32_t
    GenSpiTxd()
    {
      uint32_t reg = 0;
      
      reg = SetINBUFSEL(reg,   kLVDSIn);
      reg = SetSmartMUX(reg,   kRefIn);
      reg = SetACDCSEL(reg,    kDCIn);
      reg = SetTERMSEL(reg,    kEnTerm);
      reg = SetREFDIVIDE(reg,  kRefDiv1);
      reg = SetLOCKW(reg,      kLock21);
      reg = SetOUTDIVIDE0(reg, kOutDiv1);
      reg = SetOUTDIVIDE1(reg, kOutDiv5);
      reg = SetOUTBUFSEL0(reg, kLVDSOut);
      reg = SetOUTBUFSEL1(reg, kLVDSOut);

      std::cout << "#D : CDCE62002::Reg0::GenSpiTxd() \n";
      std::cout << std::setfill('0') << std::right;
      std::cout << std::hex << "     0x" << std::setw(8) << reg << "\n";
      std::cout << std::dec;
      std::cout << std::setfill(' ');

      return Utility::BitReverse(reg);
    }
  };

  namespace Reg1{
    // GenReg1Txd ____________________________________________________
    uint32_t
    GenSpiTxd()
    {
      uint32_t reg = 0x80000001; // Address 1
      
      reg = SetSELVCO(reg,     kVCOLow);
      reg = SetSELINDIV(reg,   4); // Set DIVIDE ratio to reg val.
      reg = SetPRESCALER(reg,  kPreScale4);
      reg = SetSELFBDIV(reg,   3); // Reg val is not DIV value.
      reg = SetSELBPDIV(reg,   kBPBypass);
      reg = SetLFRCSEL(reg,    0);


      std::cout << "#D : CDCE62002::Reg1::GenSpiTxd() \n";
      std::cout << std::setfill('0') << std::right;
      std::cout << std::hex << "     0x" << std::setw(8) << reg << "\n";
      std::cout << std::dec;
      std::cout << std::setfill(' ');

      return Utility::BitReverse(reg);
    }

  };

  namespace Reg2{
    // GenReg2Txd ____________________________________________________
    uint32_t
    GenSpiTxd()
    {
      uint32_t reg = 0x61003CF2; // Address 2
      //      reg = reg & 0xFFFFF7FF;
      reg = reg & 0xFFFFFFFF;
      
      std::cout << "#D : CDCE62002::Reg2::GenSpiTxd() \n";
      std::cout << std::setfill('0') << std::right;
      std::cout << std::hex << "     0x" << std::setw(8) << reg << "\n";
      std::cout << std::dec;
      std::cout << std::setfill(' ');

      return Utility::BitReverse(reg);
    }

  };
#endif

#if 1
  // ----------------------------------------------------------
  // Input freq: 125 MHz
  // Output freq
  // - OUT0: 500 MHz
  // - OUT1: 125 MHz
  // ----------------------------------------------------------
  
  namespace Reg0{
    // GenReg0Txd ____________________________________________________
    uint32_t
    GenSpiTxd()
    {
      uint32_t reg = 0;
      
      reg = SetINBUFSEL(reg,   kLVDSIn);
      reg = SetSmartMUX(reg,   kRefIn);
      reg = SetACDCSEL(reg,    kDCIn);
      reg = SetTERMSEL(reg,    kEnTerm);
      reg = SetREFDIVIDE(reg,  kRefDiv1);
      reg = SetLOCKW(reg,      kLock21);
      reg = SetOUTDIVIDE0(reg, kOutDiv1);
      reg = SetOUTDIVIDE1(reg, kOutDiv4);
      reg = SetOUTBUFSEL0(reg, kLVDSOut);
      reg = SetOUTBUFSEL1(reg, kLVDSOut);

      std::cout << "#D : CDCE62002::Reg0::GenSpiTxd() \n";
      std::cout << std::setfill('0') << std::right;
      std::cout << std::hex << "     0x" << std::setw(8) << reg << "\n";
      std::cout << std::dec;
      std::cout << std::setfill(' ');

      return Utility::BitReverse(reg);
    }
  };

  namespace Reg1{
    // GenReg1Txd ____________________________________________________
    uint32_t
    GenSpiTxd()
    {
      uint32_t reg = 0x80000001; // Address 1
      
      reg = SetSELVCO(reg,     kVCOLow);
      reg = SetSELINDIV(reg,   5); // Set DIVIDE ratio to reg val.
      reg = SetPRESCALER(reg,  kPreScale4);
      reg = SetSELFBDIV(reg,   3); // Reg val is not DIV value.
      reg = SetSELBPDIV(reg,   kBPBypass);
      reg = SetLFRCSEL(reg,    0);


      std::cout << "#D : CDCE62002::Reg1::GenSpiTxd() \n";
      std::cout << std::setfill('0') << std::right;
      std::cout << std::hex << "     0x" << std::setw(8) << reg << "\n";
      std::cout << std::dec;
      std::cout << std::setfill(' ');

      return Utility::BitReverse(reg);
    }

  };
#endif

#if 0
  // ----------------------------------------------------------
  // Input freq: 125 MHz
  // Output freq
  // - OUT0: 625 MHz
  // - OUT1: 125 MHz
  // ----------------------------------------------------------
  
  namespace Reg0{
    // GenReg0Txd ____________________________________________________
    uint32_t
    GenSpiTxd()
    {
      uint32_t reg = 0;
      
      reg = SetINBUFSEL(reg,   kLVDSIn);
      reg = SetSmartMUX(reg,   kRefIn);
      reg = SetACDCSEL(reg,    kDCIn);
      reg = SetTERMSEL(reg,    kEnTerm);
      reg = SetREFDIVIDE(reg,  kRefDiv1);
      reg = SetLOCKW(reg,      kLock21);
      reg = SetOUTDIVIDE0(reg, kOutDiv1);
      reg = SetOUTDIVIDE1(reg, kOutDiv5);
      reg = SetOUTBUFSEL0(reg, kLVDSOut);
      reg = SetOUTBUFSEL1(reg, kLVDSOut);

      std::cout << "#D : CDCE62002::Reg0::GenSpiTxd() \n";
      std::cout << std::setfill('0') << std::right;
      std::cout << std::hex << "     0x" << std::setw(8) << reg << "\n";
      std::cout << std::dec;
      std::cout << std::setfill(' ');

      return Utility::BitReverse(reg);
    }
  };

  namespace Reg1{
    // GenReg1Txd ____________________________________________________
    uint32_t
    GenSpiTxd()
    {
      uint32_t reg = 0x80000001; // Address 1
      
      reg = SetSELVCO(reg,     kVCOLow);
      reg = SetSELINDIV(reg,   4); // Set DIVIDE ratio to reg val.
      reg = SetPRESCALER(reg,  kPreScale3);
      reg = SetSELFBDIV(reg,   3); // Reg val is not DIV value.
      reg = SetSELBPDIV(reg,   kBPBypass);
      reg = SetLFRCSEL(reg,    0);


      std::cout << "#D : CDCE62002::Reg1::GenSpiTxd() \n";
      std::cout << std::setfill('0') << std::right;
      std::cout << std::hex << "     0x" << std::setw(8) << reg << "\n";
      std::cout << std::dec;
      std::cout << std::setfill(' ');

      return Utility::BitReverse(reg);
    }

  };
#endif

};

// Main ___________________________________________________________________________
using namespace HUL;
int main(int argc, char* argv[])
{
  if(1 == argc){
    std::cout << "Usage\n";
    std::cout << "debug [IP address]" << std::endl;
    CDCE62002::Reg0::GenSpiTxd();
    CDCE62002::Reg1::GenSpiTxd();
    return 0;
  }// usage
  
  // body ------------------------------------------------------
  std::string board_ip = argv[1];

  RBCP::UDPRBCP udp_rbcp(board_ip, RBCP::gUdpPort, RBCP::UDPRBCP::kNoDisp);
  HUL::FPGAModule fpga_module(udp_rbcp);

  //  CDCE62002::WriteReg(fpga_module, CDCE62002::Reg2::GenSpiTxd());
  CDCE62002::WriteReg(fpga_module, CDCE62002::Reg0::GenSpiTxd());
  CDCE62002::WriteReg(fpga_module, CDCE62002::Reg1::GenSpiTxd());

  CDCE62002::ReadReg(fpga_module, 0);
  CDCE62002::ReadReg(fpga_module, 1);
  //  CDCE62002::ReadReg(fpga_module, 2);
  
  CDCE62002::CopyToEEPROM(fpga_module);

  return 0;

}// main
