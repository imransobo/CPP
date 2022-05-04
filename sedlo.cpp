#include<iostream>


template<typename Tip>
Tip f(Tip **mat, int n) {

    for (int i=0; i<n; i++) {
		int minRed = mat[i][0];
		int kolonaInd = 0;
		for (int j=1; j<n; j++) {
			if (minRed > mat[i][j]) {
				minRed = mat[i][j];
				kolonaInd = j;
			}
		}

		int k;
		for (k=0; k<n; k++)
			if (minRed < mat[k][kolonaInd])
                break;

		if (k == n) {
            return minRed;
		}
	}

	throw "Nema sedlo";


}


int main() {

    int n;
    std::cout << "Unesi dimenziju kvadratne matrice: ";
    std::cin >> n;


    //dinamicka alokacija matrice
    int **mat = new int*[n];

    for(int i=0; i<n; i++) {
        mat[i] = new int[n];
    }


    //unos
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            std::cout << "Unesi element: ";
            std::cin >> mat[i][j];
        }
    }

    //poziv
    try {
        std::cout << f(mat, n);
    } catch(const char* a) {
        std::cout << a;
    }


    //dealokacija
    for(int i=0; i<n; i++) {
        delete [] mat[i];
    }
    delete [] mat;





}
