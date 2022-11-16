#include "Diccionario.hpp"

template<class T>
class Multiconjunto {
    public:
        Multiconjunto();
        void agregar(T x);
        int ocurrencias(T x) const;
        bool operator<=(Multiconjunto<T> otro);
    private:
        Diccionario<T, int> _elementos;
};

template<class T>
Multiconjunto<T>::Multiconjunto() : _elementos(Diccionario<T, int>()) {}

template<class T>
void Multiconjunto<T>::agregar(T x) {
    if (_elementos.def(x)) {
        int valor = _elementos.obtener(x) + 1;
        _elementos.definir(x, valor);
    }
    else {
        _elementos.definir(x, 1);
    }
}

template<class T>
int Multiconjunto<T>::ocurrencias(T x) const {
    if (_elementos.def(x)) {
        return _elementos.obtener(x);
    } else {
        return 0;
    }
}

template<class T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) {
    std::vector<T> claves = _elementos.claves();
    int i = 0;
    while (i < claves.size() && _elementos.obtener(claves[i]) <= otro.ocurrencias(claves[i])) {
        i++;
    }
    return i == claves.size();
}

