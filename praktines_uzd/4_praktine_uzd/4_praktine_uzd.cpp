#include <iostream>
#include <fstream>
using namespace std;

const char FIN[]="menu.txt";
const char FOUT[]="receipt.txt";

struct menuItemType {
    string menuItem;
    double menuPrice;
};

// void 

int main() {
    menuItemType menuList[100];
    string eil;
    int eil_sk=0;
    ifstream fin(FIN);
    if (fin.fail()) {
        cout<<"Nepavyko atidaryti failo "<<FIN<<endl;
        return 1;
    }
    while (getline(fin,eil)) {
        eil_sk++;
    }
    fin.clear();
    fin.seekg(0);
    for (int i=0;i<eil_sk;i++) {
        getline(fin,menuList[i].menuItem,',');
        fin>>menuList[i].menuPrice;
    }
    
    return 0;
}