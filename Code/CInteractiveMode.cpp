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
#include "CFeatureDetection.h"
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
    std::shared_ptr<CFeatureDetection> featureDetection = std::make_shared<CFeatureDetection>();
    featureExtraction->Init(true);
    featureDetection->SetShape(m_selectedShape);
    CViewWindow webcamWindow("webcam window");
    cv::Mat source;
    std::vector<std::vector<cv::Point>> extractedCorners, filteredContours;

    for(;;)
    {
        webcamWindow.UpdateSource();
        source = webcamWindow.GetSource();
        extractedCorners = featureExtraction->GetCornerPoints(source, m_selectedColour);
        filteredContours = featureDetection->ShapeFilter(extractedCorners);

        for(std::vector<cv::Point>& shape : filteredContours)
        {
            DrawShape(source, shape);
            SetLabel(source, configuredShapes.at(m_selectedShape), featureDetection->FindCenter(shape));
            std::cout<<"###################################################" << std::endl;
            std::cout<<"Shape: " << configuredShapes.at(m_selectedShape) << std::endl;
            std::cout<< "Colour: " << configuredColours.at(m_selectedColour) << std::endl;
            std::cout<< "At: " << featureDetection->FindCenter(shape) << std::endl;
            std::cout<< "Surface area: " << featureDetection->CalcSurfaceArea(shape) << std::endl;
        }

        cv::imshow("webcam window", source);
        if( cv::waitKey(10) == 110 )
        {
            Init(); // stop capturing by pressing n and enter a new shape and colour
            featureDetection->SetShape(m_selectedShape);
        }
        if( cv::waitKey(30) == 27 )
        {
            break; // stop capturing by pressing ESC 
        }
    }
}

void CInteractiveMode::DrawShape(cv::Mat& rSource, std::vector<cv::Point>& rPoints)
{
    cv::Point prevPoint = rPoints[0];
    CColour colour(m_selectedColour);

    for(uint64_t i = 1; i < rPoints.size(); ++i)
    {
        cv::line(rSource, prevPoint, rPoints[i], colour.getRgbColour(), 2);
        prevPoint = rPoints[i];
    }
    cv::line(rSource, rPoints[rPoints.size()-1] ,rPoints[0], colour.getRgbColour(), 2);
}

void CInteractiveMode::SetLabel(cv::Mat& rSource, const std::string& rLabel , const cv::Point& rCentre)
{
    int fontface = cv::FONT_HERSHEY_SIMPLEX;
    double scale = 0.4;
    int thickness = 1;
    int baseline = 0;
 
    cv::Size text = cv::getTextSize(rLabel, fontface, scale, thickness, &baseline);
    cv::Point offsetCentre(rCentre.x - (text.width/2), rCentre.y);
    cv::putText(rSource, rLabel, offsetCentre, fontface, scale, CV_RGB(0,0,0), thickness, 8);
}