#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>
#include "algoritmos.cpp"

// Completar con las funciones del enunciado
template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c);

template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c);

template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta);

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta);

template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem);

template<class Contenedor>
bool ordenado(Contenedor& c);

template<class Contenedor>
std::pair<Contenedor, Contenedor> split(const Contenedor& c, const typename Contenedor::value_type& elem);

template<class Contenedor>
void merge(const Contenedor& c1, const Contenedor& c2, Contenedor& res);

#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
