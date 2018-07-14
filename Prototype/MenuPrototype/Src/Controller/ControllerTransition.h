#ifndef __MENU_CONTROLLER_CONTROLLERTRANSITION_H__
#define __MENU_CONTROLLER_CONTROLLERTRANSITION_H__

#include <string>

class CFrontController;

class CControllerTransition
{
    public:
        CControllerTransition(CFrontController& frontController);
        ~CControllerTransition() = default;

        void GoTo(const std::string& controllerAlias);
        void Quit();

    private:
        CFrontController& FrontController;
};

#endif