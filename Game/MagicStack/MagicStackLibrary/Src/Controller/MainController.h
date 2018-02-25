#ifndef __MAGICSTACK_CONTROLLER_MAINCONTROLLER_H__
#define __MAGICSTACK_CONTROLLER_MAINCONTROLLER_H__

namespace MagicStack
{
    /**
     * Main Controller.
     *
     * Manages the entire game.
     */
    class MainController
    {
        public:
            MainController() = default;
            ~MainController() = default;

            void Run();
    };
}

#endif 