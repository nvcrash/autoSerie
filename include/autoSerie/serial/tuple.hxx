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

#ifndef SERIAL_TUPLE_HXX
# define SERIAL_TUPLE_HXX

struct tuple_internal
{
  template<class OutputStream, std::size_t I = 0, typename... Tp>
  static inline typename std::enable_if<I == sizeof...(Tp), void>::type
  iwrite_tuple(const std::tuple<Tp...>&, OutputStream&)
  { }

  template<class OutputStream, std::size_t I = 0, typename... Tp>
  static inline typename std::enable_if<I < sizeof...(Tp), void>::type
  iwrite_tuple(const std::tuple<Tp...>& t, OutputStream& o)
  {
    auto a = std::get<I>(t);
    iwrite<>(o, a);
    iwrite_tuple<OutputStream, I + 1, Tp...>(t, o);
  }

  template<class OutputStream, std::size_t I = 0, typename... Tp>
  static inline typename std::enable_if<I == sizeof...(Tp), void>::type
  iread_tuple(std::tuple<Tp...>&, OutputStream&)
  { }

  template<class OutputStream, std::size_t I = 0, typename... Tp>
  static inline typename std::enable_if<I < sizeof...(Tp), void>::type
  iread_tuple(std::tuple<Tp...>& t, OutputStream& o)
  {
    iread<>(o, std::get<I>(t));
    iread_tuple<OutputStream, I + 1, Tp...>(t, o);
  }
};

template <template<typename...> typename Object = std::tuple,
	  class InputStream,
	  typename CATCH_TYPE(Object, std::tuple, <>),
	  typename... Args> static inline
void iread(InputStream& stream, Object<Args...>& o)
{
  debug_log("tuple read");
  tuple_internal::iread_tuple(o, stream);
}

template <template<typename...> typename Object = std::tuple,
	  class OutputStream,
	  typename std::enable_if<std::is_same<Object<>, std::tuple<>>::value, int>::type = 0,
	  typename... Args> static inline
void iwrite(OutputStream& stream, const Object<Args...>& o)
{
  debug_log("tuple write");
  tuple_internal::iwrite_tuple(o, stream);
}

#endif
