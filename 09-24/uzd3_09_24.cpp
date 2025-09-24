#include <iostream>
using namespace std;

int main() {
    int egz_paz;
    cout<<"Iveskite egzamino ivertinima: ";
    cin>>egz_paz;
    if(egz_paz==10){
        cout<<"Puiku"<<endl;
    }
    else if(egz_paz==9){
        cout<<"Labai gerai"<<endl;
    }
    else if(egz_paz>=7){
        cout<<"Gerai"<<endl;
    }
    else if(egz_paz>=5){
        cout<<"Patenkinamai"<<endl;
    }
    else if(egz_paz<=0){
        cout<<"Ivestas negalimas ivertinimas"<<endl;
    }
    else cout<<"Egzaminas neislaikytas"<<endl;
    return 0;
}