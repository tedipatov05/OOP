#pragma once
#include "NumbersWriter.h"

class BinaryWriter :
    public NumbersWriter
{
public:

    void write(const int* numbers, size_t size) const override;
};

