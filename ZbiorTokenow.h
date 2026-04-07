#include <utility>

#include "Token.h"

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string WHITE = "\033[37m";

class Liczba : public Token
{
public:
    explicit Liczba(std::string s) : Token(std::move(s)) {}
    std::string getOpis() const override { return std::string("Cyfra"); }
    std::string getKolor() const override { return BLUE; }
};

class Identyfikator : public Token
{
public:
    explicit Identyfikator(std::string s) : Token(std::move(s)) {}
    std::string getOpis() const override { return std::string("Identyfikator"); }
    std::string getKolor() const override { return WHITE; }
};

class Plus : public Token
{
public:
    Plus() : Token("+") {}
    std::string getOpis() const override { return std::string("Znak dodawania"); }
    std::string getKolor() const override { return GREEN; }
};

class Minus : public Token
{
public:
    Minus() : Token("-") {}
    std::string getOpis() const override { return std::string("Znak odejmowania"); }
    std::string getKolor() const override { return GREEN; }
};

class Mnozenie : public Token
{
public:
    Mnozenie() : Token("*") {}
    std::string getOpis() const override { return std::string("Znak mnozenia"); }
    std::string getKolor() const override { return RED; }
};

class Dzielenie : public Token
{
public:
    Dzielenie() : Token("/") {}
    std::string getOpis() const override { return std::string("Znak dzielenia"); }
    std::string getKolor() const override { return RED; }
};

class LewyNawias : public Token
{
public:
    LewyNawias() : Token("(") {}
    std::string getOpis() const override { return std::string("Nawias otwierajacy"); }
    std::string getKolor() const override { return YELLOW; }
};

class PrawyNawias : public Token
{
public:
    PrawyNawias() : Token(")") {}
    std::string getOpis() const override { return std::string("Nawias zamykajacy"); }
    std::string getKolor() const override { return YELLOW; }
};