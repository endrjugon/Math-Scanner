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

std::pmr::vector<std::unique_ptr<Token>> DAS(const std::string &text)
{
    std::pmr::vector<std::unique_ptr<Token>> tokens;
    std::string buffer = "";
    for (char c : text)
    {
        if (std::isspace(c))
        {
            if (buffer != "")
            {
                if (std::all_of(buffer.begin(), buffer.end(), [](unsigned char c)
                                { return std::isdigit(c); }))
                {
                    tokens.push_back(std::make_unique<Liczba>(buffer));
                }
                else
                {
                    tokens.push_back(std::make_unique<Identyfikator>(buffer));
                }
                buffer = "";
            }
            continue;
        }

        switch (c)
        {
        case '+':
            if (buffer != "")
            {
                if (std::all_of(buffer.begin(), buffer.end(), [](unsigned char c)
                                { return std::isdigit(c); }))
                {
                    tokens.push_back(std::make_unique<Liczba>(buffer));
                }
                else
                {
                    tokens.push_back(std::make_unique<Identyfikator>(buffer));
                }

                buffer = "";
            }
            tokens.push_back(std::make_unique<Plus>());
            break;
        case '-':
            if (buffer != "")
            {
                if (std::all_of(buffer.begin(), buffer.end(), [](unsigned char c)
                                { return std::isdigit(c); }))
                {
                    tokens.push_back(std::make_unique<Liczba>(buffer));
                }
                else
                {
                    tokens.push_back(std::make_unique<Identyfikator>(buffer));
                }
                buffer = "";
            }
            tokens.push_back(std::make_unique<Minus>());
            break;
        case '*':
            if (buffer != "")
            {
                if (std::all_of(buffer.begin(), buffer.end(), [](unsigned char c)
                                { return std::isdigit(c); }))
                {
                    tokens.push_back(std::make_unique<Liczba>(buffer));
                }
                else
                {
                    tokens.push_back(std::make_unique<Identyfikator>(buffer));
                }
                buffer = "";
            }
            tokens.push_back(std::make_unique<Mnozenie>());
            break;
        case '/':
            if (buffer != "")
            {
                if (std::all_of(buffer.begin(), buffer.end(), [](unsigned char c)
                                { return std::isdigit(c); }))
                {
                    tokens.push_back(std::make_unique<Liczba>(buffer));
                }
                else
                {
                    tokens.push_back(std::make_unique<Identyfikator>(buffer));
                }
                buffer = "";
            }
            tokens.push_back(std::make_unique<Dzielenie>());
            break;
        case '(':
            if (buffer != "")
            {
                if (std::all_of(buffer.begin(), buffer.end(), [](unsigned char c)
                                { return std::isdigit(c); }))
                {
                    tokens.push_back(std::make_unique<Liczba>(buffer));
                }
                else
                {
                    tokens.push_back(std::make_unique<Identyfikator>(buffer));
                }
                buffer = "";
            }
            tokens.push_back(std::make_unique<LewyNawias>());
            break;
        case ')':
            if (buffer != "")
            {
                if (std::all_of(buffer.begin(), buffer.end(), [](unsigned char c)
                                { return std::isdigit(c); }))
                {
                    tokens.push_back(std::make_unique<Liczba>(buffer));
                }
                else
                {
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
    if (!buffer.empty())
    {
        if (std::all_of(buffer.begin(), buffer.end(), [](unsigned char c)
                        { return std::isdigit(c); }))
        {
            tokens.push_back(std::make_unique<Liczba>(buffer));
        }
        else
        {
            tokens.push_back(std::make_unique<Identyfikator>(buffer));
        }
    }
    return tokens;
}

int main()
{
    std::string text;
    std::getline(std::cin, text);

    if (!sprawdzenieTokena(text))
        return 1;

    auto tokens = DAS(text);
    size_t textIndex = 0;
    for (const auto &token : tokens)
    {
        std::string symbol = token->getSymbol();
        while (textIndex < text.length() && std::isspace(text[textIndex]))
        {
            std::cout << text[textIndex++];
        }
        std::cout << *token; // dereference pointer
        textIndex += symbol.length();
    }
    return 0;
}