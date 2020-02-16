/**
 * @file CCommandMode.cpp
 * @author Tim Beeren (T.Beeren1@student.han.nl)
 * @brief The CCommandMode Inherits from CMode, and is responsible for parsing batch 
 *        commands from an user. 
 * @version 0.1
 * @date 11-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "CCommandMode.h"

#include "CMode.h"
#include "CParser.h"

//Define an message with the triggered assert.
#define assertm(exp, msg) assert(((void)msg, exp))

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
  m_InputFile.open(m_bashArguments[1]); 

  if(m_InputFile.fail())
  {
    std::cout << "Unable to open given file, please check your path." << std::endl;
  } 

  return m_InputFile.is_open();
}

void CCommandMode::StartProcess()
{
  m_running = true;
}

void CCommandMode::StopProcess()
{
  m_running = false;
}

void CCommandMode::Execute()
{
  if(m_running)
  {
    m_spParser->ParseFile(m_InputFile);
  }
  else
  {
    std::cout << "[Warning] -> Test is not running. Please start the test first" << std::endl;
  }
}

bool CCommandMode::IsProcessRunning() const
{
    return m_running;
}