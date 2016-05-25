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

#ifndef ARITHMETIC_HXX
# define ARITHMETIC_HXX

template <class Object,
	  class OutputStream,
	  typename std::enable_if<is_data_type<Object>(), int>::type = 0>
static
void iwrite(OutputStream& stream, const Object& o)
{
  debug_log("data write");
  stream.write((const char * const) &o, sizeof(Object));
}

template <typename Object,
	  class InputStream,
	  typename std::enable_if<is_data_type<Object>(), int>::type = 0>
static
void iread(InputStream& stream, Object& o)
{
  debug_log("data read");
  stream.read((char*) &o, sizeof(Object));
}

#endif
