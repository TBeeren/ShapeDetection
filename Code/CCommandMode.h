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

//Forward Declarationsa
class CParser;

class CCommandMode : public CMode
{
public:
    CCommandMode(char* argv[]);
    virtual ~CCommandMode();

    void Init();
    void HaltThread();
    void StartTest();
    void StopTest();
    void Execute();
    bool IsTestRunning() const;

private:
    char** m_bashArguments;
    bool m_running;
    std::thread m_thread;
    std::shared_ptr<CParser> m_spParser;
};

#endif /*CCOMMANDMODE_H*/