#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

template<class Clave, class Valor>
class Diccionario {
public:
    Diccionario();
    void definir(Clave k, Valor v);
    bool def(Clave k) const;
    Valor obtener(Clave k) const;
    std::vector<Clave> claves();
private:

    struct Asociacion {
        Asociacion(Clave k, Valor v);
        Clave clave;
        Valor valor;
    };
    std::vector<Asociacion> _asociaciones;
};


template<class Clave, class Valor>
Diccionario<Clave, Valor>::Diccionario(){}

template<class Clave, class Valor>
Diccionario<Clave, Valor>::Asociacion::Asociacion(Clave k, Valor v) : clave(k), valor(v) {
}

template<class Clave, class Valor>
void Diccionario<Clave, Valor>::definir(Clave k, Valor v) {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            _asociaciones[i].valor = v;
            return;
        }
    }
    _asociaciones.push_back(Asociacion(k, v));
}

template<class Clave, class Valor>
bool Diccionario<Clave, Valor>::def(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return true;
        }
    }
    return false;
}

template<class Clave, class Valor>
Valor Diccionario<Clave, Valor>::obtener(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return _asociaciones[i].valor;
        }
    }
    assert(false);
}

template<class Clave, class Valor>
std::vector<Clave> Diccionario<Clave, Valor>::claves() {
    std::vector<Clave> v1;
    std::vector<Clave> v2;
    int i = 0;
    while (i < _asociaciones.size()) {
        v1.push_back(_asociaciones[i].clave);
        i++;
    }
    while (v1.size() != 0) {
        Valor min = v1[0];
        int i = 0;
        int minIndex = 0;
        while (i < v1.size()) {
            if (v1[i] < min) {
                min = v1[i];
                minIndex = i;
            }
            i++;
        }
        v2.push_back(min);
        v1.erase(v1.begin()+minIndex);
    }
    return v2;
}

#endif /*__DICCIONARIO_H__*/