#include<iostream>
using namespace std;

class MACAdresa {
private:
    int niz[6];
public:
    MACAdresa() {
        for(int i=0; i<6; i++) { niz[i] = 0; }
    }

    MACAdresa(int n[6]) {
        for(int i=0; i<6; i++) { niz[i] = n[i]; }
    }



    operator==(const MACAdresa &m) {
        int brojIstih = 0;
        for(int i=0; i<6; i++) { if(niz[i] == m.niz[i]) brojIstih++; }

        if(brojIstih == 6) return true;
        return false;
    }

    friend ostream &operator<<(ostream &ispis, const MACAdresa &a) {
        return ispis << a.niz[0] << ":" << a.niz[1] << ":" << a.niz[2] << ":"
                    << a.niz[3] << ":" << a.niz[4] << ":" << a.niz[5] << ":"
                    << a.niz[6] << endl;
    }


};



int main() {
    int niz[6] = {0,0,0,0,0,0};
    int niz1[6] = {1,0,0,0,0,0};

    MACAdresa a(niz);
    MACAdresa a1(niz1);

    if(a == a1) cout << "isti su"; else cout << "nisu isti" << endl;


    cout << a;

}
