//
// Created by kemal on 2/24/2024.
//

#ifndef MATURSKI_2_WRONGTYPEERROR_H
#define MATURSKI_2_WRONGTYPEERROR_H

#include "RuntimeError.h"
#include "Token.h"
#include "ErrorCode.h"
#include "RuntimeValue.h"
#include "Expression.h"
#include "ExceptionHelpers.h"

class WrongTypeError : public RuntimeError {
public:
    WrongTypeError(const std::wstring& toWhat, const RuntimeValue& value, const Expression* expression) : RuntimeError(ErrorCode::ERROR_WRONG_TYPE_OPERAND) {
        messageArguments.emplace_back(valueTypeToString(value.type));
        messageArguments.emplace_back(toWhat);
        this->token = getMostRelevantToken(expression);
    }
    Token* token;
};

#endif //MATURSKI_2_WRONGTYPEERROR_H
