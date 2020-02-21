#include "CCalibration.h"
#include "ESelections.h"

namespace
{
    constexpr const uint8_t MAXIMUM_HUE = 179;
    constexpr const uint8_t MAXIMUM_SATURATION = 255;
    constexpr const uint8_t MAXIMUM_VALUE = 255;
} // namespace

CCalibration::CCalibration()
{
}

CCalibration::~CCalibration()
{
}

bool CCalibration::InitColours(bool userCalibration)
{
    if (userCalibration)
    {
        cv::Mat source, hsv, mask;
        cv::VideoCapture cap;
        if (!cap.open(2))
        {
            return false;
        }
        cap >> source;
        if (source.empty())
        {
            return false;
        }

        int upperHue = 0, lowerHue = 0, upperSaturation = 0, lowerSaturation = 0, upperValue = 0, lowerValue = 0;
        cv::namedWindow("Initialise Values", cv::WINDOW_NORMAL);
        cv::createTrackbar("Upper Hue", "Initialise Values", &upperHue, MAXIMUM_HUE);
        cv::createTrackbar("Lower Hue", "Initialise Values", &lowerHue, MAXIMUM_HUE);
        cv::createTrackbar("Upper Sat", "Initialise Values", &upperSaturation, MAXIMUM_SATURATION);
        cv::createTrackbar("Lower Sat", "Initialise Values", &lowerSaturation, MAXIMUM_SATURATION);
        cv::createTrackbar("Upper Value", "Initialise Values", &upperValue, MAXIMUM_VALUE);
        cv::createTrackbar("Lower Value", "Initialise Values", &lowerValue, MAXIMUM_VALUE);
        for (int i = 0; i < eColours::END_OF_COLOURS; ++i)
        {
            std::cout << "Setting ranges for: " << configuredColours.at(eColours(i)) << std::endl;
            for (;;)
            {
                cap >> source;
                cv::blur(source, source, cv::Size(3, 3));
                cvtColor(source, hsv, cv::COLOR_RGB2HSV);
                inRange(hsv, cv::Scalar(lowerHue, lowerSaturation, lowerValue), cv::Scalar(upperHue, upperSaturation, upperValue), mask);
                imshow("Initialise Stream", mask);

                if (cv::waitKey(30) == 27) //wait till esc press
                {
                    std::cout << "lowerHue: " << lowerHue << std::endl;
                    std::cout << "lowerSaturation: " << lowerSaturation << std::endl;
                    std::cout << "lowerValue: " << lowerValue << std::endl;
                    std::cout << "upperHue: " << upperHue << std::endl;
                    std::cout << "upperSaturation: " << upperSaturation << std::endl;
                    std::cout << "upperValue: " << upperValue << std::endl;
                    m_colourList.emplace_back(std::make_shared<CColour>(
                        eColours(i), cv::Scalar(lowerHue, lowerSaturation, lowerValue), cv::Scalar(upperHue, upperSaturation, upperValue)));
                    break;
                }
            }
        }
        cv::destroyWindow("Initialise Stream");
        cv::destroyWindow("Initialise Values");
        cap.release();
    }
    else
    {
        for (int i = 0; i < eColours::END_OF_COLOURS; ++i)
        {
            m_colourList.emplace_back(std::make_shared<CColour>(
                eColours(i)));
        }
    }
    return true;
}

std::shared_ptr<CColour> CCalibration::GetColour(eColours colourValue)
{
    for (std::shared_ptr<CColour> colour : m_colourList)
    {
        if (colour->GetColour() == colourValue)
        {
            return colour;
        }
    }
    return m_colourList.at(0);
}