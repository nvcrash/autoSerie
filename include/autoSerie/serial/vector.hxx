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
#ifndef SERIAL_VECTOR_HXX
# define SERIAL_VECTOR_HXX
# include "serial_utils.hh"

namespace autoSerie
{
  namespace serial
  {
    /*
    template <class Contained, class Allocator>
    static inline size_t get_size(typename std::vector<Contained, Allocator>::size_type count)
    {
      return ((size_t) (count)) * sizeof(Contained);
    }


    AUTO_SERIE___x_x___SERIAL_TPL
    template <class Contained, class Allocator, class OutputStream,
	      typename std::enable_if<bool_handler<Contained>(), int>::type>
    void
    internal_serial<SizingPolicy, ErrorPolicy, FlushingPolicy>::
    iwrite_vector(OutputStream& stream, const std::vector<Contained, Allocator>& v)
    {
      debug_log("write bool type vector");
      //#pragma message( "serialization of a std::vector<bool,t> is depreciated, it allocate and copy data" )
      // stupid unefficient code do not use it but for testing
      Allocator allocator();
      size_t s = v.size();
      size_t s2 = s / CHAR_BIT + (s % CHAR_BIT ? 1 : 0);
      unsigned char* data = nullptr;
      if (s > 0)
	{
	  data = (unsigned char*) alloca(s2 * sizeof(char));
	  size_t i = 0;
	  for (; i + CHAR_BIT < s; i += CHAR_BIT)
	    {
	      unsigned char aa = 0;
	      for (unsigned int a = 0; a < (unsigned char) CHAR_BIT; ++a)
		{
		  aa = aa | (v[i + a] << a);
		}

	      data[i / CHAR_BIT] = aa;
	    }
	  unsigned char bb = s - (s % CHAR_BIT);
	  data[s2 - 1] = 0;
	  for (i = 0; i + bb < s; ++i)
	    {
	      data[s2 - 1] = data[s2 - 1] | (v[bb + i] << i);
	    }
	}
      stream.write((const char *) &s, sizeof(size_t));
      stream.write((char*) data, s2 * sizeof(char));
    }

    AUTO_SERIE___x_x___SERIAL_TPL
    template <class Contained, class Allocator, class InputStream,
	      typename std::enable_if<bool_handler<Contained>(), int>::type>
    void internal_serial<SizingPolicy, ErrorPolicy, FlushingPolicy>::
    iread_vector(InputStream& stream, std::vector<Contained, Allocator>& v)
    {
      debug_log("read bool type vector");
#pragma message( "deserialization of a std::vector<bool,t> is depreciated, it allocate and copy data" )
      // stupid unefficient code do not use it but for testing
      size_t s;
      stream.read((char *) &s, sizeof(size_t));
      size_t s2 = s / CHAR_BIT + (s % CHAR_BIT ? 1 : 0);
      v.reserve(s);
      unsigned char* data = (unsigned char*) alloca(s2 * sizeof(char));
      stream.read((char *) data, s2 * sizeof(char));
      size_t i = 0;
      for (; i < s; ++i)
	{
	  v[i] = data[i / CHAR_BIT] & (0x01 << (i % CHAR_BIT));
	}
    }

    AUTO_SERIE___x_x___SERIAL_TPL
    template <class Contained, class Allocator, class OutputStream,
	      typename std::enable_if<default_contiguous_handler<Contained>(), int>::type = 0>
    void internal_serial<SizingPolicy, ErrorPolicy, FlushingPolicy>::
    iwrite_vector(OutputStream& stream, const std::vector<Contained, Allocator>& v)
    {
      debug_log("write data type vector");
      typedef typename std::vector<Contained, Allocator>::size_type vsize_t;
      vsize_t s = v.size();
      stream.write((const char * const) &s, sizeof(vsize_t));

      stream.write((const char * const) &v[0], get_size<Contained, Allocator>(s));
    }

    AUTO_SERIE___x_x___SERIAL_TPL
    template <class Contained, class Allocator, class InputStream,
	      typename std::enable_if<default_contiguous_handler<Contained>(), int>::type = 0>
    void internal_serial<SizingPolicy, ErrorPolicy, FlushingPolicy>::
    iread_vector(InputStream& stream, std::vector<Contained, Allocator>& v)
    {
      debug_log("read data type vector");
      typename std::vector<Contained, Allocator>::size_type s = 0;
      stream.read((char*) &s, sizeof(typename std::vector<Contained, Allocator>::size_type));
      v.reserve(s);
      stream.read((char *) &v[0], sizeof(Contained) * s);
    }

    AUTO_SERIE___x_x___SERIAL_TPL
    template <class Contained, class Allocator, class OutputStream,
	      typename std::enable_if<herit_ContiguouslySerializable<Contained>(), int>::type = 0>
    void internal_serial<SizingPolicy, ErrorPolicy, FlushingPolicy>::
    iwrite_vector(OutputStream& stream, const std::vector<Contained, Allocator>& v)
    {
      debug_log("write Contiguous type vector");
      Contained::template objects_write<OutputStream>(stream, &v[0], v->size());
    }

    AUTO_SERIE___x_x___SERIAL_TPL
    template <class Contained, class Allocator, class InputStream,
	      typename std::enable_if<herit_ContiguouslySerializable<Contained>(), int>::type = 0>
    void internal_serial<SizingPolicy, ErrorPolicy, FlushingPolicy>::
    iread_vector(InputStream& stream, std::vector<Contained, Allocator>& v)
    {
      debug_log("read Contiguous type vector");
      Contained::template objects_write<InputStream>(stream, &v[0], v->size());
    }

    AUTO_SERIE___x_x___SERIAL_TPL
    template <class Contained, class Allocator, class OutputStream,
	      typename std::enable_if<default_handler<Contained>(), int>::type = 0>
    void internal_serial<SizingPolicy, ErrorPolicy, FlushingPolicy>::
    iwrite_vector(OutputStream& stream, std::vector<Contained, Allocator>& v)
    {
      debug_log("write default type vector");
      for (const Contained& a : v)
	iwrite(stream, (const char* const) &a);
    }


    AUTO_SERIE___x_x___SERIAL_TPL
    template <class Contained, class Allocator, class InputStream,
	      typename std::enable_if<default_handler<Contained>(), int>::type = 0>
    void internal_serial<SizingPolicy, ErrorPolicy, FlushingPolicy>::
    iread_vector(InputStream& stream, std::vector<Contained, Allocator> v)
    {
      debug_log("read default type vector");
      for (const Contained& a : v)
	iread(stream, (const char* const) &a);
    }

    AUTO_SERIE___x_x___SERIAL_TPL
    template <template<class...> class Vector = std::vector,
	      class Contained,
	      class Allocator,
	      class OutputStream,
	      typename CATCH_TYPE(Vector, std::vector, <Contained, Allocator>)>
    void internal_serial<SizingPolicy, ErrorPolicy, FlushingPolicy>:: iwrite(OutputStream& stream, const Vector<Contained, Allocator>& v)
    {
      iwrite_vector(stream, v);
    }

    AUTO_SERIE___x_x___SERIAL_TPL
    template <template<class...> class Vector = std::vector,
	      class Contained,
	      class Allocator,
	      class InputStream,
	      typename CATCH_TYPE(Vector, std::vector, <Contained, Allocator>)>
    void internal_serial<SizingPolicy, ErrorPolicy, FlushingPolicy>:: iread(InputStream& stream, Vector<Contained, Allocator>& v)
    {
      iread_vector(stream, v);
    }
    */
  }
}
#endif
