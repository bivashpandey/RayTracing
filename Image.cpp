/**
 *
 * This header file  defines the methods for Image class
 * @author: Professor
 *
 */

#include "Image.hpp"
cv::Vec3b& Image::operator()(int row, int col)
{
    assert(row >= 0 && row < rows);
    assert(col >= 0 && col < cols);
    return image.at<cv::Vec3b>(cv::Point(col, row));
}
void Image::display() {
    // Display the image
    cv::imshow("Ray Tracing", image);
    cv::waitKey(0);
}

void Image::save(const std::string& filename) {
    // Save the image
    cv::imwrite(filename, image);
}
