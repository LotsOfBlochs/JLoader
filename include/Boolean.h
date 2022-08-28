#pragma once

#include <Type.h>

namespace JLoader{
    class Boolean : public Type {
    private:
        bool value;
    public:
        Boolean(bool value) : value(value) {};
        ~Boolean();

        std::wstring toString() override{
            return value ? L"true" : L"false";
        }
    };
}