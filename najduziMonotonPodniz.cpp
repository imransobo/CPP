#include<iostream>
#include<vector>
using namespace std;

template <typename Tip>
vector<Tip> f(vector<Tip> v) {

    vector<vector<Tip>> m;

    for(int i=0; i<v.size()-1; i++) {
        vector<Tip> x;
        int j = i;
        while(j < v.size() - 1) {
            if( v[j] <= v[j+1]) x.push_back(v[j]);
            else {
                if(v[j] >= v[j-1]) x.push_back(v[j]);
                break;};
            ++j;

        }
        m.push_back(x);
    }



    for(int i=0; i<v.size()-1; i++) {
        vector<Tip> x1;
        int j = i;
        while(j < v.size() - 1) {
            if( v[j] >= v[j+1] ) x1.push_back(v[j]);
            else {
                if( v[j] <= v[j-1] ) x1.push_back(v[j]);
                break;};
            ++j;
        }
        m.push_back(x1);
    }


    vector<Tip> najduzi;
    for(int i=0; i<m.size(); i++) {
        if(m[i].size() > najduzi.size()) najduzi = m[i];
    }


    return najduzi;


}


int main() {


    vector <int> v{3, 6, 7, 5, 2, 4, 8, 9, 8, 8, 5, 3, 2, 4, 9, 9, 7, 1};

    vector <int>v1{3,6, 7, 5, 2, 4, 8, 15, 14, 13, 12, 11, 7, 9, 8, 8, 5, 3, 2, 4, 9, 9, 7, 1};

    for (auto x : f(v1) ) cout << x<<" ";

    cout << endl;

    for( auto x : f(v) ) cout << x << " " ;



}
