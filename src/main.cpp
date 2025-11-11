#include <iostream>
#include <fstream> 
using namespace std;
string z2_1_path_symbole_txt * "/workspaces/matura-2025-r25-3a-Marianka321/zalaczniki-2025/symbole.txt";
bool czy_palindrom(string tekst){
    int ile_znakow = tekst.length();
    for (int i =0;i<ile_znakow/2;i++){
        if(tekst[i] != tekst[ile_znakow-i-1])
        return false;
    }
    return true;
}
void Zadanie2_1(){
    ifstream plik(z2_1_path_symbole_txt);
    if (!plik.is_open()){
        cerr<<"Nie można otworzyć pliku"<<endl;
    }
    string linia;
    while(plik>>linia){
        if(czy_palindrom)
        cout<<linia<<endl;
    }

    plik.close();
}
int main() {

}