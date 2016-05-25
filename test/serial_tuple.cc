# include "autoSerie/serial.hh"
# include <iostream>
# include <sstream>

int main()
{
  // empty tuple
   {
     auto a = std::make_tuple();
     auto b = std::make_tuple();
     std::stringstream ss;
     autoSerie::serial::write(ss, a);
      std::stringstream ss2(ss.str());
      autoSerie::serial::read(ss2, b);
      assert(b == a);
    }

   // simple
   {
     auto a = std::make_tuple(10, 1.2);
     auto b = std::make_tuple(42, 1.534);
     std::stringstream ss;
    autoSerie::serial::write(ss, a);
     std::stringstream ss2(ss.str());
     autoSerie::serial::read(ss2, b);
     assert(b == a);
   }
   // nested
    {
      std::cout << "nested\n";
      auto a = std::make_tuple(10, 1.2, std::make_tuple( 89.78, 789));
      auto b = std::make_tuple(42, 1.534, std::make_tuple( 42.65, 4242));
      std::stringstream ss;
      autoSerie::serial::write(ss, a);
      std::stringstream ss2(ss.str());
      autoSerie::serial::read(ss2, b);
      assert(b == a);
   }


  return 0;
}
