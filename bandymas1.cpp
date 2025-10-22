#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// const int MAX_MOKINIAI = 100;
// const int MAX_PAZYMIAI = 10;
const int TUSCIAS_PAZYMYS = 0; 

void meniu() {
    cout << "\n--- MOKINIU PAZYMIU SISTEMA ---\n";
    cout << "1. Prideti mokini ir pazymius\n";
    cout << "2. Perziureti pazymius\n";
    cout << "3. Atnaujinti pazymi\n";
    cout << "4. Pasalinti mokini\n";
    cout << "5. Iseiti\n";
    cout << "Pasirinkite veiksma: ";
}

int main() {
    int max_mokiniu=100;
    int max_pazymiu=10;
    string vardai[max_mokiniu];
    int pazymiai[max_mokiniu][max_pazymiu];
    string vardas;
    int pas, kiek;
    int mokiniu_sk=0;

    do {
        meniu();
        cin>>pas;
        if (mokiniu_sk==0 && pas>1 && pas<5) {
            cout<<"Ivestu mokiniu kiekis: 0"<<endl;
        }
        switch (pas) {
            case 1: //prideti mokini ir pazymius
            {
                if (mokiniu_sk>=max_mokiniu) {
                    cout<<"Ivestas maksimalus galimas mokiniu kiekis"<<endl;
                    break;
                }
                cout<<"Iveskite mokinio varda: ";
                cin>>vardas;
                vardai[mokiniu_sk]=vardas;
                cout<<"Iveskite pazymiu kieki:";
                cin>>kiek;
                cout<<"Iveskite pazymius:"<<endl;
                for (int i=0; i<kiek; i++){
                    int pazymys;
                    cin>>pazymys;
                    pazymiai[mokiniu_sk][i]=pazymys;
                }
                mokiniu_sk++;
                cout<<"Mokinys "<<vardas<<" pridetas."<<endl;
                break;
            }
            case 2: //perziureti pazymius
            {
                int pas2;
                cout<<"Pasirinkimai: \n";
                cout<<"1. Perziureti visus pazymius\n";
                cout<<"2. Perziureti konkretaus mokinio pazymius\n";
                cout<<"Iveskite pasirinkima: ";
                cin>>pas2;
                switch (pas2) {
                    case 1:
                    for (int i=0; i<mokiniu_sk;i++) {
                        cout<<vardai[i]<<": ";
                        for (int j=0; j<max_pazymiu;j++) {
                            cout<<pazymiai[i][j]<<" ";
                        }
                        cout<<"\n";
                    }
                }
                break;
            }
            case 3: //atnaujinti pazymi
            {
                int pazymio_nr, naujas_paz;
                cout<<"Iveskite ieskomo mokinio varda: ";
                cin>>vardas;
                for (int i=0;i<mokiniu_sk;i++){
                    if (vardai[i]==vardas) {
                        cout<<"Kelinta pazymi norite atnaujinti: ";
                        cin>>pazymio_nr;
                        cout<<"Iveskite nauja pazymi: ";
                        cin>>naujas_paz;
                        pazymiai[i][pazymio_nr]=naujas_paz;
                    }
                }
                cout<<"Pazymys atnaujintas sekmingai"<<endl;
            }
            case 4: //pasalinti mokini
            {
                cout<<"Iveskite mokinio, kuri norite pasalinti, varda: ";
                cin>>vardas;
                for (int i=0; i<mokiniu_sk;i++) {
                    if (vardai[i]==vardas) {
                        i=-1;
                        break;
                    }
                    if (i!=-1) {
                        for (int j=0;j<mokiniu_sk;j++){
                            
                        }
                    }
                }
            }
            // case 5: //iseiti
            // {
            //     cout<<"Iseinama is programos."<<endl;
            //     break;
            // }
            default: cout<<"Ivestas netinkamas pasirinkimas"<<endl;
        }
    } while (pas==1 || pas==2 || pas==3 || pas==4 || pas==5);
    return 0;
}