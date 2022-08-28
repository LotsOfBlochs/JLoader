#pragma once

#include "Type.h"
#include <string>

namespace JLoader{
    class String : public Type {
    private:
        std::wstring value;
    public:
        String(std::wstring value) : value(value) {};
        ~String();

        std::wstring toString() override{
            return L"\"" + value + L"\"";
        }
    };
}