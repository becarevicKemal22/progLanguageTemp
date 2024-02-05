//
// Created by kemal on 1/28/2024.
//

#ifndef MATURSKI_2_TOKENTYPE_H
#define MATURSKI_2_TOKENTYPE_H

#include <cstdint>

enum class TokenType : uint8_t {
    // Characters
    OpenParenthesis,
    ClosedParenthesis,
    OpenBrace,
    ClosedBrace,
    OpenBracket,
    ClosedBracket,
    Semicolon,
    Colon,
    Comma,
    Dot,
    // Operators
    Plus,
    Minus,
    Star,
    Slash,
    Percent,
    Bang,
    BangEqual,
    Less,
    LessEqual,
    Greater,
    GreaterEqual,
    Equal,
    DoubleEqual,
    DoublePipe,
    DoubleAmpersand,
    // Types and identifiers
    Identifier,
    Number,
    String,
    True,
    False,
    Null,
    // Keywords
    If,

    Eof
};

#endif //MATURSKI_2_TOKENTYPE_H
