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
#ifndef SERIAL_OBJECT_HXX
# define SERIAL_OBJECT_HXX

template<class Object,
	 class OutputStream,
	 typename std::enable_if<serialized_class<Object>(), int>::type = 0>
static inline
void iwrite(OutputStream& stream, const Object&  o)
{
  debug_log("object write");
  typename Object::template object_write<OutputStream>(stream, o);
}

template<class Object,
	 class InputStream,
	 typename std::enable_if<serialized_class<Object>(), int>::type = 0>
static inline
void iread(InputStream& stream, Object& o)
{
  debug_log("object read");
  typename Object::template object_read<InputStream>(stream, o);
}

#endif
