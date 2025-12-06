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
    int servingNr; //porciju kiekis
    int menuItemNrPas; //pasirinkto patiekalo numeris
};

menuItemType menuList[20];
int eil_sk=0;
int patiekaloNr, patiekaluSk;
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
    double check;
    for (int i=0; i<eil_sk; i++) {
        if (menuList[i].menuItemNrPas==menuList[i].menuItemNr+1) {
            cout<<menuList[i].servingNr<<" "<<left<<setw(itemWidth)<<menuList[i].menuItem<<right<<setw(priceWidth)<<menuList[i].menuPrice*menuList[i].servingNr<<endl;
            pvmMokesciai+=(menuList[i].menuPrice*menuList[i].servingNr)*pvm;
        }
    }
    cout<<left<<setw(itemWidth)<<"Mokesciai (21%)"<<right<<setw(priceWidth)<<pvmMokesciai<<endl;
    ofstream fout(FOUT);
    for (int i=0; i<patiekaluSk; i++) {
        fout<<menuList[i].servingNr<<" "<<left<<setw(itemWidth)<<menuList[i].menuItem<<right<<setw(priceWidth)<<menuList[i].menuPrice*menuList[i].servingNr<<endl;
    }
    fout<<left<<setw(itemWidth)<<"Mokesciai (21%)"<<right<<setw(priceWidth)<<fixed<<setprecision(2)<<pvmMokesciai<<endl;
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
                    do {
                        cout<<"Iveskite patiekalo numeri: ";
                        cin>>menuList[i].menuItemNrPas;
                        if (menuList[i].menuItemNrPas<=0 || menuList[i].menuItemNrPas>eil_sk) {
                            cout<<"Ivestas neteisingas patiekalo numeris"<<endl;
                        }
                    } while (menuList[i].menuItemNrPas<=0 || menuList[i].menuItemNrPas>eil_sk);
                    do {
                            cout<<"Iveskite porciju kieki: ";
                            cin>>menuList[i].servingNr;
                            if (menuList[i].servingNr<=0) {
                                cout<<"Ivestas neteisingas kiekis"<<endl;
                            }
                    } while (menuList[i].servingNr<=0);
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

