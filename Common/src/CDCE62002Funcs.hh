#ifndef CDCE62002FUNCS_HH
#define CDCE62002FUNCS_HH

#include<vector>
#include<string>
#include<bitset>
#include<stdint.h>
#include"Uncopyable.hh"

namespace CDCE62002{
  const uint32_t kAddressShift = 4;
  const uint32_t kAddressMask  = 0xF;

  // ------------------------------------------------------------------
  // Reg0
  // ------------------------------------------------------------------
  namespace Reg0{

    enum INBUFSEL
      {
       kDisableIn = 0,
       kLVDSIn    = 1,
       kLVPECLIn  = 2,
       kLVCMOSIn  = 3
      };

    enum SmartMUX
      {
       kReserveMux = 0,
       kRefIn      = 1,
       kAUXIn      = 2,
       kAuto       = 3
      };
    
    enum ACDCSEL
      {
       kACIn       = 0,
       kDCIn       = 1
      };

    enum TERMSEL
      {
       kEnTerm       = 0,
       kDisEnTerm    = 1
      };

    enum REFDIVIDE
      {
       kRefDiv1      = 0,
       kRefDiv2      = 1,
       kRefDiv3      = 2,
       kRefDiv4      = 3,
       kRefDiv5      = 4,
       kRefDiv6      = 5,
       kRefDiv7      = 6,
       kRefDiv8      = 7,
       kRefDiv10     = 12,
       kRefDiv12     = 13,
       kRefDiv14     = 14,
       kRefDiv16     = 15
      };

    enum LOCKW
      {
       kLock21  = 0,
       kLock46  = 1,
       kLock72  = 2,
       kLock199 = 3
      };

    enum OUTDIVIDE
      {
       kDisableOutDiv = 0,
       kOutDiv1    = 1,
       kOutDiv2    = 2,
       kOutDiv3    = 3,
       kOutDiv4    = 4,
       kOutDiv5    = 5,
       kOutDiv6    = 6,
       kOutDiv8    = 8,
       kOutDiv10   = 10,
       kOutDiv20   = 11,
       kOutDiv12   = 12,
       kOutDiv24   = 13,
       kOutDiv16   = 14,
       kOutDiv32   = 15
      };


    enum OUTBUFSEL
      {
       kDisableOut = 0,
       kLVDSOut    = 1,
       kLVCMOSOut  = 2,
       kLVPECLOut  = 3
      };

    // Functions to generate reg0 ____________________________________
    uint32_t SetACDCSEL(uint32_t reg, enum ACDCSEL val);
    uint32_t SetINBUFSEL(uint32_t reg, enum INBUFSEL val);
    uint32_t SetLOCKW(uint32_t reg, enum LOCKW val);
    uint32_t SetOUTBUFSEL0(uint32_t reg, enum OUTBUFSEL val);
    uint32_t SetOUTBUFSEL1(uint32_t reg, enum OUTBUFSEL val);
    uint32_t SetOUTDIVIDE0(uint32_t reg, enum OUTDIVIDE val);
    uint32_t SetOUTDIVIDE1(uint32_t reg, enum OUTDIVIDE val);
    uint32_t SetREFDIVIDE(uint32_t reg, enum REFDIVIDE val);
    uint32_t SetSmartMUX(uint32_t reg, enum SmartMUX val);
    uint32_t SetTERMSEL(uint32_t reg, enum TERMSEL val);
  };

  // ------------------------------------------------------------------
  // Reg1
  // ------------------------------------------------------------------
  namespace Reg1{
    enum SELVCO
      {
       kVCOLow  = 0,
       kVCOHigh = 1
      };

    enum PRESCALER
      {
       kPreScale2 = 3,
       kPreScale3 = 1,
       kPreScale4 = 2,
       kPreScale5 = 0
      };

    enum SELBPDIV
      {
       kBPDIV2   = 0,
       kBPDIV5   = 1,
       kBPDIV8   = 2,
       kBPDIV10  = 3,
       kBPDIV16  = 4,
       kBPDIV20  = 5,
       kBPBypass = 7
      };

    uint32_t SetLFRCSEL(uint32_t reg, uint32_t val);
    uint32_t SetPRESCALER(uint32_t reg, enum PRESCALER val);
    uint32_t SetSELBPDIV(uint32_t reg, enum SELBPDIV val);
    uint32_t SetSELFBDIV(uint32_t reg, uint32_t reg_val); // Set 8-bit reg value
    uint32_t SetSELINDIV(uint32_t reg, uint32_t divide_ratio); // Set DIVIDE val
    uint32_t SetSELVCO(uint32_t reg, enum SELVCO val);

  };

  // ------------------------------------------------------------------
  // Control functions
  // ------------------------------------------------------------------

  // Write the register generated by Reg0::GenSpiTxd or Reg1::GenSpiTxd
  void     WriteReg(HUL::FPGAModule& fpga_module, uint32_t reg);
  
  //Read the register specified by the address
  uint32_t ReadReg(HUL::FPGAModule& fpga_module, uint32_t address);
  // Internal function to generate SpiRxd
  uint32_t GenSpiRxd(uint32_t address);

  // Copy the present register setting to EEPROM in CDCE62002
  void     CopyToEEPROM(HUL::FPGAModule& fpga_module);


};


#endif
