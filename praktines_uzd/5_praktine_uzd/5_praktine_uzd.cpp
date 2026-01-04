#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>  //stringstream
#include <algorithm> //find_if
#include <iomanip>

using namespace std;

const char FIN[]="testData.txt";
const char FOUT[]="results.txt";

struct Student {
    string studentID;
    string studentAtsakymai;
    int studentTaskai;
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
    stringstream failo_ats1(failo_ats); // atsakymu eilute pavercia i 20 skirtingu ats (T/F)
    char ats;
    while (failo_ats1>>ats) { //kol is pirmos fin eilute skaito po viena atsakymo char
        if (ats=='T' || ats=='F') { //stringstream praleidzia ','
            teisingi_ats.push_back(ats); //ideda atsakymo char i vektoriaus 'teisingi_ats' gala
        }
    }
    while (getline(fin,eilute)) {
        stringstream studento_info(eilute); //studento info pakeicia i du skirtingus info tipus
        Student temp;
        char temp_char;    
        studento_info>>temp.studentID; //sustos prie tarpo
        while (studento_info>>temp_char) { 
            if (temp_char=='T' || temp_char=='F' || temp_char=='-') {
                temp.studentAtsakymai+=temp_char;
            }
        }
        studentai.push_back(temp); // viskas suskaiciuojama Student temp ir tik tada idedama i vektoriu
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

void studentoPazymys() {
    for (auto i=studentai.begin(); i!=studentai.end(); i++) {
        //skaiciuojami pazymiai
        double pazymioProcentai=0;
        int pazymioTaskai=0;
        int pazymys;
        for (auto j=0; j<i->studentAtsakymai.length(); j++) { // i-> - rodykle i studentai vektoriu
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
        i->studentTaskai=pazymioTaskai;
        pazymioProcentai=(static_cast<double>(pazymioTaskai)/40)*100;
        i->studentGradeProcent=pazymioProcentai;
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
    }
}

void studentuPazymiuVidurkiai(double &vidurkisProcentu, double &vidurkisPazymiu) { //& pakeicia eil. 112-113 info
    double pazymioProcentai_vidurkis=0;
    double pazymioVidurkis=0;
    for (auto i=studentai.begin(); i!=studentai.end(); i++) {
        pazymioProcentai_vidurkis+=i->studentGradeProcent;
        pazymioVidurkis+=i->studentGrade;
    }
    vidurkisProcentu=pazymioProcentai_vidurkis/studentai.size();
    vidurkisPazymiu=pazymioVidurkis/studentai.size();
}

// ----------- CASE 1 ------------
void klasesStatistika() {
    double pazymioProcentai_vidurkis = 0;
    double pazymioVidurkis = 0;

    studentoPazymys();
// 1. STUDENTU SK
    cout<<"Studentu sk.: "<<studentai.size()<<endl;
    cout<<"---------------------------------------"<<endl;

// 2. DIDZIAUSIAS/MAZIAUSIAS PAZYMYS
    int didziausiasPazymys=0;
    int maziausiasPazymys=10;
    for (auto i=studentai.begin(); i!=studentai.end(); i++) {
        if (i->studentGrade>didziausiasPazymys) {
            didziausiasPazymys= i->studentGrade;
        }
    }
    for (auto i=studentai.begin(); i!=studentai.end(); i++) {
        if (i->studentGrade<=maziausiasPazymys) {
            maziausiasPazymys= i->studentGrade;
        }
    }
    cout<<"Didziausias pazymys: "<<didziausiasPazymys<<"\n"<<"Maziausias pazymys: "<<maziausiasPazymys<<endl;
    cout<<"---------------------------------------"<<endl;

// 3. VIDUTINIS PAZYMYS/PROCENTAS
    studentuPazymiuVidurkiai(pazymioProcentai_vidurkis, pazymioVidurkis);
    cout<<"Vidutinis pazymys: "<<fixed<<setprecision(1)<<pazymioVidurkis<<endl;
    cout<<"Vidutinis procentas: "<<fixed<<setprecision(1)<<pazymioProcentai_vidurkis<<endl;
    cout<<"---------------------------------------"<<endl;

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
    cout<<endl;
}

// ----------- CASE 2 ------------
void studentoPaieskaID() {
    string studentoIdPaieska;
    do {
        cout<<"Iveskite studento ID (arba 0, jei norite iseiti):";    
        cin>>studentoIdPaieska;
        cout<<endl;
        if (studentoIdPaieska=="0") {
            cout<<"Iseinama"<<endl;
            cout<<endl;
            break;
        }
        auto ieskomasStudentas=find_if(studentai.begin(), studentai.end(), [&](const Student& studentas) { //find_if grazina vieta [&] leidzia naudoti kintamuosius is isores
        return studentas.studentID==studentoIdPaieska;
        });        
        if (ieskomasStudentas!=studentai.end()) {
            cout<<"Studento ID: "<<ieskomasStudentas->studentID<<endl;
            cout<<"Studento atsakymai: "<<ieskomasStudentas->studentAtsakymai<<endl;
            cout<<"Pazymys (procentai): "<<static_cast<int>(ieskomasStudentas->studentGrade)<<" ("<<ieskomasStudentas->studentGradeProcent<<")"<<endl;
        }
        else cout<<"Ivestas mokinys nerastas."<<endl;
        cout<<endl;
    } while (studentoIdPaieska!="0");
}

void outputFailas() {
    ofstream fout(FOUT);
    int formatavimas=9;
    int studentoSk=1;
    fout<<left<<setw(formatavimas-5)<<"Nr."<<left<<setw(formatavimas-5)<<"ID"<<left<<setw(formatavimas-1)<<"Taskai"<<left<<setw(formatavimas)<<"Pazymys"<<"Procentai"<<endl;
    for (auto i=studentai.begin(); i!=studentai.end(); i++) {
        fout<<studentoSk<<left<<setw(formatavimas-6)<<")"<<left<<setw(formatavimas-5)<<i->studentID<<i->studentTaskai<<left<<setw(formatavimas)<<"/40"<<left<<setw(formatavimas)<<i->studentGrade<<i->studentGradeProcent<<"%"<<endl;
        studentoSk++;
    }
    fout.close();
}

// ----------- CASE 3 ------------
void klausimuStatistika(int atsakytiKlausimai[20][3]) {
    int formatavimas=11;
    int klausimuSk=20;
    for (int j=1; j<=klausimuSk; j++ ) {
        for (auto i=studentai.begin(); i!=studentai.end(); i++) {
            if (i->studentAtsakymai[j-1]==teisingi_ats[j-1]) {
                atsakytiKlausimai[j-1][0]++;
            }
            else if (i->studentAtsakymai[j-1]=='-') {
                atsakytiKlausimai[j-1][2]++;
            }
            else {
                atsakytiKlausimai[j-1][1]++;
            }

        }
    }
}

void klausimuStatistikaCout(int atsakytiKlausimai[20][3]) {
    int formatavimas=11;
    int klausimuSk=20;
    cout<<left<<setw(formatavimas-6)<<"Nr."<<left<<setw(formatavimas)<<"Teisingai"<<left<<setw(formatavimas+2)<<"Neteisingai"<<"Neatsake"<<endl;
    for (int j=1; j<=klausimuSk; j++) {
    cout<<left<<setw(formatavimas-6)<<j<<left<<setw(formatavimas)<<atsakytiKlausimai[j-1][0]<<left<<setw(formatavimas+2)<<atsakytiKlausimai[j-1][1]<<atsakytiKlausimai[j-1][2]<<endl;
    }
}

// ----------- CASE 4 ------------
void sunkiausiasKlausimas(int atsakytiKlausimai[20][3]) {
    int klausimuSk=20;
    int klausimoNr=1;
    int sunkiausiasKl=atsakytiKlausimai[0][0];
    for (int i=1; i<klausimuSk; i++) {
        if (atsakytiKlausimai[i][0]<sunkiausiasKl) {
            sunkiausiasKl=atsakytiKlausimai[i][0];
        }
    }
    cout<<"Sunkiausias klausimas: ";
    for (int i=0; i<klausimuSk; i++) {
        if (atsakytiKlausimai[i][0]==sunkiausiasKl) {
            cout<<i+1<<" ";
        }
    }
    cout<<" ("<<sunkiausiasKl<<"/"<<studentai.size()<<" atsake teisingai.)"<<endl;
    cout<<endl;
}

int main() {
    int pasirinkimas;
    int klausimas[20][3]={0};
    inputFailas();
    klausimuStatistika(klausimas);
    studentoPazymys();
    do {
        pasirinkimoMenu();
        cin>>pasirinkimas;
        cout<<endl;
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
                klausimuStatistikaCout(klausimas);
                break;
            }
            case 4: {
                sunkiausiasKlausimas(klausimas);
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
    outputFailas();
    return 0;
}