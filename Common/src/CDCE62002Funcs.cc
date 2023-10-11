#include<ios>
#include<iomanip>
#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include<unistd.h>

#include"Utility.hh"
#include"RegisterMapCommon.hh"
#include"FPGAModule.hh"
#include"CDCE62002Funcs.hh"
#include"BitDump.hh"

namespace CDCE62002{

  namespace Reg0{
    // INBUFSET ________________________________________________
    uint32_t
    SetINBUFSEL(uint32_t reg, enum INBUFSEL val)
    {
      const uint32_t mask  = 0xFFFFFFCF;
      const uint32_t shift = kAddressShift;

      uint32_t set = static_cast<uint32_t>(val);

      reg = (reg & mask) | (set << shift);
      return reg;
    }


    // SmartMUX ________________________________________________
    uint32_t
    SetSmartMUX(uint32_t reg, enum SmartMUX val)
    {
      const uint32_t mask  = 0xFFFFFF3F;
      const uint32_t shift = kAddressShift + 2;

      uint32_t set = static_cast<uint32_t>(val);

      reg = (reg & mask) | (set << shift);
      return reg;
    }

    // ACDCSEL__________________________________________________
    uint32_t
    SetACDCSEL(uint32_t reg, enum ACDCSEL val)
    {
      const uint32_t mask  = 0xFFFFFEFF;
      const uint32_t shift = kAddressShift + 4;

      uint32_t set = static_cast<uint32_t>(val);

      reg = (reg & mask) | (set << shift);
      return reg;
    }

    // TERMSEL__________________________________________________
    uint32_t
    SetTERMSEL(uint32_t reg, enum TERMSEL val)
    {
      const uint32_t mask  = 0xFFFFFDFF;
      const uint32_t shift = kAddressShift + 5;

      uint32_t set = static_cast<uint32_t>(val);

      reg = (reg & mask) | (set << shift);
      return reg;
    }

    
    // REFDIVIDE________________________________________________
    uint32_t
    SetREFDIVIDE(uint32_t reg, enum REFDIVIDE val)
    {
      const uint32_t mask  = 0xFFFFC3FF;
      const uint32_t shift = kAddressShift + 6;

      uint32_t set = static_cast<uint32_t>(val);

      reg = (reg & mask) | (set << shift);
      return reg;
    }

    // LOCKW____________________________________________________
    uint32_t
    SetLOCKW(uint32_t reg, enum LOCKW val)
    {
      const uint32_t mask  = 0xFFF9FFFF;
      const uint32_t shift = kAddressShift + 13;

      uint32_t set = static_cast<uint32_t>(val);

      reg = (reg & mask) | (set << shift);
      return reg;
    }

    
    // OUTDIVIDE________________________________________________
    uint32_t
    SetOUTDIVIDE0(uint32_t reg, enum OUTDIVIDE val)
    {
      const uint32_t mask  = 0xFF87FFFF;
      const uint32_t shift = kAddressShift + 15;

      uint32_t set = static_cast<uint32_t>(val);

      reg = (reg & mask) | (set << shift);
      return reg;
    }

    uint32_t
    SetOUTDIVIDE1(uint32_t reg, enum OUTDIVIDE val)
    {
      const uint32_t mask  = 0xF87FFFFF;
      const uint32_t shift = kAddressShift + 19;

      uint32_t set = static_cast<uint32_t>(val);

      reg = (reg & mask) | (set << shift);
      return reg;
    }

    // OUTBUFSEL________________________________________________
    uint32_t
    SetOUTBUFSEL0(uint32_t reg, enum OUTBUFSEL val)
    {
      const uint32_t mask  = 0xCFFFFFFF;
      const uint32_t shift = kAddressShift + 24;

      uint32_t set = static_cast<uint32_t>(val);

      reg = (reg & mask) | (set << shift);
      return reg;
    }

    uint32_t
    SetOUTBUFSEL1(uint32_t reg, enum OUTBUFSEL val)
    {
      const uint32_t mask  = 0x3FFFFFFF;
      const uint32_t shift = kAddressShift + 26;

      uint32_t set = static_cast<uint32_t>(val);

      reg = (reg & mask) | (set << shift);
      return reg;
    }
  };
  
  namespace Reg1{
    // SELVCO __________________________________________________
    uint32_t
    SetSELVCO(uint32_t reg, enum SELVCO val)
    {
      const uint32_t mask  = 0xFFFFFFEF;
      const uint32_t shift = kAddressShift;

      uint32_t set = static_cast<uint32_t>(val);

      reg = (reg & mask) | (set << shift);
      return reg;
    }

