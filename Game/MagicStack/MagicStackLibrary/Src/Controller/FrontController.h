#ifndef __MAGICSTACK_CONTROLLER_FRONTCONTROLLER_H__
#define __MAGICSTACK_CONTROLLER_FRONTCONTROLLER_H__

#include <string>
#include <map>
#include "../Model/ControllerTransition.h"

namespace MagicStack
{
    struct IController;

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
            typedef std::map<std::string, IController*> TControllerIndex;

        private:
            bool IsRunning;
            IController* CurrentController;
            TControllerIndex ControllerIndex;
            CControllerTransition Transition;
    };
}


#endif
