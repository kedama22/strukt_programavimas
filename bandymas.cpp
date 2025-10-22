#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_MOKINIAI = 100;
const int MAX_PAZYMIAI = 10;
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
    // Duomenų masyvai
    string vardai[MAX_MOKINIAI]; 
    int pazymiai[MAX_MOKINIAI][MAX_PAZYMIAI] = {0};
    int mokiniai_sk = 0;
    int pas;
    while (true) {
        meniu();
        // cout << "------------------------------------------\n";
        if (pasirinkimas == 5) {
            cout << "Programa baigia darba. Iki! \n";
            break;
        }
        if (mokiniai_sk == 0 && pas > 1 && pas < 5) {
            cout << "Sarase nera mokiniu.\n";
            continue;
        }

        // Kodo logika (switch)
        switch (pasirinkimas) {
            case 1: { // PRIDETI MOKINI
                if (mokiniai_sk >= MAX_MOKINIAI) {
                    cout << "Pasiektas maksimalus mokiniu limitas.\n";
                    break;
                }
                string naujasVardas;
                cout << "Iveskite mokinio varda: ";
                cin >> naujasVardas;
                
                // Patikrinimas: ar vardas jau egzistuoja
                // int indeksas = -1;
                // for (int i = 0; i < mokiniai_sk; ++i) {
                //     if (vardai[i] == naujasVardas) {
                //         indeksas = i;
                //         break;
                //     }
                // }
                // if (indeksas != -1) {
                //     cout << "Mokinys jau yra sarase.\n";
                //     break;
                // }
                vardai[mokiniai_sk] = naujasVardas;

                int kiekis;
                cout << "Kiek pazymiu (maks. " << MAX_PAZYMIAI << ")? ";
                cin >> kiekis;
                // if (kiekis < 0 || kiekis > MAX_PAZYMIAI) kiekis = 0;
                for (int i = 0; i < kiekis; ++i) {
                    int pazymys;
                    // cout << "Iveskite " << i + 1 << "-aji pazymi (1-10): ";
                    //     pazymiai[mokiniai_sk][j] = TUSCIAS_PAZYMYS;
                    //     cin.clear();
                    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        pazymiai[mokiniai_sk][j] = pazymys;
                    }
                }

                mokiniai_sk++;
                cout << "Mokinys \"" << naujasVardas << "\" pridėtas.\n";
                break;
            }

            case 2: { // PERZIURETI PAZYMIUS
                cout << "Pasirinkite perziuros buda (1-visi, 2-konkretus): ";
                int perziura_pasirinkimas;
                cin >> perziura_pasirinkimas;
                
                if (perziura_pasirinkimas == 2) {
                    string ieskomasVardas;
                    cout << "Iveskite mokinio varda: ";
                    cin >> ieskomasVardas;

                    int indeksas = -1;
                    for (int i = 0; i < mokiniai_sk; ++i) {
                        if (vardai[i] == ieskomasVardas) {
                            indeksas = i;
                            break;
                        }
                    }

                    if (indeksas != -1) {
                        cout << "\n" << left << setw(15) << vardai[indeksas] << " pazymiai: ";
                        for (int j = 0; j < MAX_PAZYMIAI; ++j) {
                            if (pazymiai[indeksas][j] != TUSCIAS_PAZYMYS) {
                                cout << pazymiai[indeksas][j] << " ";
                            }
                        }
                        cout << "\n";
                    } else {
                        cout << "Mokinys nerastas.\n";
                    }
                } else { // Visi mokiniai
                    cout << "\nVISU MOKINIU PAZYMIAI:\n";
                    for (int i = 0; i < mokiniai_sk; ++i) {
                        cout << left << setw(15) << vardai[i] << ": ";
                        for (int j = 0; j < MAX_PAZYMIAI; ++j) {
                            if (pazymiai[i][j] != TUSCIAS_PAZYMYS) {
                                cout << pazymiai[i][j] << " ";
                            }
                        }
                        cout << "\n";
                    }
                }
                break;
            }

            case 3: { // ATNAUJINTI PAZYMI
                string ieskomasVardas;
                cout << "Iveskite mokinio, kurio pazymi atnaujinsite, varda: ";
                cin >> ieskomasVardas;

                int indeksas = -1;
                for (int i = 0; i < mokiniai_sk; ++i) {
                    if (vardai[i] == ieskomasVardas) {
                        indeksas = i;
                        break;
                    }
                }

                if (indeksas != -1) {
                    int pazymioNr;
                    cout << "Keli pazymi (1-" << MAX_PAZYMIAI << ") norite atnaujinti? ";
                    cin >> pazymioNr;

                    if (pazymioNr >= 1 && pazymioNr <= MAX_PAZYMIAI) {
                        int naujasPazymys;
                        cout << "Iveskite nauja pazymi (1-10): ";
                        cin >> naujasPazymys;

                        if (naujasPazymys >= 1 && naujasPazymys <= 10) {
                            pazymiai[indeksas][pazymioNr - 1] = naujasPazymys; 
                            cout << "Pazymys atnaujintas sekmingai.\n";
                        } else {
                            cout << "Pazymys turi buti 1-10.\n";
                        }
                    } else {
                        cout << "Neteisingas pazymio eiles numeris.\n";
                    }
                } else {
                    cout << "Mokinys nerastas.\n";
                }
                break;
            }

            case 4: { // PASALINTI MOKINI
                string ieskomasVardas;
                cout << "Iveskite mokinio, kuri norite pasalinti, varda: ";
                cin >> ieskomasVardas;

                int indeksas = -1;
                for (int i = 0; i < mokiniai_sk; ++i) {
                    if (vardai[i] == ieskomasVardas) {
                        indeksas = i;
                        break;
                    }
                }

                if (indeksas != -1) {
                    // Perkelimas viena vieta i prieki, kad uzpildyti tuscia vieta
                    for (int i = indeksas; i < mokiniai_sk - 1; ++i) {
                        vardai[i] = vardai[i + 1];
                        for (int j = 0; j < MAX_PAZYMIAI; ++j) {
                            pazymiai[i][j] = pazymiai[i + 1][j];
                        }
                    }
                    
                    mokiniai_sk--; 
                    cout << "Mokinys \"" << ieskomasVardas << "\" pasalintas sekmingai.\n";
                } else {
                    cout << "Mokinys nerastas.\n";
                }
                break;
            }

            default:
                cout << "Nezinomas pasirinkimas. Bandykite dar karta (1-5).\n";
        }
        cout << "\n==========================================\n";
    }

    return 0;
}