//
// Created by kemal on 2/5/2024.
//

#include <iostream>

#include "PrettyPrint.h"
#include "Program.h"

#include "BinaryExpression.h"
#include "Statement.h"
#include "UnaryExpression.h"
#include "NullLiteralExpression.h"
#include "BooleanLiteralExpression.h"
#include "NumericLiteralExpression.h"
#include "StringLiteralExpression.h"

void printStatement(Statement *statement, int depth);

void printAST(std::unique_ptr<Program> &program) {
    std::wcout << L"Program" << std::endl;
    for (auto statement: program->statements) {
        printStatement(statement, 1);
    }
}

void printBinaryExpression(BinaryExpression *expression, int depth) {
    std::wcout << L"BinExpr ( ";
    std::wcout << expression->op->value << " ";
    printStatement(expression->left, depth + 1);
    std::wcout << L", ";
    printStatement(expression->right, depth + 1);
    std::wcout << L" ) ";
}

void printUnaryExpression(UnaryExpression *expression, int depth) {
    std::wcout << L"UnaryExpr ( ";
    std::wcout << expression->op->value;
    printStatement(expression->expr, depth + 1);
    std::wcout << L" ) ";
}

void printNullLiteralExpression(NullLiteralExpression *expression, int depth) {
    std::wcout << L"NullLiteralExpr ";
}

void printBooleanLiteralExpression(BooleanLiteralExpression *expression, int depth) {
    std::wcout << L"BooleanLiteralExpr ( " << expression->value << L" ) ";
}

void printNumericLiteralExpression(NumericLiteralExpression *expression, int depth) {
    std::wcout << L"NumericLiteralExpr ( " << expression->value << L" ) ";
}

void printStringLiteralExpression(StringLiteralExpression *expression, int depth) {
    std::wcout << L"StringLiteralExpr ( " << expression->value << L" ) ";
}

void printStatement(Statement *statement, int depth) {
    AstNodeType type = statement->type;
    switch (type) {
        case AstNodeType::BinaryExpression:
            printBinaryExpression(static_cast<BinaryExpression*>(statement), depth);
            break;
        case AstNodeType::UnaryExpression:
            printUnaryExpression(static_cast<UnaryExpression*>(statement), depth);
            break;
        case AstNodeType::NullLiteralExpression:
            printNullLiteralExpression(static_cast<NullLiteralExpression*>(statement), depth);
            break;
        case AstNodeType::BooleanLiteralExpression:
            printBooleanLiteralExpression(static_cast<BooleanLiteralExpression*>(statement), depth);
            break;
        case AstNodeType::NumericLiteralExpression:
            printNumericLiteralExpression(static_cast<NumericLiteralExpression*>(statement), depth);
            break;
        case AstNodeType::StringLiteralExpression:
            printStringLiteralExpression(static_cast<StringLiteralExpression*>(statement), depth);
            break;
        default:
            std::wcout << L"Unknown statement type" << std::endl;
    }
}