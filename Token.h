#include <iostream>
#include <string>
#include <utility>

const std::string RESET = "\033[0;0m";

class Token
{
protected:
    std::string symbol;

public:
    explicit Token(std::string s) : symbol(std::move(s)) {}
    virtual ~Token() = default;

    [[nodiscard]] virtual std::string getOpis() const = 0;
    [[nodiscard]] virtual std::string getKolor() const = 0;

    [[nodiscard]] std::string getSymbol() const
    {
        return symbol;
    }

    friend std::ostream &operator<<(std::ostream &os, const Token &token)
    {
        os << token.getKolor() << token.getSymbol() << RESET;
        return os;
    }
};