#pragma once

#include "Tokens.h"
#include "StringValuePair.h"
#include "Object.h"
#include "Array.h"
#include <vector>

namespace JLoader{
    class Parser{
    private:
        Object root;

        StringValuePair parseStringValuePair(std::vector<Token*> tokens);
        Object *parseObject(std::vector<Token*> tokens);
        Array *parseArray(std::vector<Token*> tokens);
        Type *parseValue(std::vector<Token*> tokens);

        static int64_t getFirstIndex(std::vector<Token*> tokens, TokenType type);
        static int64_t getLastIndex(std::vector<Token*> tokens, TokenType type);
        static int64_t getNthIndex(std::vector<Token*> tokens, TokenType type, int64_t n);
        static int64_t getCount(std::vector<Token*> tokens, TokenType type);
    public:
        Parser(std::vector<Token*> tokens);
        ~Parser() = default;

        Object getRoot();
    };
}
