#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const char FIN[]="menu.txt";
const char FOUT[]="receipt.txt";

struct menuItemType {
    string menuItem;
    double menuPrice;
    int menuItemNr; //patiekalo numeris
};

menuItemType menuList[20];
int eil_sk=0;
int patiekaloNr, patiekaluSk;
int menuItemNrPas[20];
int servingNr[20];
double pvmMokesciai=0, finalPrice=0;
const int itemWidth=38;
const int priceNameWidth=13;
const int priceWidth=8;
const double pvm=0.21;

void showMenu() {
    const string menuHeader="================ MENU ================";
    const string menuChoice="============ PASIRINKIMAI ============";
    int menuPadding=((itemWidth+priceWidth)-menuHeader.length())/2;
    int choicePadding=((itemWidth+priceWidth)-menuChoice.length())/2;
    cout<<endl;
    cout<<setw(menuPadding)<<""<<menuHeader<<endl;
    cout<<endl;
    cout<<left<<setw(itemWidth)<<"Patiekalo pavadinimas"<<right<<setw(priceNameWidth)<<"Kaina (EUR)"<<endl;
    for (int i=0; i<eil_sk; i++) {
        int patiekaloNr=i+1;
        menuList[i].menuItemNr=patiekaloNr;
        cout<<patiekaloNr<<") "<<left<<setw(itemWidth)<<menuList[i].menuItem<<right<<setw(priceWidth)<<menuList[i].menuPrice<<endl;
        patiekaloNr++;
    }
    cout<<"\n\n";
    cout<<left<<setw(choicePadding)<<""<<menuChoice<<endl;
    cout<<endl;
    cout<<"1. Rinktis patiekalus"<<endl;
    cout<<"2. Apskaiciuoti saskaita"<<endl;
    cout<<"3. Iseiti"<<endl;
    cout<<"Iveskite pasirinkima: ";
}

void getData() {
    string eil;
    ifstream fin(FIN);
    if (fin.fail()) {
        cout<<"Nepavyko atidaryti failo "<<FIN<<endl;
        return;
    }
    while (getline(fin,eil)) {
        eil_sk++;
    }
    fin.clear();
    fin.seekg(0);
    for (int i=0;i<eil_sk;i++) {
        getline(fin,menuList[i].menuItem,',');
        fin>>menuList[i].menuPrice;
        fin.ignore();
    }
    fin.close();
}

void printCheck() {
    for (int i=0; i<patiekaluSk; i++) {
        int menuItemNrPas1 = menuItemNrPas[i];
        int servingNr1 = servingNr[i];
        cout<<servingNr1<<" "<<left<<setw(itemWidth)<<menuList[menuItemNrPas1].menuItem<<right<<setw(priceWidth)<<menuList[menuItemNrPas1].menuPrice*servingNr1<<endl;
        pvmMokesciai+=(menuList[menuItemNrPas1].menuPrice*servingNr1)*pvm;
        finalPrice+=(menuList[menuItemNrPas1].menuPrice*servingNr1);
    }
    finalPrice+=pvmMokesciai;
    cout<<left<<setw(itemWidth+2)<<"Mokesciai (21%)"<<right<<setw(priceWidth)<<fixed<<setprecision(2)<<pvmMokesciai<<endl;
    cout<<left<<setw(itemWidth+2)<<"Galutine suma"<<right<<setw(priceWidth)<<fixed<<setprecision(2)<<finalPrice<<endl;
    ofstream fout(FOUT);
    for (int i=0; i<patiekaluSk; i++) {
            int menuItemNrPas1 = menuItemNrPas[i];
            int servingNr1 = servingNr[i];
            fout<<servingNr1<<" "<<left<<setw(itemWidth)<<menuList[menuItemNrPas1].menuItem<<right<<setw(priceWidth)<<menuList[menuItemNrPas1].menuPrice*servingNr1<<endl;
            pvmMokesciai+=(menuList[menuItemNrPas1].menuPrice*servingNr1)*pvm;
        }
    fout<<left<<setw(itemWidth+2)<<"Mokesciai (21%)"<<right<<setw(priceWidth)<<fixed<<setprecision(2)<<pvmMokesciai<<endl;
    fout<<left<<setw(itemWidth+2)<<"Galutine suma"<<right<<setw(priceWidth)<<fixed<<setprecision(2)<<finalPrice<<endl;
    fout.close();
    }
    

int main() {
    int pasirinkimas;
    getData();
    do {
        showMenu();
        cin>>pasirinkimas;
        switch (pasirinkimas) {
            case 1:
            {
                cout<<"Iveskite norimu skirtingu patiekalu skaiciu: ";
                cin>>patiekaluSk;
                for (int i=0; i<patiekaluSk; i++) {
                    int patiekaloNrPas;
                    do {
                        cout<<"Iveskite patiekalo numeri: ";
                        cin>>patiekaloNrPas;
                        if (patiekaloNrPas<=0 || patiekaloNrPas>eil_sk) {
                            cout<<"Ivestas neteisingas patiekalo numeris"<<endl;
                        }
                    } while (patiekaloNrPas<=0 || patiekaloNrPas>eil_sk);
                    menuItemNrPas[i]=patiekaloNrPas-1;
                    do {
                            cout<<"Iveskite porciju kieki: ";
                            cin>>servingNr[i];
                            if (servingNr[i]<=0) {
                                cout<<"Ivestas neteisingas kiekis"<<endl;
                            }
                    } while (servingNr[i]<=0);
                }
                break;
            }
            case 2:
            {
                printCheck();
                break;
            }
            case 3:
            {
                cout<<"Iseinama is programos"<<endl;
                break;
            }
            default:
            cout<<"Ivestas neteisingas pasirinkimas"<<endl;
            break;
        }
    } while (pasirinkimas!=3);
    return 0;
}

