/**
 *
 * This files implements the methods defined in the Colour header file
 * Colour as BGR because opencv colour is BGR by default
 *
 * @author: Bivash Pandey
 */

#include "Colour.hpp"

/**
 * This method returns the Red color in BGR
 *
 * @return Red Color
 */
cv::Vec3b Colour::red(){
    return cv::Vec3b(0, 0, 255);
}

/**
 * This method returns the Green color
 *
 * @return Green Color
 */
cv::Vec3b Colour::green(){
    return cv::Vec3b(0, 255,0);
}


/**
 * This method returns the Blue color
 *
 * @return Blue Color
 */
cv::Vec3b Colour::blue(){
    return cv::Vec3b(255, 0, 0);
}

/**
 * This method returns the White color
 *
 * @return White Color
 */
cv::Vec3b Colour::white(){
    return cv::Vec3b(255, 255, 255);
}

/**
 * This method returns the Black color
 *
 * @return Black Color
 */
cv::Vec3b Colour::black(){
    return cv::Vec3b(0, 0, 0);
}

/**
 * This method returns the Yellow color
 *
 * @return Dim Black Color
 */
cv::Vec3b Colour::dimBlack(){
    return cv::Vec3b(20, 20, 20);
}

/**
 * This method returns the Black as ambient color
 *
 * @return Ambient Color
 */
cv::Vec3b Colour::ambient(){
    return cv::Vec3b(0, 0, 0);
}

/**
 * This method returns  diffuse color
 *
 * @return Diffuse Color
 */
cv::Vec3b Colour::diffuse(){
    return cv::Vec3b(0, 255, 100);
}

/**
 * This method bounds the color between 0 to 255
 *
 * @param color value of color in the range[0, 255]
 * @return value between [0, 255] inclusive
 */
int Colour::clamp(int color)
{
    if (color < 0) return 0;
    if (color >= 255) return 255;
    return color;
}

/**
 * This method adds the two colour
 *
 * @param col1  first colour
 * @param col2 second colour
 * @return the addition of two colour
 */
cv::Vec3b Colour::add(cv::Vec3b col1, cv::Vec3b col2){
    return cv::Vec3b(clamp(col1(0) + col2(0)), clamp(col1(1) + col2(1)), clamp(col1(2) + col2(2)));
}

/**
 * This method multiplies a color by a scalar value
 *
 * @param col  The colour
 * @param s scalar value
 * @return the product of each component(BGR) of colour with scalar
 */
cv::Vec3b Colour::mul(cv::Vec3b col, float s){
    return cv::Vec3b(s * col(0), s * col(1), s * col(2));
}
