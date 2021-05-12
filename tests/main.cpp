#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"

// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.

#include "Vector3D.hh"
#include "Matrix3x3.hh"
#include "Cuboid.hh"
#include <sstream>

TEST_CASE("Test funktora wektora"){
    Vector3D a({2.0,3.00,-1.0});

    CHECK( (a[0] == 2.00 && a[1] == 3.00 && a[2] == -1.0) );
}


TEST_CASE("Test funktora wektora"){
    Vector3D  a({2,3.00,4.0});

    a[0] = 5.00;
    CHECK( (a[0] == 5.00 && a[1] == 3.00 && a[2] == 4.0) );
}


TEST_CASE("Test funktora wektora - wyjscie poza zakres"){
    Vector3D  a;
    
    CHECK_THROWS( a[5] = 2.00 );
}

TEST_CASE("Test funktora wektora - wyjscie poza zakres"){
    Vector3D  a;
    
    CHECK_THROWS( a[-5] = 3.00 );
}


TEST_CASE("Test funktora wektora - wyjscie poza zakres"){
    Vector3D  a;
    

    CHECK_THROWS( std::cout << a[5] );
}

TEST_CASE("Test funktora wektora - wyjscie poza zakres"){
    Vector3D  a;
    

    CHECK_THROWS( std::cout <<  a[-5] );
}


TEST_CASE("Konstruktor wektora bez argumentu"){
    Vector3D tmpV;
    double test = 0;

    
    for(int i = 0; i < 3 ; i++){
        if(tmpV[i] != 0 )
          test = -1;
    }
    
    CHECK( !test );
}


TEST_CASE("Konstruktor wektora z argumentem"){
    Vector3D  tmpV({1.00,-3.15});

    CHECK( (tmpV[0] == 1.00 && tmpV[1] == -3.15 && tmpV[2] == 0) );
}




TEST_CASE("Dodawanie dwoch wektorow"){
    Vector3D  a({1.00,2.00}),b({5.00,6.00}),result;

    result = a + b;

    CHECK(  ( result[0] - 6.00 <= 1e-5  && result[1] - 8.00 <=1e-5 && result[2] == 0 )  );
}

TEST_CASE("Dodawanie dwoch wektorow ( bledne )"){
    Vector3D  a({1.00,2.00}),b({5.00,6.00}),result;

    result = a + b;

    CHECK(  !( result[0] - 5.00 <= 1e-5  && result[1] - 7.00 <=1e-5 )  );
}


TEST_CASE("Dodawanie dwoch wektorow"){
    Vector3D  a({-1.31,3.12}),b({5.42,-6.26}),result;

    result = a + b;

    CHECK(  ( result[0] - 4.11 <= 1e-5  && result[1] + 3.14 <= 1e-5 && result[2] == 0)  );
}


TEST_CASE("Odejmowanie dwoch wektorow"){
    Vector3D  a({2,4.00}),b({0,3.00}),result;

    result = a - b;

    CHECK(  ( result[0] - 2.00 <= 1e-5  && result[1] - 1.00 <= 1e-5 && result[2] == 0)  );
}


TEST_CASE("Odejmowanie dwoch wektorow (bledne) "){
    Vector3D a({2,3.00}),b({1.00,3.00}),result;

    result = a - b;

    CHECK(  !( result[0] - 1.00 <= 1e-5  && result[1] + 1.00 <= 1e-5 && result[2] == 0)  );
}


TEST_CASE("Mnozenie wektora przez liczbe "){
    Vector3D  a({2,3.00}),result;

    result = a * 3.2;

    CHECK(  ( result[0] - 6.4 <= 1e-5  && result[1] - 9.60 <= 1e-5 && result[2] == 0)  );
}


TEST_CASE("Dzielenie wektora przez liczbe "){
    Vector3D  a({2,3.00}),result;

    result = a / 2;

    CHECK(  ( result[0] - 1 <= 1e-5  && result[1] - 1.50 <= 1e-5 && result[2] == 0)  );
}


TEST_CASE("Dzielenie wektora przez liczbe - wykrwywanie dzielenia przez 0 "){
    Vector3D a({2,3.00}),result;

    CHECK_THROWS( result = a / 0 );
}

TEST_CASE("Obliczanie dlugosci wektora "){
    Vector3D  a({-4.00,0.00,3.00});
    double result;
    result = a.lenght();

    CHECK( result - 5.00 <= 1e-5 );
}



