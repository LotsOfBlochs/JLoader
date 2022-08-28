#pragma once

#include <string>
#include <vector>
#include "Tokens.h"

namespace JLoader{
    class Lexer{
    private:
        std::vector<Token*> tokens;
        static wchar_t hexToWChar(const std::wstring &hex);

        static double lexNumber(const std::wstring &number);

        static int getNextIndexOf(const std::wstring &source, wchar_t c, int start);
    public:
        Lexer(const std::wstring& source);
        ~Lexer();

        std::vector<Token*> getTokens(){
            return tokens;
        }
    };
}