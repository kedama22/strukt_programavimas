#include <iostream>
using namespace std;

int main() {
    int egz_paz;
    cout<<"Iveskite egzamino ivertinima: ";
    cin>>egz_paz;
    switch (egz_paz)
    {
        case 10:
            cout<<"Puiku"<<endl;
            break;
        case 9:
            cout<<"Labai gerai"<<endl;
            break;
        case 8:
            cout<<"Gerai"<<endl;
            break;
        case 7:
            cout<<"Gerai"<<endl;
            break;
        case 6:
            cout<<"Patenkinamai"<<endl;
            break;
        case 5:
            cout<<"Patenkinamai"<<endl;
            break;
        case 4:
            cout<<"Egzaminas neislaikytas"<<endl;
            break;
        case 3:
            cout<<"Egzaminas neislaikytas"<<endl;
            break;
        case 2:
            cout<<"Egzaminas neislaikytas"<<endl;
            break;
        case 1:
            cout<<"Egzaminas neislaikytas"<<endl;
            break;
        default: cout<<"Ivestas negalimas ivertinimas"<<endl;
    }
    return 0;
}