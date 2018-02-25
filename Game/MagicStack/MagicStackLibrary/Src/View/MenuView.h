#ifndef __MAGICSTACK_VIEW_MENUVIEW_H__
#define __MAGICSTACK_VIEW_MENUVIEW_H__

namespace MagicStack
{
    class CMenu;

    class CMenuView
    {
        public:
            CMenuView() = default;
            ~CMenuView() = default;

            void DisplayHeadline() const;
            void DisplayWelcome() const;
            void DisplayMenu(const CMenu& menu) const;

        private:
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