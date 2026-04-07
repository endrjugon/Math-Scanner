#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <memory>

#include "ZbiorTokenow.h"
#include <memory_resource>

bool sprawdzenieTokena(const std::string& token) {
    for (size_t i = 0; i < token.length(); ++i) {
        const char c = token[i];

        if (std::isspace(c)) continue;

        if (!std::isdigit(c) &&
            !std::isalpha(c) &&
            c != '+' && c != '-' &&
            c != '*' && c != '/' &&
            c != '(' && c != ')') {

            std::cerr << "Znaleziono nieprawidlowy symbol: '" << c
                      << "' na pozycji: " << i << "\n";
            return false;
            }
    }
    return true;
}
std::pmr::vector<std::unique_ptr<Token>> DAS(const std::string& text) {
std::pmr::vector<std::unique_ptr<Token>> tokens;
    std::string buffer = "";
    for (char c : text) {
        switch (c) {
            case '+':
                if (buffer != "") {
                    if (std::all_of(buffer.begin(), buffer.end(),[](unsigned char c){return std::isdigit(c);})) {
                        tokens.push_back(std::make_unique<Liczba>(buffer));
                    }
                    else {
                        tokens.push_back(std::make_unique<Identyfikator>(buffer));
                    }

                    buffer = "";
                }
                tokens.push_back(std::make_unique<Plus>());
                break;
            case '-':
                if (buffer != "") {
                    if (std::all_of(buffer.begin(), buffer.end(),[](unsigned char c){return std::isdigit(c);})) {
                        tokens.push_back(std::make_unique<Liczba>(buffer));
                    }
                    else {
                        tokens.push_back(std::make_unique<Identyfikator>(buffer));
                    }
                    buffer = "";
                }
                tokens.push_back(std::make_unique<Minus>());
                break;
            case '*':
                if (buffer != "") {
                    if (std::all_of(buffer.begin(), buffer.end(),[](unsigned char c){return std::isdigit(c);})) {
                        tokens.push_back(std::make_unique<Liczba>(buffer));
                    }
                    else {
                        tokens.push_back(std::make_unique<Identyfikator>(buffer));
                    }
                    buffer = "";
                }
                tokens.push_back(std::make_unique<Mnozenie>());
                break;
            case '/':
                if (buffer != "") {
                    if (std::all_of(buffer.begin(), buffer.end(),[](unsigned char c){return std::isdigit(c);})) {
                        tokens.push_back(std::make_unique<Liczba>(buffer));
                    }
                    else {
                        tokens.push_back(std::make_unique<Identyfikator>(buffer));
                    }
                    buffer = "";
                }
                tokens.push_back(std::make_unique<Dzielenie>());
                break;
            case '(':
                if (buffer != "") {
                    if (std::all_of(buffer.begin(), buffer.end(),[](unsigned char c){return std::isdigit(c);})) {
                        tokens.push_back(std::make_unique<Liczba>(buffer));
                    }
                    else {
                        tokens.push_back(std::make_unique<Identyfikator>(buffer));
                    }
                    buffer = "";
                }
                tokens.push_back(std::make_unique<LewyNawias>());
                break;
            case ')':
                if (buffer != "") {
                    if (std::all_of(buffer.begin(), buffer.end(),[](unsigned char c){return std::isdigit(c);})) {
                        tokens.push_back(std::make_unique<Liczba>(buffer));
                    }
                    else {
                        tokens.push_back(std::make_unique<Identyfikator>(buffer));
                    }
                    buffer = "";
                }
                tokens.push_back(std::make_unique<PrawyNawias>());
                break;
            default:
                buffer += c;
                break;
        }
    }
    if (!buffer.empty()) {
        if (std::all_of(buffer.begin(), buffer.end(),[](unsigned char c){return std::isdigit(c);})) {
            tokens.push_back(std::make_unique<Liczba>(buffer));
        }
        else {
            tokens.push_back(std::make_unique<Identyfikator>(buffer));
        }
    }
    return tokens;
}
std::string usuwanieSpacji(const std::string& input) {
    std::string result;
    for (char c : input) {
        if (!std::isspace(c)) {
            result += c;
        }
    }
    return result;
}

int main(){
    std::string text;
    std::getline(std::cin, text);
    text = usuwanieSpacji(text);

    if (!sprawdzenieTokena(text)) return 1;

    auto tokens = DAS(text);

    for (const auto& token : tokens) {
        std::cout << *token;  // dereference pointer
    }
    return 0;
}