#include <iostream>

using namespace std;

int main(){
    int a;
    int v,d;
    cout<<"Iveskite dvizenkli skaiciu: ";
    cin>>a;
    v=a%10;
    d=a/10;
    cout<<"Skaiciaus skaitmenu suma: "<<v+d<<endl;
    return 0;
}