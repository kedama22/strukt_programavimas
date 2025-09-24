#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string marke="OPEL";
    string modelis="ZAFIRA";
    int metai=2010;
    double litrazas=2.0;
    string spalva="sidabrine";
    cout<<"Automobilis "<<marke<<" "<<modelis<<" yra pagamintas "<<metai<<" metais. Jo motoras "<<fixed<<setprecision(1)<<litrazas<<"l litrazo. Automobilis yra "<<spalva<<"s spalvos."<<endl;
    return 0;
}