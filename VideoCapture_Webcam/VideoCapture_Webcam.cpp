#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    cv::VideoCapture vCap;
    cv::Mat frame;
    const std::string windowName = "Webcam";
    
    vCap.open(0, cv::CAP_ANY);
    if(!vCap.isOpened()) {
        std::cout << "camera not opened\n";
        return -1;
    }
    
    cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE);
    
    while(true) {
        vCap.read(frame);
        
        if(frame.empty()) {
            std::cout << "frame empty\n";
            continue;
        }
        
        cv::imshow(windowName, frame);
        
        if(cv::waitKey(5) >= 0) {
            break;
        }
    }
    
    cv::destroyAllWindows();
    vCap.release();
    
    return 0;
}
