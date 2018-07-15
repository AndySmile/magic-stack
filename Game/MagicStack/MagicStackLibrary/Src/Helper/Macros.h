#ifndef __MAGICSTACK_HELPER_MACROS_h__
#define __MAGICSTACK_HELPER_MACROS_h__

#define DELETE_OBJECT(object) if (object != nullptr) { delete object; object = nullptr; }

#ifdef _DEBUG
    #define PRINT_RELEASE_INFO(className) std::cout << "Release memory of the object '" << className << "'!" << std::endl;
#else
    #define PRINT_RELEASE _INFO
#endif

#endif