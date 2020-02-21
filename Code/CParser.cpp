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

#include "CCommandMode.h"
#include "ESelections.h"
#include <iostream>
#include <fstream>
#include <memory>

CParser::CParser(eShapes rSelectedShape, eColours rSelectedColour, const std::shared_ptr<CCommandMode>& spCommandMode)
: m_rSelectedShape(rSelectedShape)
, m_rSelectedColour(rSelectedColour)
, m_wpCommandMode(spCommandMode)
{
}

void CParser::ParseFile(std::ifstream& rFilename)
{
    if (rFilename.is_open())
    {
        do
        {
            std::string line;
            std::getline(rFilename, line);

            if (line[0] != '#' && !line.empty())
            {
                uint64_t whitespacePos = 0;
                std::string colour = "";
                std::string shape = "";

                for (uint64_t i = 0; i < line.size(); ++i)
                {
                    if (line[i] == ' ')
                    {
                        whitespacePos = i;
                        break;
                    }
                }

                for (uint64_t i = 0; i < whitespacePos; ++i)
                {
                    shape = shape + line[i];
                }

                for (uint64_t i = whitespacePos + 1; i < line.size(); ++i)
                {
                    colour = colour + line[i];
                }
                if(std::shared_ptr<CCommandMode> spCommandMode = m_wpCommandMode.lock())
                {
                    spCommandMode->AddToQueue(shape, colour);
                }
            }

        } while (!rFilename.eof());
    }
    else
    {
        std::cout << "[WARNING]-> unable to open the inputfile." << std::endl;
    }
}