#ifndef __MAGICSTACK_CONTROLLER_MAINCONTROLLER_H__
#define __MAGICSTACK_CONTROLLER_MAINCONTROLLER_H__

#include "FrontController.h"

namespace MagicStack
{
    /**
     * Main Controller.
     *
     * Manages the entire game.
     */
    class CMainController
    {
        public:
            CMainController();
            ~CMainController() = default;

            void Run();

        private:
            CFrontController FrontController;
    };
}

#endif 