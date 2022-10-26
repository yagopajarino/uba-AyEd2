#include "algoritmos.hpp"

template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c) {
    typename Contenedor::value_type min = *c.begin();
    for (auto& item: c) {
        if (item < min) {
            min = item;
        }
    }
    return min;
}

template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c) {
    typename Contenedor::value_type suma = 0;
    typename Contenedor::value_type cardinal = 0;
    for (auto& item : c) {
        suma += item;
        cardinal++;
    }
    return suma / cardinal;
}

template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta) {
    typename Iterator::value_type min = *desde;
    for (auto it = desde; it != hasta; ++it) {
        if (*it < min) {
            min = *it;
        }
    }
    return min;
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta) {
    typename Iterator::value_type suma = 0;
    typename Iterator::value_type cardinal = 0;
    for (auto it = desde; it != hasta; ++it) {
        suma += *it;
        cardinal++;
    }
    return suma / cardinal;
}

template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem) {
    typename Contenedor::iterator it = c.begin();
    while (it != c.end()) {
        if (*it == elem) {
            it = c.erase(it);
        } else {
            it++;
        }
    }
}

template<class Contenedor>
bool ordenado(Contenedor& c) {
    typename Contenedor::const_iterator it = c.begin();
    typename Contenedor::value_type anterior = *it;
    ++it;
    while (it != c.end() && anterior < *it) {
        anterior = *it;
        ++it;
    }
    return it == c.end();
}

template<class Contenedor>
std::pair<Contenedor, Contenedor> split(const Contenedor& c, const typename Contenedor::value_type& elem) {
    typename Contenedor::const_iterator it = c.begin();
    Contenedor menores;
    Contenedor mayores;
    while (it != c.end()) {
        if (*it < elem) {
            menores.insert(menores.end(), *it);
        } else {
            mayores.insert(mayores.end(), *it);
        }
        ++it;
    }
    return std::make_pair(menores, mayores);
}

template<class Contenedor>
void merge(const Contenedor& c1, const Contenedor& c2, Contenedor& res) {
    typename Contenedor::const_iterator i1 = c1.begin();
    typename Contenedor::const_iterator i2 = c2.begin();
    while (i1 != c1.end() || i2 != c2.end()) {
        if (i1 == c1.end()) {
            res.insert(res.end(), *i2);
            ++i2;
        } else if (i2 == c2.end()) {
            res.insert(res.end(), *i1);
            ++i1;
        } else if (*i1 < *i2) {
            res.insert(res.end(), *i1);
            ++i1;
        } else {
            res.insert(res.end(), *i2);
            ++i2;
        }
    }
}

// Ejercicio 8: Se puede armar un nuevo contenedor e insertar el menor en el inicio, devolver el primer elemento.