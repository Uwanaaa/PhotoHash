#include <napi.h>
#include <opencv2/opencv.hpp>
#include <string>

using namespace Napi;

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

Value HashImage(const CallbackInfo &info)
{
    Env node_env = info.Env();

    // Ensures that image is provided
    if (info.Length() < 1 || !info[0].IsString())
    {
        throw TypeError::New(node_env, "Image path expected"); // Outputs error to node
    }

    std::string image_path = info[0].As<String>().Utf8Value();

    cv::Mat image = cv::imread(image_path);

    // Hashing provided image
    try
    {
        std::string hash = get_dhash(image);
        return String::New(node_env, hash);
    }
    catch (const std::exception &e)
    {
        throw Error::New(node_env, e.what());
    }
}

// The wrapper
Object Init(Env env, Object exports)
{
    exports.Set("hashImage", Function::New(env, HashImage));
    return exports;
}

NODE_API_MODULE(photo_hasher, Init)