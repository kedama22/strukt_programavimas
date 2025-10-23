#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
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
    int max_pazymiu=11; //turi buti 10+1, nes 11 slot naudojamas pazymiu kiekiui storinti
    const int kiek_pazymiu=max_pazymiu-1;
    int dabar_kiek;
    string vardai[max_mokiniu];
    int pazymiai[max_mokiniu][max_pazymiu]={0};
    string vardas;
    int pas, kiek;
    int mokiniu_sk=0;

    do {
        meniu();
        cin>>pas;
        if (pas==5) {
            cout<<"Iseinama is programos."<<endl;
            break;
        }
        if (mokiniu_sk==0 && pas>1 && pas<5) {
            cout<<"Ivestu mokiniu kiekis: 0"<<endl;
            continue;
        }
        switch (pas) {
            case 1: //prideti mokini ir pazymius
            {
                if (mokiniu_sk>=max_mokiniu) {
                    cout<<"Ivestas maksimalus galimas mokiniu kiekis."<<endl;
                    break;
                }
                cout<<"Iveskite mokinio varda: ";
                cin>>vardas;
                vardai[mokiniu_sk]=vardas;
                cout<<"Iveskite pazymiu kieki:";
                cin>>kiek;
                if (kiek>max_pazymiu-1 || kiek<0) {
                    cout<<"Ivestas neteisingas kiekis."<<endl;
                    break;
                }
                cout<<"Iveskite pazymius:"<<endl;
                for (int i=0; i<kiek; i++){
                    int pazymys;
                    cin>>pazymys;
                    if (pazymys>10 || pazymys<0) {
                        cout<<"Ivestas neteisingas pazymys."<<endl;
                        break;
                    }
                    pazymiai[mokiniu_sk][i]=pazymys;
                }
                pazymiai[mokiniu_sk][kiek_pazymiu] = kiek; //kad zinotume, kiek pazymiu turi mokinys
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
                if (pas2!=1 && pas2!=2) {
                    cout<<"Ivestas neteisingas pasirinkimas."<<endl;
                    break;
                }
                switch (pas2) {
                    case 1:
                    for (int i=0; i<mokiniu_sk;i++) {
                        dabar_kiek=pazymiai[i][kiek_pazymiu];
                        cout<<vardai[i]<<": ";
                        for (int j=0; j<dabar_kiek;j++) {
                            cout<<pazymiai[i][j]<<" ";
                        }
                        cout<<"\n";
                    }
                    break;
                    case 2: {
                        cout<<"Iveskite mokinio, kurio pazymius norite perziureti, varda: ";
                        cin>>vardas;
                        for (int i=0;i<mokiniu_sk;i++) {
                            if (vardai[i]==vardas) {
                                dabar_kiek=pazymiai[i][kiek_pazymiu];
                                cout<<vardai[i]<<": ";
                                for (int j=0;j<dabar_kiek;j++) {
                                    cout<<pazymiai[i][j]<<" ";
                                }
                            }
                        }
                    }
                }
                break;
            }
            break;
            case 3: //atnaujinti pazymi
            {
                int pazymio_nr, naujas_paz;
                cout<<"Iveskite ieskomo mokinio varda: ";
                cin>>vardas;
                for (int i=0;i<mokiniu_sk;i++){
                    if (vardai[i]==vardas) {
                        dabar_kiek=pazymiai[i][kiek_pazymiu];
                        cout<<"Kelinta pazymi norite atnaujinti (galima nuo 1 iki "<<dabar_kiek<<" ): ";
                        cin>>pazymio_nr;
                        cout<<"Iveskite nauja pazymi: ";
                        cin>>naujas_paz;
                        pazymiai[i][pazymio_nr-1]=naujas_paz;
                    }
                }
                cout<<"Pazymys atnaujintas sekmingai"<<endl;
                break;
            }
            case 4: //pasalinti mokini
            {
                cout<<"Iveskite mokinio, kuri norite pasalinti, varda: ";
                cin>>vardas;
                for (int i=0; i<mokiniu_sk;i++) {
                    if (vardai[i]==vardas) {
                        vardai[i]=vardai[i+1];
                    }
                }
                mokiniu_sk--;
                cout<<"Mokinys "<<vardas<<" ismestas sekmingai"<<endl;
                break;
            }
            default: cout<<"Ivestas netinkamas pasirinkimas"<<endl;            
            }
    } while (pas==1 || pas==2 || pas==3 || pas==4);
    return 0;
}