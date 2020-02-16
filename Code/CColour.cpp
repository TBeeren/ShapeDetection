#include "CColour.h"

namespace
{
    constexpr const uint8_t RED_UPPER_HUE_LIMIT = 175;
    constexpr const uint8_t BLUE_UPPER_HUE_LIMIT = 30;
    constexpr const uint8_t GREEN_UPPER_HUE_LIMIT = 80;
    constexpr const uint8_t YELLOW_UPPER_HUE_LIMIT = 100;
    constexpr const uint8_t WHITE_UPPER_HUE_LIMIT = 118;

    constexpr const uint8_t RED_LOWER_HUE_LIMIT = 115;
    constexpr const uint8_t BLUE_LOWER_HUE_LIMIT = 0;
    constexpr const uint8_t GREEN_LOWER_HUE_LIMIT = 30;
    constexpr const uint8_t YELLOW_LOWER_HUE_LIMIT = 60;
    constexpr const uint8_t WHITE_LOWER_HUE_LIMIT = 103;

    constexpr const uint8_t RED_UPPER_SATURATION_LIMIT = 255;
    constexpr const uint8_t BLUE_UPPER_SATURATION_LIMIT = 255;
    constexpr const uint8_t GREEN_UPPER_SATURATION_LIMIT = 255;
    constexpr const uint8_t YELLOW_UPPER_SATURATION_LIMIT = 255;
    constexpr const uint8_t WHITE_UPPER_SATURATION_LIMIT = 255;

    constexpr const uint8_t RED_LOWER_SATURATION_LIMIT = 100;
    constexpr const uint8_t BLUE_LOWER_SATURATION_LIMIT = 70;
    constexpr const uint8_t GREEN_LOWER_SATURATION_LIMIT = 70;
    constexpr const uint8_t YELLOW_LOWER_SATURATION_LIMIT = 100;
    constexpr const uint8_t WHITE_LOWER_SATURATION_LIMIT = 100;

    constexpr const uint8_t RED_UPPER_VALUE_LIMIT = 255;
    constexpr const uint8_t BLUE_UPPER_VALUE_LIMIT = 255;
    constexpr const uint8_t GREEN_UPPER_VALUE_LIMIT = 255;
    constexpr const uint8_t YELLOW_UPPER_VALUE_LIMIT = 255;
    constexpr const uint8_t WHITE_UPPER_VALUE_LIMIT = 255;

    constexpr const uint8_t RED_LOWER_VALUE_LIMIT = 70;
    constexpr const uint8_t BLUE_LOWER_VALUE_LIMIT = 50;
    constexpr const uint8_t GREEN_LOWER_VALUE_LIMIT = 50;
    constexpr const uint8_t YELLOW_LOWER_VALUE_LIMIT = 50;
    constexpr const uint8_t WHITE_LOWER_VALUE_LIMIT = 109;
} // namespace

CColour::CColour(eColours colour)
    : m_colour(colour)
{
    switch (colour)
    {
    case eColours::RED:
    {
        m_lowerLimit = cv::Scalar(RED_LOWER_HUE_LIMIT, RED_LOWER_SATURATION_LIMIT, RED_LOWER_VALUE_LIMIT);
        m_upperLimit = cv::Scalar(RED_UPPER_HUE_LIMIT, RED_UPPER_SATURATION_LIMIT, RED_UPPER_VALUE_LIMIT);
        break;
    }
    case eColours::BLUE:
    {
        m_lowerLimit = cv::Scalar(BLUE_LOWER_HUE_LIMIT, BLUE_LOWER_SATURATION_LIMIT, BLUE_LOWER_VALUE_LIMIT);
        m_upperLimit = cv::Scalar(BLUE_UPPER_HUE_LIMIT, BLUE_UPPER_SATURATION_LIMIT, BLUE_UPPER_VALUE_LIMIT);
        break;
    }
    case eColours::GREEN:
    {
        m_lowerLimit = cv::Scalar(GREEN_LOWER_HUE_LIMIT, GREEN_LOWER_SATURATION_LIMIT, GREEN_LOWER_VALUE_LIMIT);
        m_upperLimit = cv::Scalar(GREEN_UPPER_HUE_LIMIT, GREEN_UPPER_SATURATION_LIMIT, GREEN_UPPER_VALUE_LIMIT);
        break;
    }
    case eColours::YELLOW:
    {
        m_lowerLimit = cv::Scalar(YELLOW_LOWER_HUE_LIMIT, YELLOW_LOWER_SATURATION_LIMIT, YELLOW_LOWER_VALUE_LIMIT);
        m_upperLimit = cv::Scalar(YELLOW_UPPER_HUE_LIMIT, YELLOW_UPPER_SATURATION_LIMIT, YELLOW_UPPER_VALUE_LIMIT);
        break;
    }
    case eColours::WHITE:
    {
        m_lowerLimit = cv::Scalar(WHITE_LOWER_HUE_LIMIT, WHITE_LOWER_SATURATION_LIMIT, WHITE_LOWER_VALUE_LIMIT);
        m_upperLimit = cv::Scalar(WHITE_UPPER_HUE_LIMIT, WHITE_UPPER_SATURATION_LIMIT, WHITE_UPPER_VALUE_LIMIT);
        break;
    }
    default:
    {
        break;
    }
    }
}

CColour::CColour(eColours colour, cv::Scalar lowerRange, cv::Scalar upperRange)
    : m_colour(colour), m_lowerLimit(lowerRange), m_upperLimit(upperRange)
{
}

CColour::~CColour()
{
}

const eColours CColour::GetColour() const
{
    return m_colour;
}

const cv::Scalar& CColour::GetLowerLimit() const
{
    return m_lowerLimit;
}
const cv::Scalar& CColour::GetUpperLimit() const
{
    return m_upperLimit;
}