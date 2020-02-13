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

#include "CFeatureExtraction.h"

#include "opencv2/opencv.hpp"

#include <iostream>
int main(int argc, char const *argv[])
{
    std::cout << "Program started" << std::endl;
    cv::namedWindow("mainputwindow", cv::WINDOW_NORMAL);
    cv::Mat source, output, bi;
    CFeatureExtraction extr;
    extr.init(false);
    cv::VideoCapture cap;
    if (!cap.open(0))
    {
        return 0;
    }
    cap >> source;
    if (source.empty())
    {
        return -1;
    }
    cap >> source;
    for (;;)
    {
        //cap >> source;
        source = cv::imread("/home/evren/Downloads/yellow_circle.jpg");
        output = extr.extractColours(source, YELLOW);
        output = extr.extractEdges(output);
        extr.extractContours(output);

        imshow("mainputwindow", output);
        if (cv::waitKey(30) == 27) //wait till esc press
        {
            break;
        }
    }
    std::cout << "Program ended" << std::endl;
    return 0;
}
