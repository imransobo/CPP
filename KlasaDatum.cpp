#include<iostream>
using namespace std;


class Datum {
private:
    int dan;
    int mjesec;
    int godina;

    bool neispravanDatum(int dan, int mjesec, int godina) {
        if(dan < 1 || dan > 31 || mjesec < 1 || mjesec > 12 || godina <=0) return true;
        return false;
    }

public:
    Datum(int d, int m, int g) {
        if(neispravanDatum(d, m, g)) {
            cout << "Datum je u neispravnom obliku";
        }

        dan = d;
        mjesec = m;
        godina = g;

    }

    int getDan() { return dan; }
    int getMjesec() { return mjesec; }
    int getGodina() { return godina; }

    bool operator==(const Datum& d) {
        if(dan == d.dan && mjesec == d.mjesec && godina == d.godina) return true;
        return false;
    }

    bool operator!=(const Datum &d) {
        if(d.dan != dan || d.mjesec != mjesec || d.godina != godina) return false;
        return true;
    }

    friend ostream &operator<<(ostream &ispis, const Datum &d) {
        ispis << d.dan << "." << d.mjesec << "." << d.godina;
        return ispis;
    }



};



int main() {
    Datum d1(10, 10, 2000);
    Datum d2(10, 10, 2000);

    cout << "Datum 1: " << d1 << endl;
    cout << "Datum 2: " << d2 << endl;

    if(d1 == d2) cout << "Jednaki su"; else cout << "Nisu jednaki";

}
