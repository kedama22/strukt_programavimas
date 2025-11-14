#include <iostream>
using namespace std;

int main() {
    for (int i=1;i<20+1;i++) {
        if(i%5==0) {
            cout<<"- ";
            continue;
        }
        else cout<<i<<" ";
    }
    return 0;
}