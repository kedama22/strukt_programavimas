#include <iostream>
#include <fstream>
#include <iomanip>
#include <string> //gal nereikia??

using namespace std;

const char FIN1[]="bilietu_pardavimu_info.csv";
const char FIN2[]="salary.txt";
const char FOUT2[]="new_salary.txt";
// const char FOUT[]=""

void menu() {
    cout<<"---- Duomenu apdorojimo sistema ----\n";
    cout<<"1. Skaiciuoti bilietu pardavimus\n";
    cout<<"2. Perziureti atnaujintus atlyginimus\n";
    cout<<"3. Iseiti\n";
    cout<<"------------------------------------\n";
}

int main() {
    int pas;
    menu();
    cin>>pas;
    do {
        if (pas=3) {
            cout<<"Iseinama is programos"<<endl;
            break;
        }
        if (pas!=1 && pas!=2) {
            cout<<"Ivestas neteisingas pasirinkimas"<<endl;
            break;
        }
        switch (pas) {
            case 1:
            {
                ifstream fin1(FIN1);

            }
            case 2:
            {
                ifstream fin2(FIN2);
            }
        }
    } while (pas==1 || pas==2);
    return 0;
}