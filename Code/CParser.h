/**
 * @file CColour.h
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief 
 * @version 0.1
 * @date 07-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CTRACKBAR_H
#define CTRACKBAR_H

#include "ESelections.h"

class CParser
{
public:
    CParser(eShapes& rSelectedShape, eColours& rSelectedColour);
    ~CParser();

    void ParseFile(std::ifstream& rFilename);
    bool ParseStringToEnum(char** argv);

    bool IsConfiguredAsColour(std::string cmdArgument);
    bool IsConfiguredAsShape(std::string cmdArgument);

private:
    eShapes& m_rSelectedShape;
    eColours& m_rSelectedColour;

    std::string m_firstArgument;
    std::string m_secondArgument;

};

#endif /*CTRACKBAR_H*/