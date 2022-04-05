#include<iostream>
#include "lista.h"
using namespace std;


int main() {

    Lista l;

    l.dodajNaPocetak(3);
    l.dodajNaPocetak(7);
    l.obrisiSaPocetka();
    l.dodajNaPocetak(2);
    l.dodajNaKraj(8);
    l.dodajNaPocetak(0);

    l.ispisi();
    //fercera
}
