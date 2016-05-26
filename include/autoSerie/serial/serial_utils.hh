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

#ifndef SERIAL_TYPE_UTILS_HXX
#define SERIAL_TYPE_UTILS_HXX
# include "autoSerie/utils/log.hh"
# include "autoSerie/serializable.hh"
#define CATCH_TYPE(A, B, ...)						\
  std::enable_if<std::is_same<A __VA_ARGS__, B __VA_ARGS__ >::value, int>::type

namespace autoSerie
{
  namespace serial
  {

    static inline void debug_log(const std::string& s)
    {
      autoSerie::utils::log<DEBUG_SERIAL>::l(s);
    }

    template <typename O>
    static inline constexpr bool is_not_pointer()
    {
      return !std::is_pointer<O>() && !std::is_reference<O>();
    }

    template <typename O>
    static inline constexpr bool is_data_type()
    {
      return is_not_pointer<O>() && (std::is_arithmetic<O>() || std::is_pod<O>() || std::is_same<O,bool>::value);
    }

    template <class Object>
    static inline constexpr bool serialized_class()
    {
      return std::is_base_of<Serializable<Object>, Object>() && !std::is_same<Serializable<Object>, Object>();
    }

    template <class Object>
    static inline constexpr bool herit_ContiguouslySerializable()
    {
      return std::is_base_of<ContiguouslySerializable<Object>, Object>();
    }

    template <class Contained> static inline
    constexpr bool default_handler()
    {
      return (!autoSerie::serial::is_data_type<Contained>() && ! autoSerie::serial::herit_ContiguouslySerializable<Contained>() && !std::is_same<Contained,bool>::value);
    }

    template <class Contained> static inline
    constexpr bool bool_handler()
    {
      return std::is_same<Contained,bool>::value;
    }

    template <class Contained> static inline
    constexpr bool default_contiguous_handler()
    {
      return ( autoSerie::serial::is_data_type<Contained>() && !std::is_same<Contained,bool>::value);
    }


  }

}

#endif
