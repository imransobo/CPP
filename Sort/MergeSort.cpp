#include<iostream>
#include<algorithm>

void MergeSort(int *pocetak, int izaKraja) {
    //if(izaKraja-pocetak == 1) return;

    int *sredina = pocetak + (izaKraja-pocetak)/2;

    MergeSort(pocetak, sredina);
    MergeSort(sredina, izaKraja);

    //u vektor smjestamo elemente u sortiranom poretku
    std::vector<int> v;

    int *lP = pocetak, *dP = sredina;

    while(lP != sredina && dP != izaKraja) {
        if(*lp < *dp) {
            v.push_back(*lp); lp++;
        }
        else {
            v.push_back(*dp);
            dp++;
        }

    }
    //ako je "desni" pokazivac tj onaj sto je krenuo sa sredine == izaKraja, onda pomocu "lijevog" dopisi preostale elemente
    if(dP == izaKraja) {
        while(lP != sredina) {
            v.push_back(*lP);
            lp++;
        }
    }
    else {
        while(dP != izaKraja) {
            v.push_back(*dP);
            dP++;
        }
    }


    for(int i=0; i<v.size(); i++) {
        *(pocetak+i) = v[i];
    }

}

int main() {
    int n;
    std::cin >> n;

    int niz[n];


    MergeSort(niz, niz+n);

    for(int i=0; i<n; i++) std::cout << niz[i] << " ";


    return 0;
}
