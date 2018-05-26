#ifndef __MAGICSTACK_CONTROLLER_BASECONTROLLER_H__
#define __MAGICSTACK_CONTROLLER_BASECONTROLLER_H__

#include "IController.h"

namespace MagicStack
{
    class BaseController : public IController
    {
        public:
            virtual ~BaseController() = default;

            virtual void OnEnter();
            virtual void OnLeave();
    };
}

#endif