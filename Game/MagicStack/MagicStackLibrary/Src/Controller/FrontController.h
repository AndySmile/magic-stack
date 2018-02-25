#ifndef __MAGICSTACK_CONTROLLER_FRONTCONTROLLER_H__
#define __MAGICSTACK_CONTROLLER_FRONTCONTROLLER_H__

#include <string>
#include <map>
#include "ControllerTransition.h"

namespace MagicStack
{
    struct IController;

    typedef std::map<std::string, IController*> TControllerIndex;

    class CFrontController
    {
        public:
            CFrontController();
            ~CFrontController();

            void AddController(IController* controller, const bool isDefault = false);
            void GoToController(const std::string& alias);
            void Quit();
            void Run() const;

        private:
            void SwitchToController(IController* controller);

        private:
            bool IsRunning;
            IController* CurrentController;
            TControllerIndex ControllerIndex;
            CControllerTransition Transition;
    };
}


#endif
