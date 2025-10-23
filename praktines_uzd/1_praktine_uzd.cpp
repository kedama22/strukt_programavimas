#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Kursu strukturos
struct GBP {
const double GBP_Bendras=0.8729;
const double GBP_Pirkti=0.8600;
const double GBP_Parduoti=0.9220;
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
    int pas1, pas2; //pasirinkimai (didysis ir case 1)
    string valiuta;
    double suma;
    do { //loopina koda iki pirmo neteisingo pasirinkimo
    cout<<"Iveskite '1', jei norite lyginti valiutas\nIveskite '2', jei norite isigyti valiuta\nIveskite '3', jei norite parduoti valiuta"<<endl;
    cin>>pas1;
    switch (pas1) //didysis pasirinkimas
    {
        case 1: //valiutu lyginimas
        {
        double keisti;
        cout<<"Iveskite '1', jeigu norite versti EUR i kita valiuta\nIveskite '2', jeigu norite versti kita valiuta i EUR"<<endl;
        cin>>pas2;
        switch (pas2) { //keitimo pasirinkimas
            case 1: //EUR i kita valiuta
                {
                    cout<<"Iveskite suma, kuria norite versti:";
                    cin>>suma;
                    if(suma<=0){
                    cout<<"Ivesta netinkama suma"<<endl;
                    break;}
                    cout<<"Iveskite kita valiuta: ";
                    cin>>valiuta;
                    if(valiuta=="GBP"||valiuta=="gbp"){
                        keisti=suma*gbp.GBP_Bendras;
                        cout<<"Gauta suma: "<<fixed<<setprecision(2)<<keisti<<" GBP."<<endl;
                    }
                    else if(valiuta=="USD"||valiuta=="usd"){
                        keisti=suma*usd.USD_Bendras;
                        cout<<"Gauta suma: "<<fixed<<setprecision(2)<<keisti<<" USD."<<endl;
                    }
                    else if(valiuta=="INR"||valiuta=="inr"){
                        keisti=suma*inr.INR_Bendras;
                        cout<<"Gauta suma: "<<fixed<<setprecision(2)<<keisti<<" INR."<<endl;
                    }
                    else cout<<"Ivesta netinkama valiuta"<<endl;
                    break;
                }
            case 2: //kita valiuta i EUR
                {
                    cout<<"Iveskite suma, kuria norite versti:";
                    cin>>suma;
                    if(suma<=0){
                    cout<<"Ivesta netinkama suma"<<endl;
                    break;}
                    cout<<"Iveskite kita valiuta: ";
                    cin>>valiuta;
                    if(valiuta=="GBP"||valiuta=="gbp"){
                        keisti=suma/gbp.GBP_Bendras;
                        cout<<"Gauta suma: "<<fixed<<setprecision(2)<<keisti<<" EUR."<<endl;
                    }
                    else if(valiuta=="USD"||valiuta=="usd"){
                        keisti=suma/usd.USD_Bendras;
                        cout<<"Gauta suma: "<<fixed<<setprecision(2)<<keisti<<" EUR."<<endl;
                    }
                    else if(valiuta=="INR"||valiuta=="inr"){
                        keisti=suma/inr.INR_Bendras;
                        cout<<"Gauta suma: "<<fixed<<setprecision(2)<<keisti<<" EUR."<<endl;
                    } 
                    else cout<<"Ivesta netinkama valiuta"<<endl;
                    break;
                }
            default: cout<<"Ivestas netinkamas pasirinkimas"<<endl;
            break;
                }
            break;
        }
        case 2: //pirkti valiutas
        {
        double pirkti;
        cout<<"Iveskite eur: ";
        cin>>suma;
        if(suma<=0){
            cout<<"Ivesta netinkama suma"<<endl;
            break;
        }
        cout<<"Iveskite valiuta, kuria norite pirkti (GBP/USD/INR): ";
        cin>>valiuta;
        if(valiuta=="GBP"||valiuta=="gbp"){
            pirkti=suma*gbp.GBP_Pirkti;
            cout<<"Gauta suma: "<<fixed<<setprecision(2)<<pirkti<<" GBP."<<endl;
        }
        else if(valiuta=="USD"||valiuta=="usd"){
            pirkti=suma*usd.USD_Pirkti;
            cout<<"Gauta suma: "<<fixed<<setprecision(2)<<pirkti<<" USD."<<endl;
        }
        else if(valiuta=="INR"||valiuta=="inr"){
            pirkti=suma*inr.INR_Pirkti;
            cout<<"Gauta suma: "<<fixed<<setprecision(2)<<pirkti<<" INR."<<endl;
        }
        else cout<<"Ivesta netinkama valiuta"<<endl;
        break;
        }
        case 3: //parduoti valiuta
        {
        double parduoti;
        cout<<"Iveskite parduodama suma: ";
        cin>>suma;
        if(suma<=0){
            cout<<"Ivesta netinkama suma"<<endl;
            break;
        }
        cout<<"Iveskite valiuta, kuria norite parduoti (GBP/USD/INR): ";
        cin>>valiuta;
        if(valiuta=="GBP"||valiuta=="gbp"){
            parduoti=suma/gbp.GBP_Parduoti;
            cout<<"Gauta suma: "<<fixed<<setprecision(2)<<parduoti<<" EUR."<<endl;
        }
        else if(valiuta=="USD"||valiuta=="usd"){
            parduoti=suma/usd.USD_Parduoti;
            cout<<"Gauta suma: "<<fixed<<setprecision(2)<<parduoti<<" EUR."<<endl;
        }
        else if(valiuta=="INR"||valiuta=="inr"){
            parduoti=suma/inr.INR_Parduoti;
            cout<<"Gauta suma: "<<fixed<<setprecision(2)<<parduoti<<" EUR."<<endl;
        }
        else cout<<"Ivesta netinkama valiuta"<<endl;
        break;
        }
        default: cout<<"Ivestas netinkamas pasirinkimas"<<endl;
    }
    } while(pas1==1 || pas1==2 || pas1==3);
    return 0;
}
