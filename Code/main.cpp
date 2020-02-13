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

#include <iostream>
#include <opencv2/opencv.hpp>

#include "CInteractiveMode.h"

int main(int argc, char const *argv[])
{
    if(argc == 1)
    {
        std::cout << "Interactive mode" << std::endl;

        CInteractiveMode mode;
            while(true){
                if(mode.Init())
                {
                    mode.Execute();
                }else{
                    std::cout << "No valid shape or color!!" << std::endl; 
                }
            }
    }else{
        std::cout << "batch mode" << std::endl;
    }

    return 0;
}
