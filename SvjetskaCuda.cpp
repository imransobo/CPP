#include<iostream>
#include<vector>
#include<memory>
using namespace std;


class Cudo {
public:
    string naziv;
    pair<string, string> lokacija;
    int godina_pronalaska;

    //Cudo c1
    Cudo(string naziv, pair<string, string> lokacija, int godina_pronalaska): naziv(naziv), lokacija(lokacija), godina_pronalaska(godina_pronalaska) {};

    //Cudo c2
    Cudo(string naziv, string drzava, string grad, int godina_pronalaska) : naziv(naziv), lokacija({drzava, grad}), godina_pronalaska(godina_pronalaska) {};

    friend class SvjetskaCuda;




};


class SvjetskaCuda {
public:
    vector<shared_ptr<Cudo>> cuda;

    //SvjetskaCuda unesco;
    SvjetskaCuda() {};


    //unesco.Dodaj(c1)
    void Dodaj(const Cudo &c) { cuda.push_back(make_shared<Cudo> (c)) ;}

    //unesco.Dodaj("Piramide......");
    void Dodaj(string naziv, pair<string, string> lokacija, int godina_pronalaska) {
        cuda.push_back(shared_ptr<Cudo>(new Cudo(naziv, lokacija, godina_pronalaska)));
    }


    void operator +=(const Cudo &c) { Dodaj(c); }



    //SvjetskaCuda(const Cudo&& c) { cuda = move(c.cuda); }
    int& operator[](string naziv) {
        for(int i=0; i<cuda.size(); i++){
            if(cuda[i] -> naziv == naziv) return cuda[i] -> godina_pronalaska;

        }

    }

};




int main() {


    SvjetskaCuda unesco;
    Cudo c1("Mehina kafana", {"BiH", "Sarajevo, Sedrenik"}, 2016);
    Cudo c2("Piramida", {"BiH", "Visoko"}, 2005);
    unesco.Dodaj("Piramida", {"BiH", "Visoko"},2005);
    unesco.Dodaj(c1);
    unesco += c2;
    SvjetskaCuda kopija(unesco);
    SvjetskaCuda kopija2(move(kopija));






}
