#include<iostream>
using namespace std;


class Polje
{
public:
    char kolona;
    int red;
    //konstr. sa 2 parametra
    Polje(char k, int r)
    {
        if(int(k) > 'H' || int(k) < 'A') throw "Kolona nije validna";
        if(r < 1 || r > 8) throw "Red nije validan";
        kolona = k;
        red = r;
    }
    Polje() { }

    //getteri
    char getKolona()
    {
        return kolona;
    }
    int getRed()
    {
        return red;
    }

    //provjerava jesu li dva polja jednaka
    operator==(const Polje &a)
    {
        if(a.kolona == kolona && a.red == red) return true;
        return false;
    }

    //provjerava jesu li dvije figure na istoj dijagonali
    operator/(const Polje &a) {}

    //provjerava jesu li dvije figure u istom redu ili u istoj koloni
    operator+(const Polje &a)
    {
        if(a.red == red || a.kolona == kolona) return true;
        return false;
    }

};
enum boje {BIJELA, CRNA};

class Boja
{
protected:
    boje b;
public:
    Boja() { }
    Boja(boje boje)
    {
        b = boje;
    }

};



class Figura
{
protected:
    Boja b;
    Polje p;
    char oznakaFigure;
    int vrijednostFigure;
public:
    virtual ~Figura() {}

    Figura(Boja boja, Polje polje)
    {
        b = boja;
        p = polje;
    }

    Boja getBoja()
    {
        return b;
    }
    Polje getPolje()
    {
        return p;
    }

    //moze li se pomaknuti sa trenutnog polja na neko drugo
    virtual void mozePolje() = 0;
    //moze li jedna figura "pojesti" drugu figuru
    virtual void mozeFigura() = 0;

    //vraca jednoslovnu oznaku figure
    virtual oznaka() = 0;
    //vraca cjelobrojnu vrijednost figure
    virtual vrijednost() = 0;
    //vraca kopiju klase koja se iz nje derivira
    virtual kopiraj() = 0;
    //uporedivanje dvije figure na osnovu njihovih vrijednosti
    operator>(const Figura &f)
    {
        if(f.vrijednostFigure > vrijednostFigure) return true;
        return false;
    }

    friend ostream &operator<<(ostream &ispis, const Figura &f)
    {
        //implementiraj poslije
        return ispis;
    }




};

class Top : public virtual Figura
{
private:
    char oznakaFigure = 'T';
    int vrijednostFigure = 5;
public:
    Top(Boja b, Polje p) : Figura(b, p) {};
    //krece se samo vertikalno po koloni i horizontalno po redovima
    virtual void mozePolje(Polje p1)
    {
        if(p.red != p.red) cout << "Top se krece samo po istom redu";
        if(p.kolona != p1.kolona) cout << "Top se krece samo po istoj koloni";
    }

    virtual oznaka()
    {
        return oznakaFigure;
    }

    virtual vrijednost()
    {
        return vrijednostFigure;
    }

    //implementiraj poslije
    virtual kopiraj() { }


};


class Lovac: public virtual Figura
{
private:
    char oznakaFigure = 'L';
    int vrijednostFigure = 3;
public:
    //poziva bazni konstruktor i inicijalizira vrijednosti na zadane
    Lovac(Boja b, Polje p) : Figura(b, p) {};
    //krece se samo dijagonalno, implementiraj poslije
    virtual void mozePolje(Polje p1) { }

    virtual oznaka()
    {
        return oznakaFigure;
    }

    virtual vrijednost()
    {
        return vrijednostFigure;
    }

    //implementiraj poslije
    virtual kopiraj() { }


};


class Skakac: public virtual Figura
{
private:
    char oznakaFigure = 'S';
    int vrijednostFigure = 2;
public:
    Skakac(Boja b, Polje p) : Figura(b, p) {};
    //pomjera se za
    //dvije kolone i jedan red ILI
    //jednu kolonu i dva reda
    virtual void mozePolje(Polje p1)
    {
        bool prviSlucaj = false;
        bool drugiSlucaj = false;
        if(int(p.kolona) - int(p1.kolona) == 2 && p.red - p1.red == 1)
        {
            prviSlucaj = true;
            cout << "Ispravan potez";
        }
        else if(int(p.kolona) - int(p1.kolona) == 1 && p.red - p1.red == 2)
        {
            drugiSlucaj = true;
            cout << "Ispravan potez";
        }
        else cout << "Neispravan potez";
    }

    virtual oznaka()
    {
        return oznakaFigure;
    }
    virtual vrijednost()
    {
        return vrijednostFigure;
    }
    //implementiraj poslije
    virtual kopiraj() { }


};

class Tabla {
private:
    int **figure;
    //popuni matricu sa figurama koje se proslijede kroz parametar
    //poslije premjesti metode izvan klase
    void kopiraj(int **f) {
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                figure[i][j] = f[i][j];
            }
        }
    }
    //popunjava matricu s elementima iz matrice proslijedene kroz parametar
    //namjesti ih na nullptr
    void premjesti(int **f) {
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                figure[i][j] = f[i][j];
            }
        }

        for(int i=0; i<64; i++) figure[i] = nullptr;
    }

    void obrisi() {
        int brojac(0);
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; i++) {
                //provjeri jos
                if(figure[i][j] == NULL) brojac++;
            }
        }
        if(brojac == 64) {
            for(int i=0; i<8; i++) {
                delete figure[i];
            }
            delete [] figure;
        }
    }


public:

    //elementi matrice su pokazivaci na klasu Figura
    //format 8x8
    Tabla() {
        figure = new int*[8];
        for(int i=0; i<8; i++) figure[i] = nullptr;
    }

    //nastavak...

};






int main()
{




}
