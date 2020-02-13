/**
 * @file CColour.h
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief 
 * @version 0.1
 * @date 07-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "CCommandMode.h"

//Define an message with the triggered assert.
#define assertm(exp, msg) assert(((void)msg, exp))

int main(int argc, char** argv)
{
    assertm(argc <= 2, "Please enter a maximum of 2 arguments");

    if(argc == 2)
    {
        // Enter CommandMode
        std::unique_ptr<CCommandMode> spCommandMode = std::make_unique<CCommandMode>(argv);
        if(spCommandMode->Init())
        {
            spCommandMode->StartTest();
            spCommandMode->Execute();
        }
    }
    else if(argc == 1)
    {
        // Enter GUI mode
    }
    else
    {
        std::cout << "Please enter a maximum of 2 arguments" << std::endl;
    }

    // Feature -> Calibration mode 
    // @brief: Enter Calibrarion window

    return 0;
}
