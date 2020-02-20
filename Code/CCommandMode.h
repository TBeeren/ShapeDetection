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
#include "opencv2/opencv.hpp"

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
     * @brief Prints the output values to a file or terminal (or both).
     * 
     * @param surfaceArea, Calculated surface area from the detected shape
     * @param rCenterPoint, Calculated centerpoint from the detected shape
     */
    void ProcessOutput(uint64_t surfaceArea, const cv::Point& centerPoint, clock_t duration);
    
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

    /**
     * @brief Add task to the queue, to schedule a new task. The used algorithm is FIFO.
     * 
     * @param shape, string of the shape to detect.
     * @param colour, string of the colour to detect.
     */
    void AddToQueue(std::string shape, std::string colour);

    /**
     * @brief Logger with only a description string. The logger will print this line to an outputfile. 
     * 
     * @param rDescription, String description, provided by the user..
     */
    void Log(const std::string& rDescription);

    /**
     * @brief Logger with a description and perspects. The logger will print this line to an outputfile. 
     * 
     * @param rDescription, String description, provided by the user.
     * @param rPerspects, Perspects from the system, required from stimuli. 
     */
    void Log(const std::string& rDescription, const std::string& rPerspects);

    /**
     * @brief Set the File Log Enabled object
     * 
     * @param state, The user is able to enable or disable the logging to an outputfile. 
     */
    void SetFileLogEnabled(bool state);


private:
    std::queue<std::pair<eShapes, eColours>> m_extractionQueue;
    bool m_fileLogEnabled;
    std::ifstream m_inputFile;
    std::ofstream m_outputFile;
    char** m_bashArguments;
    bool m_running;
    std::shared_ptr<CParser> m_spParser;
};

#endif /*CCOMMANDMODE_H*/