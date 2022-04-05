#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool postojiLiZbir(vector<double> niz, double x) {
    sort(niz.begin(), niz.end());

    int pocetak = 0, kraj = niz.size()-1;
    while(pocetak != kraj) {
        if(niz[pocetak] + niz[kraj] == x) return true;

        if(niz[pocetak] + niz[kraj] > x) kraj--;
        else pocetak++;

    }

    return false;
}
int main() {

    vector<double> v{7,9,1,3,15,27,33,23};

    cout << postojiLiZbir(v, 32);

}
