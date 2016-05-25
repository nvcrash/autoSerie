#ifndef LOG_HH
#define LOG_HH
# include "config.h"
# include <iostream>
# include <sstream>
# include "cnull.hh"

namespace autoSerie
{
  namespace utils
  {

    template <bool enabled>
    struct log;

    template<> struct log<true>
    {
      static void l(const std::string& s)
      {
	DEBUG_STREAM << s << std::endl;
	DEBUG_STREAM .flush();
      }
    };
    template<> struct log<false>
    {
      static inline void l(const std::string& s)
      {
      }
    };
  }
}
#endif /* !LOG_HH */
