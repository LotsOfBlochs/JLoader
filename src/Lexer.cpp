#include "Lexer.h"
#include <cmath>

namespace JLoader {
    Lexer::Lexer(const std::wstring &source) {
        for(int i = 0; i < source.length(); i++){
            wchar_t c = source[i];
            switch(c){
                case (L'['):
                    tokens.push_back(new LeftSquareBracketToken());
                    break;
                case L']':
                    tokens.push_back(new RightSquareBracketToken());
                    break;
                case L'{':
                    tokens.push_back(new LeftCurlyBracketToken());
                    break;
                case L'}':
                    tokens.push_back(new RightCurlyBracketToken());
                    break;
                case L',':
                    tokens.push_back(new CommaToken());
                    break;
                case L':':
                    tokens.push_back(new ColonToken());
                    break;
                case L't':
                    if(source[i + 1] == 'r' && source[i + 2] == 'u' && source[i + 3] == 'e'){
                        tokens.push_back(new TrueToken());
                        i += 3;
                    }
                    break;
                case L'f':
                    if(source[i + 1] == 'a' && source[i + 2] == 'l' && source[i + 3] == 's' && source[i + 4] == 'e'){
                        tokens.push_back(new FalseToken());
                        i += 4;
                    }
                    break;
                case L'n':
                    if(source[i + 1] == 'u' && source[i + 2] == 'l' && source[i + 3] == 'l'){
                        tokens.push_back(new NullToken());
                        i += 3;
                    }
                    break;
                case L'"': {
                    std::wstring str;
                    i++;
                    while (source[i] != '"') {
                        if (source[i] == '\\') {
                            i++;
                            switch (source[i]) {
                                case ('"'):
                                    str += '"';
                                    break;
                                case ('\\'):
                                    str += '\\';
                                    break;
                                case ('/'):
                                    str += '/';
                                    break;
                                case ('b'):
                                    str += '\b';
                                    break;
                                case ('f'):
                                    str += '\f';
                                    break;
                                case ('n'):
                                    str += '\n';
                                    break;
                                case ('r'):
                                    str += '\r';
                                    break;
                                case ('t'):
                                    str += '\t';
                                    break;
                                case ('u'):
                                    str += hexToWChar(source.substr(i, 4));
                                    i += 4;
                                    break;
                            }
                        } else {
                            str += source[i];
                            i++;
                        }
                    }
                    tokens.push_back(new StringToken(str));
                    break;
                }
                default:
                    if(isdigit(c) || c == '-'){
                        tokens.push_back(new NumberToken(lexNumber(source.substr(i, i - getNextIndexOf(source, ',', i)))));
                    }
                    break;
            }
        }
    }

    int Lexer::getNextIndexOf(const std::wstring &source, wchar_t c, int start){
        for(int i = start; i < source.length(); i++){
            if(source[i] == c){
                return i;
            }
        }
        return -1;
    }

    wchar_t Lexer::hexToWChar(const std::wstring &hex) {
        wchar_t result = 0;
        for(int i = 0; i < hex.length(); i++){
            wchar_t c = hex[i];
            if(isdigit(c)){
                result += (c - '0') * pow(16, hex.length() - i - 1);
            }
            else if(c >= 'a' && c <= 'f'){
                result += (c - 'a' + 10) * pow(16, hex.length() - i - 1);
            }
            else if(c >= 'A' && c <= 'F'){
                result += (c - 'A' + 10) * pow(16, hex.length() - i - 1);
            }
        }
        return result;
    }

    double Lexer::lexNumber(const std::wstring &number) {
        int i = 0;
        double result = 0;
        if(number[0] == '-'){
            i++;
        }
        while(isdigit(number[i])){
            result *= 10;
            result += number[i] - '0';
            i++;
        }
        if(number[i] == '.'){
            i++;
            int decimal = 0;
            while(isdigit(number[i])){
                result *= 10;
                result += number[i] - '0';
                decimal++;
                i++;
            }
            result /= pow(10, decimal);
        }
        if(number[i] == 'e' || number[i] == 'E'){
            i++;
            int exponent = 0;
            while(isdigit(number[i])){
                exponent *= 10;
                exponent += number[i] - '0';
                i++;
            }
            result *= pow(10, exponent);
        }
        if(number[0] == '-'){
            result *= -1;
        }
        return result;
    }
}