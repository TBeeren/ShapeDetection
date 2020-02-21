/**
 * @file CFeatureDetection.h
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief This class is responsible for processing detecting data from the, by the CFeatureExtraction extracted, data. It provides functions to filter on a shape and 
 * find middlepoints aswell as surface areas.
 * @version 0.1
 * @date 07-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "CFeatureDetection.h"

#include <iostream>
#include "Shapes/CTriangle.h"
#include "Shapes/CSquare.h"
#include "Shapes/CCircle.h"
#include "Shapes/CHalfCircle.h"

void CFeatureDetection::SetShape(eShapes shape)
{
    switch(shape)
    {
        case eShapes::TRIANGLE:
        {
            m_spShape = std::make_shared<CTriangle>();
            break;
        }
        case eShapes::SQUARE:
        {
            m_spShape = std::make_shared<CSquare>();
            break;
        }
        case eShapes::CIRCLE:
        {
            m_spShape = std::make_shared<CCircle>();
            break;
        }
        case eShapes::HALF_CIRCLE:
        {
            m_spShape = std::make_shared<CHalfCircle>();
            break;
        }
        default:
        {
            std::cout<< "Invalid Shape in CFeatureDetection::SetShape" <<std::endl;
            break;
        }
    }
}

std::vector<std::vector<cv::Point>> CFeatureDetection::ShapeFilter(const std::vector<std::vector<cv::Point>>& rAllContours)
{
    std::vector<std::vector<cv::Point>> returnVector;
    for(const std::vector<cv::Point>& shape: rAllContours)
    {
        if(m_spShape->Process(shape))
        {
            returnVector.push_back(shape);
        }
    }
    return returnVector;
}

cv::Point CFeatureDetection::FindCenter(const std::vector<cv::Point>& rContour)
{
    cv::Rect boundingRect = cv::boundingRect(rContour);
    uint64_t centerX = boundingRect.x + boundingRect.width/2; 
    uint64_t centerY = boundingRect.y + boundingRect.height/2;
    return cv::Point(centerX,centerY);
}

uint64_t CFeatureDetection::CalcSurfaceArea(const std::vector<cv::Point>& rContour)
{
    return cv::contourArea(rContour);
}