TEST_CASE("Test przeciazenia >> dla wektora"){
    Vector3D  a,b = {10,20,30};
    
    std::istringstream in("10.0 20.0 30.0");
    in >> a;
    
    CHECK( a == b );
}



TEST_CASE("Test przeciazenia == dla wektora"){
    Vector3D  a,b;

    double arg1[]={2.1234567890,-12.0987654321};

    a[0] = arg1[0];
    a[1] = arg1[1];
    b[0] = arg1[0];
    b[1] = arg1[1];

    CHECK( a == b );
}


TEST_CASE("Test przeciazenia == dla wektora"){
    Vector3D  a,b;

    double arg1[]={2.1234567890,-12.0987654321};
    double arg2[]={2.1234567892,-12.0987654322};
    
    a[0] = arg1[0];
    a[1] = arg1[1];
    b[0] = arg2[0];
    b[1] = arg2[1];


    CHECK( !(a == b) );
}



TEST_CASE("Test funktora dla macierzy const"){
    Matrix3x3  M;

    CHECK( M(0,0) == 1.0 );
}


TEST_CASE("Test funktora dla macierzy"){
    Matrix3x3  M;

    M(0,0) = 12.2;

    CHECK(  M(0,0)==12.2  );
}


TEST_CASE("Test funktora dla macierzy wyjscie poza zakres const "){
    Matrix3x3  M;

    CHECK_THROWS( std::cout << M(12,1) );
}


TEST_CASE("Test funktora dla macierzy wyjscie poza zakres const"){
    Matrix3x3  M;

    CHECK_THROWS( std::cout << M(0,-1) );
}


TEST_CASE("Test funktora dla macierzy wyjscie poza zakres "){
    Matrix3x3  M;

    CHECK_THROWS(  M(0,-1) = 2.0 );
}


TEST_CASE("Test funktora dla macierzy wyjscie poza zakres "){
    Matrix3x3  M;

    CHECK_THROWS(  M(10,0) = -2.0 );
}

TEST_CASE("Test konstruktora bezparametrycznego dla macierzy"){
    Matrix3x3  M;
    int err = 0;

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(  M(i,j) != 0  ){
                if( i == j && M(i,j) != 1.00 )
                    err++;
            }
        }
    }

    CHECK(!err);
}



TEST_CASE("Test konstruktora parametrycznego dla macierzy"){
    Matrix3x3  M;
    double argumentsM[][3] = {{1.0, 2.0},{-3.0, 4.0}};

    M = Matrix3x3 (argumentsM);
    CHECK( ( M(0,0)==1.0 && M(0,1) == 2.0 && M(1,0) == -3.0 && M(1,1) == 4.0 ) );
}



TEST_CASE("Test mnozenia macierzy przez wektor"){
    Vector3D  a({2.0,3.0,1.0}),b,c({11,8,1});
    Matrix3x3  M;

    double argumentsM[][3] = {{1.0, 2.0,3.0},{-3.0, 4.0, 2.0},{1,-1,2}};

    M = Matrix3x3 (argumentsM);
    b = M * a;

    CHECK( c == b );
}

TEST_CASE("Test dodawania macierzy"){
    Matrix3x3  M,M0;
    double argumentsM[][3] = {{1.0, 2.0},{-3.0, 4.0}};
    M0 = Matrix3x3 (argumentsM);

    M = M + M0;

    CHECK( ( M(0,0)==2.0 && M(0,1) == 2.0 && M(1,0) == -3.0 && M(1,1) == 5.0 ) );
}




TEST_CASE("Test przeciazenia >> dla macierzy"){
    Matrix3x3  M;
    
    std::istringstream in("10.0 20.0 20.0 -50.0");
    in >> M;
   
    
    CHECK( ( M(0,0)==10.0 && M(0,1) == 20.0 && M(0,2) == 20.0 && M(1,0) == -50.0 )  );
}



TEST_CASE("Test funktora dla prostopadloscianu const"){
    Cuboid tmpC;
    Vector3D  V;
    CHECK(  tmpC[0] == V );
}


TEST_CASE("Test funktora dla prostopadloscianu const"){
    Cuboid tmpC;

    CHECK_THROWS( std::cout << tmpC[15] );
}



