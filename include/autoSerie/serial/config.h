// insure macro parameters are defined and set defaults values if not
// can be included multiple times

/* forcing parameters to DEFAULT can use but better set them all or no ones for clarity*/
#ifdef AUTO_SERIE_SERIAL_DEFAULT
#  define AUTO_SERIE_DEBUG_SERIAL 1

/* enable support of std::array */
#  define AUTO_SERIE_SERIAL_STD_ARRAY 1


/* enable support of std::string */
#  define AUTO_SERIE_SERIAL_STD_STRING 1


/* enable support of std::tuple */
#  define AUTO_SERIE_SERIAL_STD_TUPLE 1

/* enable support of std::vector */
#  define AUTO_SERIE_SERIAL_STD_VECTOR 1


/* set a prefix for serial, this allow multiple use with different configurations*/

#  define AUTO_SERIE_SERIAL_PREFIX

#else

# ifndef AUTO_SERIE_DEBUG_SERIAL
#  define AUTO_SERIE_DEBUG_SERIAL 1
# endif

/* enable support of std::array */
# ifndef AUTO_SERIE_SERIAL_STD_ARRAY
#  define AUTO_SERIE_SERIAL_STD_ARRAY 1
# endif

/* enable support of std::string */
# ifndef AUTO_SERIE_SERIAL_STD_STRING
#  define AUTO_SERIE_SERIAL_STD_STRING 1
# endif

/* enable support of std::tuple */
# ifndef AUTO_SERIE_SERIAL_STD_TUPLE
#  define AUTO_SERIE_SERIAL_STD_TUPLE 1
# endif

/* enable support of std::vector */
# ifndef AUTO_SERIE_SERIAL_STD_VECTOR
#  define AUTO_SERIE_SERIAL_STD_VECTOR 1
# endif

/* set a prefix for serial, this allow multiple use with different configurations*/
# ifndef AUTO_SERIE_SERIAL_PREFIX
#  define AUTO_SERIE_SERIAL_PREFIX
# endif
#endif
