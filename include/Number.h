#pragma once

#include <Type.h>

namespace JLoader{
    class Number : public Type {
    private:
        double value;
    public:
        Number(double  value) : value(value) {};
        ~Number();

        std::wstring toString() override{
            return std::to_wstring(value);
        }
    };
}