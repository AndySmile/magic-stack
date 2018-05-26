#ifndef __MAGICSTACK_CONTROLLER_MENU_HELPCONTROLLER_H__
#define __MAGICSTACK_CONTROLLER_MENU_HELPCONTROLLER_H__

#include "BaseMenuController.h"
#include "../IControllerActionExecutable.h"

namespace MagicStack
{
    class CHelpController
        : public CBaseMenuController
        , public IControllerActionExecutable
    {
        public:
            CHelpController() = default;
            virtual ~CHelpController() = default;

            virtual void Init(CControllerTransition& transition) override;
            virtual void ExecuteControllerAction(const std::string& action) override;
            virtual std::string GetAlias() const;

        private:
            void DisplayWorldDescription() const;
            void DisplayUnknownTopic() const;
    };
}

#endif