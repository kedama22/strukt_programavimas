#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const char FIN[]="menu.txt";
const char FOUT[]="receipt.txt";

struct menuItemType {
    string menuItem;
    double menuPrice;
};

menuItemType menuList[100];
int eil_sk=0;
int patiekaloNr, porcijuSk, patiekaluSk;

void showMenu() {
    const int itemWidth=38;
    const int priceNameWidth=13;
    const int priceWidth=8;
    const string menuHeader="================ MENU ================";
    const string menuChoice="============ PASIRINKIMAI ============";
    int menuPadding=((itemWidth+priceWidth)-menuHeader.length())/2;
    int choicePadding=((itemWidth+priceWidth)-menuChoice.length())/2;
    cout<<endl;
    cout<<setw(menuPadding)<<""<<menuHeader<<endl;
    cout<<endl;
    cout<<left<<setw(itemWidth)<<"Patiekalo pavadinimas"<<right<<setw(priceNameWidth)<<"Kaina (EUR)"<<endl;
    for (int i=0; i<eil_sk; i++) {
        int patiekalo_sk=i+1;
        cout<<patiekalo_sk<<") "<<left<<setw(itemWidth)<<menuList[i].menuItem<<right<<setw(priceWidth)<<menuList[i].menuPrice<<endl;
        patiekalo_sk++;
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
    ofstream fout(FOUT);

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
                    cout<<"Iveskite patiekalo skaiciu: ";
                    cin>>patiekaloNr;
                    cout<<"Iveskite porciju kieki: ";
                    cin>>porcijuSk;
                }
                cout<<"Jusu uzsakymas: "<<
                break;
            }
            case 2:
            {

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

