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
#ifndef SERIAL_FWD_HXX
# define SERIAL_FWD_HXX

// function declarations

template<class Object,
	 class OutputStream,
	 typename std::enable_if<serialized_class<Object>(), int>::type = 0>
static inline
void iwrite(OutputStream& stream, const Object& o);

template<class Object,
	 class InputStream,
	 typename std::enable_if<serialized_class<Object>(), int>::type = 0>
static inline
void iread(InputStream& stream, Object& o);

template <template<typename...> typename Object = std::tuple,
	  class OutputStream,
	  typename CATCH_TYPE(Object, std::tuple, <>),
	  typename... Args> static inline
void iwrite(OutputStream& stream, const Object<Args...>&  o);

template <template<typename...> typename Object = std::tuple,
	  class InputStream,
	  typename CATCH_TYPE(Object, std::tuple, <>),
	  typename... Args> static inline
void iread(InputStream& stream, Object<Args...>& o);

template <class Object,
	  class OutputStream,
	  typename std::enable_if<is_data_type<Object>(), int>::type = 0>
static
void iwrite(OutputStream& stream, const Object&  o);

template <typename Object,
	  class InputStream,
	  typename std::enable_if<is_data_type<Object>(), int>::type = 0>
static
void iread(InputStream& stream, Object& o);


template <template<class...> class Vector = std::vector,
	  class Contained,
	  class Allocator,
	  class OutputStream,
	  typename CATCH_TYPE(Vector, std::vector, <Contained, Allocator>)>
static inline
void iwrite(OutputStream& stream, const Vector<Contained, Allocator>& v);

template <template<class...> class Vector = std::vector,
	  class Contained,
	  class Allocator,
	  class InputStream,
	  typename CATCH_TYPE(Vector, std::vector, <Contained, Allocator>)>
static inline
void iread(InputStream& stream, Vector<Contained, Allocator>& v);

template <template<class CharT, class Traits, class Allocator>
	  class Object = std::basic_string,
	  class OutputStream,
	  class CharT,
	  class Traits,
	  class Allocator,
	  typename CATCH_TYPE(Object, std::basic_string, <CharT, Traits, Allocator>)>
static inline void
iwrite(OutputStream& stream,
       const Object<CharT, Traits, Allocator>&  o);

template <template<class CharT, class Traits, class Allocator>
	  class Object = std::basic_string,
	  class InputStream,
	  class CharT,
	  class Traits,
	  class Allocator,
	  typename CATCH_TYPE(Object, std::basic_string, <CharT, Traits, Allocator>)>
static inline void
iread(InputStream& stream, Object<CharT, Traits, Allocator>& o);



#endif
