#include <iostream>
#include <fstream>

using namespace std;

int main() {

    int N, broj, suma, temp;
    double prosek;

#pragma region Kreiranje fajla i punjenje rnd brojevima

    cin >> N; //Unosim broj nasumicnih brojeva
    suma = 0; //Postavljam sumu na 0

    ofstream dat10o("DAT10.TXT"); //Otvaram fajl u koji cu upisati sve nasumicne brojeve

    srand((time(0)));
    

    for (int i = 0; i < N; i++) {

        broj = rand() % 1000 + 1; //Generisem nasumicni broj

        suma += broj; //Sumu linije povecavam za taj broj

        //proveravam da li je suma manja od 5000 (limit za sumu u datoj liniji)
        if (suma <= 5000) {

            dat10o << broj << " "; //Ako jeste upisujemo taj broj u fajl

        }
        else {

            dat10o << "\n"; //Ako nije upisujemo karakter \n da predjemo u novi red
            dat10o << broj << " "; //Upisujemo nasumicni broj
            suma = broj; //Postavljamo sumu u liniji na vrednost tog broja

        }
    }
    dat10o.close();

#pragma endregion

#pragma region Obrada

    ifstream dat10i("DAT10.TXT"); //Otvaram fajl sa svim brojevim za unos u kasnije operacije
    ofstream rezultati("REZULTATI.TXT"); //Otvaram fajl za sumu, prosek i broj nadprosecnih
    ofstream nadprosecni("IZNADPROSEKA.TXT"); //Otvaram fajl u koji stavljam sve nadprosecne

    suma = 0; //resetujem sumu na 0 sobzirom da sam je koristio i pre
    temp = 0; //Postavljam temp na 0

    while (dat10i >> broj) {

        //racunam sumu svih brojeva i odredjujem broj svih brojeva (potencijalno bi bilo moguce koristiti N ali nisam siguran zbog \n karaktera)
        suma += broj;
        temp++;
    }

    prosek = double(suma) / temp; //racunam prosek

    rezultati << "prosek: " << prosek << endl; //Upisujem prosek u fajl rezultati
    rezultati << "Zbir: " << suma << endl; //Upisujem sumu u fajl rezultati

    temp = 0; //resetujem temp na 0 sobzirom da sam ga koristio i pre
    broj = 0; //resetujem broj na 0 sobzirom da sam ga koristio i pre

    dat10i.clear(); //Cisti error flag koji kaze da je na kraju fajla
    dat10i.seekg(0); //Vracanje na pocetak fajla 

    while (dat10i >> broj) {

        //proveravam za svaki broj iz fajla da li je veci od proseka
        if (broj > prosek) {
            nadprosecni << broj << " "; //ako jeste upisujem ga u fajl nadprosecni
            temp++; //povecavam broj nadprosecnih za 1
        }
    }

    rezultati << "nadprosecni: " << temp << endl; //Upisujem broj nadprosecnih u fajl rezultat


    //Zatvaram sve fajlove na kraju
    dat10i.close();
    rezultati.close();
    nadprosecni.close();

#pragma endregion

    return 0;
}
