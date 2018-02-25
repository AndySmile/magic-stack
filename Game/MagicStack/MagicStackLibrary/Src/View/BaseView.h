#ifndef __MAGICSTACK_VIEW_BASEVIEW_H__
#define __MAGICSTACK_VIEW_BASEVIEW_H__

#include <string>

namespace MagicStack
{
    class CBaseView
    {
        public:
            CBaseView() = default;
            ~CBaseView() = default;

            void DisplayBoxLine() const;
            void DisplayBoxText(const std::string& text) const;
            void DisplayDotLine() const;
            void DisplayRoundLine() const;
            void DisplayArrowText(const std::string& text) const;
            void DisplayNewLine() const;
            void DisplayMessageBox(const std::string& message) const;
    };
}

#endif