#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <memory>

#include "ZbiorTokenow.h"
#include <memory_resource>

bool sprawdzenieTokena(const std::string &token)
{
    for (size_t i = 0; i < token.length(); ++i)
    {
        const char c = token[i];

        if (std::isspace(c))
            continue;

        if (!std::isdigit(c) &&
            !std::isalpha(c) &&
            c != '+' && c != '-' &&
            c != '*' && c != '/' &&
            c != '(' && c != ')')
        {

            std::cerr << "Znaleziono nieprawidlowy symbol: '" << c
                      << "' na pozycji: " << i << "\n";
            return false;
        }
    }
    return true;
}

std::unique_ptr<Token> DAS(std::string &text)
{
    if (text.empty())
        return nullptr;

    char c = text[0];

    switch (c)
    {
        case '+':
            text.erase(0, 1);
        return std::make_unique<Plus>();
        case '-':
            text.erase(0, 1);
        return std::make_unique<Minus>();
        case '*':
            text.erase(0, 1);
        return std::make_unique<Mnozenie>();
        case '/':
            text.erase(0, 1);
        return std::make_unique<Dzielenie>();
        case '(':
            text.erase(0, 1);
        return std::make_unique<LewyNawias>();
        case ')':
            text.erase(0, 1);
        return std::make_unique<PrawyNawias>();
    }

    size_t i = 0;
    while (i < text.size() &&
           std::string("+-*/()").find(text[i]) == std::string::npos)
    {
        ++i;
    }

    std::string tokenStr = text.substr(0, i);
    text.erase(0, i);

    if (std::all_of(tokenStr.begin(), tokenStr.end(),
                    [](unsigned char c)
                    { return std::isdigit(c); }))
    {
        return std::make_unique<Liczba>(tokenStr);
    }
    else
    {
        return std::make_unique<Identyfikator>(tokenStr);
    }
}
int main()
{
    std::string text;
    std::getline(std::cin, text);
    std::string buffer = text;
    if (!sprawdzenieTokena(text))
        return 1;
    buffer.erase(
    std::remove_if(buffer.begin(), buffer.end(),
                   [](unsigned char c){ return std::isspace(c); }),
    buffer.end());
    std::pmr::vector<std::unique_ptr<Token>> tokens;
    while (!buffer.empty()) {
        tokens.push_back(DAS(buffer));
    }
    size_t textIndex = 0;
    for (const auto &token : tokens)
    {
        std::string symbol = token->getSymbol();
        while (textIndex < text.length() && std::isspace(text[textIndex]))
        {
            std::cout <<  text[textIndex++];
        }
        std::cout << *token;
        textIndex += symbol.length();
    }
    return 0;
}