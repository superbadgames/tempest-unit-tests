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
#include <Engine/Vector4.h>
#include <Engine/Vector3.h>
#include <Engine/Point3.h>


namespace TM = TempestMath;

BOOST_AUTO_TEST_CASE(Vector4efaultConstructorAndAccessor) 
{
    TM::Vector4 v {};

    BOOST_CHECK_EQUAL(v.x, 0.0f);
    BOOST_CHECK_EQUAL(v.y, 0.0f);
    BOOST_CHECK_EQUAL(v.z, 0.0f);
    BOOST_CHECK_EQUAL(v.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4SingleContructor) 
{
    TM::Vector4 v {5.0f};

    BOOST_CHECK_EQUAL(v.x, 5.0f);
    BOOST_CHECK_EQUAL(v.y, 5.0f);
    BOOST_CHECK_EQUAL(v.z, 5.0f);
    BOOST_CHECK_EQUAL(v.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4CopyContructor) 
{
    TM::Vector4 Vector41 {3.0f, 6.0f, 9.0f, 0.0f};

    TM::Vector4 Vector4(Vector41);

    BOOST_CHECK_EQUAL(Vector4.x, 3.0f);
    BOOST_CHECK_EQUAL(Vector4.y, 6.0f);
    BOOST_CHECK_EQUAL(Vector4.z, 9.0f);
    BOOST_CHECK_EQUAL(Vector4.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4Setters) 
{
    TM::Vector4 v{};

    v.x = 5.0f;
    v.y = 10.0f;
    v.z = 20.0f;
    v.w = 0.0f;

    BOOST_CHECK_EQUAL(v.x, 5.0f);
    BOOST_CHECK_EQUAL(v.y, 10.0f);
    BOOST_CHECK_EQUAL(v.z, 20.0f);
    BOOST_CHECK_EQUAL(v.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4CopyAssignment) 
{
    TM::Vector4 v1 {4.5f, 5.4f, 6.8f, 0.0f};

    TM::Vector4 v2 = v1;

    BOOST_CHECK_EQUAL(v2.x, 4.5f);
    BOOST_CHECK_EQUAL(v2.y, 5.4f);
    BOOST_CHECK_EQUAL(v2.z, 6.8f);
    BOOST_CHECK_EQUAL(v2.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4Assignment) 
{
    TM::Vector4 v1{};
    v1 = 3.0f;

    BOOST_CHECK_EQUAL(v1.x, 3.0f);
    BOOST_CHECK_EQUAL(v1.y, 3.0f);
    BOOST_CHECK_EQUAL(v1.z, 3.0f);
    BOOST_CHECK_EQUAL(v1.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4AddVector4) 
{
    TM::Vector4 v1 {1.0f, 1.0f, 2.0f, 0.0f};
    TM::Vector4 v2 {2.0f, 3.0f, 4.0f, 0.0f};

    TM::Vector4 sum = v1 + v2;

    BOOST_CHECK_EQUAL(sum.x, 3.0f);
    BOOST_CHECK_EQUAL(sum.y, 4.0f);
    BOOST_CHECK_EQUAL(sum.z, 6.0f);
    BOOST_CHECK_EQUAL(sum.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4AddEqVector4) 
{
    TM::Vector4 v1 {1.0f, 1.0f, 2.0f, 0.0f};
    TM::Vector4 v2 {1.0f, 1.0f, 3.0f, 0.0f};

    v1 += v2;

    BOOST_CHECK_EQUAL(v1.x, 2.0f);
    BOOST_CHECK_EQUAL(v1.y, 2.0f);
    BOOST_CHECK_EQUAL(v1.z, 5.0f);
    BOOST_CHECK_EQUAL(v1.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4AddVector3) 
{
    TM::Vector4 v1 {1.0f, 1.0f, 2.0f, 0.0f};
    TM::Vector3 v2 {2.0f, 3.0f, 4.0f};

    TM::Vector4 sum = v1 + v2;

    BOOST_CHECK_EQUAL(sum.x, 3.0f);
    BOOST_CHECK_EQUAL(sum.y, 4.0f);
    BOOST_CHECK_EQUAL(sum.z, 6.0f);
    BOOST_CHECK_EQUAL(sum.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4AddEqVector3) 
{
    TM::Vector4 v1 {1.0f, 1.0f, 2.0f, 0.0f};
    TM::Vector3 v2 {1.0f, 1.0f, 3.0f};

    v1 += v2;

    BOOST_CHECK_EQUAL(v1.x, 2.0f);
    BOOST_CHECK_EQUAL(v1.y, 2.0f);
    BOOST_CHECK_EQUAL(v1.z, 5.0f);
    BOOST_CHECK_EQUAL(v1.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4AddPoint) 
{
    TM::Vector4 v1 {1.0f, 1.0f, 2.0f, 0.0f};
    TM::Point3 v2 {2.0f, 3.0f, 4.0f};

    TM::Vector4 sum = v1 + v2;

    BOOST_CHECK_EQUAL(sum.x, 3.0f);
    BOOST_CHECK_EQUAL(sum.y, 4.0f);
    BOOST_CHECK_EQUAL(sum.z, 6.0f);
    BOOST_CHECK_EQUAL(sum.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4AddEqPoint) 
{
    TM::Vector4 v1 {1.0f, 1.0f, 2.0f, 0.0f};
    TM::Point3 v2 {1.0f, 1.0f, 3.0f};

    v1 += v2;

    BOOST_CHECK_EQUAL(v1.x, 2.0f);
    BOOST_CHECK_EQUAL(v1.y, 2.0f);
    BOOST_CHECK_EQUAL(v1.z, 5.0f);
    BOOST_CHECK_EQUAL(v1.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4SubtractVector4) 
{
    TM::Vector4 v1 {20.0f, 30.0f, 40.0f, 0.0f};
    TM::Vector4 v2 {5.0f, 5.0f, 5.0f, 0.0f};

    TM::Vector4 difference = v1 - v2;

    BOOST_CHECK_EQUAL(difference.x, 15.0f);
    BOOST_CHECK_EQUAL(difference.y, 25.0f);
    BOOST_CHECK_EQUAL(difference.z, 35.0f);
    BOOST_CHECK_EQUAL(difference.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4SubtractEqVector4) 
{
    TM::Vector4 v1 {2.0f, 3.0f, 4.0f, 0.0f};
    TM::Vector4 v2 {1.0f, 1.0f, 1.0f, 0.0f};

    v1 -= v2;

    BOOST_CHECK_EQUAL(v1.x, 1.0f);
    BOOST_CHECK_EQUAL(v1.y, 2.0f);
    BOOST_CHECK_EQUAL(v1.z, 3.0f);
    BOOST_CHECK_EQUAL(v1.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4SubtractVector3) 
{
    TM::Vector4 v1 {20.0f, 30.0f, 40.0f, 0.0f};
    TM::Vector3 v2 {5.0f, 5.0f, 5.0f};

    TM::Vector4 difference = v1 - v2;

    BOOST_CHECK_EQUAL(difference.x, 15.0f);
    BOOST_CHECK_EQUAL(difference.y, 25.0f);
    BOOST_CHECK_EQUAL(difference.z, 35.0f);
    BOOST_CHECK_EQUAL(difference.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4SubtractEqVector3) 
{
    TM::Vector4 v1 {2.0f, 3.0f, 4.0f, 0.0f};
    TM::Vector3 v2 {1.0f, 1.0f, 1.0f};

    v1 -= v2;

    BOOST_CHECK_EQUAL(v1.x, 1.0f);
    BOOST_CHECK_EQUAL(v1.y, 2.0f);
    BOOST_CHECK_EQUAL(v1.z, 3.0f);
    BOOST_CHECK_EQUAL(v1.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4SubtractPoint) 
{
    TM::Vector4 v1 {20.0f, 30.0f, 40.0f, 0.0f};
    TM::Point3 v2 {5.0f, 5.0f, 5.0f};

    TM::Vector4 difference = v1 - v2;

    BOOST_CHECK_EQUAL(difference.x, 15.0f);
    BOOST_CHECK_EQUAL(difference.y, 25.0f);
    BOOST_CHECK_EQUAL(difference.z, 35.0f);
    BOOST_CHECK_EQUAL(difference.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4SubtractEqPoint) 
{
    TM::Vector4 v1 {2.0f, 3.0f, 4.0f, 0.0f};
    TM::Point3 v2 {1.0f, 1.0f, 1.0f};

    v1 -= v2;

    BOOST_CHECK_EQUAL(v1.x, 1.0f);
    BOOST_CHECK_EQUAL(v1.y, 2.0f);
    BOOST_CHECK_EQUAL(v1.z, 3.0f);
    BOOST_CHECK_EQUAL(v1.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4MultiplyVector4Scalar) 
{
    TM::Vector4 v1 {2.0f, 3.0f, 4.0f, 0.0f};
    F32 v2 {5.0f};

    TM::Vector4 product = v1 * v2;

    BOOST_CHECK_EQUAL(product.x, 10.0f);
    BOOST_CHECK_EQUAL(product.y, 15.0f);
    BOOST_CHECK_EQUAL(product.z, 20.0f);
    BOOST_CHECK_EQUAL(product.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4MultiplyEqVector4Scalar) 
{
    TM::Vector4 v1 {8.0f, 10.0f, 15.0f, 0.0f};
    F32 v2 {5.0f};

    v1 *= v2;

    BOOST_CHECK_EQUAL(v1.x, 40.0f);
    BOOST_CHECK_EQUAL(v1.y, 50.0f);
    BOOST_CHECK_EQUAL(v1.z, 75.0f);
    BOOST_CHECK_EQUAL(v1.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4MultiplyByVector4)
{
    TM::Vector4 A {2.0f, 5.0f, 10.0f, 0.0f};
    TM::Vector4 B {6.0f, 8.0f, 9.0f, 0.0f};

    TM::Vector4 C = A * B;


    BOOST_CHECK_EQUAL(C.x, 12.0f);
    BOOST_CHECK_EQUAL(C.y, 40.0f);
    BOOST_CHECK_EQUAL(C.z, 90.0f);
    BOOST_CHECK_EQUAL(C.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4DotMultiplication) 
{
    TM::Vector4 A {4.0f, 6.0f, 9.0f, 0.0f};
    TM::Vector4 B {-3.0f, 7.0f, 3.0f, 0.0f};
    TM::Point3   C {-3.0f, 7.0f, 3.0f};

    BOOST_CHECK_EQUAL(A.Dot(B), 57.0f);
    BOOST_CHECK_EQUAL(A.Dot(C), 57.0f);
}

BOOST_AUTO_TEST_CASE(Vector4DivideVector4ByScalar) 
{
    TM::Vector4 v1 {10.0f, 20.0f, 30.0f, 0.0f};

    TM::Vector4 quotient = v1 / 2.0f;

    BOOST_CHECK_EQUAL(quotient.x, 5.0f);
    BOOST_CHECK_EQUAL(quotient.y, 10.0f);
    BOOST_CHECK_EQUAL(quotient.z, 15.0f);
    BOOST_CHECK_EQUAL(quotient.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4DivideEqVector4ByScalar) 
{
    TM::Vector4 v1 {10.0f, 20.0f, 40.0f, 0.0f};
    F32 v2 {2.0f};

    v1 /= v2;

    BOOST_CHECK_EQUAL(v1.x, 5);
    BOOST_CHECK_EQUAL(v1.y, 10);
    BOOST_CHECK_EQUAL(v1.z, 20.0f);
    BOOST_CHECK_EQUAL(v1.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4_Comparison_Operators)
{
    TM::Vector4 midValue {5.0f, 10.0f, 15.0f, 0.0f};
    TM::Vector4 highValue {40.0f, 50.0f, 60.0f, 0.0f};
    highValue.w = 0.5f;
    TM::Vector4 lowValue {1.0f, 2.0f, 3.0f, 0.0f};
    lowValue.w = -0.5f;
    TM::Vector4 equalValue = midValue;
    
    BOOST_CHECK_EQUAL(midValue > lowValue, true);
    BOOST_CHECK_EQUAL(midValue < highValue, true);
    BOOST_CHECK_EQUAL(midValue >= equalValue, true);
    BOOST_CHECK_EQUAL(midValue <= equalValue, true);
    BOOST_CHECK_EQUAL(midValue == equalValue, true);
    BOOST_CHECK_EQUAL(midValue != highValue, true);

    BOOST_CHECK_EQUAL(midValue < lowValue, false);
    BOOST_CHECK_EQUAL(midValue > highValue, false);
    BOOST_CHECK_EQUAL(midValue <= lowValue, false);
    BOOST_CHECK_EQUAL(midValue >= highValue, false);
    BOOST_CHECK_EQUAL(midValue == lowValue, false);	
    BOOST_CHECK_EQUAL(midValue != equalValue, false);

    highValue.x = 1.0f;

    BOOST_CHECK_EQUAL(midValue >= highValue, false);
}

BOOST_AUTO_TEST_CASE(Vector4Magnitude) 
{
    TM::Vector4 Vector4Test {5.0f, -4.0f, 10.0f, 0.0f};
    F32 mag = Vector4Test.Magnitude();

    BOOST_CHECK_EQUAL(RoundFloat(mag), 11.87434f);
}

BOOST_AUTO_TEST_CASE(Vector4Normalize) 
{
    TM::Vector4 Vector4Test {12.0f, -5.0f, 25.0f, 0.0f};
    Vector4Test.Normalize();

    BOOST_CHECK_EQUAL(RoundFloat(Vector4Test.x), 0.42586f);
    BOOST_CHECK_EQUAL(RoundFloat(Vector4Test.y), -0.17744f);
    BOOST_CHECK_EQUAL(RoundFloat(Vector4Test.z), 0.88722f);
    BOOST_CHECK_EQUAL(Vector4Test.w, 0.0f);

//===== TODO:: Add 2D test =====	
}

BOOST_AUTO_TEST_CASE(Vector4Resetvoid) 
{
    TM::Vector4 Vector4Test {12.0f, -5.0f, 20.0f, 0.0f};

    BOOST_CHECK_EQUAL(Vector4Test.x, 12.0f);
    BOOST_CHECK_EQUAL(Vector4Test.y, -5.0f);
    BOOST_CHECK_EQUAL(Vector4Test.z, 20.0f);
    BOOST_CHECK_EQUAL(Vector4Test.w, 0.0f);

    Vector4Test.Reset();

    BOOST_CHECK_EQUAL(Vector4Test.x, 0.0f);
    BOOST_CHECK_EQUAL(Vector4Test.y, 0.0f);
    BOOST_CHECK_EQUAL(Vector4Test.z, 0.0f);
    BOOST_CHECK_EQUAL(Vector4Test.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4AddScaledVector) 
{
    TM::Vector4 Vector4Test {15.0f, 25.0f, 45.0f, 0.0f};
    TM::Vector4 scaled {45.0f, 10.0f, 20.0f, 0.0f};

    Vector4Test.AddScaledVector(scaled, 10);

    BOOST_CHECK_EQUAL(Vector4Test.x, 465.0f);
    BOOST_CHECK_EQUAL(Vector4Test.y, 125.0f);
    BOOST_CHECK_EQUAL(Vector4Test.z, 245.0f);
    BOOST_CHECK_EQUAL(Vector4Test.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4CrossProduct) 
{
    TM::Vector4 v1 {1.0f, 3.0f, 4.0f, 0.0f};
    TM::Vector4 v2 {2.0f, -5.0f, 8.0f, 0.0f};

    TM::Vector4 cross = v1.CrossProduct(v2);

    BOOST_CHECK_EQUAL(cross.x, 44.0f);
    BOOST_CHECK_EQUAL(cross.y, 0.0f);
    BOOST_CHECK_EQUAL(cross.z, -11.0f);
    BOOST_CHECK_EQUAL(cross.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4SetFunctionTest)
{
    TM::Vector4 v {};

    v.Set(10.0f, 15.0f, 20.0f);

    BOOST_CHECK_EQUAL(v.x, 10.0f);
    BOOST_CHECK_EQUAL(v.y, 15.0f);
    BOOST_CHECK_EQUAL(v.z, 20.0f);
    BOOST_CHECK_EQUAL(v.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4Negation)
{
    TM::Vector4 v{1.0f, 2.0f, 3.0f, 1.0f};

    v = -v;

    BOOST_CHECK_EQUAL(v.x, -1.0f);
    BOOST_CHECK_EQUAL(v.y, -2.0f);
    BOOST_CHECK_EQUAL(v.z, -3.0f);
    BOOST_CHECK_EQUAL(v.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4Pre_PostIncrement)
{
    TM::Vector4 v {1.0f, 2.0f, 3.0f, 0.0f};

    ++v;

    BOOST_CHECK_EQUAL(v.x, 2.0f);
    BOOST_CHECK_EQUAL(v.y, 3.0f);
    BOOST_CHECK_EQUAL(v.z, 4.0f);
    BOOST_CHECK_EQUAL(v.w, 0.0f);

    v++;

    BOOST_CHECK_EQUAL(v.x, 3.0f);
    BOOST_CHECK_EQUAL(v.y, 4.0f);
    BOOST_CHECK_EQUAL(v.z, 5.0f);
    BOOST_CHECK_EQUAL(v.w, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector4Pre_PostDecrement)
{
    TM::Vector4 v {10.0f, 20.0f, 30.0f, 0.0f};

    --v;

    BOOST_CHECK_EQUAL(v.x, 9.0f);
    BOOST_CHECK_EQUAL(v.y, 19.0f);
    BOOST_CHECK_EQUAL(v.z, 29.0f);
    BOOST_CHECK_EQUAL(v.w, 0.0f);

    v--;

    BOOST_CHECK_EQUAL(v.x, 8.0f);
    BOOST_CHECK_EQUAL(v.y, 18.0f);
    BOOST_CHECK_EQUAL(v.z, 28.0f);
    BOOST_CHECK_EQUAL(v.w, 0.0f);
}