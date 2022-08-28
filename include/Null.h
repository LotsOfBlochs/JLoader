#pragma once

#include <Type.h>

namespace JLoader{
    class Null : public Type {
    public:
        Null();
        ~Null();

        std::wstring toString() override{
            return L"null";
        }
    };
}