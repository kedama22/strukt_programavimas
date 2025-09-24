#include <iostream>

using namespace std;

int main() {
    int a;
    int suma=0;
    int n=5;
    double vidurkis;
    for(int i=0;i<n;i++){
        cin>>a;
        suma+=a;
    }
    vidurkis=static_cast<double>(suma)/n;
    cout<<"Vidurkis: "<<vidurkis<<endl;
    return 0;
}