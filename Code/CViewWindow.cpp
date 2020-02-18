#include "CViewWindow.h"

//CViewWindow::CViewWindow(std::string windowName,std::shared_ptr<eShapes> spShape, std::shared_ptr<eColours> spColour )

CViewWindow::CViewWindow(std::string windowName, cv::Mat src) 
    :m_windowName(windowName), m_src(src)
{
    cv::namedWindow(m_windowName, cv::WINDOW_NORMAL);
    cv::imshow(m_windowName, m_src);
}

CViewWindow::CViewWindow(std::string windowName) 
    : m_windowName(windowName)
    , m_spVideoCapture(std::make_shared<cv::VideoCapture>())
{
    if(!m_spVideoCapture->open(0))
    {
        std::cout << "Unable to open webcam!!" << std::endl;
    }
}

CViewWindow::~CViewWindow()
{
    cv::destroyWindow(m_windowName);
    m_spVideoCapture->release();
}

void CViewWindow::UpdateSource(bool updateWindow)
{
    *m_spVideoCapture >> m_src;
    cv::flip(m_src, m_src, 1);
    if(updateWindow)
    {
        imshow(m_windowName, m_src);
    }
}

cv::Mat CViewWindow::GetSource()
{
    return m_src;
}