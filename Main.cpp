#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "ZbiorTokenow.h"
#include <memory_resource>

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
std::pmr::vector<Token>* DAS(const std::string& text) {
    auto* tokens = new std::pmr::vector<Token>();
    std::string buffer = "";
    for (char c : text) {
        switch (c) {
            case '+':
                if (buffer != "") {
                    tokens->push_back(Liczba(buffer));
                    buffer = "";
                }
                tokens->push_back(Plus());
                break;
            case '-':
                if (buffer != "") {
                    tokens->push_back(Liczba(buffer));
                    buffer = "";
                }
                tokens->push_back(Minus());
                break;
            case '*':
                if (buffer != "") {
                    tokens->push_back(Liczba(buffer));
                    buffer = "";
                }
                tokens->push_back(Mnozenie());
                break;
            case '/':
                if (buffer != "") {
                    tokens->push_back(Liczba(buffer));
                    buffer = "";
                }
                tokens->push_back(Dzielenie());
                break;
            case '(':
                if (buffer != "") {
                    tokens->push_back(Liczba(buffer));
                    buffer = "";
                }
                tokens->push_back(LewyNawias());
                break;
            case ')':
                if (buffer != "") {
                    tokens->push_back(Liczba(buffer));
                    buffer = "";
                }
                tokens->push_back(PrawyNawias());
                break;
            default:
                buffer += c;
                break;
        }
    }
    if (buffer != "") {
        tokens->push_back(Liczba(buffer));
    }
    return tokens;
}

int main(){
    std::string text;
    std::cin >> text;
    if (!sprawdzenieTokena(text)) {
        return 1;
    }
    auto* tokens = DAS(text);
    return 0;
}