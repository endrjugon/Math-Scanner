#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "ZbiorTokenow.h"


bool sprawdzenieTokena(const std::string& token) {
    for (char c : token) {
        if (std::isspace(c)) continue;
        
        if (!std::isdigit(c) && 
            c != '+' && c != '-' && 
            c != '*' && c != '/' && 
            c != '(' && c != ')') {
            std::cerr << "Znaleziono nieprawidlowy symbol: '" << c << "'\n";
            return false; 
        }
    }
    return true;
}


int main(){
    return 0;
}