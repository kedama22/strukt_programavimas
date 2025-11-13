#include <iostream>
#include <fstream>
using namespace std;

const char FIN[]="studentai.txt";

struct Studentai {
    string vardas;
    int paz;
};

int main() {
    Studentai studentas[10];
    int n=0;
    int min_paz=8;
    string eil;
    ifstream fin(FIN);
    if (fin.fail()) {
        cout<<"Nepavyko atidaryti failo."<<endl;
        return 1;
    }
    while (getline(fin,eil)) {
        n++;
    }
    fin.clear();
    fin.seekg(0);
    for (int i=0; i<n; i++) {
        getline(fin, studentas[i].vardas,' ');
        fin>>studentas[i].paz;
    }
    fin.close();
    cout<<"Studentai, kuriu pazymys > 8:"<<endl;
    for (int i=0; i<n; i++) {
        if (studentas[i].paz>8) {
            cout<<studentas[i].vardas<<" "<<studentas[i].paz<<endl;
        }
    }
    return 0;
}