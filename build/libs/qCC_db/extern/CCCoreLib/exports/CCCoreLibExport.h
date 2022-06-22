
#ifndef CC_CORE_LIB_API_H
#define CC_CORE_LIB_API_H

#ifdef CCCORELIB_STATIC_DEFINE
#  define CC_CORE_LIB_API
#  define CCCORELIB_NO_EXPORT
#else
#  ifndef CC_CORE_LIB_API
#    ifdef CCCoreLib_EXPORTS
        /* We are building this library */
#      define CC_CORE_LIB_API __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define CC_CORE_LIB_API __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef CCCORELIB_NO_EXPORT
#    define CCCORELIB_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef CCCORELIB_DEPRECATED
#  define CCCORELIB_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef CCCORELIB_DEPRECATED_EXPORT
#  define CCCORELIB_DEPRECATED_EXPORT CC_CORE_LIB_API CCCORELIB_DEPRECATED
#endif

#ifndef CCCORELIB_DEPRECATED_NO_EXPORT
#  define CCCORELIB_DEPRECATED_NO_EXPORT CCCORELIB_NO_EXPORT CCCORELIB_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef CCCORELIB_NO_DEPRECATED
#    define CCCORELIB_NO_DEPRECATED
#  endif
#endif

#endif /* CC_CORE_LIB_API_H */
