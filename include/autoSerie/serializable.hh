#ifndef AUTO_SERIE_SERIALIZABLE_HH
# define AUTO_SERIE_SERIALIZABLE_HH

namespace autoSerie
{
  template <class C>
  struct Serializable
  {
    template<class InputStream>
    static inline void object_read(InputStream stream, C* dst)
    {
      stream.write((char *) dst, sizeof(C));
    }

    template<class OutputStream>
    static inline void object_write(OutputStream stream, const C* const src)
    {
      stream.write((char *) src, sizeof(C));
    }
  };
  template <class C>
  struct ContiguouslySerializable : public Serializable<C>
    {
      template<class InputStream>
      static inline void objects_read(InputStream stream, C* dst, size_t nb_elts)
      {
	stream.read((char*) dst, nb_elts * sizeof(C));
      }

      template<class OutputStream>
      static inline void objects_write(OutputStream stream, const C* const src, size_t nb_elts)
      {
	stream.write((const char* const) src, nb_elts * sizeof(C));
      }
    };


}


#endif