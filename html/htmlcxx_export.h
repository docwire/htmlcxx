#ifndef HTMLCXX_EXPORT
  #if _MSC_VER && !__INTEL_COMPILER
    #define HTMLCXX_EXPORT __declspec(dllexport)
  #else
    #define HTMLCXX_EXPORT
  #endif
#endif