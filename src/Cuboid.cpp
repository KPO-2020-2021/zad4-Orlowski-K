#include "Cuboid.hh"

/******************************************************************************
 * ! \brief Konstruktor bezparametryczny klasy Cuboid.                        |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      \retval Tablice wypelniona wartoscia 0.                               |
 */
Cuboid::Cuboid() {
    for (int i = 0; i < 8 ; ++i) {
        value[i] = Vector3D();
    }
}


/******************************************************************************
 * ! \brief konstruktor klasy Cuboid.                                         |
 |  Argumenty:                                                                |
 |      \param tmp - Jednowymiarowa tablica typu Vector3D                     |
 |  Zwraca:                                                                   |
 |      \retval Tablice wypelniona wartosciami podanymi w argumencie          |
 */ 
Cuboid::Cuboid(Vector3D tmp[8]) {
    for (int i = 0; i < 8 ; ++i) {
        value[i] = tmp[i];
    }
}


/******************************************************************************
 * ! \brief Funktor prostopadloscianu.                                        |
 |  Argumenty:                                                                |
 |      \param index - index wierzcholka.                                     |
 |  Zwraca:                                                                   |
 |      \retval Wartosc wierzcholka w danym miejscu tablicy jako wektor staly.|
 */
const Vector3D &Cuboid::operator [] (int index) const {
    if (index < 0 || index >= 8) {
        throw( "Error: Wierzholek jest poza zasiegiem!" );
    }
    return value[index];
}

/******************************************************************************
 * ! \brief Funktor prostopadloscianu.                                        |
 |  Argumenty:                                                                |
 |      \param index - index wierzcholka.                                     |
 |  Zwraca:                                                                   |
 |      \retval Wartosc wierzcholka w danym miejscu tablicy jako wektor staly.|
 */
 Vector3D &Cuboid::operator [] (int index) {
    if (index < 0 || index >= 8) {
        throw ("Error: Wierzholek jest poza zasiegiem!");
    }
    return value[index];
}




/********************************************************************
 * !\brief Realizuje translacje o podany wektor                     |
 | Argumenty:                                                       |
 |    \param this - Zadany prostopadloscian;                        |        
 |    \param tmp  - wektor translacji;                              |
 |    \param times - ilosc powtorzen                                |
 |  Wynik dzialania:                                                |
 |    Dodanie do kazdego wektora prostopadloscianu                  |
 |    wektora translacji. W ten sposob prostopadloscian             |
 |    jest przesuwany.                                              |
 */
void Cuboid::Translate (Vector3D &tmp,  unsigned int times){
    tmp = tmp * times;
    for(int i = 0; i < 8; ++i){
        value[i] = value[i] + tmp;
    }
}


/************************************************************************
 * ! \brief Realizuje translacje o podana macierz obrotu                |         
 * Argumenty:                                                           |                                                
 *    \param r_Matrix  - macierz obrotu;                                |
 *    \param times - ilosc powtorzen                                    |
 *  Wynik dzialania:                                                    |
 *    Mnozenie wektorow opisujacych wierzcholki z macierza obrotu       |
 *    W ten sposob prostopadloscian jest obracany.                      |
 */
void Cuboid::Rotate (Matrix3x3 &r_Matrix, unsigned int times){
    for(unsigned int j = 0; j < times; ++j ){
        for(int i = 0; i < 8; ++i){
            value[i] = r_Matrix * value[i];
        }
    }
}






/************************************************************************
 * ! \brief Realizuje porownywanie dlugosci bokow                       |         
 * Argumenty:                                                           |
 *    \param this - Zadany prostokat;                                   |
 *  Wynik dzialania:                                                    |
 *    Okresla czy boki sa rowne i wyswietla ich dlugosc                 |
 *  Zwraca:
 *     \retval true - jezeli boki sa rowne
 *     \retval false - jezeli boki nie sa rowne
 */
bool  Cuboid::compare_len_a() const{
    Vector3D a,b,c,d;
    double len1,len2,len3,len4;
    
    a = value[1] - value[0];
    b = value[3] - value[2];
    c = value[5] - value[4];
    d = value[7] - value[6];
    len1 = a.lenght();
    len2 = b.lenght();
    len3 = c.lenght();
    len4 = d.lenght();
    std::cout << std::endl;
    if(fabs(len1 - len2 ) <= 1e-11  && fabs(len1 - len3 ) <= 1e-11 && fabs(len1 - len4 ) <= 1e-11 ){
        std::cout << "Pierwsze przeciwlegle boki sa rowne." << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  "Dlugosc pierwszego boku: " << len1 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  "  Dlugosc drugiego boku: " << len2 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  " Dlugosc trzeciego boku: " << len3 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  " Dlugosc czwartego boku: " << len4 << std::endl <<std::endl;
        
    }
    else{
        std::cout << "Pierwsze przeciwlegle boki nie sa rowne!!!" << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  "Dlugosc pierwszego boku: " << len1 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  "  Dlugosc drugiego boku: " << len2 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  " Dlugosc trzeciego boku: " << len3 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  " Dlugosc czwartego boku: " << len4 << std::endl <<std::endl;
        return false;
    }
    
    return true;
}

/************************************************************************
 * ! \brief Realizuje porownywanie dlugosci bokow                       |         
 * Argumenty:                                                           |
 *    \param this - Zadany prostokat;                                   |
 *  Wynik dzialania:                                                    |
 *    Okresla czy boki sa rowne i wyswietla ich dlugosc                 |
 *  Zwraca:
 *     \retval true - jezeli boki sa rowne
 *     \retval false - jezeli boki nie sa rowne
 */
