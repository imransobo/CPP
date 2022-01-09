#include<iostream>
using namespace std;

//prima dinamicki alociranu matricu M, broj elemenata matrice, broj vrsta matrice
// i koordinate elementa (i,j), vraca zbir elemenata koji se nalaze na
//lijevoj i desnoj dijagonali elementa (i,j) ne ukljucujuci taj element.
template<typename Tip>
Tip f(Tip **M, int n, int v, int i, int j) {
    int redovi = n / v;
    
    int sumaIspodElementa = 0;
    for(int a=i; a<redovi; a++) {
        for(int b=j; b<v; b++) {
            if((b+1)-(a+1)== 1) sumaIspodElementa += M[a][b];
        }
    }
    sumaIspodElementa -= M[i][j];


  
    int sumaIznadElementa = 0;
    for(int a=i; a>=0; a--) {
        for(int b=j; b>=0; b--) {
            if( (b-1)- (a-1) == 1 ) sumaIznadElementa += M[a][b];
        }
    }
    sumaIznadElementa -= M[i][j];


    //1 dijagonala
    int dijagonala = sumaIspodElementa + sumaIznadElementa;


    //-------------------------------------------------------------------

    int sumaIznadElementa2 = 0;
    for(int a=i; a<redovi; a++) {
        for(int b=j; b<v; b++) {
            if( (b+1) + (a-1) == 3) sumaIznadElementa2 += M[a-1][b+1];
        }
    }
    sumaIznadElementa2 -= M[i][j];


  
    int sumaIspodElementa2 = 0;

    for(int a=i; a<redovi; a++) {
        for(int b=j; b>=0; b--) {
            if((a+1) + (b-1) == 3) sumaIspodElementa2 += M[a][b];
        }
    }
    sumaIspodElementa2 -= M[i][j];

    int dijagonala2 = sumaIznadElementa2 + sumaIspodElementa2;

    int zbirDijagonala = dijagonala + dijagonala2;

    return zbirDijagonala
    ;



}



int main() {
    int redovi, vrste;

    cout << "Unesi br. redova: ";
    cin >> redovi;

    cout << endl << "Unesi broj vrsti: ";
    cin >> vrste;

    int n = redovi*vrste;

    int **matrica =  new int*[redovi];

    for(int i=0; i<redovi; i++){
        matrica[i] = new int[vrste];
    }

    for(int i=0; i<redovi; i++) {
        for(int j=0; j<vrste; j++) {
            cout << "Unesi element : ";
            cin >> matrica[i][j];
            cout << endl;
        }
    }

    cout << f(matrica, n, vrste, 1, 2);




    for(int i=0; i<redovi; i++) {
        delete matrica[i];
    }
    delete []matrica;





}
