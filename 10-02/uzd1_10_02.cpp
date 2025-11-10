#include <iostream>
using namespace std;

int main() {
    int masyvas[4];
    int n=5, suma=0;
    int didz;
    cout<<"Iveskite masyvo elementa:"<<endl;
    for (int i=0;i<n;i++){
        cin>>masyvas[i];
        suma+=masyvas[i];
    }
    for (int i=0;i<-1;i++) { //ISSIAISKINTI
        didz=masyvas[i];
        if(masyvas[i]>didz){
            didz=masyvas[i];
        }
    }
    cout<<suma<<didz<<endl;
    return 0;
}
