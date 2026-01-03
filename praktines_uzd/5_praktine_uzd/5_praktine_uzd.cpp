#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

const char FIN[]="testData.txt";
const char FOUT[]="results.txt";

struct Student {
    string studentID;
    string studentAtsakymai;
    double studentGrade;
};

vector<Student> studentai;
vector<char> teisingi_ats;

void inputFailas() {
    string failo_ats;
    string eilute;
    ifstream fin(FIN);
    if (fin.fail()) {
        cout<<"Nepavyko atidaryti failo"<<endl;
        return;
    }
    getline(fin,failo_ats);
    stringstream failo_ats1(failo_ats);
    char ats;
    while (failo_ats1>>ats) {
        if (ats=='T' || ats=='F') { //stringstream praleidzia ','
            teisingi_ats.push_back(ats);
        }
    }
    while (getline(fin,eilute)) {
        stringstream studento_info(eilute);
        Student temp;
        char temp_char;    
        studento_info>>temp.studentID; //sustos prie tarpo
        while (studento_info>>temp_char) {
            if (temp_char=='T' || temp_char=='F' || temp_char=='-') {
                temp.studentAtsakymai+=temp_char;
            }
        }
        studentai.push_back(temp);
    }
    fin.close();
}

void studentoPazymys(double &vidurkisProcentu, double &vidurkisPazymiu) {
    double pazymioProcentai_vidurkis=0;
    double pazymioVidurkis=0;

    for (auto i=studentai.begin(); i!=studentai.end(); i++) {
        //skaiciuojami pazymiai
        double pazymioProcentai=0;
        int pazymioTaskai=0;
        int pazymys;
        for (auto j=0; j<i->studentAtsakymai.length(); j++) {
            if (i->studentAtsakymai[j] == teisingi_ats[j]) {
                pazymioTaskai+=2;
            }
            else if (i->studentAtsakymai[j] == 'T' && teisingi_ats[j] == 'F' || i->studentAtsakymai[j] == 'F' && teisingi_ats[j] == 'T') {
                pazymioTaskai-=1;
            }
            else if (i->studentAtsakymai[j] == '-') {
                continue;
            }
        }
        pazymioProcentai=(static_cast<double>(pazymioTaskai)/40)*100;
        pazymioProcentai_vidurkis+=pazymioProcentai;
        if (pazymioProcentai>=95 && pazymioProcentai<=100) {
            pazymys=10;
        }
        else if (pazymioProcentai>=85 && pazymioProcentai<=94) {
            pazymys=9;
        }
        else if (pazymioProcentai>=75 && pazymioProcentai<=84) {
            pazymys=8;
        }
        else if (pazymioProcentai>=65 && pazymioProcentai<=74) {
            pazymys=7;
        }
        else if (pazymioProcentai>=55 && pazymioProcentai<=64) {
            pazymys=6;
        }
        else if (pazymioProcentai>=50 && pazymioProcentai<=54) {
            pazymys=5;
        }
        else if (pazymioProcentai>=35 && pazymioProcentai<=49) {
            pazymys=4;
        }
        else if (pazymioProcentai>=25 && pazymioProcentai<=34) {
            pazymys=3;
        }
        else if (pazymioProcentai>=15 && pazymioProcentai<=24) {
            pazymys=2;
        }
        else if (pazymioProcentai>=0 && pazymioProcentai<=14) {
            pazymys=1;
        }
        i->studentGrade=pazymys;
        pazymioVidurkis+=pazymys;
    }
    vidurkisProcentu=pazymioProcentai_vidurkis/studentai.size();
    vidurkisPazymiu=pazymioVidurkis/studentai.size();
}

void klasesStatistika() {
    double pazymioProcentai_vidurkis = 0;
    double pazymioVidurkis = 0;

    studentoPazymys(pazymioProcentai_vidurkis, pazymioVidurkis);
    // 1. STUDENTU SK
    cout<<"Studentu sk.: "<<studentai.size()<<endl;

    // 2. DIDZIAUSIAS/MAZIAUSIAS PAZYMYS
    int didziausiasPazymys=0;
    int maziausiasPazymys=10;
    for (auto i=studentai.begin(); i!=studentai.end(); i++) {
        if (i->studentGrade>didziausiasPazymys) {
            didziausiasPazymys= i->studentGrade;
        }
    }
    for (auto i=studentai.begin(); i!=studentai.end(); i++) {
        if (i->studentGrade<maziausiasPazymys) {
            maziausiasPazymys= i->studentGrade;
        }
    }
    cout<<didziausiasPazymys<<" "<<maziausiasPazymys<<endl; //ISTRINTI

    // 3. VIDUTINIS PAZYMYS/PROCENTAS
    cout<<"Vidutinis pazymys: "<<pazymioVidurkis<<endl;
    cout<<"Vidutinis procentas: "<<pazymioProcentai_vidurkis<<endl;

    // 4. PAZYMIU PASISKIRSTYMAS
    
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

int main() { //ISKVIESK FUNKCIJAS BUTINAI !!!!!!!!!!!!!!
    inputFailas();
    klasesStatistika();
    return 0;
}