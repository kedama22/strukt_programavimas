#include <iostream>
#include <fstream>
using namespace std;

const char FIN[]="studentai.txt";

struct Studentas {
    string vardas;
    int paz;
};

int main() {
    // Studentas studentas[10];
    string studv[10];
    int studentai_paz[10];
    int n=0;
    int simboliu_suma=0;
    string eil;
    string a="Labas";
    ifstream fin(FIN);
    if (fin.fail()) {
        cout<<"Nepavyko atidaryti failo."<<endl;
        return 1;
    }
    while (getline(fin,eil)) {
        n++;
    }
    for (int i=0; i<n; i++) {
        getline(fin,studv[i],' ');
        fin>>studentai_paz[i];
    }
    for (int i=0; i<n; i++) {
        simboliu_suma+=studv[i].length(); //???????????????????????
        simboliu_suma+=1;
    }
    fin.close();
    cout<<"Eiluciu sk.: "<<n<<endl;
    cout<<"Simboliu sk.: "<<simboliu_suma<<endl;
    cout<<"Zodziu sk.: "<<endl;

    return 0;
}