TEST_CASE("Test funktora dla prostopadloscianu const"){
    Cuboid tmpC;

    CHECK_THROWS( std::cout << tmpC[-15] );
}

TEST_CASE("Test funktora dla prostopadloscianu"){
    Cuboid tmpC;
    Vector3D  V,R;
    V[0] = 1;
    V[1] = 2;
    tmpC[0] = V;
    R[0] = 1;
    R[1] = 2;
    CHECK(  tmpC[0] == R  );
}


TEST_CASE("Test funktora dla prostopadloscianu"){
    Cuboid tmpC;
    Vector3D  V;
    
    CHECK_THROWS(  tmpC[-1] == V  );
}



TEST_CASE("Test funktora dla prostopadloscianu"){
    Cuboid tmpC;
    Vector3D  V;
    
    CHECK_THROWS(  tmpC[14] == V  );
}



TEST_CASE("Test konstruktora bezparametrycznego dla prostopadloscianu"){
    Cuboid tmpC;
    Vector3D  V;
    int err = 0;

    for(int i = 0; i < 8; ++i){
        if(tmpC[i] == V)
            err++;
    }
    
    CHECK(  err >=4  );
}



TEST_CASE("Test konstruktora parametrycznego dla prostopadloscianu"){
    Cuboid tmpC;
    Vector3D  V1({1,2}),V2({2,1});
    Vector3D  arg[] = {V1,V2,V1,V2};

    tmpC = Cuboid(arg);
    
    CHECK(  (tmpC[0] == V1 && tmpC[1] == V2 && tmpC[2] == V1 && tmpC[3] == V2)  );
}



TEST_CASE("Translacja prostopadloscianu o wektor"){
    Cuboid tmpC;
    Vector3D  trans({ 50.0, 25.0, 50});
    unsigned int times;
    
    Vector3D V1={50,50,50},V2={100,50,50},V3={50,100,50},V4={100,100,50},V5={50,100,100},V6={100,100,100},V7={50,50,100},V8={100,50,100};
    Vector3D  argumentsR[] = {V1,V2,V3,V4,V5,V6,V7,V8};

    tmpC = Cuboid(argumentsR);

    times = 1;

    tmpC.Translate(trans,times);
    Vector3D  R1={100,75,100},R2={150,75,100},R3={100,125,100},R4={150,125,100},R5={100,125,150},R6={150,125,150},R7={100,75,150},R8={150,75,150};

    CHECK(( tmpC[0] == R1 && tmpC[1] == R2 && tmpC[2] == R3 && tmpC[3] == R4 && tmpC[4] == R5  && tmpC[5] == R6  && tmpC[6] == R7  && tmpC[7] == R8) );
}



TEST_CASE("Rotacja prostopadloscianu  os z"){
    Cuboid tmpC;
    Vector3D  trans;
    Matrix3x3  rotation;
    
    Vector3D V1={0,0,0},V2={50,0,0},V3={0,50,0},V4={50,50,0},V5={0,50,50},V6={50,50,50},V7={0,0,50},V8={50,0,50};
    Vector3D  argumentsR[] = {V1,V2,V3,V4,V5,V6,V7,V8};

    tmpC = Cuboid(argumentsR);
    rotation = create_rotation('z',90);

    tmpC.Rotate(rotation,1);

    Vector3D R1={0,0,0},R2={0,50,0},R3={-50,0,0},R4={-50,50,0},R5={-50,0,50},R6={-50,50,50},R7={0,0,50},R8={0,50,50};

    CHECK(( tmpC[0] == R1 && tmpC[1] == R2 && tmpC[2] == R3 && tmpC[3] == R4 && tmpC[4] == R5 && tmpC[5] == R6 && tmpC[6] == R7 && tmpC[7] == R8) );
}



TEST_CASE("Rotacja prostopadloscianu kat dodatni os y"){
    Cuboid tmpC;
    Vector3D  trans;
    Matrix3x3  rotation;
    
    Vector3D V1={0,0,0},V2={50,0,0},V3={0,50,0},V4={50,50,0},V5={0,50,50},V6={50,50,50},V7={0,0,50},V8={50,0,50};
    Vector3D  argumentsR[] = {V1,V2,V3,V4,V5,V6,V7,V8};

    tmpC = Cuboid(argumentsR);
    rotation = create_rotation('y',90);

    tmpC.Rotate(rotation,1);

    Vector3D R1={0,0,0},R2={0,0,-50},R3={-0,50,0},R4={0,50,-50},R5={50,50,0},R6={50,50,-50},R7={50,0,0},R8={50,0,-50};

    CHECK(( tmpC[0] == R1 && tmpC[1] == R2 && tmpC[2] == R3 && tmpC[3] == R4 && tmpC[4] == R5 && tmpC[5] == R6 && tmpC[6] == R7 && tmpC[7] == R8) );
}




