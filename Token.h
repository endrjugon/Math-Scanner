#include <iostream>
#include <string>


class Token {
protected:
    char symbol;

public:
    Token(char s) : symbol(s) {}
    virtual ~Token() = default;

    virtual std::string getOpis() const = 0;

    char getSymbol() const {
        return symbol;
    }
};