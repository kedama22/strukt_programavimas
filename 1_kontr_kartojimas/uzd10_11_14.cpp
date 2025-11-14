#include <iostream>
using namespace std;

int main() {
    int d,v;
    int n;
    cout<<"Iveskite skaiciu: ";
    cin>>n;
    d=n/10;
    v=n%10;
    n=(v*10)+d;
    cout<<n<<endl;
    return 0;
}