#pragma once

namespace JLoader{
    class Type{
    public:
        Type();
        ~Type();

        virtual std::wstring toString() = 0;
    };
}