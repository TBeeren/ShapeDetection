/**
 * @file CCommandMode.h
 * @author Tim Beeren (T.Beeren1@student.han.nl)
 * @brief The CCommandMode Inherits from CMode, and is responsible for parsing batch 
 *        commands, executing feature extraction, feature detection and printing output. 
 * @version 0.1
 * @date 11-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CCOMMANDMODE_H
#define CCOMMANDMODE_H

#include "CMode.h"

#include <fstream>
#include <cassert>
#include <queue>

//Forward Declarations
class CParser;

class CCommandMode : public CMode
{
public:
    CCommandMode(char** argv);
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

    void AddToQueue(std::string shape, std::string colour);

private:
    std::queue<std::pair<eShapes, eColours>> m_extractionQueue;
    std::ifstream m_inputFile;
    char** m_bashArguments;
    bool m_running;
    std::shared_ptr<CParser> m_spParser;
};

#endif /*CCOMMANDMODE_H*/