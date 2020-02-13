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
#include "CMode.h"

#include "CParser.h"

CCommandMode::CCommandMode(char** argv)
: CMode()
, m_bashArguments(argv)
, m_running(false)
, m_spParser(std::make_unique<CParser>(m_SelectedShape, m_SelectedColour))
{
}

CCommandMode::~CCommandMode()
{

}

bool CCommandMode::Init()
{
  return true;
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
    std::cout << "[Warning] -> Test is not running. Please start the test first" << std::endl;
  }
}

bool CCommandMode::IsTestRunning() const
{
    return m_running;
}