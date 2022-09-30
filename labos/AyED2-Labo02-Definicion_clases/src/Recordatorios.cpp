#include <iostream>
#include <list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    Fecha(int mes, int dia);
    int dia();
    int mes();
    // Completar declaraciones funciones
    #if EJ >= 7 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif
    void incrementar_dia();

  private:
    int _dia;
    int _mes;
};

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes();
    return os;
}

Fecha::Fecha(int mes, int dia): _dia(dia), _mes(mes) {}

int Fecha::dia() {
    return _dia;
}

int Fecha::mes() {
    return _mes;
}

#if EJ >= 7
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();
    return igual_dia && igual_mes;
}
#endif

void Fecha::incrementar_dia() {
    uint max_dias = dias_en_mes(_mes);
    if (_dia == max_dias) {
        _dia = 1;
        _mes = _mes == 12 ? 1 : _mes+1;
    } else {
        _dia++;
    }
}

// Ejercicio 11, 12

// Clase Horario
class Horario {
    public:
        Horario(uint hora, uint min);
        uint hora();
        uint min();
        bool operator==(Horario h);
        bool operator<(Horario h);
    private:
        uint _hora;
        uint _min;
};

Horario::Horario(uint hora, uint min): _hora(hora), _min(min) {}

uint Horario::hora() {
    return _hora;
}

uint Horario::min() {
    return _min;
}

ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" << h.min();
    return os;
}

bool Horario::operator==(Horario r) {
    return this->hora() == r.hora() && this->min() == r.min();
}

bool Horario::operator<(Horario h) {
    return this->hora() < h.hora() || (h.hora() == this->hora() && this->min() < h.min());
}

// Ejercicio 13

// Clase Recordatorio
class Recordatorio {
    public:
        Recordatorio(Fecha f, Horario h, string mensaje);
        string mensaje();
        Fecha fecha();
        Horario horario();
    private:
        string _mensaje;
        Fecha _fecha;
        Horario _horario;
};

Recordatorio::Recordatorio(Fecha f, Horario h, std::string mensaje): _fecha(f), _horario(h), _mensaje(mensaje) {}

string Recordatorio::mensaje() {
    return _mensaje;
}

Fecha Recordatorio::fecha() {
    return _fecha;
}

Horario Recordatorio::horario() {
    return _horario;
}

ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.mensaje() << " @ " << r.fecha() << " " << r.horario();
    return os;
}

// Ejercicio 14

class Agenda {
    public:
        Agenda(Fecha fecha_inicial);
        void agregar_recordatorio(Recordatorio rec);
        void incrementar_dia();
        list<Recordatorio> recordatorios_de_hoy();
        Fecha hoy();
    private:
        list<Recordatorio> _recordatorios;
        Fecha _fecha;
};

Agenda::Agenda(Fecha fecha_inicial): _fecha(fecha_inicial), _recordatorios({}) {}

void Agenda::agregar_recordatorio(Recordatorio rec) {
    _recordatorios.push_back(rec);
}

void Agenda::incrementar_dia() {
    _fecha.incrementar_dia();
}

bool cmp(Recordatorio r1, Recordatorio r2) {
    return r1.horario() < r2.horario();
}

list <Recordatorio> Agenda::recordatorios_de_hoy() {
    list <Recordatorio> res;
    for (auto x: _recordatorios) {
        if (x.fecha() == _fecha) {
            res.push_back(x);
        }
    }
    res.sort(cmp);
    return res;
}

Fecha Agenda::hoy() {
    return _fecha;
}

ostream& operator<<(ostream& os, Agenda a) {
    os << a.hoy() << endl;
    os << "=====" << endl;
    for (auto x: a.recordatorios_de_hoy()) {
        os << x << endl;
    }
    return os;
}
