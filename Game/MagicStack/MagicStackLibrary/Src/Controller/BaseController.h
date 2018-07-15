#ifndef __MAGICSTACK_CONTROLLER_BASECONTROLLER_H__
#define __MAGICSTACK_CONTROLLER_BASECONTROLLER_H__

#include "IController.h"

namespace MagicStack
{
    class CBaseController : public IController
    {
        public:
            virtual ~CBaseController();

            virtual void OnEnter() override;
            virtual void OnLeave() override;
    };
}

#endif