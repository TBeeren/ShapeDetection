#include "CFeatureExtraction.h"
#include "CCalibration.h"

#include <iostream>
#include "stdint.h"

namespace
{
    constexpr const int8_t BILATERFILTER_ITERATIONS = 3;
    constexpr const int8_t BILATERFILTER_KERNEL = 9;
    constexpr const int16_t BILATERFILTER_SIGMA_COLOUR = 50;
    constexpr const int16_t BILATERFILTER_SIGMA_SPACE = 120;

    constexpr const int16_t EDGE_LINKING_THRESHHOLD = 0;
    constexpr const int16_t INITIAL_STRONG_EDGE_THRESHOLD = 50;
    constexpr const int16_t CANNY_APERATURE_SIZE = 5;

    constexpr const int16_t MIN_SHAPE_SIZE = 200;

    constexpr const double EDGE_APPROX_FACTOR = 0.02; //was 0.09
}

CFeatureExtraction::CFeatureExtraction()
    : m_spCalibration(std::make_shared<CCalibration>())
{
}

CFeatureExtraction::~CFeatureExtraction()
{
}

bool CFeatureExtraction::Init(bool userCalibration)
{
    m_spCalibration->InitColours(userCalibration);
}

std::vector<std::vector<cv::Point>> CFeatureExtraction::GetCornerPoints(const cv::Mat& source, eColours colour)
{
    std::vector<std::vector<cv::Point>> returnVector;
    cv::Mat colourMask, edgeMatrix;
    colourMask = ExtractColours(source, colour);
    edgeMatrix = ExtractEdges(colourMask);
    returnVector = ExtractContours(edgeMatrix);
    return returnVector;
}

cv::Mat CFeatureExtraction::ExtractColours(const cv::Mat& rInput, eColours colour)
{
    cv::Mat hsv, output, biFilter;
    m_spLookupColour = m_spCalibration->GetColour(colour);

    for (int i = 0; i < BILATERFILTER_ITERATIONS; ++i)
    {
        cv::bilateralFilter(rInput, biFilter, BILATERFILTER_KERNEL, BILATERFILTER_SIGMA_COLOUR, BILATERFILTER_SIGMA_SPACE);
    }
    cv::cvtColor(rInput, hsv, cv::COLOR_RGB2HSV);
    cv::inRange(hsv, m_spLookupColour->GetLowerLimit(), m_spLookupColour->GetUpperLimit(), output);
    return output;
}

cv::Mat CFeatureExtraction::ExtractEdges(const cv::Mat &input)
{
    cv::Mat output;
    cv::Canny(input, output, EDGE_LINKING_THRESHHOLD, INITIAL_STRONG_EDGE_THRESHOLD, CANNY_APERATURE_SIZE);
    cv::dilate(output, output, cv::Mat());
    cv::erode(output, output, cv::Mat());
    return output;
}
std::vector<std::vector<cv::Point>> CFeatureExtraction::ExtractContours(const cv::Mat &input)
{
    std::vector<std::vector<cv::Point>> allContours;    //stores all contour point
    std::vector<std::vector<cv::Point>> contourCorners; //stores all contour corner points
    std::vector<cv::Point> approx;                      //temporarily stores contour corner points
    cv::findContours(input, allContours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    for (int i = 0; i < allContours.size(); ++i)
    {
        if (std::fabs(cv::contourArea(allContours[i])) > MIN_SHAPE_SIZE)
        {
            cv::approxPolyDP(cv::Mat(allContours[i]), approx, cv::arcLength(cv::Mat(allContours[i]), true) * EDGE_APPROX_FACTOR, true);
            contourCorners.push_back(approx);
        }
    }
    return contourCorners;
}
