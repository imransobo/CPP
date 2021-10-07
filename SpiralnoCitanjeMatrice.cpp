#include<iostream>
using namespace std;

template<typename Tip>
Tip* fd(Tip **A, int m, int n) {
    //niz u koji smjestamo elemente koje dobijemo spiralnim citanjem
    Tip *B = new Tip[m*n];

    int brojac = 0;

    bool desno, doljeUkoso, dolje, goreUkoso;
    desno = true;
    int i=0, j=0;

    B[brojac] = A[i][j];
    brojac++;

    while(true) {
        if(desno) {
            j++; //pomjerio se na A[0][1]
            B[brojac] = A[i][j]; //smjesta trenutni element

            //ako (ni)smo dosli do kraja redova
            if(i == m-1) { goreUkoso = true; }
            else doljeUkoso = true;

            desno = false;
            brojac++;
        }

        else if(doljeUkoso) {
            //sve dok je red<brojRedova-1 i dok nismo na "nultoj" koloni
            while(i<m-1 && j>0) {
                i++; j--;
                //spustamo se ukoso npr sa 2 na 4
                B[brojac] = A[i][j];
                brojac++;

                if(i == m-1) desno = true; //ako smo dosli do zadnjeg reda, idi desno
                else if (j == 0) dolje = true; //ako smo dosli do prve kolone, idi dolje
                doljeUkoso = false;  //ako su gornji uslovi ispunjeni, ne moze ici dolje ukoso
            }
        }

        else if(dolje) {
            i++;
            B[brojac] = A[i][j];
            brojac++;

            if(j == n-1) doljeUkoso = true;
            else goreUkoso = true;

            dolje = false;

        }
        else if(goreUkoso) {
            //sve dok ne dodjemo do prvog reda i zadnje kolone, tj coska.
            while(i>0 && j<n-1) {
                i--; j++;
                B[brojac] = A[i][j];
                brojac++;
            }

            if(j == n-1) dolje = true; //ako smo dosli do zadnje kolone, idemo dolje
            else if(i == 0) desno = true;

            goreUkoso = false;
        }

        //ako smo dosli do zadnjeg elementa u matrici, prekini petlju
        if (i == m-1 && j == n-1) {
            break;
        }

    }

    return B;



}

int main() {

    int m, n;

    cout << "Br. redova: ";
    cin >> m;

    cout << endl << "Br. kolona: ";
    cin >> n;

    int **A = new int*[m];

    //alokacija
    for(int i=0; i<m; i++) {
        A[i] = new int[n];
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cout << "Unesi element: ";
            cin>>A[i][j];
        }
    }





    int *niz = fd(A, m, n);
    for (int i=0; i<m*n; i++) {
        cout<<niz[i]<<" ";
    }




}
