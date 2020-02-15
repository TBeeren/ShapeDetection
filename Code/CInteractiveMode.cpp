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

    if(checkShapeInput(shape))
    {
        std::cout << "Choose the color:" << std::endl;
        std::cin >> colour ;  

        if(checkColourInput(colour))
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

bool CInteractiveMode::checkShapeInput(std::string aShape)
{
    for(const auto &v  : configuredShapes)
    {
        if(v.second == aShape)
        {
            m_shape = v.first;
            std::cout << "Object = " << aShape << std::endl;
            return true;
        }
    }

    std::cout << "Invalid object given." << std::endl;
    return false;
}

bool CInteractiveMode::checkColourInput(std::string aColour)
{
    for(const auto &v  : configuredColours)
    {
        if(v.second == aColour)
        {
            m_colour = v.first;
            std::cout << "Colour = " << aColour << std::endl;
            return true;
        }
    }

    std::cout << "Invalid color given." << std::endl;
    return false;
}