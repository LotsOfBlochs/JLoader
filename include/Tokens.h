#pragma once

#include <string>

namespace JLoader{
    enum class TokenType : unsigned char{
        LeftsSquareBracket,
        RightsSquareBracket,
        LeftCurlyBracket,
        RightCurlyBracket,
        Comma,
        Colon,
        True,
        False,
        Null,
        String,
        Number
    };

    struct Token{
    private:
        TokenType type;
    public:
        TokenType getTokenType(){
            return type;
        }

        Token(TokenType type){
            this->type = type;
        }
    };

    struct LeftSquareBracketToken : public Token{
        LeftSquareBracketToken() : Token(TokenType::LeftsSquareBracket){}
    };

    struct RightSquareBracketToken : public Token{
        RightSquareBracketToken() : Token(TokenType::RightsSquareBracket){}
    };

    struct LeftCurlyBracketToken : public Token{
        LeftCurlyBracketToken() : Token(TokenType::LeftCurlyBracket){}
    };

    struct RightCurlyBracketToken : public Token{
        RightCurlyBracketToken() : Token(TokenType::RightCurlyBracket){}
    };

    struct CommaToken : public Token{
        CommaToken() : Token(TokenType::Comma){}
    };

    struct ColonToken : public Token{
        ColonToken() : Token(TokenType::Colon){}
    };

    struct TrueToken : public Token{
        TrueToken() : Token(TokenType::True){}
    };

    struct FalseToken : public Token{
        FalseToken() : Token(TokenType::False){}
    };

    struct NullToken : public Token{
        NullToken() : Token(TokenType::Null){}
    };

    struct StringToken : public Token{
        std::wstring value;
        StringToken(const std::wstring& value) : Token(TokenType::String){
            this->value = value;
        }
    };

    struct NumberToken : public Token{
        double value;
        NumberToken(double value) : Token(TokenType::Number){
            this->value = value;
        }
    };
}