#ifndef CUBOID_HH
#define CUBOID_HH

#include <iostream>
#include <fstream>
#include "Vector3D.hh"
#include "Matrix3x3.hh"
/*!
 * \file
 * \brief Plik zawiera definicje klasy cuboid
 *
 *  Plik zawiera definicje klasy cuboid.
 */



/*********************************************************************
 * ! \brief Opis klasy                                               |
 |  Klasa modeluje pojecie prostopadloscianu jako zbioru osmiu       |
 |  wierzcholkow przedstawionych jako wektory 3D. Dane sa            |
 |  przechowywane w tablicy typu Wektor3D, wiec klasa korzysta       |
 |  bezposrednio z innej klasy.                                      |
 |                                                                   |
 |  Przeciazenia operatorow pozwalaja na dostep i modyfikacje        |
 |  danych. Zdefiniowane metody pozwalaja na translacje o            |
 |  zadany wektor, obrot wzgledem macierzy obrotu i obliczenie       |
 |  dlugosci bokow.                                                  |
 */
class Cuboid {
  private:

    Vector3D value[8];

  public:

    Cuboid(Vector3D tmp[8]);

    Cuboid();

    const Vector3D &operator [] (int index) const;

    Vector3D &operator [] (int index);

    void Translate (Vector3D &tmp, unsigned int times);

    void Rotate (Matrix3x3 &r_Matrix, unsigned int times);

    bool compare_len_a() const;

    bool compare_len_b() const;

    bool compare_len_c() const;
   
};



std::ostream& operator << ( std::ostream &out, const Cuboid &tmp );


std::ofstream& operator << ( std::ofstream &out, const Cuboid &tmp);

std::ifstream& operator >> (std::ifstream &infile, Cuboid &tmp );



#endif
