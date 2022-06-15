#include <iostream>
#include <cmath>
using namespace std;


class VektorNd {
private:
    int dimenzija;
    int *pok;

public:


    int getDimenzija() { return dimenzija; }
    void setDimenzija(int d) { this->dimenzija = d; }

    // b)
    explicit VektorNd(int dim, int inicijalna=0) {
        dimenzija = dim;
        pok = new int[dimenzija];

        for(int i=0; i<dimenzija; i++) {
            pok[i] = inicijalna;
        }

    }

    // c)
    VektorNd(int dim, int niz[]) {
        dimenzija = dim;
        pok = new int[dimenzija];

        for(int i=0; i<dimenzija; i++) {
            pok[i] = niz[i];
        }

    }

    // d) -> destruktor
    ~VektorNd() {
        delete [] pok;
    }


    // e) -> konstr kopije i preklopljeni operator dodjele

    VektorNd(const VektorNd& v1) {
        dimenzija = v1.dimenzija;

        for(int i=0; i<dimenzija; i++) {
            pok[i] = v1.pok[i];
        }
    }


    VektorNd& operator=(const VektorNd& v1) {
        dimenzija = v1.dimenzija;

        pok = new int[dimenzija];

        for(int i=0; i<dimenzija; i++) {
            pok[i] = v1.pok[i];
        }
    }

    // f) je getter za dimenziju, ima


    // g)
    int getKoordinata(int indeks) {

        for(int i=0; i<dimenzija; i++) {
            if(i == indeks) { return pok[i]; }
            else throw "Nije validan indeks!";  //moze i throw
        }

    }


    // h) -> metoda sa 2 parametra, postavlja zadanu koordinatu vektora na zadanu vrijednost
    void setKoordinata(int indeks, int element) {
        for(int i=0; i<dimenzija; i++) {
            if(i == indeks) { pok[i] = element; }
            else throw "Opseg nije validan!";
        }
    }

    // i) metoda koja vraca duzinu vektora -> kvadr korijen iz sume kvadrata svih koordinata
    int getDuzina() {
        int suma = 0;

        for(int i=0; i<dimenzija; i++) {
            suma += sqrt(i);
        }

        return sqrt(suma);
    }



    // j) prijateljska funkcija sa jednim parametro koja vraca duzinu vektora
    // koji je zadan parametrom

    friend int getDuzina(const VektorNd& v1) {
        int suma = 0;
        for(int i=0; i<v1.dimenzija; i++) {
            suma += sqrt(i);
        }

        return sqrt(suma);
    }




    // k) metoda bez parametra koja daje rang vektora , odnosno broj koordinata koje su razlicite od nule
    int getRangVektora() {
        int broj = 0;
        for(int i=0; i<dimenzija; i++) {
            if(pok[i] != 0) { broj++;}
        }

        return broj;
    }



    // l) metoda sa jednim prametrom koja vrsi promjenu dimenzionalnosti vektora na novu vrijednost
    // nejasan zadatak


    // m) preklopi operator << za ispis vektora

    friend ostream &operator<<(ostream& ispis, const VektorNd &v1) {
        ispis << "{";

        for(int i=0; i<v1.dimenzija; i++) {
            ispis << v1.pok[i];
            if(i != v1.dimenzija - 1) {
                ispis << ",";
            }
        }

        ispis << "}";
        return ispis;

    }


    // n) preklopi + i - za sabiiranje i oduzimanje dva vektora

    VektorNd operator+(const VektorNd& v) {
        VektorNd t(v.dimenzija);

        if(this->dimenzija != v.dimenzija) { throw "Dimenzije vektora nisu iste!"; }
        else {
            for(int i=0; i<v.dimenzija; i++) {
                t.pok[i] = this->pok[i] + v.pok[i];
            }

            return t;
        }
    }

     VektorNd operator-(const VektorNd& v) {
        VektorNd t(v.dimenzija);

        if(this->dimenzija != v.dimenzija) { throw "Dimenzije vektora nisu iste!"; }
        else {
            for(int i=0; i<v.dimenzija; i++) {
                t.pok[i] = this->pok[i] - v.pok[i];
            }

            return t;
        }
    }



