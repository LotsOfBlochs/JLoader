#pragma once

#include "Type.h"
#include <string>
#include <utility>

namespace JLoader{
    class StringValuePair{
    private:
        std::wstring key;
        Type* value;
    public:
        StringValuePair(std::wstring  key, Type* value) : key(std::move(key)), value(value) {};
        ~StringValuePair();

        std::string getKey();
        Type* getValue();

        std::wstring toString(){
            return L"\"" + key + L"\" : " + value->toString();
        }
    };
}