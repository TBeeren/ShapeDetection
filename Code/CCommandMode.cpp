/**
 * @file CCommandMode.cpp
 * @author Tim Beeren (T.Beeren1@student.han.nl)
 * @brief The CCommandMode Inherits from CMode, and is responsible for parsing batch 
 *        commands, executing feature extraction, feature detection and printing output. 
 * @version 0.1
 * @date 11-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "CCommandMode.h"

#include "CFeatureExtraction.h"
#include "CFeatureDetection.h"
#include "CMode.h"
#include "CParser.h"
#include <fstream>
#include <ctime>

//Define an message with the triggered assert.
#define assertm(exp, msg) assert(((void)msg, exp))

CCommandMode::CCommandMode(const std::vector<std::string>& bashArguments)
: CMode()
, m_bashArguments(bashArguments)
, m_running(false)
, m_outputFile("output.txt",std::ofstream::binary)
, m_fileLogEnabled(false)
{
}

CCommandMode::~CCommandMode()
{
}

bool CCommandMode::Init()
{
  m_spParser = std::make_unique<CParser>(m_selectedShape, m_selectedColour, shared_from_this());
  m_inputFile.open(m_bashArguments.at(1)); 

  if(m_inputFile.fail())
  {
    std::cout << "Unable to open given file, please check your path." << std::endl;
  } 

  return m_inputFile.is_open();
}

void CCommandMode::Execute()
{
  m_spParser->ParseFile(m_inputFile);
  std::shared_ptr<CFeatureExtraction> featureExtraction = std::make_shared<CFeatureExtraction>();
  std::shared_ptr<CFeatureDetection> featureDetection = std::make_shared<CFeatureDetection>();
  featureExtraction->Init(false);
  std::vector<std::vector<cv::Point>> extractedCorners;
  std::vector<std::vector<cv::Point>> extractedShapeContours;
  cv::Mat source;
  while(!m_extractionQueue.empty())
  {
    source = cv::imread(m_bashArguments.at(2));
    std::string shape = ShapeToString(m_extractionQueue.front().first);
    std::string colour = ColourToString(m_extractionQueue.front().second);
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "Shape: " << shape << std::endl;
    std::cout << "Colour: " << colour << std::endl;
    clock_t startTimer = clock();
    extractedCorners = featureExtraction->GetCornerPoints(source, m_extractionQueue.front().second);
    featureDetection->SetShape(m_extractionQueue.front().first);
    extractedShapeContours = featureDetection->ShapeFilter(extractedCorners);
    clock_t endTimer = clock();
    long duration = endTimer - startTimer;
    if(m_fileLogEnabled)
    {
        Log("----------------------------------------------------------------");
        Log("Shape: ", shape);
        Log("Colour: ", colour);
    }
    if(extractedShapeContours.size())
    {
      for (const std::vector<cv::Point>& shapeContour : extractedShapeContours)
      {
          ProcessOutput(featureDetection->CalcSurfaceArea(shapeContour), featureDetection->FindCenter(shapeContour), duration);
      }
    }
    else
    {
      Log("Shape not detected in image");
      std::cout << "Shape not detected in image" << std::endl;
      std::cout << "Operation time: " << duration << std::endl;
      Log("Operation time", std::to_string(duration));
    }
    m_extractionQueue.pop();
    }
    m_outputFile.close();
}

void CCommandMode::ProcessOutput(uint64_t surfaceArea, const cv::Point& centerPoint, clock_t duration)
{
  std::string pointValues = "(" + std::to_string(centerPoint.x) + "," + std::to_string(centerPoint.y) + ")";
  std::cout << "Shape detected at: " << pointValues << std::endl;
  std::cout << "Surface area: " << surfaceArea << std::endl;
  std::cout << "Operation time: " << duration << std::endl;
  
  if(m_fileLogEnabled)
  {
    Log("Shape detected at", pointValues);
    Log("The Surface area is", std::to_string(surfaceArea));
    Log("Operation time", std::to_string(duration));
  }
}

void CCommandMode::Log(const std::string& rDescription)
{
  std::string message = rDescription + "\n"; 
  char logMessage[message.length()];
  strcpy(logMessage, message.c_str());

  m_outputFile.write(logMessage, sizeof(logMessage));
  m_outputFile.flush();
}

void CCommandMode::Log(const std::string& rDescription, const std::string& rPerspects)
{
  std::string message = rDescription + ": " + rPerspects + "\n"; 
  char logMessage[message.length()];
  strcpy(logMessage, message.c_str());

  m_outputFile.write(logMessage, sizeof(logMessage));
  m_outputFile.flush();
}

void CCommandMode::AddToQueue(const std::string& shape, const std::string& colour)
{
    if(IsConfiguredAsShape(shape) && IsConfiguredAsColour(colour))
    {
        m_extractionQueue.push(std::make_pair<eShapes, eColours>(StringToShape(shape), StringToColour(colour)));
    }
}

void CCommandMode::SetFileLogEnabled(bool state)
{
    m_fileLogEnabled = state;
}