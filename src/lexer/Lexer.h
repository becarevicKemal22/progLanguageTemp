//
// Created by kemal on 1/28/2024.
//

#ifndef MATURSKI_2_LEXER_H
#define MATURSKI_2_LEXER_H

#include <string>
#include <vector>

#include "Token.h"
#include "ErrorPrinter.h"

class Lexer {
public:
    Lexer(const std::wstring&  source) : source(source), printer(nullptr) {}
    Lexer(const std::wstring& source, ErrorPrinter* printer) : source(source), printer(printer) {}
    std::vector<Token> tokens{};
    void tokenize();
    void setPrinter(ErrorPrinter* printer){
        this->printer = printer;
    }
private:
    std::wstring source;
    unsigned int currentChar = 0;
    unsigned int line = 1;
    unsigned int charIndexOnLine = 0;
    ErrorPrinter* printer;
    void addToken(TokenType type, wchar_t character);
    void addToken(TokenType type, const std::wstring& value, bool offsetIsStartOfToken = false);
    void addStringToken(const std::wstring& value, unsigned int line, unsigned int offset);
    void advance() { currentChar++; charIndexOnLine++;}
    wchar_t peek() { return source[currentChar + 1];}
    void handleTab();
    void handleNewLine();
    void handleString();
    void handleComment();
};


#endif //MATURSKI_2_LEXER_H
