#pragma once

#include "StringValuePair.h"
#include <vector>

namespace JLoader{
    class Object : public Type{
    private:
        std::vector<StringValuePair> pairs;
    public:
        Object(std::vector<StringValuePair> pairs) : pairs(std::move(pairs)) {};
        ~Object();

        std::wstring toString() override{
            std::wstring result = L"{\n";
            for (auto &pair : pairs) {
                result += pair.toString() + L",\n";
            }
            result += L"}";
            return result;
        }
    };
}