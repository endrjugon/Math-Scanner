# Skaner

## Ogólne informacje

Token.h ma w sobie abstrakcyjna klasę Token.  
ZbiorTokenow.h zawiera klasy tokenów dziedziczące po Token:

- Liczba (cyfry) w kolorze niebieskim
- Identyfikator (zmienne) w kolorze białym
- Plus (+) w kolorze zielonym
- Minus (-) w kolorze zielonym
- Mnozenie (\*) w kolorze czerwonym
- Dzielenie (/) w kolorze czerwonym
- LewyNawias ( ( ) w kolorze żółtym
- PrawyNawias ( ) ) w kolorze żółtym

W pliku Main.cpp jest główna logika skanera.  
W Readme.md znajduje się opis projektu

## Instalacja

```bash
git clone <...>
cd Math-Scanner
g++ Main.cpp -o skaner -std=c++17
chmod +x skaner
```

## Użycie

```bash
/.skaner
2 + 2 * 10 - test * ( 15 / (12 / 2 - 4) )
```
