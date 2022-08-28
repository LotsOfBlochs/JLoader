#include "JLoader.h"

#include "Lexer.h"
#include "Parser.h"

namespace JLoader {
    Object parseJSON(std::wstring json) {
        return Parser(Lexer(json).getTokens()).getRoot();
    }

    std::wstring getJSON(Object object) {
        return object.toString();
    }
}