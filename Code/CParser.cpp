/**
 * @file CParser.cpp
 * @author Tim Beeren (T.Beeren1@student.han.nl)
 * @brief The CParser class is responsible for reading and parsing commands from the given inputfile. 
 * @version 0.1
 * @date 16-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

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

bool CParser::IsConfiguredAsColour(std::string cmdArgument)
{
    for(const std::pair<const eColours, std::__cxx11::string>& rColour : configuredColours)
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
    for(const std::pair<const eShapes, std::__cxx11::string>& rShape : configuredShapes)
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