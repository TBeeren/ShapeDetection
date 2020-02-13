#include "CFeatureExtraction.h"
#include "CCalibration.h"

#include <iostream>
#include "stdint.h"

CFeatureExtraction::CFeatureExtraction()
    : m_spCalibration(std::make_shared<CCalibration>())
{
}

CFeatureExtraction::~CFeatureExtraction()
{
}

bool CFeatureExtraction::init(bool userCalibration)
{
    m_spCalibration->initColours(userCalibration);
}

cv::Mat CFeatureExtraction::extractColours(cv::Mat &input, eColours colour)
{
    cv::Mat hsv, output, bi;
    m_lookupColour = m_spCalibration->GetColour(colour);
    for (int i = 0; i < 3; ++i)
    {
        cv::bilateralFilter(input, bi, 9, 50, 120);
    }
    cv::cvtColor(input, hsv, cv::COLOR_RGB2HSV);
    cv::inRange(hsv, m_lookupColour->GetLowerLimit(), m_lookupColour->GetUpperLimit(), output);
    return output;
}

cv::Mat CFeatureExtraction::extractEdges(cv::Mat &input)
{
    cv::Mat output;
    cv::Canny(input, output, 0, 50, 5);
    return output;
}
std::vector<std::vector<cv::Point>> CFeatureExtraction::extractContours(cv::Mat &input)
{
    std::vector<std::vector<cv::Point>> allContours;  //stores all points for contours
    std::vector<std::vector<cv::Point>> contourEdges; //stores edge points for contours
    std::vector<cv::Point> approx;                    //temporarily stores contour edge points
    cv::findContours(input, allContours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    for (int i = 0; i < allContours.size(); ++i)
    {
        if (std::fabs(cv::contourArea(allContours[i])) > 100)
        {
            cv::approxPolyDP(cv::Mat(allContours[i]), approx, cv::arcLength(cv::Mat(allContours[i]), true) * 0.02, true);
            contourEdges.push_back(approx);
            for (int j = 0; j < approx.size(); ++j)
            {
                cv::circle(input, approx.at(j), 20, cv::Scalar(255, 0, 0), 5);
            }
        }
    }
    return contourEdges;
}
