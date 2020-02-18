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