#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Iveskite skaiciu: ";
    cin >> n;

    if (n < 0) {
        cout << "Skaicius yra neigiamas." << endl;
    } else if (n > 0) {
        cout << "Skaicius yra teigiamas." << endl;
    } else {
        cout << "Skaicius yra lygus nuliui." << endl;
    }

    return 0;
}