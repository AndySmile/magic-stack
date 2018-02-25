#ifndef __MAGICSTACK_HELPER_MACROS_h__
#define __MAGICSTACK_HELPER_MACROS_h__

#define DELETE_OBJECT(object) if (object != nullptr) { delete object; object = nullptr; }

#endif