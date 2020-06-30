/*------------------------------------------------------------
This file will test the functionality of the Vector4 class which
will be used in the Killer1 Engine. Most of the examples and all
of the equations are from 3D Math Primer for Graphics and Game
Development by Dunn and Parberry (awesome book for those who
wish to learn).

Uses the boost test library.

Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.


Written by Maxwell Miller
-------------------------------------------------------------*/

#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include <UnitTests/TestHelper.h>
#include <Engine/Atom.h>
#include <Engine/Random.h>
#include <Engine/Vector4.h>
#include <Engine/Vector4.h>
#include <Engine/Quaternion.h>

namespace TM = TempestMath;


BOOST_AUTO_TEST_CASE(RandomInt_tests)
{
    TM::Random gen { };

    S32 a = gen.RandomInt(0, 1000);
    BOOST_CHECK_GE(a, 0);
    BOOST_CHECK_LE(a, 1000);

    a = gen.RandomInt(1, 10);
    BOOST_CHECK_GE(a, 1);
    BOOST_CHECK_LE(a, 10);

    a = gen.RandomInt(5, 10);
    BOOST_CHECK_GE(a, 5);
    BOOST_CHECK_LE(a, 10);
}

BOOST_AUTO_TEST_CASE(RandomLong_tests)
{
    TM::Random gen { };

    S64 a = gen.RandomLong(0, 200);
    BOOST_CHECK_GE(a, 0);
    BOOST_CHECK_LE(a, 200);

    a = gen.RandomLong(1000, 100000);
    BOOST_CHECK_GE(a, 1000);
    BOOST_CHECK_LE(a, 100000);

    a = gen.RandomLong(50000, 100000);
    BOOST_CHECK_GE(a, 50000);
    BOOST_CHECK_LE(a, 100000);
}

BOOST_AUTO_TEST_CASE(RandomFloat_tests)
{
    TM::Random gen { };

    F32 a = gen.RandomFloat(-10.0f, 10.0f);
    BOOST_CHECK_GE(a, -10.0f);
    BOOST_CHECK_LE(a, 10.0f);

    a = gen.RandomFloat(5.0f, 50.0f);
    BOOST_CHECK_GE(a, 5.0f);
    BOOST_CHECK_LE(a, 50.0f);

    a = gen.RandomFloat(-1000.0f, 1000.0f);
    BOOST_CHECK_GE(a, -1000.0f);
    BOOST_CHECK_LE(a, 1000.0f);

    a = gen.RandomFloat(0.25f, 0.5f);
    BOOST_CHECK_GE(a, 0.25f);
    BOOST_CHECK_LE(a, 0.5f);
}

BOOST_AUTO_TEST_CASE(RandomDouble_tests)
{
    TM::Random gen { };

    F64 a = gen.RandomDouble(-10.0f, 10.0f);
    BOOST_CHECK_GE(a, -10.0f);
    BOOST_CHECK_LE(a, 10.0f);

    a = gen.RandomDouble(5.0f, 50.0f);
    BOOST_CHECK_GE(a, 5.0f);
    BOOST_CHECK_LE(a, 50.0f);

    a = gen.RandomDouble(-1000.0f, 1000.0f);
    BOOST_CHECK_GE(a, -1000.0f);
    BOOST_CHECK_LE(a, 1000.0f);

    a = gen.RandomDouble(0.25f, 0.5f);
    BOOST_CHECK_GE(a, 0.25f);
    BOOST_CHECK_LE(a, 0.5f);
}

BOOST_AUTO_TEST_CASE(RandomVector4_tests)
{
    TM::Vector4 a = TM::Random::Instance()->RandomVector4(0.0f, 1.0f);

    BOOST_CHECK_GE(a.x, 0.0f);
    BOOST_CHECK_LE(a.x, 1.0f);
    BOOST_CHECK_GE(a.y, 0.0f);
    BOOST_CHECK_LE(a.y, 1.0f);

    a = TM::Random::Instance()->RandomVector4(10.0f, 100.0f);

    BOOST_CHECK_GE(a.x, 10.0f);
    BOOST_CHECK_LE(a.x, 100.0f);
    BOOST_CHECK_GE(a.y, 10.0f);
    BOOST_CHECK_LE(a.y, 100.0f);

    TM::Vector4 b = TM::Random::Instance()->RandomVector4(0.0f, 1.0f);

    BOOST_CHECK_GE(b.x, 0.0f);
    BOOST_CHECK_LE(b.x, 1.0f);
    BOOST_CHECK_GE(b.y, 0.0f);
    BOOST_CHECK_LE(b.y, 1.0f);
    BOOST_CHECK_GE(b.z, 0.0f);
    BOOST_CHECK_LE(b.z, 1.0f);

    b = TM::Random::Instance()->RandomVector4(10.0f, 100.0f);

    BOOST_CHECK_GE(b.x, 10.0f);
    BOOST_CHECK_LE(b.x, 100.0f);
    BOOST_CHECK_GE(b.y, 10.0f);
    BOOST_CHECK_LE(b.y, 100.0f);
    BOOST_CHECK_GE(b.z, 10.0f);
    BOOST_CHECK_LE(b.z, 100.0f);
}

BOOST_AUTO_TEST_CASE(RandomQuaternion_tests)
{
    TM::Quaternion a = TM::Random::Instance()->RandomQuaternion(0.0f, 1.0f);

    BOOST_CHECK_GE(a.x, 0.0f);
    BOOST_CHECK_LE(a.x, 1.0f);
    BOOST_CHECK_GE(a.y, 0.0f);
    BOOST_CHECK_LE(a.y, 1.0f);
    BOOST_CHECK_GE(a.z, 0.0f);
    BOOST_CHECK_LE(a.z, 1.0f);
    BOOST_CHECK_GE(a.x, 0.0f);
    BOOST_CHECK_LE(a.x, 1.0f);

    a = TM::Random::Instance()->RandomQuaternion(10.0f, 100.0f);

    BOOST_CHECK_GE(a.x, 10.0f);
    BOOST_CHECK_LE(a.x, 100.0f);
    BOOST_CHECK_GE(a.y, 10.0f);
    BOOST_CHECK_LE(a.y, 100.0f);
    BOOST_CHECK_GE(a.z, 10.0f);
    BOOST_CHECK_LE(a.z, 100.0f);
    BOOST_CHECK_GE(a.x, 10.0f);
    BOOST_CHECK_LE(a.x, 100.0f);
}