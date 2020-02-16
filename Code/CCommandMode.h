/**
 * @file CColour.h
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief The CCommandMode Inherits from CMode, and is responsible for parsing batch 
 *        commands from an user. 
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

    /**
    * @brief Initializes variables for the specified CMode.
    * 
    * @return true, If the initialisation flow worked correctly.
    * @return false, if there's a mistake during the init process.
    */
    bool Init() override;

    /**
     * @brief Execute the program and fixes thread boundries if needed.
     * 
     */
    void Execute() override;
    
    /**
     * @brief Start the execution process of the batch file. This functionality 
     * provides the option to make it preemptive if needed.
     * 
     */
    void StartProcess();
    
    /**
     * @brief Stops the execution process of the batch file. This functionality 
     * provides the option to make it preemptive if needed.
     * 
     */
    void StopProcess();

    /**
     * @brief Checks if the process is running.
     * 
     * @return true, if the test is running.
     * @return false, if the test is running.
     */
    bool IsProcessRunning() const;

private:
    std::ifstream m_InputFile;
    char** m_bashArguments;
    bool m_running;
    std::shared_ptr<CParser> m_spParser;
};

#endif /*CCOMMANDMODE_H*/