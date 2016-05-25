#include <iostream>
#include <sstream>
#include <cstdint>
#include <cassert>

#include <autoSerie/serial.hh>
int main()
{

  char a[2] = {45, '\0'};
  char b[2] =  {127, '\0'};
  bool c = false;
  std::stringstream ss;
  autoSerie::serial::write(ss, a[0]);
  ss.write(&a[1], 1);
  autoSerie::serial::write(ss, c);

  std::stringstream ss2(ss.str());
  autoSerie::serial::read(ss2, b[0]);
  std::cerr << (int) a[0] << ',' << (int) b[0] << std::endl;
  assert(b[0] == a[0]);
  return 0;
}
