#pragma once

#include <Type.h>
#include <utility>
#include <vector>

namespace JLoader{
    class Array : public Type {
    private:
        std::vector<Type*> values;
    public:
        Array(std::vector<Type*> values) : values(std::move(values)) {};
        ~Array();

        std::wstring toString() override{
            std::wstring result = L"[\n";
            for (auto &value : values) {
                result += value->toString() + L",\n";
            }
            result += L"]";
            return result;
        }
    };
}