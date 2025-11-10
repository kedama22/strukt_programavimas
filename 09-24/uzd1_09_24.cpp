#include <iostream>
using namespace std;

int main() {
    int n; //pazymiu sk.
    int paz;
    int suma=0;
    cout<<"Iveskite pazymiu sk.: ";
    cin>>n;
    cout<<"Iveskite pazymi: "<<endl;
    for(int i=0;i<n;i++){
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