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
    //Set theze values to the default
    shape = END_OF_SHAPES;
    color = END_OF_COLOURS;

    //Store the incomming values temporary
    std::string aShape;
    std::string aColor;

    std::cout << "Choose the object:" << std::endl;
    std::cin >> aShape ;

    for(auto v  : configuredShapes)
    {
        if(v.second == aShape)
        {
            shape = v.first;
            std::cout << "Object = " << aShape << std::endl;
        }
    }

    std::cout << "Choose the color:" << std::endl;
    std::cin >> aColor ;  

    for(auto v  : configuredColours)
    {
        if(v.second == aColor)
        {
            color = v.first;
            std::cout << "Color = " << aColor << std::endl;
        }
    }  

    return (shape != END_OF_SHAPES && color != END_OF_COLOURS)? true :  false;
}

void CInteractiveMode::Execute()
{
    //CViewWindow sourceWindow("src window", cv::imread( cv::samples::findFile("../../img/colored_blocks.jpg")));
    CViewWindow webcamWindow("webcam window");
}