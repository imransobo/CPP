#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

struct Prava {
    double k; //koeficijent pravca
    double n; //odsjecak na y osi
    Prava(double k1, double n1) : k(k1), n(n1) {};
};

struct Kvadrat {
    //koordinate gornjeg lijevog ugla
    double x;
    double y;
    double a; //duzina stranice
    Kvadrat(double x1, double y1, double a1) : x(x1), y(y1), a(a1) {};
};

struct Kruznica {
    double x,y; //koordinate centra
    double r;   //poluprecnik
    Kruznica(double x1, double y1, double r1) : x(x1), y(y1), r(r1) {};
};

void procitajDatoteku(string nazivFajla) {
    vector<Prava*> prave;
    vector<Kvadrat*> kvadrati;
    vector<Kruznica*> kruznice;

    //citamo iz fajla
    ifstream citac(nazivFajla);

    //kruznica
    int k,n, brojac(0);

    //kvadrat, kruznica
    int x,y,a;

    string znak;
    int r;

    //peek() gleda koji je iduci znak, ali ga ne uklanja iz toka
    while(citac.peek() != '\n') {
        if(citac.peek() != ' ') {
            znak = citac.get(); //uzimamo zarez
            k = stoi(znak); //smjesti koeficijent pravca

            citac.get(); //uzima prazno mjesto

            znak = citac.get();
            n = stoi(znak); //uzima odsjecak na y osi

            prave.push_back(new Prava(k, n));
            brojac++;
        }
        else {
            citac.get();
        }
    }
    //uklanja \n
    citac.get();

    while(citac.peek() != '\n') {
        if(citac.peek() != ' ') {
            znak = citac.get();
            x = stoi(znak);  //koordinate gornjeg lijevog ugla -> x

            citac.get();

            znak = citac.get();
            y = stoi(znak);  //koordinate gornjeg lijevog ugla -> y

            citac.get();

            znak = citac.get();
            a = stoi(znak);

            kvadrati.push_back(new Kvadrat(x, y, a));
            brojac++;
        }
        else  {
            citac.get();
        }
    }
    citac.get();

    while(citac.peek() != '\n') {
        if(citac.peek() != ' ') {
            znak = citac.get();
            x = stoi(znak);

            citac.get();

            znak = citac.get();
            y = stoi(znak);

            citac.get();

            znak = citac.get();
            r = stoi(znak);

            kruznice.push_back(new Kruznica(x, y, r));
            brojac++;
        }
        else {
            citac.get();
        }
    }

    citac.get();

    citac.close();


    for(int i=0; i<prave.size(); i++) {
        cout << prave[i]->k << ", " << prave[i]->n << " ";
    }
    cout << endl;


    for(int i=0; i<kvadrati.size(); i++) {
        cout << kvadrati[i]->x << ", " << kvadrati[i]->y << ", " << kvadrati[i]->a << " ";
    }
    cout << endl;

    for(int i=0; i<kruznice.size(); i++) {
        cout << kruznice[i]->x << ", " << kruznice[i]->y << ", " << kruznice[i]->r << " ";
    }
    cout << endl;




    ofstream upis("IzvjestajGO.dat.txt");
    upis << brojac;
    upis.close();

}

int main() {

    procitajDatoteku("GO.dat.txt");


    return 0;
}
