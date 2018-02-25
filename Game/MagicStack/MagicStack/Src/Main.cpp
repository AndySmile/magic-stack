/**
 * @copyright Copyright (c) 2018 by Andy Liebke. All rights reserved.
 */
#include <cstdlib>
#include "Controller\MainController.h"

int main()
{
    MagicStack::MainController mainController;

    mainController.Run();

    system("pause");

    return EXIT_SUCCESS;
}