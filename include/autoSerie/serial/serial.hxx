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
#ifndef SERIAL_HXX
# define SERIAL_HXX

namespace autoSerie
{
  namespace serial
  {
    template <class SizingPolicy, class ErrorPolicy, class FlushingPolicy>
    template <typename Object, class OutputStream>
    inline void
    Serial<SizingPolicy, ErrorPolicy, FlushingPolicy>::write(OutputStream& stream, const Object& o)
    {
      internal.iwrite(stream, o);
    }

    template <class SizingPolicy, class ErrorPolicy, class FlushingPolicy>
    template <typename Object, class InputStream>
    inline void
    Serial<SizingPolicy, ErrorPolicy, FlushingPolicy>::read(InputStream& stream, Object& o)
    {
      internal.iread(stream, o);
    }

  }
}



#endif
