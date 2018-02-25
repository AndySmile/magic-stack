#ifndef __MAGICSTACK_CONTROLLER_BASEMENUCONTROLLER_H__
#define __MAGICSTACK_CONTROLLER_BASEMENUCONTROLLER_H__

#include "IController.h"

namespace MagicStack
{
    struct IAction;

    class CBaseMenuController : public IController
    {
        public:
            CBaseMenuController() = default;
            virtual ~CBaseMenuController() = default;

            virtual void Render() const override
            {
                this->View.DisplayMenu(this->Menu);
            }

            virtual IAction* Execute() const override
            {
                unsigned int selectedMenuId = 0;

                do {
                    std::cout << "Your selection: ";
                    std::cin >> selectedMenuId;
                } while (!this->Menu.IsValidItemId(selectedMenuId));

                return this->Menu.GetAction(selectedMenuId);
            }

        protected:
            CMenu Menu;
            CMenuView View;
    };
}

#endif
