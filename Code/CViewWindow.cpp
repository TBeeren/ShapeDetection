#include "CViewWindow.h"

//CViewWindow::CViewWindow(std::string windowName,std::shared_ptr<eShapes> spShape, std::shared_ptr<eColours> spColour )

CViewWindow::CViewWindow(std::string windowName, cv::Mat src) 
    :m_windowName(windowName), m_src(src)
{
    cv::namedWindow(m_windowName, cv::WINDOW_NORMAL);
    cv::imshow(m_windowName, m_src);
}

CViewWindow::CViewWindow(std::string windowName) 
    :m_windowName(windowName)
{
    cv::VideoCapture cap;
    if(!cap.open(0))
    {
        std::cout << "Unable to open webcam!!" << std::endl;
    }

    cv::Mat frame;

    for(;;)
    {
        cap >> frame;

        if( frame.empty() ) 
        {
            break; // end of video stream
        }

        imshow(m_windowName, frame);

        if( cv::waitKey(10) == 27 )
        {
            break; // stop capturing by pressing ESC 
        }
    }
    cv::destroyWindow(m_windowName);
}

CViewWindow::~CViewWindow()
{
}