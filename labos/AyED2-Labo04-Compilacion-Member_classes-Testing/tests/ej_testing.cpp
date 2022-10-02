#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.h"
#include "../src/Truco.h"
#include <map>
#include <cmath>

using namespace std;

// Ejercicio 4
TEST(Aritmetica, suma) {
    EXPECT_EQ(15 + 7, 22);
}

// Ejercicio 5
TEST(Aritmetica, potencia) {
    float res = pow(10, 2);
    EXPECT_EQ(res, 100);
}

// Ejercicios 6..9
TEST(Aritmetica, potencia_general) {
    for (int i = -5; i <= 5; ++i) {
        EXPECT_EQ(pow(i, 2), i*i);
    }
}

TEST(Diccionario, obtener) {
    map<int, int> diccionario;
    diccionario.insert(make_pair(1,2));
    EXPECT_EQ(diccionario.at(1), 2);
}

TEST(Diccionario, definir) {
    map<int, int> diccionario;
    int clave = 0;
    EXPECT_EQ(diccionario.count(clave), 0);
    diccionario[clave] = 10;
    EXPECT_EQ(diccionario.count(clave), 1);
}

TEST(Truco, inicio) {
    Truco juego = Truco();
    EXPECT_EQ(juego.puntaje_j1(), 0);
    EXPECT_EQ(juego.puntaje_j2(), 0);
}

TEST(Truco, buenas) {
    Truco juego = Truco();
    // Verifico que no está en las buenas
    EXPECT_FALSE(juego.buenas(1));

    // Sumo 15 usando el método sumar_punto y verifico no está en las buenas
    for (int i = 0; i < 15; ++i) {
        juego.sumar_punto(1);
    }
    EXPECT_FALSE(juego.buenas(1));

    // Sumo uno al jugador 1 y verifico que está en las buenas
    juego.sumar_punto(1);
    EXPECT_TRUE(juego.buenas(1));

    // Sumo dos al jugador 1 y verifico que está en las buenas
    juego.sumar_punto(1);
    juego.sumar_punto(1);
    EXPECT_TRUE(juego.buenas(1));
}
