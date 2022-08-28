#include <stdexcept>
#include "Parser.h"
#include "String.h"
#include "Number.h"
#include "Boolean.h"
#include "Null.h"

namespace JLoader{
    StringValuePair Parser::parseStringValuePair(std::vector<Token*> tokens){
        if(tokens.size() < 3){
            throw std::runtime_error("Invalid StringValuePair");
        }
        if(tokens[0]->getTokenType() != TokenType::String){
            throw std::runtime_error("Invalid StringValuePair");
        }
        if(tokens[1]->getTokenType() != TokenType::Colon){
            throw std::runtime_error("Invalid StringValuePair");
        }
        return {((StringToken*)tokens[0])->value, parseValue(std::vector<Token*>(tokens.begin() + 2, tokens.end()))};
    }

    Object* Parser::parseObject(std::vector<Token*> tokens){
        std::vector<StringValuePair> pairs;

        int i = 0;
        while(i < getCount(tokens, TokenType::Comma)){
            pairs.push_back(parseStringValuePair(std::vector<Token*>(
                tokens.begin() + getNthIndex(tokens, TokenType::Comma, i - 1) + 1,
                tokens.begin() + getNthIndex(tokens, TokenType::Comma, i) - 1)));
            i++;
        }

        return new Object(pairs);
    };

    Array* Parser::parseArray(std::vector<Token*> tokens){
        std::vector<Type*> values;

        int i = 0;
        while(i < getCount(tokens, TokenType::Comma)){
            values.push_back(parseValue(std::vector<Token*>(
                    tokens. begin() + getNthIndex(tokens, TokenType::Comma, i) + 1,
                    tokens.begin() + getNthIndex(tokens, TokenType::Comma, i + 1) - 1)));
            i++;
        }

        return new Array(values);
    }

    Type *Parser::parseValue(std::vector<Token*> tokens){
        switch (tokens[2]->getTokenType()) {
            case (TokenType::LeftCurlyBracket):
                return parseObject(std::vector<Token*>(
                        tokens.begin() + getFirstIndex(tokens, TokenType::LeftCurlyBracket) + 2,
                        tokens.begin() + getLastIndex(tokens, TokenType::RightCurlyBracket) - 1));
            case (TokenType::LeftsSquareBracket):
                return parseArray(std::vector<Token*>(
                        tokens.begin() + getFirstIndex(tokens, TokenType::LeftsSquareBracket) + 1,
                        tokens.begin() + getLastIndex(tokens, TokenType::RightsSquareBracket) - 1));
            case (TokenType::String):
                return new String(((StringToken*)tokens[2])->value);
            case (TokenType::Number):
                return new Number(((NumberToken*)tokens[2])->value);
            case (TokenType::True):
                return new Boolean(true);
            case (TokenType::False):
                return new Boolean(false);
            case (TokenType::Null):
                return new Null();
            default:
                throw std::runtime_error("Invalid StringValuePair");
        }
    }

    Parser::Parser(std::vector<Token*> tokens) : root(*parseObject(std::vector<Token*>(tokens.begin() + getFirstIndex(tokens, TokenType::LeftCurlyBracket) + 1,
        tokens.begin() + getLastIndex(tokens, TokenType::RightCurlyBracket) + 1))) {}

    int64_t Parser::getFirstIndex(std::vector<Token*> tokens, TokenType type) {
        for(int64_t i = 0; i < tokens.size(); i++){
            if(tokens[i]->getTokenType() == type){
                return i;
            }
        }
        return -1;
    }

    int64_t Parser::getLastIndex(std::vector<Token*> tokens, TokenType type) {
        for (int64_t i = tokens.size(); i >= 0; i--) {
            if (tokens[i]->getTokenType() == type) {
                return i;
            }
        }
        return -1;
    }

    int64_t Parser::getNthIndex(std::vector<Token *> tokens, TokenType type, int64_t n) {
        int count = 0;
        for (int64_t i = 0; i < tokens.size(); i++) {
            if (tokens[i]->getTokenType() == type) {
                count++;
                if(count == n){
                    return i;
                }
            }
        }
        return -1;
    }

    int64_t Parser::getCount(std::vector<Token *> tokens, TokenType type) {
        int64_t count = 0;
        for (Token* token : tokens) {
            if (token->getTokenType() == type) {
                count++;
            }
        }
        return count;
    }

    Object Parser::getRoot() {
        return root;
    }
}