TEST_CASE("Rotacja prostopadloscianu kat dodatni os x"){
    Cuboid tmpC;
    Vector3D  trans;
    Matrix3x3  rotation;
    
    Vector3D V1={0,0,0},V2={50,0,0},V3={0,50,0},V4={50,50,0},V5={0,50,50},V6={50,50,50},V7={0,0,50},V8={50,0,50};
    Vector3D  argumentsR[] = {V1,V2,V3,V4,V5,V6,V7,V8};

    tmpC = Cuboid(argumentsR);
    rotation = create_rotation('x',90);

    tmpC.Rotate(rotation,1);

    Vector3D R1={0,0,0},R2={50,0,0},R3={0,0,50},R4={50,0,50},R5={0,-50,50},R6={50,-50,50},R7={0,-50,0},R8={50,-50,0};

    CHECK(( tmpC[0] == R1 && tmpC[1] == R2 && tmpC[2] == R3 && tmpC[3] == R4 && tmpC[4] == R5 && tmpC[5] == R6 && tmpC[6] == R7 && tmpC[7] == R8) );
}




TEST_CASE("Test tworzenia macierzy obrotu os z"){
    Matrix3x3  M;

    M = create_rotation('z',90);

    CHECK( ( M(0,0) < 1e-11 && M(0,1) == -1.00 && M(0,2) == 0 && M(1,0) == 1.00 && M(1,1) < 1e-11 && M(1,2) == 0 && M(2,0) == 0 && M(2,1) == 0 && M(2,2) == 1) );
}



TEST_CASE("Test tworzenia macierzy obrotu os y"){
    Matrix3x3  M;

    M = create_rotation('y',90);

    CHECK( ( M(0,0) < 1e-11 && M(0,1) < 1e-11 && M(0,2) == 1.0 && M(1,0) < 1e-11 && M(1,1) == 1.0 && M(1,2) < 1e-11 && M(2,0) == -1.0 && M(2,1) < 1e-11 && M(2,2) < 1e-11) );
}


TEST_CASE("Test tworzenia macierzy obrotu os x"){
    Matrix3x3  M;

    M = create_rotation('x',90);

    CHECK( ( M(0,0) == 1.00 && M(0,1) < 1e-11 && M(0,2) == 0 && M(1,0) < 1e-11 && M(1,1) < 1e-11  && M(1,2) == -1.00 && M(2,0) <1e-11 && M(2,1) == 1.00 && M(2,2) < 1e-11) );
}


TEST_CASE("Test tworzenia macierzy obrotu kat ujemny os z"){
    Matrix3x3  M;

    M = create_rotation('z',-270);

    CHECK( ( M(0,0) < 1e-11 && M(0,1) == -1.00 && M(0,2) == 0 && M(1,0) == 1.00 && M(1,1) < 1e-11 && M(1,2) == 0 && M(2,0) == 0 && M(2,1) == 0 && M(2,2) == 1) );
}



TEST_CASE("Test tworzenia macierzy obrotu kat ujemny os y"){
    Matrix3x3  M;

    M = create_rotation('y',-270);

    CHECK( ( M(0,0) < 1e-11 && M(0,1) < 1e-11 && M(0,2) == 1.0 && M(1,0) < 1e-11 && M(1,1) == 1.0 && M(1,2) < 1e-11 && M(2,0) == -1.0 && M(2,1) < 1e-11 && M(2,2) < 1e-11) );
}


TEST_CASE("Test tworzenia macierzy obrotu kat ujemny os x"){
    Matrix3x3  M;

    M = create_rotation('x',-270);

    CHECK( ( M(0,0) == 1.00 && M(0,1) < 1e-11 && M(0,2) == 0 && M(1,0) < 1e-11 && M(1,1) < 1e-11  && M(1,2) == -1.00 && M(2,0) <1e-11 && M(2,1) == 1.00 && M(2,2) < 1e-11) );
}



