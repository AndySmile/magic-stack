#ifndef __MAGICSTACK_VIEW_MENUVIEW_H__
#define __MAGICSTACK_VIEW_MENUVIEW_H__

#include "BaseView.h"

namespace MagicStack
{
    class CMenu;

    class CMenuView : public CBaseView
    {
        public:
            CMenuView() = default;
            ~CMenuView() = default;

            void DisplayHeadline() const;
            void DisplayWelcome() const;
            void DisplayMenu(const CMenu& menu) const;
    };
}

#endif