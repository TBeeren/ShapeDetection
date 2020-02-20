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
#include "CFeatureExtraction.h"
#include "CColour.h"

#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

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

    if(IsConfiguredAsShape(shape))
    {
        std::cout << "Choose the color:" << std::endl;
        std::cin >> colour ;  

        if(IsConfiguredAsColour(colour))
        {
            std::cout << "Detecting shape..." << std::endl;
            return true;
        }
    }

    return false;
}

void CInteractiveMode::Execute()
{
    std::shared_ptr<CFeatureExtraction> featureExtraction = std::make_shared<CFeatureExtraction>();
    featureExtraction->Init(true);
    CViewWindow webcamWindow("webcam window");
    cv::Mat source;
    std::vector<std::vector<cv::Point>> extractedCorners;
    for(;;)
    {
        webcamWindow.UpdateSource();
        source = webcamWindow.GetSource();
        extractedCorners = featureExtraction->GetCornerPoints(source, m_selectedColour);

        for(std::vector<cv::Point>& shape : extractedCorners)
        {
            DrawShape(source, shape);
        }

        if( cv::waitKey(10) == 110 )
        {
            Init(); // stop capturing by pressing n and enter a new shape and colour
        }
        if( cv::waitKey(30) == 27 )
        {
            break; // stop capturing by pressing ESC 
        }
    }
}

void CInteractiveMode::DrawShape(cv::Mat source, std::vector<cv::Point>& rPoints)
{
    cv::Point prevPoint = rPoints[0];
    std::cout << "Colour: " << m_selectedColour << std::endl;
    CColour colour(m_selectedColour);

    for(int i = 1; i < rPoints.size(); ++i)
    {
        cv::line(source, prevPoint, rPoints[i], colour.getRgbColour(), 2);
        prevPoint = rPoints[i];
    }
    cv::line(source, rPoints[rPoints.size()-1] ,rPoints[0], colour.getRgbColour(), 2);

    cv::imshow("webcam window", source);
}