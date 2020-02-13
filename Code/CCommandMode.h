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

#ifndef CCOMMANDMODE_H
#define CCOMMANDMODE_H

#include "CMode.h"

#include <fstream>
#include <cassert>

//Forward Declarationsa
class CParser;

class CCommandMode : public CMode
{
public:
    CCommandMode(char* argv[]);
    virtual ~CCommandMode();

    bool Init() override;
    void Execute() override;
    
    void StartTest();
    void StopTest();
    bool IsTestRunning() const;

private:
    std::ifstream m_InputFile;
    char** m_bashArguments;
    bool m_running;
    std::shared_ptr<CParser> m_spParser;
};

#endif /*CCOMMANDMODE_H*/