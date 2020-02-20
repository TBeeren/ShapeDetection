#include "CMode.h" 

CMode::CMode()
: m_selectedColour(END_OF_COLOURS)
, m_selectedShape(END_OF_SHAPES)
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

const std::string& CMode::ColourToString(eColours eColour)
{
    for (const std::pair<const eColours, std::__cxx11::string>& rColours : configuredColours)
    {
        if (rColours.first == eColour)
        {
            return rColours.second;
        }
    }
}

const std::string& CMode::ShapeToString(eShapes eShape)
{
    for (const std::pair<const eShapes, std::__cxx11::string>& rShape : configuredShapes)
    {
        if (rShape.first == eShape)
        {
            return rShape.second;
        }
    }
}