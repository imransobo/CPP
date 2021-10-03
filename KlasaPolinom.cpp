#include<iostream>
#include<cmath>

using namespace std;



class Polinom {

private:
    int stepen;
    double *koeficijent;
public:
    Polinom();
    Polinom(int n, double* niz);
    Polinom(int n);
    Polinom(const Polinom& a);

    Polinom& operator=(const Polinom& a);

    ~Polinom() { delete[] koeficijent;}

    int vratiStepen() const {return stepen;}
    double Evaluiraj(double x) ;

    friend bool operator==(const Polinom& a, const Polinom& b);




};

Polinom::Polinom() : stepen(0) {
    koeficijent = new double(0);

}


Polinom::Polinom(int n, double* niz) : stepen(n) {
    koeficijent = new double[stepen + 1];
    for(int i=0; i<=stepen; i++){
        koeficijent[i] = niz[i];
    }
}

Polinom::Polinom(int n) : stepen(n) {
    koeficijent = new double[n+1];
}

double Polinom::Evaluiraj(double x)  {
    double suma = 0;
    for(int i=0; i<=stepen; i++) suma += koeficijent[i] * (pow(x,i));

    return suma;

}

Polinom::Polinom(const Polinom& a) : stepen(a.stepen) {
    koeficijent = new double[stepen+1];
    for(int i=0; i<=stepen; i++) koeficijent[i] = a.koeficijent[i];


}



bool operator==(const Polinom& a, const Polinom& b){
    if(a.stepen != b.stepen) return false;


    for(int i=0; i<=a.stepen; i++)
        if(a.koeficijent[i] != b.koeficijent[i]) return false;

    return true;

}

Polinom Polinom::operator-{
    Polinom izvod( (this->stepen) - 1);
    for(int i=0; i<=izvod.stepen; i++) {
        izvod.koeficijent[i] =  (this->koeficijent [i+1]) *(i+1);
    }


    return izvod;
}


Polinom operator+(const Polinom& a, const Polinom& b) {
    int m = min(a.stepen, b.stepen);
    Polinom zbir;

    if(a.stepen > b.stepen) {
        zbir = a;
        for(int i=0; i<=b.stepen; i++) zbir.koeficijent[i] += b.koeficijent[i];
    }
    else {
        zbir = b;
        for(int i=0; i<=a.stepen; i++) zbir.koeficijent[i] += a.koeficijent[i];

    }


}



int main(){

    Polinom b;

    double niz[4] = {1, 3, 0, -5};
    Polinom a(3, &niz[0]);

    Polinom c(a);




    return 0;
}
