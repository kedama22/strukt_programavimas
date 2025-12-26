#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const char FIN[]="testData.txt";
const char FOUT[]="results.txt";

struct Student {
    string studentID;
    string studentAtsakymai;
    double studentGrade;
};

void inputFailas() {
    vector<Student> studentai;
    ifstream fin(FIN);
    if (fin.fail()) {
        cout<<"Nepavyko atidaryti failo"<<endl;
        return;
    }



    while (!fin.eof()) {
        getline (fin,klausimuAts.push_back(),','); /* ?????? */
    }

}

void klasesStatistika() {

}

void studentoPaieskaID() {
    int studentoIdPaieska;
    cout<<"Iveskite studento ID:";
    cin>>studentoIdPaieska;
    do {

    } while (studentoIdPaieska!=0);
}

void outputFailas() {

}

void klausimuStatistika() {

}

void sunkiausiasKlausimas() {

}

int main() {

    return 0;
}