    // o) preklopi operator * za mnozenje
    VektorNd operator*(int n) {

        VektorNd v1(dimenzija, 1);

        if( n != 0) {
            for(int i=0; i<dimenzija; i++) {
                v1.pok[i] *= n;
            }

            return v1;
        }

        else {
            throw "Nemoguce mnoziti vektor sa nulom";
        }
    }


    int operator*(const VektorNd& v1) {
        int trenutni = 1;
        int konacno = 0;
        if(dimenzija == v1.dimenzija) {
            for(int i=0; i<v1.dimenzija; i++) {
                trenutni = pok[i] * v1.pok[i];
                konacno += trenutni;
            }
            return konacno;
        }
         else {
            throw "Nemoguce pomnoziti dva vektora, nisu iste dimenzije";
        }

    }


    // p) preklopi operatore +=, -=, *=

    int operator*=(const VektorNd &v1) {
        int trenutni = 1;
        int konacno = 0;
        if(dimenzija == v1.dimenzija) {
            for(int i=0; i<v1.dimenzija; i++) {
                trenutni = pok[i] * v1.pok[i];
                konacno += trenutni;
            }
            return konacno;
        }
         else {
            throw "Nemoguce pomnoziti dva vektora, nisu iste dimenzije";
        }
    }


    VektorNd operator+=(const VektorNd &v1) {

        VektorNd t(v1.dimenzija);

        if(this->dimenzija != v1.dimenzija) { throw "Dimenzije vektora nisu iste!"; }
        else {
            for(int i=0; i<v1.dimenzija; i++) {
                t.pok[i] = this->pok[i] + v1.pok[i];
            }

            return t;
        }

    }

    VektorNd operator-=(const VektorNd &v1) {

        VektorNd t(v1.dimenzija);

        if(this->dimenzija != v1.dimenzija) { throw "Dimenzije vektora nisu iste!"; }
        else {
            for(int i=0; i<v1.dimenzija; i++) {
                t.pok[i] = this->pok[i] - v1.pok[i];
            }

            return t;
        }

    }


    /*VektorNd operator++(){
        for(int i=0; i<dimenzija; i++) {
            this->pok[i] = this->pok[i] + 1;
        }

        return VektorNd();


    } */



    bool operator!() const {
        int brojac = 0;
        for(int i=0; i<dimenzija; i++) {
            if(pok[i] == 0) brojac++;
        }

        if(brojac == dimenzija) { return true; }
        else {
            return false;
        }
    }


    bool operator==(const VektorNd& v1) {
        int brojac = 0;
        bool isti = true;

        if(dimenzija == v1.dimenzija) {
            for(int i=0; i<dimenzija; i++) {
                if(this->pok[i] == v1.pok[i]) {
                    brojac++;
                }
            }

            if(brojac == dimenzija) {
                return isti;
            }
            else {
                return !isti;
            }
        }
        else {
            return !isti;
        }


    }


    bool operator!=(const VektorNd& v1) {
        int brojac = 0;
        bool isti = true;

        if(dimenzija == v1.dimenzija) {
            for(int i=0; i<dimenzija; i++) {
                if(this->pok[i] == v1.pok[i]) {
                    brojac++;
                }
            }

            if(brojac != dimenzija) {
                return isti;
            }
            else {
                return !isti;
            }
        }
        else {
            return isti;
        }


    }







};

int main() {

    VektorNd v1(5,5);
    VektorNd v5(5,5);
    VektorNd v2(5,10);
    VektorNd v3(5);
    VektorNd v4(12, 3);
    VektorNd nul(10,0);
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;

    cout << v1 + v2 << endl;
    cout << v1 - v2 << endl;


    try {
        cout << v1 + v4 << endl;
    }catch (...) {
        cout << "Nemoguce sabrati, vektori nisu iste dimenzije!" << endl;
    }


    cout << v1 * 3 << endl;

    try {
        cout << v1 * v2 << endl;
    }catch(...) {
        cout << "Nemoguce pomnoziti dva vektora, nisu iste dimenzije!" << endl;
    }


    cout << !nul << endl;
    bool isti = v1 == v5;
    bool isti2 = v1 == v2;
    cout << isti << endl;
    cout << isti2 << endl;

//    cout << v4++ << endl;





}
