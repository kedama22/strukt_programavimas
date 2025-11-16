#include <iostream>
using namespace std;

int main() {
    int n,a=0;
    int skaicius[10];
    cout<<"Iveskite sk.: ";
    cin>>n;
    while (n/10!=0) {
        a++;
        n=n/10;
    }
    for(int i=0;i<a;i++) {
        skaicius[i]=n%10;
        n=n/10;
    }
    for(int i=0;i<a;i++) {
        //??????????????????
    }
    cout<<a+1<<endl;
    return 0;
}