// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>

#include "exampleConfig.h"
#include "example.h"


#include "Vector3D.hh"
#include "Matrix3x3.hh"
#include "Cuboid.hh"
#include "lacze_do_gnuplota.hh"





/* Funkcja wyswietlajaca MENU */
void  MENU(){
   std::cout << " o - obrot bryly o zadana sekwencje katow" <<std::endl;
   std::cout << " t - powtorzenie poprzedniego obrotu" <<std::endl;
   std::cout << " r - wyswietlenie macierzy rotacji" <<std::endl;
   std::cout << " p - przesuniecie bryly o zadany wektor" <<std::endl;
   std::cout << " w - wyswietlenie wspolrzednych wierzcholkow" <<std::endl;
   std::cout << " s - sprawdzenie dlugosci przeciwleglych bokow" <<std::endl;
   std::cout << " m - wyswietl menu" <<std::endl;
   std::cout << " k - koniec dzialania programu\n" <<std::endl;
}


/*
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 */
int main() {
  std::cout << "Project 3D Rotation based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR
            << "."
            << PROJECT_VERSION_MINOR
            << "."
            << PROJECT_VERSION_PATCH
            << "."
            << PROJECT_VERSION_TWEAK
            << std::endl;



  Cuboid object;
  std::ifstream infile;
  std::ofstream outfile;
  PzG::LaczeDoGNUPlota  Lacze;
  Matrix3x3 rotator,new_rotation;
  Vector3D translator;
  double angle;
  unsigned int times;
  char option[1],axis[1];


  infile >> object;
  Lacze.DodajNazwePliku("../datasets/cuboid.dat",PzG::RR_Ciagly,2);
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.UstawZakresY(-155,155);
  Lacze.UstawZakresX(-155,155);
  Lacze.UstawZakresZ(-155,155);
  outfile << object;
  Lacze.Rysuj();
  std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
  std::cin.ignore(100000,'\n');
  object.compare_len_a();
  object.compare_len_b();
  object.compare_len_c();

  MENU();
    
    while( option[0] != 'k'){
      std::cout << "Twoj wybor? (m - menu) >  ";
      std::cin >> option;
      switch(option[0]){
       
          case 'o' :
              std::cout << "Podaj sekwencje oznaczen osi oraz katy obrotu w stopniach:\n"; 
              while(axis[0] != '.'){
                std::cin >> axis;
                if( axis[0] == 'x' || axis[0] == 'y' || axis[0] == 'z' ){
                  std::cin >> angle;
                  new_rotation = create_rotation(axis[0],angle);
                  rotator = new_rotation * rotator;
                }
                else if(axis[0] != '.'){
                  std::cin.ignore(100000,'\n');
                  std::cout << "Bledne oznaczenie osi. Dopuszczalne znaki to: x y z ." << std::endl;
                  std::cout << "Sprobuj jeszcze raz." << std::endl;
                }
              }
              std::cout << "Ile razy nalezy powtorzyc operacje? ";
              std::cin >> times;
              object.Rotate(rotator,times);
              Lacze.DodajNazwePliku("../datasets/cuboid.dat",PzG::RR_Ciagly,2);
              Lacze.ZmienTrybRys(PzG::TR_3D);
              Lacze.UstawZakresY(-155,155);
              Lacze.UstawZakresX(-155,155);
              Lacze.UstawZakresZ(-155,155);
              outfile << object;
              Lacze.Rysuj();
              std::cin.ignore(100000,'\n');
              break;
          case 't' :
              object.Rotate(rotator,times);
              Lacze.DodajNazwePliku("../datasets/cuboid.dat",PzG::RR_Ciagly,2);
              Lacze.ZmienTrybRys(PzG::TR_3D);
              Lacze.UstawZakresY(-155,155);
              Lacze.UstawZakresX(-155,155);
              Lacze.UstawZakresZ(-155,155);
              outfile << object;
              Lacze.Rysuj();
              std::cin.ignore(100000,'\n');
              break;
          case 'r' :
              std::cout << std::endl << rotator << std::endl;
              break;
          case 'p' :
              std::cout << std::endl;
              std::cout << "Podaj wspolrzedne wektora translacji w postaci trzech liczb\ntzn. wspolrzednych x, y i z\n";
              std::cin >> translator;
              std::cout << "Ile razy przesunac?  ";
              std::cin >> times;
              object.Translate(translator,times);

              Lacze.DodajNazwePliku("../datasets/cuboid.dat",PzG::RR_Ciagly,2);

              Lacze.ZmienTrybRys(PzG::TR_3D);
              Lacze.UstawZakresY(-155,155);
              Lacze.UstawZakresX(-155,155);
              Lacze.UstawZakresZ(-155,155);
              outfile << object;
              Lacze.Rysuj();
              std::cin.ignore(100000,'\n');
              break;
          case 'w':
              std::cout << std::endl << object << std::endl;
              break;
          case 's' :
              object.compare_len_a();
              object.compare_len_b();
              object.compare_len_c();
              break;
          case 'm' :
              MENU();
              break;
          case 'k':
              std::cout << "Wybrano koniec pracy programu" << std::endl;
              break;
          default :
              exit(1);
      }

    }

    return 0;
}
