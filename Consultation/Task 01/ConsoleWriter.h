#pragma once
#include "NumbersWriter.h"
class ConsoleWriter :
    public NumbersWriter
{
public:
    void write(const int* numbers, size_t size) const override;
};

