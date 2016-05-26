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
#ifndef AUTO_SERIE___x_x___SERIAL_FWD_HXX
# define AUTO_SERIE___x_x___SERIAL_FWD_HXX
# include "serial_utils.hh"
# include "autoSerie/serial/config.h"

# define AUTO_SERIE___x_x___SERIAL_TPL template <class SizingPolicy, class ErrorPolicy, class FlushingPolicy>
# define AUTO_SERIE___x_x___SERIAL_TPLA SizingPolicy, ErrorPolicy, FlushingPolicy
# define AUTO_SERIE___x_x___SERIAL_TPLS internal_serial<SizingPolicy, ErrorPolicy, FlushingPolicy>::

namespace autoSerie
{
  namespace serial
  {
    AUTO_SERIE___x_x___SERIAL_TPL
    struct internal_serial
    {
/// ---- Serializable --- /// ------------------------------------------------/
      template<class Object,
	       class OutputStream,
	       typename std::enable_if<serialized_class<Object>(), int>::type = 0>

      void iwrite(OutputStream& stream, const Object& o);

      template<class Object,
	       class InputStream,
	       typename std::enable_if<serialized_class<Object>(), int>::type = 0>

      void iread(InputStream& stream, Object& o);
/// ---- END Serializable /// ------------------------------------------------/


/// ---- Tuples --- /// ------------------------------------------------------/
      template <template<typename...> typename Object = std::tuple,
		class OutputStream,
		typename CATCH_TYPE(Object, std::tuple, <>),
		typename... Args>

      void iwrite(OutputStream& stream, const Object<Args...>&  o);

      template <template<typename...> typename Object = std::tuple,
		class InputStream,
		typename CATCH_TYPE(Object, std::tuple, <>),
		typename... Args>

      void iread(InputStream& stream, Object<Args...>& o);

      template<class OutputStream, std::size_t I = 0, typename... Tp>
       typename std::enable_if<I == sizeof...(Tp), void>::type
      iwrite_tuple(const std::tuple<Tp...>&, OutputStream&);

      template<class OutputStream, std::size_t I = 0, typename... Tp>
       typename std::enable_if<I < sizeof...(Tp), void>::type
      iwrite_tuple(const std::tuple<Tp...>& t, OutputStream& o);

      template<class OutputStream, std::size_t I = 0, typename... Tp>
       typename std::enable_if<I == sizeof...(Tp), void>::type
      iread_tuple(std::tuple<Tp...>&, OutputStream&);


      template<class OutputStream, std::size_t I = 0, typename... Tp>
       typename std::enable_if<I < sizeof...(Tp), void>::type
      iread_tuple(std::tuple<Tp...>& t, OutputStream& o);
/// ---- END Tuples /// ------------------------------------------------------/


/// ---- Data Types --- /// --------------------------------------------------/
      template <class Object,
		class OutputStream,
		typename std::enable_if<is_data_type<Object>(), int>::type = 0
		>


      void iwrite(OutputStream& stream, const Object&  o);

      template <typename Object,
		class InputStream,
		typename std::enable_if<is_data_type<Object>(), int>::type = 0
		>

      void iread(InputStream& stream, Object& o);
/// ---- END Data Types /// --------------------------------------------------/


/// ---- std::vector --- /// -------------------------------------------------/
      template <template<class...> class Vector = std::vector,
		class Contained,
		class Allocator,
		class OutputStream,
		typename CATCH_TYPE(Vector, std::vector, <Contained, Allocator>)
		>

      void iwrite(OutputStream& stream, const Vector<Contained, Allocator>& v);

      template <template<class...> class Vector = std::vector,
		class Contained,
		class Allocator,
		class InputStream,
		typename CATCH_TYPE(Vector, std::vector, <Contained, Allocator>)
		>

      void iread(InputStream& stream, Vector<Contained, Allocator>& v);


    template <class Contained, class Allocator, class OutputStream,
	      typename std::enable_if<bool_handler<Contained>(), int>::type = 0>
    void
    iwrite_vector(OutputStream& stream, const std::vector<Contained, Allocator>& v);

    template <class Contained, class Allocator, class InputStream,
	      typename std::enable_if<bool_handler<Contained>(), int>::type = 0>
    void
    iread_vector(InputStream& stream, std::vector<Contained, Allocator>& v);

    template <class Contained, class Allocator, class OutputStream,
	      typename std::enable_if<default_contiguous_handler<Contained>(), int>::type = 0>
    void
    iwrite_vector(OutputStream& stream, const std::vector<Contained, Allocator>& v);

    template <class Contained, class Allocator, class InputStream,
	      typename std::enable_if<default_contiguous_handler<Contained>(), int>::type = 0>
    void
    iread_vector(InputStream& stream, std::vector<Contained, Allocator>& v);


    template <class Contained, class Allocator, class OutputStream,
	      typename std::enable_if<herit_ContiguouslySerializable<Contained>(), int>::type = 0>
    void
    iwrite_vector(OutputStream& stream, const std::vector<Contained, Allocator>& v);


    template <class Contained, class Allocator, class InputStream,
	      typename std::enable_if<herit_ContiguouslySerializable<Contained>(), int>::type = 0>
    void
    iread_vector(InputStream& stream, std::vector<Contained, Allocator>& v);


    template <class Contained, class Allocator, class OutputStream,
	      typename std::enable_if<default_handler<Contained>(), int>::type = 0>
    void
    iwrite_vector(OutputStream& stream, std::vector<Contained, Allocator>& v);


    template <class Contained, class Allocator, class InputStream,
	      typename std::enable_if<default_handler<Contained>(), int>::type = 0>
    void
    iread_vector(InputStream& stream, std::vector<Contained, Allocator> v);


/// ---- END std::vector /// -------------------------------------------------/


/// ---- std::basic_string --- /// -------------------------------------------/
      template <template<class CharT, class Traits, class Allocator>
		class Object = std::basic_string,
		class OutputStream,
		class CharT,
		class Traits,
		class Allocator,
		typename CATCH_TYPE(Object, std::basic_string, <CharT, Traits, Allocator>)
		>

       void iwrite(OutputStream& stream,
	     const Object<CharT, Traits, Allocator>&  o);

      template <template<class CharT, class Traits, class Allocator>
		class Object = std::basic_string,
		class InputStream,
		class CharT,
		class Traits,
		class Allocator,
		typename CATCH_TYPE(Object, std::basic_string, <CharT, Traits, Allocator>)
		>
      void
      iread(InputStream& stream, Object<CharT, Traits, Allocator>& o);
/// ---- END std::basic_string /// -------------------------------------------/
    };
  }
}
#endif
