#include <napi.h>
#include <opencv2/opencv.hpp>
#include <string>

std::string get_dhash(const cv::Mat &image)
{

    /*
    Function get_dhash to hash the image input to get its difference hash value

    Input:
    image

    Output:
    hashed_value - A string of the hashed value
    */

    if (image.empty())
    {
        throw std::invalid_argument("No image provided");
    }

    if (image.channels() != 3)
    {
        throw std::invalid_argument("A 3-channel BGR format is expected");
    }

    // grayscale - to save the image's grayscale format, resized - to save the resized image
    cv::Mat grayscale, resized;

    cv::cvtColor(image, grayscale, cv::COLOR_BGR2GRAY);
    cv::resize(grayscale, resized, cv::Size(9, 8)); // dhash produces a 64 bit hash

    std::string hashed_value;

    for (int row = 0; row < resized.rows; ++row)
    {
        for (int col = 0; col < resized.cols - 1; ++col)
        {
            hashed_value += (resized.at<uchar>(row, col) > resized.at<uchar>(row, col + 1)) ? "1" : "0";
        }
    }

    return hashed_value;
}
