#include<iostream>
#include<vector>

using namespace std;

class Naljepnica {
private:
    static int ID;
    //instanciranjem objekta tipa Naljepnica uvecava se za 1
    int id;
    string naziv;

public:
    Naljepnica() { }

    Naljepnica(string n) {
        naziv = n;
        id = ++ID;
    }

    Naljepnica(const Naljepnica &kopija) {
        naziv = kopija.naziv;
        id = kopija.id;
    }

    Naljepnica &operator=(const Naljepnica &originalni) {
        naziv = originalni.naziv;
        id = originalni.id;
        return (*this);
    }

    friend ostream &operator<<(ostream &it, const Naljepnica &n) {
        it << n.naziv << ":" << n.id << endl;
        return it;
    }

    //potrebno dodati const, kada pozivamo metodu getNaziv()
    //koja je "nekonstantna" nad "konstantnim" objektom
    //kompajler javlja gresku, tj nema garancije da nece biti modifikacije nad objektom
    string getNaziv() const { return naziv; }
    int getID() const { return ID; }

    //setteri
    void setNaziv(string n) { naziv = n; }
    void setID(int id) { ID = id; }

    void ispisiNaljepnicu() {
        cout << naziv << ", " << id;
    }




};

int Naljepnica::ID = 0;

enum VRSTA { BEZALKOHOLNA, ALKOHOLNA };


class Flasa {
private:
    virtual void pisi();
protected:
    Naljepnica naljepnica;
    VRSTA vrsta;
    float zapremina;
    int cijena;

public:
    Flasa() {
        //vrsta = BEZALKOHOLNA;
        //zapremina = 0.33;
    }
    Flasa(Naljepnica n, VRSTA v, float z, int c) {
        naljepnica = n;
        vrsta = v;
        zapremina = z;
        cijena = c;

    }

    Naljepnica getNaljepnica() { return naljepnica; }
    VRSTA getVrsta() { return vrsta; }
    float getZapremina() { return zapremina; }
    int getCijena() { return cijena; }

    void setCijena(int c) { cijena = c; }

    virtual void cijenaSaKaucijom() = 0;

    //flase su iste ako su im isti naziv, cijena sa kaucijom i ista vrsta pica.
    bool operator==(const Flasa &f) {
        if(f.naljepnica.getNaziv() != naljepnica.getNaziv() &&
           f.cijena != cijena && f.vrsta != vrsta) return false;
        return true;
    }

    //inace treba pozivati metodu pisi(), uradi kasnije
    friend ostream& operator<<(ostream &ispis, const Flasa &f) {
        ispis << f.cijena << ", " << f.zapremina << ", " << f.vrsta << endl;
        return ispis;
     }


};
void Flasa::pisi() {

}
//defaultna vrijednost
//VRSTA Flasa::vrsta = BEZALKOHOLNA;
//float Flasa::zapremina = 0.33;

class Staklena : public Flasa {
public:
    //cijena s kaucijom -> dodaj 5% na cijenu bez kaucije ako je 0.33
    //ako je 0.5 onda 10%
    void cijenaSaKaucijom() {

    }
    void pisi() {

    }
};


class Plasticna : public Flasa {
public:
    //kod plasticne je cijena s kaucijom == cijeni bez kaucije
    void cijenaSaKaucijom() {

    }

    void pisi() {

    }


};

class Diskont {
private:
    string naziv;
    vector<Flasa*> elementi;
public:
    //inicijalizira prazan diskont sa imenom
    Diskont(string n) {
        naziv = n;
        vector<Flasa*> elementi;
    }

    ~Diskont() { elementi.clear(); }

    //zabrani kopiranje
    Diskont() = delete;
    Diskont(const Diskont &kopija) = delete;

    //?
    operator+=(const Flasa &f) {

    }

    operator[](int indeks) {

    }

};






int main() {

    Naljepnica n("cocacola");
    Naljepnica n1("fanta");

    n.ispisiNaljepnicu();
    n1.ispisiNaljepnicu();


    cout << endl;

    //kopija
    Naljepnica n2(n);
    n2.ispisiNaljepnicu();

    cout << endl;
    //dodjela
    n = n1;
    n.ispisiNaljepnicu();

    cout << endl;
    //ispisivanje naljepnice
    cout << n;

    Diskont d("diskont1");

    //d += f;







}
