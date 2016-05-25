#include <iostream>
#include "autoSerie/serial.hh"


int main()
{
  std::string a = "foo";
  std::string b = "bar";
  char c = '\0';
  std::stringstream ss;
  autoSerie::serial::write(ss, a);
  ss.write(&c, 1);
  std::stringstream ss2(ss.str());
  autoSerie::serial::read(ss2, b);
  std::cerr << a  << ',' << b << std::endl;
  assert(b[0] == a[0]);
  return 0;
}
