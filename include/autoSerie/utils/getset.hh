#ifndef GETSET_HH
# define GETSET_HH


// getter whith const ref, copy on need
#define GEN_GETR(_type_, _attr_)				\
  inline const _type_&  _attr_##get() const { return _attr_; }	\


// getter whith ref (no copy), and setter with const ref (copy)
#define GEN_SETR(_type_, _attr_)\
  inline void _attr_##set(const _type_& attr) { _attr_=attr;} \
  inline  _type_&  _attr_##get()  { return attr; }

// like GEN_GETR but whith pointer derefferencing, copy on need. please provide derefferenced type
#define GEN_GETRP(_type_, _attr_)				\
  inline const _type_&  _attr_##get() const { return *_attr_; }	\

// like GEN_SETR but whith pointer derefferencing, copy on need for getter, set: no copy or allocation,
// please provide derefferenced type
#define GEN_SETRP(_type_, _attr_)\
  inline void _attr_##set(_type_* attr) { _attr_=attr;} \
  inline  _type_&  _attr_##get()  { return *attr; }



// simple GET (no head-ache but most of time stupid)
#define GEN_GET(_type_, _attr_)\
  inline  _type_  _attr_##get() const { return _attr_; }	\


// simple SET (no head-ache but most of time stupid)
#define GEN_SET(_type_, _attr_)\
  inline void _attr_##set(const _type_ attr) { _attr_=attr;}	\
  inline _type_ _attr_##get() {return _attr_;}




#endif /* !GETSET_HH */
