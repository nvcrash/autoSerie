/*
* Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
*
* Everyone is permitted to copy and distribute verbatim copies
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef AUTO_SERIE_SERIAL_HH
# define AUTO_SERIE_SERIAL_HH
# include <tuple>
# include <vector>
# include <string>
# include <numeric>
# include <cassert>
# include "serial/fwd.hh"

namespace autoSerie
{
  namespace serial
  {
    // USE AT YOUR OWN RISKS, Great power comes along with great responsabilities


    // warning dynamic dispatch not available here, always use the lowest type definition in your call of read or write
    // except for collection inherited class if you only want to serialize their contents then use the collection class
    // inside template parameter for call of read and write


    // warning this classes definition are voluntary not virtual, you must inherit one of these class and redefine his static methods
    // not inheriting this class will result to a compile time error if you call write on a not supported type/class.

    // this class exists for 2 things
    //   - to specify a behavior such as a policy, inheritance to this class is checked (Policy are not used to maintain a pod behavior (which is way faster) and to not alter the objects size (there is no 0 size object in c++))
    //   - to ensure there is a default implementation for the specify behavior

    // those serialisation functions does not have specific allocation methods for containers, you are free to choose them
    // those serialisation functions does not use specific stream, you are free to choose them or to implement them
    // to use your own stream, it require for reading a read method with the same prototype from std::istream
    //                         it require for writing a write method with the same prototype from std::ostream
    // except that the return type is never checked

    // stream flush method is never call directly but might be called from the stream you use
    // also you are free to flush in your template specialisation of object_read, objects_read, object_write, objects_write
    // remeber that simple inheritance with only inline function overloading is at no cost except that it expand the caller
    // remember inline big function or function with conditionals or loops or io calls may be leading to code bloat if the compiler
    // wasn't that smart,

    //support the folowings by default
    //- std::tuple<...>
    //- std::vector<Element, Allocator> with Element MoveInsertable (c++11)
    //                                  see http://en.cppreference.com/w/cpp/concept/MoveInsertable
    //- arythmetic types such as char, int, double, ... but not c array such as a char* with '\0' character terminating
    //- std::basic_string<Char_trait, class Traits, class Allocator>
    // ContiguouslySerializable is to herit and erase if you want the pod behavior on non pod object or special behavior (i-e if you need data operations for compression)

    template <class SizingPolicy, class ErrorPolicy, class FlushingPolicy>
    struct Serial
    {
      template <typename Object, class OutputStream>  inline void
      write(OutputStream& stream, const Object& o);

      template <typename Object, class InputStream>  inline void
      read(InputStream& stream, Object& o);

    private:
      internal_serial<SizingPolicy, ErrorPolicy, FlushingPolicy> internal;
    };


    template <typename Object, class OutputStream> static inline void
    write(OutputStream& stream, const Object& o)
    {
      static Serial<bool,bool,bool> defaultSerial;
      defaultSerial.write(stream, o);
    }

    template <typename Object, class InputStream> static inline void
    read(InputStream& stream, Object& o)
    {
      static Serial<bool,bool,bool> defaultSerial;
      defaultSerial.read(stream, o);
    }
  }
}
#include "serial/serial.hxx"
#endif /* !SERIAL_HH */
