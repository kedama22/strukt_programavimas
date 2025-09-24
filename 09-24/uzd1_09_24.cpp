#include <iostream>
using namespace std;

int main() {
    int n; //pazymiu sk.
    int paz;
    int suma=0;
    cout<<"Iveskite pazymiu sk.: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        //cout<<"Iveskite pazymi: "<<endl;
        cin>>paz;
        suma+=paz;
    }
    int vidurkis=suma/n;
    if(vidurkis>=5) {
        cout<<"Vidurkis teigiamas!"<<endl;
    }
    else cout<<"Vidurkis yra neigiamas :("<<endl;
    return 0;
}