#include "autoSerie/utils/execute.hh"
#include <iostream>

unsigned long foo(unsigned short a, unsigned b, unsigned long c)
{
  std::cout << a << '+' << b << '+' <<  c << '=' << a + b + c;
  return a + b + c;
}

class FooCall : public autoSerie::util::Call<unsigned long, unsigned short, unsigned, unsigned long>
{
public:
  FooCall()
  {
    func = foo;
  }

};

int main()
{
  FooCall f;
  return f.execute(FooCall::t_args(2,4,8)) == 16;
}
