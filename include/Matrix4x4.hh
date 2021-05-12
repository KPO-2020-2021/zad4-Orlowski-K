#pragma once

#include "Matrix.hh"
#include "Vector3D.hh"

/*!
 * \file
 * \brief Plik zawiera definicje macierzy 4x4
 *
 * Plik zawiera definicje macierzy 4x4
 */


/*!
 * \brief Klasa Matrix4x4 jest instancją szablonu Matrix<>
 *
 *  Instancja szablonu modeluje pojecie macierzy kwadratowej 4x4.
 *  Mozliwe sa wszystkie operacje jak w przypadku innych wymiarow.
 *  Typem danych jest double.
 */
typedef Matrix<double,4>  Matrix4x4;


/*!
 *\brief Funkcja tworzaca macierz jednoczesnej translacji i rotacji;
 *
 * Argumenty:
 * \param alpha - kat obrotu wokol z w stopniach
 * \param beta  - kat obrotu wokol y w stopniach
 * \param gamma - kat obrotu wokol x w stopniach
 * \param translator -  wektor przesuniecia
 * 
 * Zwraca:
 * \retval Matrix4x4 - macierz jednoczesnego obrotu i translacji
*/ 
Matrix4x4 rotate_translate(double alpha, double beta, double gamma, Vector3D translator);