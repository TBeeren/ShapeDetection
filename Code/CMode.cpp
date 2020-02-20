#include "CMode.h" 

CMode::CMode(/* args */)
{
}

CMode::~CMode()
{
}

bool CMode::IsConfiguredAsColour(const std::string& cmdArgument)
{
    for (const std::pair<const eColours, std::__cxx11::string>& rColour : configuredColours)
    {
        if (rColour.second == cmdArgument)
        {
            m_selectedColour = rColour.first;
            return true;
        }
    }

    std::cout << "[WARNING]-> Please provide a colour as configurated." << std::endl;
    return false;
}

bool CMode::IsConfiguredAsShape(const std::string& cmdArgument)
{
    for (const std::pair<const eShapes, std::__cxx11::string> &rShape : configuredShapes)
    {
        if (rShape.second == cmdArgument)
        {
            m_selectedShape = rShape.first;
            return true;
        }
    }

    std::cout << "Please provide a shape as configurated:" << std::endl;
    return false;
}

eColours CMode::StringToColour(const std::string& colourString)
{
    for (const std::pair<const eColours, std::__cxx11::string>& rColour : configuredColours)
    {
        if (rColour.second == colourString)
        {
            return rColour.first;
        }
    }
}

eShapes CMode::StringToShape(const std::string& shapeString)
{
    for (const std::pair<const eShapes, std::__cxx11::string>& rShape : configuredShapes)
    {
        if (rShape.second == shapeString)
        {
            return rShape.first;
        }
    }
}

cv::Scalar CMode::EnumToColour(eColours colour)
{
    uint16_t r, g, b;

    switch(colour){
        case eColours::BLACK:
        r = 0;
        g = 0;
        b = 0;
        break;

        case eColours::BLUE:
        r = 0;
        g = 0;
        b = 255;
        break;

        case eColours::GREEN:
        r = 0;
        g = 255;
        b = 0;
        break;

        case eColours::RED:
        r = 255;
        g = 0;
        b = 0;
        break;

        case eColours::WHITE:
        r = 255;
        g = 255;
        b = 255;
        break;

        case eColours::YELLOW:
        r = 255;
        g = 255;
        b = 0;
        break;

        default:
        r = 0;
        g = 255;
        b = 255;
        break;
    }
    return cv::Scalar(b, g, r);
}