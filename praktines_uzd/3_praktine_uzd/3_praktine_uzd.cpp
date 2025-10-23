#include <iostream>
#include <fstream>
#include <iomanip>
#include <string> //gal nereikia??

using namespace std;

const char FIN1[]="bilietu_pardavimu_info.csv";
const char FIN2[]="salary.txt";
const char FOUT2[]="new_salary.txt";
// const char FOUT[]=""
struct Zmogus {
    string pavarde;
    string vardas;
    int esamas_atlyg;
    int padidejimo_proc;
    double naujas_atlyg;
};

void menu() {
    cout<<"---- Duomenu apdorojimo sistema ----\n";
    cout<<"1. Skaiciuoti bilietu pardavimus\n";
    cout<<"2. Perziureti atnaujintus atlyginimus\n";
    cout<<"3. Iseiti\n";
    cout<<"------------------------------------\n";
    cout<<"Iveskite pasirinkima: ";
}

int main() {
    // int i=0,j=0;
    double bilietai[10][10];
    Zmogus darbuotojas[10];
    int pas;
    string eil;
    double pard_bilietu_sk,bendra_pard_suma=0,pard_suma=0;
    menu();
    cin>>pas;
    do {
        if (pas==3) {
            cout<<"Iseinama is programos"<<endl;
            break;
        }
        if (pas!=1 && pas!=2) { //&& - IR
            cout<<"Ivestas neteisingas pasirinkimas"<<endl;
            break;
        }
        switch (pas) {
            case 1:
            {
                int i=0,j=0;
                int n=0;
                ifstream fin1(FIN1);
                if (fin1.fail()) {
                    cout<<"Nepavyko atidaryti failo."<<endl;
                    break;
                }
                while(getline(fin1,eil)) { //skaiciuoja, kiek eiluciu yra fin1
                    n++;
                }
                cout<<n<<endl;
                fin1.clear(); //istrina getline, kad galetu is naujo eiti per faila
                for(int k=0;k<n;k++) {
                    fin1>>bilietai[i][j];
                    j++;
                    fin1>>bilietai[i][j];
                    i++;
                    j=0;
                }
                i=0; //kad is naujo eitu per eilutes (PAZIURETI, AR VEIKIA)
                for(int k=0;k<n-1;k++) {
                    pard_bilietu_sk=bilietai[i][1]+bilietai[i+1][1];
                    i++;
                }
                i=0;
                for(int k=0;k<n-1;k++) {
                    pard_suma=bilietai[i][0]*bilietai[i][1];
                    bendra_pard_suma+=pard_suma;
                }
                fin1.close();
                // ofstream fout (COUT??? kaip isvesti ats)
                cout<<"Parduotu bilietu sk.: "<<pard_bilietu_sk<<endl;
                cout<<"Bendra pardavimu suma: "<<bendra_pard_suma<<endl;
            }
            break;
            case 2:
            {
                int i=0,j=0;
                int n=0;
                ifstream fin2(FIN2);
                if (fin2.fail ()) {
                    cout<<"Nepavyko atidaryti failo."<<endl;
                    break;
                }
                while(getline(fin2,eil)) {
                    n++;
                }
                fin2.clear();
                fin2.seekg(0); //pirma eilute yra tekstas, todel reikia ja praleisti PASIDOMETI!!!
                while(!fin2.eof()) {
                    getline(fin2,darbuotojas[i].pavarde,',');
                    getline(fin2,darbuotojas[i].vardas,',');
                    fin2>>darbuotojas[i].esamas_atlyg;
                    fin2>>darbuotojas[i].padidejimo_proc;
                    i++;
                }
                i=0;
                ofstream fout2(FOUT2);
                if(fout2.fail()) {
                    cout<<"Nepavyko sukurti failo."<<endl;
                    break;
                }
                for(int k=0;k<n-1;k++) {
                    darbuotojas[i].naujas_atlyg=darbuotojas[i].esamas_atlyg+(darbuotojas[i].esamas_atlyg*(darbuotojas[i].padidejimo_proc/100));
                }
                for(int k=0;k<n-1;k++) {
                    fout2<<darbuotojas[i].pavarde<<" "<<darbuotojas[i].vardas<<" "<<fixed<<setprecision(2)<<darbuotojas[i].naujas_atlyg<<endl;
                }
                fin2.close();
                fout2.close();
            }
            break;
        }
    } while (pas==1 || pas==2);
    return 0;
}