#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;

string z3_1_path_symbole_txt = "../zalaczniki-2025/symbole.txt";

long long to_decimal(const string& trinary_str) {
    long long decimal_val = 0;
    long long power_of_3 = 1;
    
    
    for (int i = trinary_str.length() - 1; i >= 0; --i) {
        int digit = 0;
        char symbol = trinary_str[i];
        
        if (symbol == 'o') {
            digit = 0;
        } else if (symbol == '+') {
            digit = 1;
        } else if (symbol == '*') {
            digit = 2;
        } else {
            continue;
        }
        
        decimal_val += (long long)digit * power_of_3;
        power_of_3 *= 3;
    }
    return decimal_val;
}

/**
 * @brief
 */
string to_trinary_string(long long decimal_val) {
    if (decimal_val == 0) {
        return "o";
    }

    string trinary_str = "";
    long long temp_val = decimal_val;
    
    while (temp_val > 0) {
        int remainder = temp_val % 3;
        char symbol;
        
        if (remainder == 0) {
            symbol = 'o';
        } else if (remainder == 1) {
            symbol = '+';
        } else { 
            symbol = '*';
        }
        
        trinary_str += symbol;
        temp_val /= 3;
    }
    
    
    std::reverse(trinary_str.begin(), trinary_str.end());
    return trinary_str;
}
bool czy_palindrom(string slowo)
{
    int dlugosc = slowo.length();
    for(int i = 0; i < dlugosc / 2; i++)
    {
        if(slowo[i] != slowo[dlugosc - i - 1])
        {
            return false;
        }
    }
    return true;
}

void zadanie2_1()
{
    ifstream plik(z3_1_path_symbole_txt);
    if(!plik.is_open())
    {
        cerr << "nie mozna otworzyc pliku" << endl;
    }

    string linia;
    while(plik >> linia)
    {
        if (czy_palindrom(linia))
        {
            cout << linia << endl;
        }
    }


    plik.close();

}
 void zadanie3_1(){
    ifstream plik(z3_1_path_symbole_txt);
    if(!plik.is_open()){
        cerr<<"nie mozna otworzyc pliku:" << z3_1_path_symbole_txt << endl;
        return;
    }

    vector<string> data;
    string linia;
    while(getline(plik, linia)) {
        if(!linia.empty()){
            data.push_back(linia);
        }
    }
    plik.close();
    int rows = data.size();
    if(rows < 3 ) return;
    int cols = data[0].size();
    if (cols<3) return;
    
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        if (data[i].size() != cols) {
          
            break; 
        }
        for (int j = 0; j < cols; ++j) {
            char symbol = data[i][j];
            if (symbol == 'o') {
                matrix[i][j] = 0;
            } else if (symbol == '+') {
                matrix[i][j] = 1;
            } else if (symbol == '*') {
                matrix[i][j] = 2;
            } else {
                matrix[i][j] = -1; 
            }
        }
    }
vector<pair<int, int>> squares_found;
    
    
    for (int i = 1; i < rows - 1; ++i) {
        for (int j = 1; j < cols - 1; ++j) {
            int centerValue = matrix[i][j];
            bool isSquare = true;

            
            for (int r = i - 1; r <= i + 1; ++r) {
                for (int c = j - 1; c <= j + 1; ++c) {
                   
                    if (matrix[r][c] != centerValue) {
                        isSquare = false;
                        break;
                    }
                }
                if (!isSquare) break;
            }

            if (isSquare) {
                
                squares_found.push_back({i + 1, j + 1});
            }
        }
    }
cout << "\n--- Zadanie Kwadraty (3x3) ---\n";
    cout << "Liczba znalezionych kwadratow: " << squares_found.size() << endl;

    if (!squares_found.empty()) {
        cout << "Wspolrzedne srodkowych pol (wiersz, pozycja w wierszu, liczac od 1):\n";
        for (const auto& p : squares_found) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }
 }
 


void zadanie3_2() {
    ifstream plik(z3_1_path_symbole_txt);
    if (!plik.is_open()) {
        cerr << "Nie mozna otworzyc pliku: " << z3_1_path_symbole_txt << endl;
        return;
    }
    
    long long max_val = -1;
    string max_str = "";
    string linia;

    cout << "\n--- Zadanie Najwieksza Liczba Trojkowa ---\n";

    
    while (getline(plik, linia)) {
        if (!linia.empty()) {
            
            long long current_val = to_decimal(linia);
            
            
            if (current_val > max_val) {
                max_val = current_val;
                max_str = linia;
            }
          
        }
    }
    plik.close();
    
  
    if (max_val >= 0) {
        cout << "Najwieksza liczba (dziesietnie): " << max_val << endl;
        cout << "Odpowiadajacy jej napis: " << max_str << endl;
        
        cout << "Odpowiedz: " << max_val << " " << max_str << endl;
    } else {
        cout << "Plik jest pusty lub zawiera nieprawidlowe dane." << endl;
    }
}
void zadanie3_3() {
    ifstream plik(z3_1_path_symbole_txt);
    if (!plik.is_open()) {
        cerr << "Nie mozna otworzyc pliku: " << z3_1_path_symbole_txt << endl;
        return;
    }
    
    long long total_sum = 0;
    string linia;

    
    while (getline(plik, linia)) {
        if (!linia.empty()) {
            total_sum += to_decimal(linia);
        }
    }
    plik.close();
    
    
    string trinary_sum_str = to_trinary_string(total_sum);
    
    
    cout << "\n--- Zadanie Suma Liczb Trojkowych ---\n";
    cout << "Odpowiedz: " << total_sum << " " << trinary_sum_str << endl;
}


int main(){


    zadanie2_1();
    zadanie3_1();
    zadanie3_2();
   zadanie3_3();
    return 0;
}
