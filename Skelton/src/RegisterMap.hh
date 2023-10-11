#ifndef REGISTER_HH
#define REGISTER_HH

#include<stdint.h>
#include"RegisterMapCommon.hh"

namespace CIRASAME{
namespace Skelton{
// LED Module -------------------------------------------------------------
namespace LED{
  enum LocalAddress
    {
     kAddrLED = 0x00000000 // W/R, [7:0] select trigger line
    };
};

};

};

#endif
