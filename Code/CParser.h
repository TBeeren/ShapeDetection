/**
 * @file CColour.h
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief The CParser class is responsible for reading and parsing commands from the given inputfile. 
 * @version 0.1
 * @date 07-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CTRACKBAR_H
#define CTRACKBAR_H

#include "ESelections.h"

#include <memory>
#include <queue>
#include <utility>

class CCommandMode;
class CParser
{
public:
    CParser(eShapes rSelectedShape, eColours rSelectedColour, CCommandMode* pCommandMode);
    ~CParser();

    /**
     * @brief Parses all commands from an input file and translates
     *        it to an action in the system.
     * 
     * @param rFilename: The input file given by the user as input.
     */
    void ParseFile(std::ifstream& rFilename);

private:
    eColours StringToColour(const std::string& colourString);
    eShapes StringToShape(const std::string& shapeString);

    CCommandMode* m_pCommandMode;

    eShapes& m_rSelectedShape;
    eColours& m_rSelectedColour;

    std::string m_firstArgument;
    std::string m_secondArgument;
};

#endif /*CTRACKBAR_H*/