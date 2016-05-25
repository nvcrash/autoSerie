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
#ifndef SERIAL_STRING_HXX
#define SERIAL_STRING_HXX

template <template<class CharT, class Traits, class Allocator>
	  class Object = std::basic_string,
	  class OutputStream,
	  class CharT,
	  class Traits,
	  class Allocator,
	  typename CATCH_TYPE(Object, std::basic_string, <CharT, Traits, Allocator>)>
static inline void
iwrite(OutputStream& stream,
       const Object<CharT, Traits, Allocator>& o)
{
  debug_log("string write");
  typename Object<CharT, Traits, Allocator>::size_type s = o.size();
  stream.write((char*) &s, sizeof(typename Object<CharT, Traits, Allocator>::size_type));
  stream.write((const char* const) o.c_str(), o.size() * sizeof(CharT));
}

template <template<class CharT, class Traits, class Allocator>
	  class Object = std::basic_string,
	  class InputStream,
	  class CharT,
	  class Traits,
	  class Allocator,
	  typename CATCH_TYPE(Object, std::basic_string, <CharT, Traits, Allocator>)>
static inline void
iread(InputStream& stream, Object<CharT, Traits, Allocator>& o)
{
  debug_log("string read");
  typename std::basic_string<CharT, Traits, Allocator>::size_type s;
  stream.read((char*) &s, sizeof(typename std::basic_string<CharT, Traits, Allocator>::size_type));
  o.reserve(s+1);
  stream.read((char*) &(o[0]), sizeof(CharT) * s);
  CharT* ptr = &(o[s]);
  *ptr = '\0';

}

#endif
