/**
 *
 * This files implements the methods defined in the Material header file
 * @author: Bivash Pandey
 */

#include "Material.hpp"

/**
 * This constructor initializes the colour, ambient, diffuse, specular, and
 * reflectance value
 *
 * @param colour  The  colour of the material
 * @param ambient  The ambient coefficient
 * @param diffuse  The diffuse coefficient
 * @param specular  The specular coefficient
 */
Material:: Material(cv::Vec3b colour, float ambient, float diffuse, float specular){
    materialColour = colour;
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
}

/**
 * This method returns ambient coefficient
 *
 * @return The ambient value
 */
float Material::getAmbient(){
    return ambient;
}

/**
 * This method returns the diffuse coefficient
 *
 * @return The diffuse value
 */
float Material::getDiffuse(){
    return diffuse;
}

/**
 * This method returns the specular coefficient
 *
 * @return The specular value
 */
float Material::getSpecular(){
    return specular;
}

/**
 * This method returns the colour of object
 *
 * @return The material colour
 */
cv::Vec3b Material::getColour(){
    return materialColour;
}

/**
 * This method sets the colour of a material
 *
 * @param newColour The Colour to be set
 */
void Material::setColour(cv::Vec3b newColour){
    materialColour = newColour;
}
