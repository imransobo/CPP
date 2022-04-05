#ifndef LISTA_H
#define LISTA_H
#endif // LISTA_H

#include<iostream>
using namespace std;

// prva verzija

struct Cvor {
    int element;
    Cvor* sljedeci;
    Cvor(int el, Cvor* slj) : element(el), sljedeci(slj) {}
};

class Lista {
    Cvor* pocetak; //pokazivač na prvi element liste
    Cvor* kraj;
    int broj_elemenata;
public:
    Lista() { broj_elemenata = 0; pocetak =  nullptr; kraj = nullptr; }
    void dodajNaPocetak(int broj) {
        Cvor* novi = new Cvor(broj, pocetak);
        pocetak = novi; // "stari" pocetak se preusmjerava na novi
        broj_elemenata++;
        if(broj_elemenata == 1) kraj = pocetak; //ako je 1 element u listi, tada je on i kraj i pocetak
    }
    void dodajNaKraj(int broj) {
         if(broj_elemenata == 0) dodajNaPocetak(broj);
         else {
             Cvor *novi = new Cvor(broj, nullptr); //nullptr jer iza njega nema nikog
             kraj->sljedeci = novi;
             kraj = novi;
             broj_elemenata++;
        }
    }
    void ispisi() {
        Cvor* trenutni = pocetak;
        //jer je kraj == nullptr
        while(trenutni != nullptr) {
            cout << trenutni->element << " ";
            trenutni = trenutni->sljedeci;
        }
    }
    void obrisiSaPocetka() {
        if(broj_elemenata == 0) throw "Lista je prazna";
        else if(broj_elemenata == 1) {
                delete pocetak; //brise cvor na koji pokazuje
                pocetak = kraj = nullptr;
                broj_elemenata = 0;
        }
        else {
            Cvor* novi_pocetak = pocetak->sljedeci;
            delete pocetak;
            pocetak = novi_pocetak;
            broj_elemenata--;
        }
    }




};



//reverse iterator
