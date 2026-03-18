#include <iostream>
#include <string>
#include <utility>


class Token {
protected:
    std::string symbol;

public:
    explicit Token(std::string s) : symbol(std::move(s)) {}
    virtual ~Token() = default;

    [[nodiscard]] virtual std::string getOpis() const = 0;

    [[nodiscard]] std::string getSymbol() const {
        return symbol;
    }
};