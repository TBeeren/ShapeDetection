#include "CParser.h"

#include "ESelections.h"
#include <iostream>

CParser::CParser(eShapes& rSelectedShape, eColours& rSelectedColour)
: m_rSelectedShape(rSelectedShape)
, m_rSelectedColour(rSelectedColour)
{
}

CParser::~CParser()
{
}

// [Shape][Whitespace][Colour]
// #Comments comments comments (<- Filter this out)
void CParser::ParseFile(std::string filename ,char** argv)
{
    ParseStringToEnum(argv);
}

bool CParser::ParseStringToEnum(char** argv)
{
    if(!IsConfiguredAsShape(argv[1]) | !IsConfiguredAsColour(argv[2]))
    {      
        return false;
    }

    return true;
}

bool CParser::IsConfiguredAsColour(std::string cmdArgument)
{
    for(const auto& rColour : configuredColours)
    {
        if(rColour.second == cmdArgument)
        {
            m_rSelectedColour = rColour.first;
            return true;
        }
    }

    std::cout << "Please provide a colour as configurated:" << std::endl;
    return false;
}

bool CParser::IsConfiguredAsShape(std::string cmdArgument)
{
    for(const auto& rShape : configuredShapes)
    {
        if(rShape.second == cmdArgument)
        {
            m_rSelectedShape = rShape.first;
            return true;
        }
    }

    std::cout << "Please provide a shape as configurated:" << std::endl;
    return false;
}