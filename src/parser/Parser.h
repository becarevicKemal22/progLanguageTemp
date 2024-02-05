//
// Created by kemal on 2/4/2024.
//

#ifndef MATURSKI_2_PARSER_H
#define MATURSKI_2_PARSER_H

#include <vector>
#include <memory>

#include "Token.h"
#include "Ast.h"

class Parser {
public:
    Parser(std::vector<Token> tokens) : tokens(tokens) {}

    std::vector<Token> tokens;
    std::unique_ptr<Program> parse();
private:
    unsigned int current = 0;
    bool atType(TokenType type){
        return tokens[current].type == type;
    }
    void advance() { current++; }
    Token previous() { return tokens[current - 1]; }
    bool match(std::vector<TokenType> types);

    Statement* statement();
    Statement* expression();
    Statement* equalityExpression();
    Statement* comparisonExpression();
    Statement* termExpression();
    Statement* factorExpression();
    Statement* unaryExpression();
    Statement* primaryExpression();
};


#endif //MATURSKI_2_PARSER_H