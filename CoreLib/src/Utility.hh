#ifndef UTILITY_HH
#define UTILITY_HH

#include<string>
#include<stdint.h>

namespace Utility
{
  void     PrintProgressBar(const double max, const double current);
  void     FlashMessage(const std::string message);
  uint32_t BitReverse(uint32_t reg);
};

#endif
