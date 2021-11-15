#include <iostream>
#include <fstream>

using namespace std;

class Uczen
{
public:
   
    int klasa;
    float ocena_kon_jp, ocena_kon_mat, ocena_kon_fiz;
    string imie="";
    string nazwisko="";

    void dodaj_Ucznia() {
        cout << "Podaj imie:";
        cin >> imie;
        cout <<endl<< "Podaj nazwisko:";
        cin >> nazwisko;
        cout << endl << "Podaj klase:";
        cin >> klasa;
        cout << endl << "Podaj ocene koncowa z jezyka polskiego:";
        cin >> ocena_kon_jp;
        cout << endl << "Podaj ocene koncowa z matemamatyki:";
        cin >> ocena_kon_mat;
        cout << endl << "Podaj ocene koncowa z fizyki:";
        cin >> ocena_kon_fiz;
    }
    void wyswietl_Dane() {
        cout <<endl<<"Imie: " << imie;
        cout << endl <<"Nazwisko: "<< nazwisko;
        cout << endl <<"Klasa: " << klasa;
    }
    void wyswietl_Oceny() {
        cout << endl << "ocene koncowa z jezyka polskiego: " << ocena_kon_jp;
        cout << endl << "ocene koncowa z  matemamatyki: " << ocena_kon_mat;
        cout << endl << "ocene koncowa z fizyki: " << ocena_kon_fiz<<endl;
    }
    void Metryczka() {
        cout << "Imie i nazwisko: Robert Dec"<<endl;
        cout << "Klasa 3CG";
    }
    
};

void srednia_ocen(Uczen ob1, Uczen ob2) {
    float sr_uczen1,sr_uczen2;
    
    sr_uczen2 = (ob2.ocena_kon_fiz + ob2.ocena_kon_jp + ob2.ocena_kon_mat)/3;
    sr_uczen1=(ob1.ocena_kon_fiz + ob1.ocena_kon_jp + ob1.ocena_kon_mat) / 3;

    if (sr_uczen1 > sr_uczen2) {
        cout << "Uczen " << ob1.imie << " " << ob1.nazwisko << " ma większa srednia od " << ob2.imie << " " << ob2.nazwisko << " o: " << sr_uczen1 - sr_uczen2;
    }
    else if (sr_uczen2 > sr_uczen1) {
        cout << "Uczen " << ob2.imie << " " << ob2.nazwisko << " ma większa srednia od " << ob1.imie << " " << ob1.nazwisko << " o: " << sr_uczen2 - sr_uczen1;
    }
    else {
        cout << "Uczniowie maja identyczyna srednia";
    }

}
int main()
{
    
    fstream zapis("uczniowie.txt", ios::out);
    Uczen uczen1;
    Uczen uczen2;

    cout << "Dane uczen 1: " << endl;
    uczen1.dodaj_Ucznia();
    uczen1.wyswietl_Dane();
    uczen1.wyswietl_Oceny();
    cout <<endl<<endl<< "Dane uczen 2: " << endl;
    uczen2.dodaj_Ucznia();
    uczen2.wyswietl_Dane();
    uczen2.wyswietl_Oceny();

    zapis <<"Imie: " << uczen1.imie << endl;
    zapis <<"Nazwisko: "<< uczen1.nazwisko << endl;
    zapis <<"Klasa:"<< uczen1.klasa << endl;
    zapis<<"Ocena koncowa z jezyka polskiego" << uczen1.ocena_kon_jp << endl;
    zapis << "Ocena koncowa z fizyki " << uczen1.ocena_kon_fiz << endl;
    zapis <<"Ocena koncowa z matematyki" << uczen1.ocena_kon_mat<<endl<<endl;
    
    zapis << "Imie: " << uczen2.imie << endl;
    zapis << "Nazwisko: " << uczen2.nazwisko << endl;
    zapis << "Klasa:" << uczen2.klasa << endl;
    zapis << "Ocena koncowa z jezyka polskiego" << uczen2.ocena_kon_jp << endl;
    zapis << "Ocena koncowa z fizyki " << uczen2.ocena_kon_fiz << endl;
    zapis << "Ocena koncowa z matematyki" << uczen2.ocena_kon_mat << endl << endl;

    srednia_ocen(uczen1,uczen2);
}
