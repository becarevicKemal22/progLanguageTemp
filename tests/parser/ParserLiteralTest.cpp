//
// Created by kemal on 2/5/2024.
//

#include <catch2/catch_test_macros.hpp>

#include "Parser.h"
#include "Lexer.h"
#include "Program.h"
#include "NumericLiteralExpression.h"
#include "BooleanLiteralExpression.h"
#include "StringLiteralExpression.h"
#include "NullLiteralExpression.h"
#include "../TestHelpers.h"

TEST_CASE("Parses literals", "[parser][literal]") {
    std::wstring source = L"24.2; istina; neistina; \"string\"; nula;";
    Lexer lexer(source);
    lexer.tokenize();
    Parser parser(lexer.tokens);
    auto program = parser.parse();

    REQUIRE(program->statements.size() == 5);
    auto statements = program->statements;

    auto numericLiteral = getNode<NumericLiteralExpression>(statements[0]);
    REQUIRE(numericLiteral->value == 24.2);

    auto booleanLiteral = getNode<BooleanLiteralExpression>(statements[1]);
    REQUIRE(booleanLiteral->value == true);

    booleanLiteral = getNode<BooleanLiteralExpression>(statements[2]);
    REQUIRE(booleanLiteral->value == false);

    auto stringLiteral = getNode<StringLiteralExpression>(statements[3]);
    REQUIRE(stringLiteral->value == L"string");

    auto nullLiteral = getNode<NullLiteralExpression>(statements[4]);
}

TEST_CASE("Parses empty string", "[parser][literal]") {
    std::wstring source = L"\"\";";
    Lexer lexer(source);
    lexer.tokenize();
    Parser parser(lexer.tokens);
    auto program = parser.parse();

    REQUIRE(program->statements.size() == 1);
    auto statements = program->statements;

    auto stringLiteral = getNode<StringLiteralExpression>(statements[0]);
    REQUIRE(stringLiteral->value == L"");
}
