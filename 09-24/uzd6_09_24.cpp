#include <iostream>
using namespace std;
int main() {
    double prad=1000;
    double palukanos=0.05;
    int m=10;
    double suma;
    for(int i=0;i<m;i++){
        suma=prad+(prad*palukanos);
        prad=suma;
    }
    cout<<"Suma po 10 metu: "<<suma<<" euru."<<endl;
    return 0;
}