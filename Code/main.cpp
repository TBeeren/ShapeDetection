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

#include <cassert>
#include <iostream>
#include "CCommandMode.h"

//Define an message with the triggered assert.
#define assertm(exp, msg) assert(((void)msg, exp))

int main(int argc, char** argv)
{
    assertm(argc <= 4, "Please enter a maximum of 3 arguments");

    if(argc == 4)
    {
        // Enter CommandMode
    }
    else if(argc == 1)
    {
        // Enter GUI mode
        std::unique_ptr<CCommandMode> spCommandMode = std::make_unique<CCommandMode>(argv);
        spCommandMode->Init();
        spCommandMode->StartTest();
        spCommandMode->Execute();
        
    }
    else
    {
        std::cout << "Please enter a maximum of 3 arguments" << std::endl;
    }

    return 0;
}
