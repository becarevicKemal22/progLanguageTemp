//
// Created by kemal on 2/20/2024.
//

#ifndef MATURSKI_2_RUNTIMEVALUE_H
#define MATURSKI_2_RUNTIMEVALUE_H

#include <cstdint>

enum class ValueType : uint8_t {
    Number,
    Boolean,
    Null,
};

typedef struct {
    ValueType type;
    union {
        bool boolean;
        double number;
    } as;
} RuntimeValue;

#endif //MATURSKI_2_RUNTIMEVALUE_H
