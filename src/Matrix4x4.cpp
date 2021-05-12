#include "Matrix4x4.hh"

Matrix4x4 rotate_translate(double alpha, double beta, double gamma, Vector3D translator){
    Matrix4x4 tmp;
    alpha = alpha * M_PI / 180;
    beta = beta * M_PI / 180;
    gamma = gamma * M_PI / 180;

    tmp(0,0) = cos(alpha)*cos(beta);
    tmp(0,1) = cos(alpha)*sin(beta)*sin(gamma) - sin(alpha)*cos(gamma);
    tmp(0,2) = cos(alpha)*sin(beta)*cos(gamma) + sin(alpha)*sin(gamma);
    tmp(0,3) = translator[0];
    tmp(1,0) = sin(alpha)*cos(beta);
    tmp(1,1) = sin(alpha)*sin(beta)*sin(gamma) + cos(alpha)*cos(gamma);
    tmp(1,2) = sin(alpha)*sin(beta)*cos(gamma) - cos(alpha)*sin(gamma);
    tmp(1,3) = translator[1];
    tmp(2,0) = -sin(beta);
    tmp(2,1) = cos(beta)*sin(gamma);
    tmp(2,2) = cos(beta)*cos(gamma);
    tmp(2,3) = translator[2];
    
    return tmp;
}