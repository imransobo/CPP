#include<iostream>
#include<list>
using namespace std;


class RGBBoja {
private:
    int x;
    int y;
    int z;
    void baciIzuzetak() { throw "Vrijednost parametra nije validna"; };
public:
    RGBBoja(int x=255, int y=255, int z=255) {
        if(x<0 || x>255 || y<0 || y>255 || z<0 || z>255) baciIzuzetak();
        this->x = x; this->y = y; this->z = z;
    }
    int getX() { return x; }
    int getY() { return y; }
    int getZ() { return z; }

    void setX(int x) { if(x>=0 || x<255) this->x = x; }
    void setY(int y) { if(y>=0 || y<255) this->y = y; }
    void setZ(int z) { if(z>=0 || z<255) this->z = z; }

    friend bool operator==(const RGBBoja &a, const RGBBoja &b) {
        if(a.x != b.x || a.y != b.y || a.z != b.z) return false;
        return true;
    }



};


class Element {
private:
    RGBBoja boja;
public:
    //konstr. sa jednim parametrom, ako mu se nista ne proslijedi postavlja vrijednost na bijelu
    Element(const RGBBoja &b = RGBBoja()) : boja(b) {};

    void izmijeniBoju(const RGBBoja &b = RGBBoja()) {
        this->boja = b;
    }
    RGBBoja getBoja() { return boja; }

    ostream& operator<<(ostream &ispis) {
        ispis << "[" << boja.getX() << "," << boja.getY() << "," << boja.getZ()<< "]";
        return ispis;
    }


};


class Slika {
private:
    //poslije premjesti izvan klase
    void kopiraj(const Slika &kopija) {
        matrica = new Element*[kopija.vrste];
        for(int i = 0; i<kopija.vrste; i++) {
            Element *r = new Element[kopija.kolone];
            for(int j=0; j<kopija.kolone; j++) {
                r[j] = kopija.matrica[i][j];
            }
            matrica[i] = r;
        }
        kolone = kopija.kolone;
        vrste = kopija.vrste;
        boja = kopija.boja;
    }
    void pomjeri(Slika s) {
        vrste = s.vrste;
        kolone = s.kolone;
        matrica = s.matrica;
        boja = s.boja;
        s.vrste = 0;
        s.kolone = 0;
        s.matrica = nullptr;
    }
    void obrisi() {
        for(int i=0; i<vrste; i++) delete matrica[i];
        delete[] matrica;
    }

protected:
    RGBBoja boja;
    Element **matrica;
    int vrste;
    int kolone;
public:
    Slika(int vr=5, int kol=5, RGBBoja b = RGBBoja()) {
        vrste = vr; kolone = kol;
        matrica = new Element*[vrste];
        for(int i=0; i<vrste; i++) {
            Element *r = new Element[kolone];
            for(int j=0; j<kolone; j++) {
                r[i] = boja;
            }
            matrica[i] = r;
        }
    }

    virtual void promijeniBoju(RGBBoja boja, int vr, int kol) {};
    int getVrste() { return vrste; }
    int getKolone() { return kolone; }

    Element operator()(int i, int j) {
        if(i<0 || i>vrste || j<0 || j>kolone) throw "Indeksi nisu validni";
        return matrica[i][j];
    }

    ostream& operator<<(ostream &ispis) {
       //ispis << boja << endl;
        ispis << vrste << endl;
        ispis << kolone << endl;
        return ispis;
    }

    //konstr. kopije
    Slika(const Slika &kopija) { this->kopiraj(kopija); }
    //pomjerajuci konstruktor
    Slika(Slika &&s) { this->pomjeri(s); }
    //destruktor
    ~Slika() { this->obrisi(); }


};

class CrnoBijela: public Slika {
public:
    void baciIzuzetak() { throw "Boja moze biti ili crna ili bijela."; }
    //osiguravamo da ce boja biti ili crna ili bijela, u suprotnom bacamo izuzetak
    CrnoBijela(int x, int y, int z=255) {
       if(x==0 && y==0 && z==0 || x==255 && y==255 && z==255) {
            boja.setX(x);
            boja.setY(y);
            boja.setZ(z);
       }
       else baciIzuzetak();
    }

    virtual void promijeniBoju(int x, int y, int z) {
        if(x != 0 || x != 255 || y != 0 || y != 255 || z != 0 || z != 255) throw "Neispravna boja";
        this->boja.setX(x);
        this->boja.setY(y);
        this->boja.setZ(z);
    }
};

class Siva : public Slika {
public:
    void baciIzuzetak() { throw "Boja nije siva"; }
    Siva(int x, int y, int z) {
        if(x==y==z) {
            this->boja.setX(x);
            this->boja.setY(y);
            this->boja.setZ(z);
        }
        else baciIzuzetak();
    };

    virtual void promijeniBoju(int x, int y, int z) {
        if(x != y || x != z || y != z) throw "Neispravna boja";
        this->boja.setX(x);
        this->boja.setY(y);
        this->boja.setZ(z);

    }

};

class Lista {
protected:
    list<int> lista;
public:
    //zabrani kopiranje
    Lista() = delete;
    Lista(const Lista &kopija) = delete;

    //dodavanje elementa u listu pomocu operatora +=
    void operator+=(const int &dodaj) {
        this->lista.push_back(dodaj);
    }


    friend ostream& operator<<(ostream &ispis, const Lista &l) {
        for(const auto& i: l.lista) ispis <<  i << endl;

        return ispis;
    }
};

class Galerija : public Lista {
public:


};


class Filter {
public:
    friend class Galerija;

};

class InvertirajuciFilter : public Filter {


};



int main() {

    Slika s1(1,1);


}
