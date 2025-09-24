#include <iostream>
#include <iomanip>
using namespace std;

struct GBP {
const double GBP_Bendras=0.8729;
const double GBP_Pirkti=0.8600;
const double GBP_parduoti=0.9220;
};

struct USD {
const double USD_Bendras=1.1793;
const double USD_Pirkti=1.1460;
const double USD_Parduoti=1.2340;
};

struct INR {
const double INR_Bendras=104.6918;
const double INR_Pirkti=101.3862;
const double INR_Parduoti=107.8546;
};

int main() {
    GBP gbp;
    USD usd;
    INR inr;
    int pasirinkimas;
    string valiuta;
    double eurai;
    cout<<"Iveskite '1', jei norite lyginti valiutas\nIveskite '2', jei norite isigyti valiuta\nIveskite '3', jei norite parduoti valiuta"<<endl;
    cin>>pasirinkimas;
    switch (pasirinkimas)
    {
        case 1: //valiutu lyginimas

        break;
        case 2: //pirkti valiuta
        double pirkti;
        cout<<"Iveskite eur: ";
        cin>>eurai;
        if(eurai<=0){
            cout<<"Ivesta netinkama suma"<<endl;
            return 0;
        }
        cout<<"Iveskite valiuta, kuria norite pirkti (GBP/USD/INR): ";
        cin>>valiuta;
        if(valiuta=="GBP"||valiuta=="gbp"||valiuta=="Gbp"){
            pirkti=eurai*gbp.GBP_Pirkti;
            cout<<"Suma, kuria nusipirkote: "<<fixed<<setprecision(2)<<pirkti<<" GBP."<<endl;
        }
        else if(valiuta=="USD"||valiuta=="usd"||valiuta=="Usd"){
            pirkti=eurai*usd.USD_Pirkti;
            cout<<"Suma, kuria nusipirkote: "<<fixed<<setprecision(2)<<pirkti<<" USD."<<endl;
        }
        else if(valiuta=="INR"||valiuta=="inr"||valiuta=="Inr"){
            pirkti=eurai*inr.INR_Pirkti;
            cout<<"Suma, kuria nusipirkote: "<<fixed<<setprecision(2)<<pirkti<<" INR."<<endl;
        }
        else cout<<"Ivesta netinkama valiuta"<<endl;
        break;
        case 3: //parduoti valiuta
        double parduoti;
        cout<<"Iveskite valiuta, kuria norite parduoti (GBP/USD/INR): ";
        cin>>valiuta;
        cout<<"Iveskite parduodama suma: ";
        cin>>eurai;
        if(eurai<=0){
            cout<<"Ivesta netinkama suma"<<endl;
            return 0;
        }

        if(valiuta=="GBP"||valiuta=="gbp"||valiuta=="Gbp"){
            pirkti=eurai*gbp.GBP_Pirkti;
            cout<<"Suma, kuria nusipirkote: "<<fixed<<setprecision(2)<<pirkti<<" GBP."<<endl;
        }
        else if(valiuta=="USD"||valiuta=="usd"||valiuta=="Usd"){
            pirkti=eurai*usd.USD_Pirkti;
            cout<<"Suma, kuria nusipirkote: "<<fixed<<setprecision(2)<<pirkti<<" USD."<<endl;
        }
        else if(valiuta=="INR"||valiuta=="inr"||valiuta=="Inr"){
            pirkti=eurai*inr.INR_Pirkti;
            cout<<"Suma, kuria nusipirkote: "<<fixed<<setprecision(2)<<pirkti<<" INR."<<endl;
        }
        else cout<<"Ivesta netinkama valiuta"<<endl;
        break;
        default: cout<<"Ivestas netinkamas pasirinkimas"<<endl;
    }
}