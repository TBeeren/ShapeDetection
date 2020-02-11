/**
 * @file CCommandMode.cpp
 * @author Tim Beeren (T.Beeren1@student.han.nl)
 * @brief 
 * @version 0.1
 * @date 11-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "CCommandMode.h"

#include "CParser.h"
#include <thread> 

CCommandMode::CCommandMode(char** argv)
: m_bashArguments(argv)
, m_running(false)
, m_spParser(std::make_unique<CParser>())
{
}

CCommandMode::~CCommandMode()
{
   HaltThread(); 
}

void CCommandMode::Init()
{
  m_thread = std::thread(StartTest);
}

void CCommandMode::HaltThread()
{
  m_thread.join();
}

void CCommandMode::StartTest()
{
  m_running = true;
}

void CCommandMode::StopTest()
{
  m_running = false;
}

void CCommandMode::Execute()
{
    if(m_running)
    {
        m_spParser->ParseCommandLineArguments(m_bashArguments);
    }
    else
    {

    }
    
}

bool CCommandMode::IsTestRunning() const
{
    return m_running;
}