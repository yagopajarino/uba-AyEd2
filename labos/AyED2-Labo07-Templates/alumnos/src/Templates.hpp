

// Ejercicio 1: Pasar a templates
template<class T>
T cuadrado(T x) {
    return x * x;
}

// Ejercicio 2: Pasar a templates
template<class Contenedor, class Elem>
bool contiene(Contenedor s, Elem c) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

template<class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b) {
    if (a.size() <= b.size()) {
        int i = 0;
        while (i < a.size() && a[i] == b[i]) {
            i++;
        }
        return i == a.size();
    }
    return false;
}

template<class Contenedor, class Elem>
Elem maximo(Contenedor c) {
    Elem max = c[0];
    int i = 0;
    while (i < c.size()) {
        if (c[i] > max) {
            max = c[i];
        }
        i++;
    }
    return max;
}