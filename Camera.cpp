/**
 *
 * This files implements the methods defined in the Camera header file
 * @author: Bivash Pandey
 */

#include "Camera.hpp"

typedef Eigen::Matrix<float, 3, 1> Vec3;

/**
 * This constructor initializes the position of a camera
 *
 * @param position The position of the camera
 */
Camera::Camera(Vec3 position){
    this->position = position;
}


/**
 * This method returns the position of the camera
 *
 * @return The camera position
 */
Vec3 Camera::getCameraPosition(){
    return position;
}
