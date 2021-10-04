#include<iostream>
using namespace std;

bool jeLiToeplitz(int **matrica, int m, int n) {
        for(int i=0; i<m-1; i++) {
            for(int j=0; j<n-1; j++) {
                if(matrica[i][j] != matrica[i+1][j+1]) return false;
            }
        }
        return true;
    }

int main() {

    int m(0), n(0);

    cout << "Unesi broj redova: ";
    cin >> m;

    cout << endl << "Unesi broj kolona: ";
    cin >> n;




    int **matrica = new int*[m];
    for(int i=0; i<m; i++) { matrica[i] = new int[n]; }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout << "Unesi element na poziciji [" << i << "]" << "[" << j << "]. ";
            cin >> matrica[i][j];
        }
    }



    if(jeLiToeplitz(matrica, m, n)) cout << "Matrica je Toeplitz";
    else cout << "Nije Toeplitz.";




}
