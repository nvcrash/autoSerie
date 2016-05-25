#ifndef ERROR_HH
# define ERROR_HH
namespace autoSerie
{
  namespace utils
  {
    template<bool> struct CompileTimeChecker
    {
      CompileTimeChecker(...);
    };
    template<> struct CompileTimeChecker<false> { };

#define STATIC_CHECK(expr, msg)						\
    {									\
      class ERROR_##msg {};						\
      (void)sizeof(CompileTimeChecker<(expr) != 0>((ERROR_##msg())));}
  }
}

#endif /* ERROR_HH */
