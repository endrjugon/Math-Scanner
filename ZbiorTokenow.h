#include "Token.h"


class Cyfra : public Token {
public:
    Cyfra(char s) : Token(s) {}
    std::string getOpis() const override { return std::string("Cyfra");}
};

class Plus : public Token {
public:
    Plus() : Token('+') {}
    std::string getOpis() const override { return std::string("Znak dodawania");}
};

class Minus : public Token {
public:
    Minus() : Token('-') {}
    std::string getOpis() const override { return std::string("Znak odejmowania");}
};

class Mnozenie : public Token {
public:
    Mnozenie() : Token('*'){}
    std::string getOpis() const override {return std::string("Znak mnozenia");}
};

class Dzielenie : public Token {
public:
    Dzielenie() : Token('/'){}
    std::string getOpis() const override {return std::string("Znak dzielenia");}
};

class LewyNawias : public Token {
public:
    LewyNawias() : Token('(') {}
    std::string getOpis() const override { return std::string("Nawias otwierajacy");}
};

class PrawyNawias : public Token {
public:
    PrawyNawias() : Token(')') {}
    std::string getOpis() const override { return std::string("Nawias zamykajacy");}
};