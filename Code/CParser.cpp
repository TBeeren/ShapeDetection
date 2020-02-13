#include "CParser.h"

#include "ESelections.h"
#include <iostream>
#include <fstream>

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
void CParser::ParseFile(std::ifstream& rFilename)
{
    do
    {
        std::string line;
        std::getline(rFilename, line); 

        if(line[0] != '#' && !line.empty())
        {
            int whitespacePos = 0;
            std::string colour = "";
            std::string shape = "";

            for(int i = 0; i < line.size(); ++i)
            {
                if(line[i] == ' ')
                {
                    whitespacePos = i;
                    break;
                }
            }

            for(int i = 0; i < whitespacePos; ++i)
            {
                shape = shape + line[i];
            }

            for(int i = whitespacePos + 1; i < line.size(); ++i)
            {
                colour = colour + line[i];
            }

            IsConfiguredAsShape(shape);
            IsConfiguredAsColour(colour);
        }

    } while(!rFilename.eof());
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