#include<iostream>
#include<algorithm>

void BubbleSort(int *niz, int n) {
    int pom(0);
    int brojac(0);
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(niz[j] > niz[j+1]) std::swap(niz[j], niz[j+1]);
        }
    }

}

int main() {

    int n(0);

    std::cout << "Unesi velicinu niza: " << std::endl;
    std::cin >> n;

    int niz[n];

    for(int i=0; i<n; i++) std::cin >> niz[i];

    BubbleSort(niz, n);

    for(int i=0; i<n; i++) std::cout << niz[i];

    return 0;
}
