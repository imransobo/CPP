#include<iostream>
#include<vector>

using namespace std;

int nedostajuciElement(vector<int> &niz) {
    int d = (niz[niz.size()-1] - niz[0]) / niz.size();
    int pocetak = 0, kraj = niz.size()-1;

    while(kraj-pocetak > 1) {
        int sredina = (pocetak+kraj) / 2;
        if(niz[sredina] - niz[pocetak] == d*(sredina-pocetak));
            pocetak = sredina;
        else kraj = sredina;

    }

    return niz[pocetak] + d;

}


//rekurzivno
int nedostajuciElementRek(int *pocetak, int *kraj, int d) {
    if(kraj - pocetak == 1}
        return *pocetak + d;

    int*sredina = pocetak + (kraj-pocetak) / 2;

    if(*sredina - *pocetak == d*(sredina-pocetak))
        return nedostajuciElementRek(sredina, kraj, d);

    else return nedostajuciElementRek(pocetak, sredina, d);
}

int nedostajuciElement2(vector<int> &niz) {
    int d = (niz[niz.size()-1] - niz[0]) / niz.size();
    return nedostajuciElementRek(&niz[0], &niz[niz.size()-1], d);
}


int main() {



}
