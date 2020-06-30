#pragma once

#include "stdafx.h"
#include <Engine/Atom.h>

//==========================================================================================================================
//
//Global Helper Functions
//
//==========================================================================================================================

F32 inline RoundFloat(F32 n)
{
    return floor((F32)n * 100000.0f + 0.5f) / 100000;
}

real inline RoundReal(real n)
{
    return floor((real)n * 100000.0f + 0.5f) / 100000;
}