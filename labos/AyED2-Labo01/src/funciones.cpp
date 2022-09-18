#include <vector>
#include "algobot.h"
#include <set>

using namespace std;

// Auxiliares

set<int> construir_set(vector<int> v) {
    set<int> res;
    for (int i = 0; i < v.size(); ++i) {
        res.insert(v[i]);
    }
    return res;
}


// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    vector<int> res;
    for (int i = 0; i < s.size(); ++i) {
        int j = 0;
        while (j < res.size() && s[i] != res[j]) {
            j++;
        }
        if (j == res.size()) {
            res.push_back(s[i]);
        }
    }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    vector<int> res;
    set<int> uniques = construir_set(s);
    for (auto x: uniques){
        res.push_back(x);
    }
    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    for (int i = 0; i < a.size(); ++i) {
        int j = 0;
        while (j < b.size() && a[i] != b[j]) {
            j++;
        }
        if (j == b.size()) {
            return false;
        }
    }

    for (int i = 0; i < b.size(); ++i) {
        int j = 0;
        while (j < a.size() && b[i] != a[j]) {
            j++;
        }
        if (j == a.size()) {
            return false;
        }
    }
    return true;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> as = construir_set(a);
    set<int> bs = construir_set(b);
    return as == bs;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> res;
    for (int i = 0; i < s.size(); ++i) {
        res[s[i]]++;
    }
    return res;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> res;
    map<int, int> counts = contar_apariciones(s);
    for (auto x: counts) {
        if (x.second == 1) {
            res.push_back(x.first);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for (auto x: a) {
        if (b.count(x) == 1) {
            res.insert(x);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res;
    for (auto x: s) {
        res[x % 10].insert(x);
    }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res;
    for (auto x: str) {
        int i = 0;
        while (i < tr.size() && tr[i].first != x) {
            i++;
        }
        if (i == tr.size()) {
            res.push_back(x);
        } else {
            res.push_back(tr[i].second);
        }
    }
    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    set<set<LU>> grupos;
    for (auto x: s) {
        grupos.insert(x.libretas());
    }
    map<LU, int> counts;
    for (auto x: grupos) {
        for (auto y: x) {
            counts[y]++;
        }
    }
    bool b = false;
    for (auto x: counts) {
        if (x.second > 1) {
            b = true;
        }
    }
    return b;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> res;
    map<set<LU>, vector<Mail>> mails_por_grupo;
    for (auto x: s) {
        if (x.adjunto()) {
            mails_por_grupo[x.libretas()].push_back(x);
        }
    }
    for (auto x: mails_por_grupo) {
        Fecha min = x.second[0].fecha();
        Mail mas_reciente = x.second[0];
        for (auto y: x.second) {
            if (y.fecha() < min) {
                min = y.fecha();
                mas_reciente = y;
            }
        }
        res[x.first] = mas_reciente;
    }
    return res;
}
