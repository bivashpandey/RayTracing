/**
 *
 * This files implements the constructor and methods defined in the Light header file
 * @author: Bivash Pandey
 */

#include "Light.hpp"

/**
 * This constructor initializes the position and the colour of a Light
 *
 * @param position The position of the Light
 * @param colour The colour of the Light
 */
Light::Light(Vec3 position, cv::Vec3b colour){
    this->position = position;
    this->colour = colour;
}

/**
 * This constructor initializes the position and the colour of a Light (White by default)
 *
 * @param position The position of the Light
 *
 */
Light::Light(Vec3 position){
    this->position = position;
    colour = cv::Vec3b(255, 255, 255);
}

/**
 * This method returns the position of the light as Vec3
 *
 * @return The position of the Light
 */
Vec3 Light::getLightPosition(){
    return position;
}

/**
 * This method returns the Colour of the Light as Vec3b
 *
 * @return The colour of the Light
 */
cv::Vec3b Light::getLightColour(){
    return colour;
}