bool  Cuboid::compare_len_b() const{
    Vector3D a,b,c,d;
    double len1,len2,len3,len4;
    
    a = value[3] - value[1];
    b = value[2] - value[0];
    c = value[4] - value[6];
    d = value[5] - value[7];
    len1 = a.lenght();
    len2 = b.lenght();
    len3 = c.lenght();
    len4 = d.lenght();
    std::cout << std::endl;
    if(fabs(len1 - len2 ) <= 1e-11  && fabs(len1 - len3 ) <= 1e-11 && fabs(len1 - len4 ) <= 1e-11 ){
        std::cout << "Pierwsze przeciwlegle boki sa rowne." << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  "Dlugosc pierwszego boku: " << len1 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  "  Dlugosc drugiego boku: " << len2 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  " Dlugosc trzeciego boku: " << len3 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  " Dlugosc czwartego boku: " << len4 << std::endl <<std::endl;
        
    }
    else{
        std::cout << "Pierwsze przeciwlegle boki nie sa rowne!!!" << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  "Dlugosc pierwszego boku: " << len1 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  "  Dlugosc drugiego boku: " << len2 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  " Dlugosc trzeciego boku: " << len3 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  " Dlugosc czwartego boku: " << len4 << std::endl <<std::endl;
        return false;
    }
    
    return true;
}




/************************************************************************
 * ! \brief Realizuje porownywanie dlugosci bokow                       |         
 * Argumenty:                                                           |
 *    \param this - Zadany prostokat;                                   |
 *  Wynik dzialania:                                                    |
 *    Okresla czy boki sa rowne i wyswietla ich dlugosc                 |
 *  Zwraca:
 *     \retval true - jezeli boki sa rowne
 *     \retval false - jezeli boki nie sa rowne
 */
bool  Cuboid::compare_len_c() const{
    Vector3D a,b,c,d;
    double len1,len2,len3,len4;
    
    a = value[7] - value[1];
    b = value[5] - value[3];
    c = value[4] - value[2];
    d = value[6] - value[0];
    len1 = a.lenght();
    len2 = b.lenght();
    len3 = c.lenght();
    len4 = d.lenght();
    std::cout << std::endl;
    if(fabs(len1 - len2 ) <= 1e-11  && fabs(len1 - len3 ) <= 1e-11 && fabs(len1 - len4 ) <= 1e-11 ){
        std::cout << "Pierwsze przeciwlegle boki sa rowne." << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  "Dlugosc pierwszego boku: " << len1 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  "  Dlugosc drugiego boku: " << len2 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  " Dlugosc trzeciego boku: " << len3 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  " Dlugosc czwartego boku: " << len4 << std::endl <<std::endl;
        
    }
    else{
        std::cout << "Pierwsze przeciwlegle boki nie sa rowne!!!" << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  "Dlugosc pierwszego boku: " << len1 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  "  Dlugosc drugiego boku: " << len2 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  " Dlugosc trzeciego boku: " << len3 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  " Dlugosc czwartego boku: " << len4 << std::endl <<std::endl;
        return false;
    }
    
    return true;
}













/******************************************************************************
 * ! \brief Przeciazenie operatora <<                                         |
 |  Argumenty:                                                                |
 |      out - strumien wyjsciowy,                                             |
 |      tmp - prostokat.                                                      |
 */
std::ostream& operator << ( std::ostream &out, const Cuboid &tmp ){
    
    for(int i = 0; i < 8 ; i++){
        out << tmp[i] << std::endl;
    }

    return out;
}


/******************************************************************************
 * ! \brief Przeciazenie operatora << dla zapisu do pliku                     |
 |  Argumenty:                                                                |
 |      outfile - strumien plikowy                                            |
 |      tmp - prostokat.                                                      |
 */
std::ofstream& operator << ( std::ofstream &outfile, const Cuboid &tmp){
    
    outfile.open("../datasets/cuboid.dat");
    if (!outfile.is_open())  {
        std::cerr << ":(  Operacja otwarcia do zapisu \"" << "../datasets/cuboid.dat" << "\"" << std::endl
	    << ":(  nie powiodla sie." << std::endl;
        exit(0);
    }


    for(int i = 0; i < 8 ; i++){
        outfile << tmp[i] << std::endl;
        if( i%2 )
         outfile << std::endl;
    }

    outfile << tmp[0] << std::endl;
    outfile << tmp[1] << std::endl;
    outfile.close();


    return outfile;

}





/******************************************************************************
 * ! \brief Przeciazenie operatora >>                                         |
 |  Argumenty:                                                                |
 |      in - strumien wejsciowy                                               |
 |      tmp - prostopadloscian.                                               |
 */
std::ifstream& operator >> (std::ifstream &infile, Cuboid &tmp ){

    infile.open("../datasets/obj.dat");
    if(!infile.is_open()){
        std::cerr << ":(  Operacja otwarcia do wczytania \"" << "../datasets/obj.dat" << "\"" << std::endl
	    << ":(  nie powiodla sie." << std::endl;
        exit(0);
    }

    for(int i = 0; i < 8 ; ++i){
        infile >> tmp[i];
        if( i%2 )
         std::cout << std::endl;
    }

    infile.close();

    return infile;
}





