#ifndef MATRIX3X3_HH
#define MATRIX3X3_HH


#include <iostream>

#include "Matrix.hh"



/*!
 * \file
 * \brief Plik zawiera definicje macierzy 3x3
 *
 * Plik zawiera definicje macierzy 3x3
 */


/*!
 * \brief Klasa Matrix3x3 jest instancją szablonu Matrix<>
 *
 *  Instancja szablonu modeluje pojecie macierzy kwadratowej 3x3.
 *  Mozliwe sa wszystkie operacje jak w przypadku innych wymiarow.
 *  Typem danych jest double.
 */
typedef Matrix<double,3>  Matrix3x3;



Matrix3x3 create_rotation(char axis,double angle);


#endif
