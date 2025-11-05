#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const char FIN1[]="bilietu_pardavimu_info.txt";
const char FIN2[]="salary.txt";
const char FOUT2[]="new_salary.txt";

const int max_bilietu_tipu=4;
const int max_darbuotoju=3;

struct Zmogus {
    string pavarde;
    string vardas;
    double esamas_atlyg;
    double padidejimo_proc;
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
    int bilietai[max_bilietu_tipu][max_bilietu_tipu];
    Zmogus darbuotojas[max_darbuotoju];
    int pas;
    string eil;
    double pard_bilietu_sk=0,bendra_pard_suma=0,pard_suma=0;
    do {
        menu();
        cin>>pas;
        if (pas==3) {
            cout<<"Iseinama is programos"<<endl;
            return 0;
        }
        switch (pas) {
            case 1:
            {
                int j=0;
                int n=0;
                char a;
                ifstream fin1(FIN1);
                if (fin1.fail()) {
                    cout<<"Nepavyko atidaryti failo."<<endl;
                    break;
                }
                while(getline(fin1,eil)) { //skaiciuoja, kiek eiluciu yra fin1
                    n++;
                }
                fin1.clear();
                fin1.seekg(0);
                for(int i=0;i<n;i++) {
                    fin1>>bilietai[i][j]>>a>>bilietai[i][j+1];
                    j=0;
                }
                int i=0;
                for(int k=0;k<n;k++) {
                    pard_bilietu_sk+=bilietai[i][1];
                    i++;
                }
                for(int i=0;i<n;i++) {
                    pard_suma=bilietai[i][0]*bilietai[i][1];
                    bendra_pard_suma+=pard_suma;
                }
                fin1.close();
                cout<<"Parduotu bilietu sk.: "<<fixed<<setprecision(2)<<pard_bilietu_sk<<endl;
                cout<<"Bendra pardavimu suma: "<<fixed<<setprecision(2)<<bendra_pard_suma<<endl;
            }
            break;
            case 2:
            {
                int i=0,j=0;
                int n=0;
                char a;
                ifstream fin2(FIN2);
                if (fin2.fail ()) {
                    cout<<"Nepavyko atidaryti failo."<<endl;
                    break;
                }
                while(getline(fin2,eil)) {
                    n++;
                }
                fin2.clear();
                fin2.seekg(0); //pirma eilute yra tekstas, todel reikia ja praleisti
                for(i=0;i<n;i++) {
                    getline(fin2,darbuotojas[i].pavarde,',');
                    getline(fin2,darbuotojas[i].vardas,',');
                    fin2>>darbuotojas[i].esamas_atlyg>>a>>darbuotojas[i].padidejimo_proc;
                    fin2.ignore(1,'\n');
                }
                i=0;
                ofstream fout2(FOUT2);
                if(fout2.fail()) {
                    cout<<"Nepavyko sukurti failo."<<endl;
                    break;
                }
                for(i=0;i<n;i++) {
                    darbuotojas[i].naujas_atlyg=darbuotojas[i].esamas_atlyg+(darbuotojas[i].esamas_atlyg*(darbuotojas[i].padidejimo_proc/100));
                }
                i=0;
                for(i=0;i<n;i++) {
                    fout2<<darbuotojas[i].pavarde<<" "<<darbuotojas[i].vardas<<" "<<fixed<<setprecision(2)<<darbuotojas[i].naujas_atlyg<<endl;
                }
                cout<<"Nauji atlyginimai issaugoti faile: "<<FOUT2<<endl;
                fin2.close();
                fout2.close();
                break;
            }
            break;
            default: cout<<"Ivestas netinkamas pasirinkimas"<<endl;
            break;
        } 
    } while (pas==1 || pas==2 || pas==3);
    return 0;
}