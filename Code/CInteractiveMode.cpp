/**
 * @file CInteractiveMode.cpp
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief This class makes the interactive mode. It asks a shape and colour from the user. 
 * If he enters a valid shape and colour, the shape detection will start.
 * @version 0.1
 * @date 07-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "CInteractiveMode.h"
#include "CViewWindow.h"

#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

CInteractiveMode::CInteractiveMode()
{

}

CInteractiveMode::~CInteractiveMode()
{

}

bool CInteractiveMode::Init()
{
    std::string shape;
    std::string colour;

    std::cout << "Choose the object:" << std::endl;
    std::cin >> shape ;

    if(CheckShapeInput(shape))
    {
        std::cout << "Choose the color:" << std::endl;
        std::cin >> colour ;  

        if(CheckColourInput(colour))
        {
            return true;
        }
    }

    return false;
}

void CInteractiveMode::Execute()
{
    //CViewWindow sourceWindow("src window", cv::imread( cv::samples::findFile("../../img/colored_blocks.jpg")));
    CViewWindow webcamWindow("webcam window");
}

bool CInteractiveMode::CheckShapeInput(const std::string& rShape)
{
    for(const auto &v  : configuredShapes)
    {
        if(v.second == rShape)
        {
            m_shape = v.first;
            std::cout << "Object = " << rShape << std::endl;
            return true;
        }
    }

    std::cout << "Invalid object given." << std::endl;
    return false;
}

bool CInteractiveMode::CheckColourInput(const std::string& rColour)
{
    for(const auto &v  : configuredColours)
    {
        if(v.second == rColour)
        {
            m_colour = v.first;
            std::cout << "Colour = " << rColour << std::endl;
            return true;
        }
    }

    std::cout << "Invalid color given." << std::endl;
    return false;
}