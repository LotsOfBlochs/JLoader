#pragma once

#include <string>
#include "Object.h"

namespace JLoader{
    Object parseJSON(std::wstring json);

    std::wstring getJSON(Object object);
}