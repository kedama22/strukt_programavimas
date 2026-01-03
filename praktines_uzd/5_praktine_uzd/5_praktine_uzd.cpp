#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

const char FIN[]="testData.txt";
const char FOUT[]="results.txt";

struct Student {
    string studentID;
    string studentAtsakymai;
    double studentGrade;
    double studentGradeProcent;
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
            // else {
            //     cout<<"Faile ivestas neteisingas atsakymas"<<endl;
            //     break;
            // }
        }
        studentai.push_back(temp);
    }
    fin.close();
}

void pasirinkimoMenu() {
    cout<<"-------- TESTAS --------"<<endl;
    cout<<"1. Klases statistika"<<endl;
    cout<<"2. Studento paieska (pagal ID)"<<endl;
    cout<<"3. Kiekvieno klausimo statistika"<<endl;
    cout<<"4. Sunkiausias klausimas"<<endl;
    cout<<"5. Iseiti"<<endl;
    cout<<"Iveskite pasirinkima: ";
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
        i->studentGradeProcent=pazymioProcentai;
        pazymioProcentai_vidurkis+=pazymioProcentai;
        if (pazymioProcentai>=95 && pazymioProcentai<=100) pazymys=10;
        else if (pazymioProcentai>=85) pazymys=9;
        else if (pazymioProcentai>=75) pazymys=8;
        else if (pazymioProcentai>=65) pazymys=7;
        else if (pazymioProcentai>=55) pazymys=6;
        else if (pazymioProcentai>=50) pazymys=5;
        else if (pazymioProcentai>=35) pazymys=4;
        else if (pazymioProcentai>=25) pazymys=3;
        else if (pazymioProcentai>=15) pazymys=2;
        else if (pazymioProcentai>=0 && pazymioProcentai<=14) pazymys=1;

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
    cout<<"Didziausias pazymys: "<<didziausiasPazymys<<"\n"<<"Maziausias pazymys: "<<maziausiasPazymys<<endl; //ISTRINTI

// 3. VIDUTINIS PAZYMYS/PROCENTAS
    cout<<"Vidutinis pazymys: "<<fixed<<setprecision(1)<<pazymioVidurkis<<endl;
    cout<<"Vidutinis procentas: "<<fixed<<setprecision(1)<<pazymioProcentai_vidurkis<<endl;

// 4. PAZYMIU PASISKIRSTYMAS
    int pazymiuPaskirstymas[11]={0};
    for (auto i=studentai.begin(); i!=studentai.end(); i++) {
        int pazymiuSk=static_cast<int>(i->studentGrade);
        pazymiuPaskirstymas[pazymiuSk]++;
    }
    cout<<"Pazymiu pasiskirstymas:"<<endl;
    for (int i=1; i<=10; i++) {
        if (i==1) {
            cout<<i<<" balas: "<<pazymiuPaskirstymas[i]<<" mokiniu"<<endl;
        }
        else if (i==10) {
            cout<<i<<" balu: "<<pazymiuPaskirstymas[i]<<" mokiniu"<<endl;
        }
        else {
            cout<<i<<" balu: "<<pazymiuPaskirstymas[i]<<" mokiniu"<<endl;
        }
    }
}

void studentoPaieskaID() {
    string studentoIdPaieska;
    do {
        cout<<"Iveskite studento ID (arba 0, jei norite iseiti):";    
        cin>>studentoIdPaieska;
        if (studentoIdPaieska=="0") {
            cout<<"Iseinama"<<endl;
            break;
        }
        auto ieskomasStudentas=find_if(studentai.begin(), studentai.end(), [&](const Student& studentas) {
        return studentas.studentID==studentoIdPaieska;
        });        
        if (ieskomasStudentas!=studentai.end()) {
            cout<<"Studento ID: "<<ieskomasStudentas->studentID<<endl;
            cout<<"Studento atsakymai: "<<ieskomasStudentas->studentAtsakymai<<endl;
            cout<<"Pazymys (procentai): "<<static_cast<int>(ieskomasStudentas->studentGrade)<<" ("<<ieskomasStudentas->studentGradeProcent<<")"<<endl;
        }
        else cout<<"Ivestas mokinys nerastas."<<endl;
    } while (studentoIdPaieska!="0");
}

void outputFailas() {
    ofstream fout(FOUT);
    for (int i=0; i>5; i++) {

    }
}

void klausimuStatistika() {

}

void sunkiausiasKlausimas() {

}

int main() {
    int pasirinkimas;
    inputFailas();    
    do {
        pasirinkimoMenu();
        cin>>pasirinkimas;
        switch (pasirinkimas) {
            case 1: {
                klasesStatistika();
                break;
            }
            case 2: {
                studentoPaieskaID();
                break;
            }
            case 3: {
                klausimuStatistika();
                break;
            }
            case 4: {
                sunkiausiasKlausimas();
                break;
            }
            case 5: {
                cout<<"Iseinama ir programos"<<endl;
                break;
            }
            default: cout<<"Ivestas neteisingas pasirinkimas"<<endl;
            break;
        }
    } while (pasirinkimas!=5);
    return 0;
}