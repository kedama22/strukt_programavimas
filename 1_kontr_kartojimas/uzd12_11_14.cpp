#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Iveskite skaiciu kieki: ";
    cin>>n;
    cout<<"Iveskite skaicius: "<<endl;
    int sk[n];
    for(int i=0;i<n;i++) {
        cin>>sk[i];
    }
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(sk[j]<sk[i]) {
                int temp=sk[i];
                sk[i]=sk[j];
                sk[j]=temp;
                //???????????????????? manrods supratau
            }
        }
    }
    cout<<"Maziausias sk.: "<<sk[0]<<endl;
    return 0;
}