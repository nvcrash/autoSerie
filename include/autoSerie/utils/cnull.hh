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

#ifndef CNULL_HH
# define CNULL_HH
# include <ostream>
# include <cassert>

namespace autoSerie
{
namespace utils
{

  struct cnull : public std::ostream
  {
  protected:
    std::ostream& operator=( const basic_ostream&  ) { throw; }
    std::ostream& operator=( basic_ostream&& ) { throw; }
    void swap(basic_ostream& );

  public:
    template<typename O, typename O2>
    std::ostream& operator<<(const O&) { return *this;}

    std::ostream& put(char_type ) { return *this; }

    std::ostream& write( const char_type* , std::streamsize  ) { return *this; }

    pos_type tellp() { return 0;}
    std::ostream& seekp( pos_type  ) { return *this; }
    std::ostream& seekp( off_type , std::ios_base::seekdir ) { return *this; }

    std::ostream& flush() { return *this; }

  };

    template<typename O, typename O2> static inline
    std::ostream& operator<<(utils::cnull& s, const O& o) { return s;}

}
}
#endif
