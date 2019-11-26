
#ifndef STL_EXPORT_H
#define STL_EXPORT_H

#ifdef STL_STATIC_DEFINE
#  define STL_EXPORT
#  define STL_NO_EXPORT
#else
#  ifndef STL_EXPORT
#    ifdef STL_EXPORTS
        /* We are building this library */
#      define STL_EXPORT 
#    else
        /* We are using this library */
#      define STL_EXPORT 
#    endif
#  endif

#  ifndef STL_NO_EXPORT
#    define STL_NO_EXPORT 
#  endif
#endif

#ifndef STL_DEPRECATED
#  define STL_DEPRECATED __declspec(deprecated)
#endif

#ifndef STL_DEPRECATED_EXPORT
#  define STL_DEPRECATED_EXPORT STL_EXPORT STL_DEPRECATED
#endif

#ifndef STL_DEPRECATED_NO_EXPORT
#  define STL_DEPRECATED_NO_EXPORT STL_NO_EXPORT STL_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef STL_NO_DEPRECATED
#    define STL_NO_DEPRECATED
#  endif
#endif

#endif /* STL_EXPORT_H */
