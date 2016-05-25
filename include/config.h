/* include/config.h.  Generated from config.h.in by configure.  */
/* include/config.h.in.  Generated from configure.ac by autoheader.  */

/* enabled if DEVEL is not 0, true by default */
#define DEBUG_SERIAL true

/* enabled if DEVEL is not 0, cerr by default for std::cerr, can be 'cout' for
   std::cout otherwise */
#define DEBUG_STREAM std::cerr

/* 0 if release, debug level otherwise */
#define DEVEL 1

/* Name of package */
#define PACKAGE "autoserie"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "autoSerie"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "autoSerie 0.0.1"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "autoserie"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "0.0.1"

/* log2 of the network share page size */
#define SHARED_PAGE_SIZES_BITS 11

/* Version number of package */
#define VERSION "0.0.1"
