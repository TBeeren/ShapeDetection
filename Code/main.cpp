/**
 * @file main.cpp
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief 
 * @version 0.1
 * @date 07-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "CCommandMode.h"
#include "CInteractiveMode.h"
#include <vector>

//Define an message with the triggered assert.
#define assertm(exp, msg) assert(((void)msg, exp))

int main(int argc, char** argv)
{
    assertm(argc <= 3, "Please enter a maximum of 3 arguments");

    if (argc == 3)
    {
        std::vector<std::string> bashArguments;
        for(int i = 0; i < argc; ++i)
        {
            bashArguments.emplace_back(argv[i]);
        }
        // Enter CommandMode
        std::shared_ptr<CCommandMode> spCommandMode = std::make_shared<CCommandMode>(bashArguments);
        if (spCommandMode->Init())
        {
            spCommandMode->SetFileLogEnabled(true);
            spCommandMode->Execute();
        }
    }
    else if (argc == 1)
    {
        // Enter GUI mode
        std::unique_ptr<CInteractiveMode> spInteractiveMode = std::make_unique<CInteractiveMode>();
        if (spInteractiveMode->Init())
        {
            spInteractiveMode->Execute();
        }
    }
    else
    {
        std::cout << "Please enter a maximum of 2 arguments" << std::endl;
    }

    return 0;
}