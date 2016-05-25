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
# include <type_traits>
# include <vector>
# include <tuple>
# include <limits.h>
# include "autoSerie/utils/log.hh"

namespace autoSerie
{
  namespace serial
  {

#include "type_utils.hxx"
#include "fwd.hxx"
#include "object.hxx"
#include "arithmetic.hxx"
#include "tuple.hxx"
#include "vector.hxx"
#include "string.hxx"

    template <typename Object, class OutputStream> static inline void
    write(OutputStream& stream, const Object& o)
    {
      iwrite(stream, o);
    }

    template <typename Object, class InputStream> static inline void
    read(InputStream& stream, Object& o)
    {
      iread(stream, o);
    }

  }
}



#endif