    // SELINDIV ________________________________________________
    uint32_t
    SetSELINDIV(uint32_t reg, uint32_t divide_ratio)
    {
      if( !(1 <= divide_ratio && divide_ratio <= 256)){
	std::cerr << "#E : CDCE62002::Reg1::SetSELINDIV()" << std::endl;
	std::cerr << "     Arg2 exceeds the range of INDIV (1 - 256)." << std::endl;
	return reg;
      }

      uint32_t val = divide_ratio -1;
      
      const uint32_t mask  = 0xFFFFE01F;
      const uint32_t shift = kAddressShift + 1;

      uint32_t set = static_cast<uint32_t>(val);

      reg = (reg & mask) | (set << shift);
      return reg;
    }

    // PRESCALER _______________________________________________
    uint32_t
    SetPRESCALER(uint32_t reg, enum PRESCALER val)
    {
      const uint32_t mask  = 0xFFFF9FFF;
      const uint32_t shift = kAddressShift + 9;

      uint32_t set = static_cast<uint32_t>(val);

      reg = (reg & mask) | (set << shift);
      return reg;
    }

    // SELFBDIV ________________________________________________
    // Use this function carefully because no complete protection to prevent setting 
    // the incorrect register values.
    uint32_t
    SetSELFBDIV(uint32_t reg, uint32_t reg_val)
    {
      if( !(0 <= reg_val && reg_val <= 256)){
	std::cerr << "#E : CDCE62002::Reg1::SetSELFBDIV()" << std::endl;
	std::cerr << "     Arg2 exceeds the range of FBDIV (8 - 1280)." << std::endl;
	return reg;
      }
      
      const uint32_t mask  = 0xFF807FFF;
      const uint32_t shift = kAddressShift + 11;

      uint32_t set = static_cast<uint32_t>(reg_val);

      reg = (reg & mask) | (set << shift);
      return reg;
    }

    // SELBPDIV  _______________________________________________
    uint32_t
    SetSELBPDIV(uint32_t reg, enum SELBPDIV val)
    {
      const uint32_t mask  = 0xFC7FFFFF;
      const uint32_t shift = kAddressShift + 19;

      uint32_t set = static_cast<uint32_t>(val);

      reg = (reg & mask) | (set << shift);
      return reg;
    }

    // LFRCSEL _________________________________________________
    uint32_t
    SetLFRCSEL(uint32_t reg, uint32_t val)
    {
      if( !(0 <= val && val <= 15)){
	std::cerr << "#E : CDCE62002::Reg1::SetLFRCSEL()" << std::endl;
	std::cerr << "     Arg2 exceeds the range of LFRCSEL (0 - 15)." << std::endl;
	return reg;
      }
      
      const uint32_t mask  = 0xC3FFFFFF;
      const uint32_t shift = kAddressShift + 22;

      uint32_t set = static_cast<uint32_t>(val);

      reg = (reg & mask) | (set << shift);
      return reg;
    }

  };
    
  // GenSpiRxd _____________________________________________________
  uint32_t
  GenSpiRxd(uint32_t address)
  {
    const uint32_t kInstruction  = 0xE;  
    address = address & kAddressMask;

    uint32_t reg = 0;
    reg = (address << kAddressShift) | kInstruction;
    return Utility::BitReverse(reg);
  }
  
  // WriteReg ______________________________________________________
  void
  WriteReg(HUL::FPGAModule& fpga_module, uint32_t reg)
  {
    fpga_module.WriteModule(CIRASAME::C6C::kAddrTxd, reg, 4);
    fpga_module.WriteModule(CIRASAME::C6C::kAddrExecWrite, 0, 1);
  }
  
  // ReadReg _______________________________________________________
  uint32_t
  ReadReg(HUL::FPGAModule& fpga_module, uint32_t address)
  {
    fpga_module.WriteModule(CIRASAME::C6C::kAddrTxd, GenSpiRxd(address), 4);
    fpga_module.ReadModule(CIRASAME::C6C::kAddrExecRead, 1);
    uint32_t ret = fpga_module.ReadModule(CIRASAME::C6C::kAddrRxd, 4);
    ret = Utility::BitReverse(ret);
  
    std::cout << "#D : CDCE62002::ReadReg() \n";
    std::cout << std::setfill('0') << std::right;
    std::cout << std::hex << "     0x" << std::setw(8) << ret << "\n";
    std::cout << std::dec;
    std::cout << std::setfill(' ');
  
    hddaq::BitDump bdump;
    bdump(ret);

    return ret;
  }

  // CopyToEEPROM __________________________________________________
  void
  CopyToEEPROM(HUL::FPGAModule& fpga_module)
  {
    const uint32_t reg = 0x1F;
    
    fpga_module.WriteModule(CIRASAME::C6C::kAddrTxd, Utility::BitReverse(reg), 4);
    fpga_module.WriteModule(CIRASAME::C6C::kAddrExecWrite, 0, 1);
  }

};
