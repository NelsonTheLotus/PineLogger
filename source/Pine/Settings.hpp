#pragma once
// DO NOT INCLUDE PineLib.hpp !!!

//Library-wide used headers
#include <string>

#ifdef IS_PINE_INTERNAL // used for core library headers
    #define PINE_CORE
#endif


#ifdef IS_PINE_EXTRA // used for library plugins
    #define PINE_CORE
#endif