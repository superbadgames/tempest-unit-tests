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
#include <Engine/Matrix4.h>
#include <Engine/Vector2.h>
#include <Engine/Vector4.h>


namespace TM = TempestMath;

BOOST_AUTO_TEST_CASE(Matrix4DefaultConstructor) 
{
    TM::Matrix4 M1{};

    BOOST_CHECK_EQUAL(M1.column1.x, 1.0f);
    BOOST_CHECK_EQUAL(M1.column1.y, 0.0f);
    BOOST_CHECK_EQUAL(M1.column1.z, 0.0f);
    BOOST_CHECK_EQUAL(M1.column1.w, 0.0f);
    
    BOOST_CHECK_EQUAL(M1.column2.x, 0.0f);
    BOOST_CHECK_EQUAL(M1.column2.y, 1.0f);
    BOOST_CHECK_EQUAL(M1.column2.z, 0.0f);
    BOOST_CHECK_EQUAL(M1.column2.w, 0.0f);
    
    BOOST_CHECK_EQUAL(M1.column3.x, 0.0f);
    BOOST_CHECK_EQUAL(M1.column3.y, 0.0f);
    BOOST_CHECK_EQUAL(M1.column3.z, 1.0f);
    BOOST_CHECK_EQUAL(M1.column3.w, 0.0f);

    BOOST_CHECK_EQUAL(M1.column4.x, 0.0f);
    BOOST_CHECK_EQUAL(M1.column4.y, 0.0f);
    BOOST_CHECK_EQUAL(M1.column4.z, 0.0f);
    BOOST_CHECK_EQUAL(M1.column4.w, 1.0f);
}

BOOST_AUTO_TEST_CASE(Matrix4DiagnalConstructor) 
{
    TM::Matrix4 M1(5.0f);

    BOOST_CHECK_EQUAL(M1.column1.x, 5.0f);
    BOOST_CHECK_EQUAL(M1.column1.y, 0.0f);
    BOOST_CHECK_EQUAL(M1.column1.z, 0.0f);
    BOOST_CHECK_EQUAL(M1.column1.w, 0.0f);
    
    BOOST_CHECK_EQUAL(M1.column2.x, 0.0f);
    BOOST_CHECK_EQUAL(M1.column2.y, 5.0f);
    BOOST_CHECK_EQUAL(M1.column2.z, 0.0f);
    BOOST_CHECK_EQUAL(M1.column2.w, 0.0f);
    
    BOOST_CHECK_EQUAL(M1.column3.x, 0.0f);
    BOOST_CHECK_EQUAL(M1.column3.y, 0.0f);
    BOOST_CHECK_EQUAL(M1.column3.z, 5.0f);
    BOOST_CHECK_EQUAL(M1.column3.w, 0.0f);
    
    BOOST_CHECK_EQUAL(M1.column4.x, 0.0f);
    BOOST_CHECK_EQUAL(M1.column4.y, 0.0f);
    BOOST_CHECK_EQUAL(M1.column4.z, 0.0f);		 
    BOOST_CHECK_EQUAL(M1.column4.w, 1.0f);

}


BOOST_AUTO_TEST_CASE(Matrix4Vector4Constructor) 
{
    TM::Vector4 vecX {1.0f, 2.0f, 3.0f, 0.0f};
    TM::Vector4 vecY {15.0f, 25.0f, 35.0f, 0.0f};
    TM::Vector4 vecZ {30.0f, 50.0f, 70.0f, 0.0f};

    TM::Matrix4 mat(vecX, vecY, vecZ);

    BOOST_CHECK_EQUAL(mat.column1.x, 1.0f);
    BOOST_CHECK_EQUAL(mat.column1.y, 2.0f);
    BOOST_CHECK_EQUAL(mat.column1.z, 3.0f);
    BOOST_CHECK_EQUAL(mat.column1.w, 0.0f);
    
    BOOST_CHECK_EQUAL(mat.column2.x, 15.0f);
    BOOST_CHECK_EQUAL(mat.column2.y, 25.0f);
    BOOST_CHECK_EQUAL(mat.column2.z, 35.0f);
    BOOST_CHECK_EQUAL(mat.column2.w, 0.0f);
    
    BOOST_CHECK_EQUAL(mat.column3.x, 30.0f);
    BOOST_CHECK_EQUAL(mat.column3.y, 50.0f);
    BOOST_CHECK_EQUAL(mat.column3.z, 70.0f);
    BOOST_CHECK_EQUAL(mat.column3.w, 0.0f);
    
    BOOST_CHECK_EQUAL(mat.column4.x, 0.0f);
    BOOST_CHECK_EQUAL(mat.column4.y, 0.0f);
    BOOST_CHECK_EQUAL(mat.column4.z, 0.0f);		 
    BOOST_CHECK_EQUAL(mat.column4.w, 1.0f);
}

BOOST_AUTO_TEST_CASE(Matrix4CopyConstructor)
{
    TM::Matrix4 A(10.0f);

    TM::Matrix4 B = A;

    BOOST_CHECK_EQUAL(B.column1.x, 10.0f);
    BOOST_CHECK_EQUAL(B.column1.y, 0.0f);
    BOOST_CHECK_EQUAL(B.column1.z, 0.0f);
    BOOST_CHECK_EQUAL(B.column1.w, 0.0f);
    
    BOOST_CHECK_EQUAL(B.column2.x, 0.0f);
    BOOST_CHECK_EQUAL(B.column2.y, 10.0f);
    BOOST_CHECK_EQUAL(B.column2.z, 0.0f);
    BOOST_CHECK_EQUAL(B.column2.w, 0.0f);
    
    BOOST_CHECK_EQUAL(B.column3.x, 0.0f);
    BOOST_CHECK_EQUAL(B.column3.y, 0.0f);
    BOOST_CHECK_EQUAL(B.column3.z, 10.0f);
    BOOST_CHECK_EQUAL(B.column3.w, 0.0f);
    
    BOOST_CHECK_EQUAL(B.column4.x, 0.0f);
    BOOST_CHECK_EQUAL(B.column4.y, 0.0f);
    BOOST_CHECK_EQUAL(B.column4.z, 0.0f);		 
    BOOST_CHECK_EQUAL(B.column4.w, 1.0f);
}

BOOST_AUTO_TEST_CASE(Matrix4OperatorMultiply) {
    TM::Matrix4 A
    (
        TM::Vector4(3.0f, 5.0f, 7.0f, 0.0f),
        TM::Vector4(6.0f, 3.0f, 8.0f, 0.0f),
        TM::Vector4(9.0f, 3.0f, 5.0f, 0.0f)
    );

    TM::Matrix4 B
    (
        TM::Vector4(2.0f, 5.0f, 1.0f, 0.0f),
        TM::Vector4(6.0f, 2.0f, 2.0f, 0.0f),
        TM::Vector4(2.0f, 3.0f, 2.0f, 0.0f)
    );

    TM::Matrix4 C = A * B;

    BOOST_CHECK_EQUAL(C.column1.x, 45.0f);
    BOOST_CHECK_EQUAL(C.column1.y, 28.0f);
    BOOST_CHECK_EQUAL(C.column1.z, 59.0f);
    BOOST_CHECK_EQUAL(C.column1.w, 0.0f);
    
    BOOST_CHECK_EQUAL(C.column2.x, 48.0f);
    BOOST_CHECK_EQUAL(C.column2.y, 42.0f);
    BOOST_CHECK_EQUAL(C.column2.z, 68.0f);
    BOOST_CHECK_EQUAL(C.column2.w, 0.0f);
    
    BOOST_CHECK_EQUAL(C.column3.x, 42.0f);
    BOOST_CHECK_EQUAL(C.column3.y, 25.0f);
    BOOST_CHECK_EQUAL(C.column3.z, 48.0f);
    BOOST_CHECK_EQUAL(C.column3.w, 0.0f);
    
    BOOST_CHECK_EQUAL(C.column4.x, 0.0f);
    BOOST_CHECK_EQUAL(C.column4.y, 0.0f);
    BOOST_CHECK_EQUAL(C.column4.z, 0.0f);		 
    BOOST_CHECK_EQUAL(C.column4.w, 1.0f);

}


BOOST_AUTO_TEST_CASE(Matrix4OperatorEQMultiply) {
    TM::Matrix4 A
    (
        TM::Vector4(3.0f, 5.0f, 7.0f, 0.0f),
        TM::Vector4(6.0f, 3.0f, 8.0f, 0.0f),
        TM::Vector4(9.0f, 3.0f, 5.0f, 0.0f)
    );

    TM::Matrix4 B
    (
        TM::Vector4(2.0f, 5.0f, 1.0f, 0.0f),
        TM::Vector4(6.0f, 2.0f, 2.0f, 0.0f),
        TM::Vector4(2.0f, 3.0f, 2.0f, 0.0f)
    );

    A = A * B;

    BOOST_CHECK_EQUAL(A.column1.x, 45.0f);
    BOOST_CHECK_EQUAL(A.column1.y, 28.0f);
    BOOST_CHECK_EQUAL(A.column1.z, 59.0f);
    BOOST_CHECK_EQUAL(A.column1.w, 0.0f);
    
    BOOST_CHECK_EQUAL(A.column2.x, 48.0f);
    BOOST_CHECK_EQUAL(A.column2.y, 42.0f);
    BOOST_CHECK_EQUAL(A.column2.z, 68.0f);
    BOOST_CHECK_EQUAL(A.column2.w, 0.0f);
    
    BOOST_CHECK_EQUAL(A.column3.x, 42.0f);
    BOOST_CHECK_EQUAL(A.column3.y, 25.0f);
    BOOST_CHECK_EQUAL(A.column3.z, 48.0f);
    BOOST_CHECK_EQUAL(A.column3.w, 0.0f);
    
    BOOST_CHECK_EQUAL(A.column4.x, 0.0f);
    BOOST_CHECK_EQUAL(A.column4.y, 0.0f);
    BOOST_CHECK_EQUAL(A.column4.z, 0.0f);		 
    BOOST_CHECK_EQUAL(A.column4.w, 1.0f);
}

BOOST_AUTO_TEST_CASE(Matrix4MakeOrthographic)
{
    TM::Matrix4 A(1.0f);

    A.MakeOrthographic(0.0f, 600.0f, 0.0f, 400.0f, 0.01f, 200.0f);

    BOOST_CHECK_EQUAL(RoundFloat(A.column1.x), 0.00333f);
    BOOST_CHECK_EQUAL(A.column1.y, 0.0f);
    BOOST_CHECK_EQUAL(A.column1.z, 0.0f);
    BOOST_CHECK_EQUAL(A.column1.w, 0.0f);

    BOOST_CHECK_EQUAL(A.column2.x, 0.0f);
    BOOST_CHECK_EQUAL(A.column2.y, 0.005f);
    BOOST_CHECK_EQUAL(A.column2.z, 0.0f);
    BOOST_CHECK_EQUAL(A.column2.w, 0.0f);
    
    BOOST_CHECK_EQUAL(A.column3.x, 0.0f);
    BOOST_CHECK_EQUAL(A.column3.y, 0.0f);
    BOOST_CHECK_EQUAL(RoundFloat(A.column3.z), -0.01f);
    BOOST_CHECK_EQUAL(A.column3.w, 0.0f);
    
    BOOST_CHECK_EQUAL(A.column4.x, -1.0f);
    BOOST_CHECK_EQUAL(A.column4.y, -1.0f);
    BOOST_CHECK_EQUAL(RoundFloat(A.column4.z), -1.0001f);		 
    BOOST_CHECK_EQUAL(A.column4.w, 1.0f);
}

BOOST_AUTO_TEST_CASE(Matrix4MakePerspective)
{
    TM::Matrix4 A(1.0f);

    A.MakePerspective(45.0f, 600.0f / 400.0f, 0.1f, 100.0f);

    BOOST_CHECK_EQUAL(RoundFloat(A.column1.x), 1.60948f);
    BOOST_CHECK_EQUAL(A.column1.y, 0.0f);
    BOOST_CHECK_EQUAL(A.column1.z, 0.0f);
    BOOST_CHECK_EQUAL(A.column1.w, 0.0f);
    
    BOOST_CHECK_EQUAL(A.column2.x, 0.0f);
    BOOST_CHECK_EQUAL(RoundFloat(A.column2.y), 2.41421f);
    BOOST_CHECK_EQUAL(A.column2.z, 0.0f);
    BOOST_CHECK_EQUAL(A.column2.w, 0.0f);
    
    BOOST_CHECK_EQUAL(A.column3.x, 0.0f);
    BOOST_CHECK_EQUAL(A.column3.y, 0.0f);
    BOOST_CHECK_EQUAL(RoundFloat(A.column3.z), -1.002f);
    BOOST_CHECK_EQUAL(A.column3.w, -1.0f);

    BOOST_CHECK_EQUAL(A.column4.x, 0.0f);
    BOOST_CHECK_EQUAL(A.column4.y, 0.0f);
    BOOST_CHECK_EQUAL(RoundFloat(A.column4.z), -0.2002f);
    BOOST_CHECK_EQUAL(A.column4.w, 1.0f);
}

BOOST_AUTO_TEST_CASE(Matrix4Reset)
{
    TM::Matrix4 mat
    (
        TM::Vector4(2.0f, 4.0f, 10.0f, 0.0f),
        TM::Vector4(10.0f, 15.0f, 25.0f, 0.0f),
        TM::Vector4(1.0f, 2.0f, 3.0f, 0.0f)
    );

    mat.Reset();

    BOOST_CHECK_EQUAL(mat.column1.x, 0.0f);
    BOOST_CHECK_EQUAL(mat.column1.y, 0.0f);
    BOOST_CHECK_EQUAL(mat.column1.z, 0.0f);
    BOOST_CHECK_EQUAL(mat.column1.w, 0.0f);
    
    BOOST_CHECK_EQUAL(mat.column2.x, 0.0f);
    BOOST_CHECK_EQUAL(mat.column2.y, 0.0f);
    BOOST_CHECK_EQUAL(mat.column2.z, 0.0f);
    BOOST_CHECK_EQUAL(mat.column2.w, 0.0f);
    
    BOOST_CHECK_EQUAL(mat.column3.x, 0.0f);
    BOOST_CHECK_EQUAL(mat.column3.y, 0.0f);
    BOOST_CHECK_EQUAL(mat.column3.z, 0.0f);
    BOOST_CHECK_EQUAL(mat.column3.w, 0.0f);

    BOOST_CHECK_EQUAL(mat.column4.x, 0.0f);
    BOOST_CHECK_EQUAL(mat.column4.y, 0.0f);
    BOOST_CHECK_EQUAL(mat.column4.z, 0.0f);
    BOOST_CHECK_EQUAL(mat.column4.w, 0.0f);

    mat.Reset(1.0f);

    BOOST_CHECK_EQUAL(mat.column1.x, 1.0f);
    BOOST_CHECK_EQUAL(mat.column1.y, 0.0f);
    BOOST_CHECK_EQUAL(mat.column1.z, 0.0f);
    BOOST_CHECK_EQUAL(mat.column1.w, 0.0f);
    
    BOOST_CHECK_EQUAL(mat.column2.x, 0.0f);
    BOOST_CHECK_EQUAL(mat.column2.y, 1.0f);
    BOOST_CHECK_EQUAL(mat.column2.z, 0.0f);
    BOOST_CHECK_EQUAL(mat.column2.w, 0.0f);
    
    BOOST_CHECK_EQUAL(mat.column3.x, 0.0f);
    BOOST_CHECK_EQUAL(mat.column3.y, 0.0f);
    BOOST_CHECK_EQUAL(mat.column3.z, 1.0f);
    BOOST_CHECK_EQUAL(mat.column3.w, 0.0f);

    BOOST_CHECK_EQUAL(mat.column4.x, 0.0f);
    BOOST_CHECK_EQUAL(mat.column4.y, 0.0f);
    BOOST_CHECK_EQUAL(mat.column4.z, 0.0f);
    BOOST_CHECK_EQUAL(mat.column4.w, 1.0f);
}

BOOST_AUTO_TEST_CASE(Matrix4Translation)
{
    TM::Matrix4 T{};
    T.Translate(10.0f, 5.0f);

    BOOST_CHECK_EQUAL(T.column4.x, 10.0f);
    BOOST_CHECK_EQUAL(T.column4.y, 5.0f);
    BOOST_CHECK_EQUAL(T.column4.z, 0.0f);
    BOOST_CHECK_EQUAL(T.column4.w, 1.0f);

    T.Translate(15.0f, 20.0f, 30.0f);

    BOOST_CHECK_EQUAL(T.column4.x, 15.0f);
    BOOST_CHECK_EQUAL(T.column4.y, 20.0f);
    BOOST_CHECK_EQUAL(T.column4.z, 30.0f);
    BOOST_CHECK_EQUAL(T.column4.w, 1.0f);
}

BOOST_AUTO_TEST_CASE(Matrix4Scale)
{
    TM::Matrix4 mat(1.0f);

    mat.Scale(3.0f, 4.0f);

    BOOST_CHECK_EQUAL(mat.column1.x, 3.0f);
    BOOST_CHECK_EQUAL(mat.column2.y, 4.0f);
    BOOST_CHECK_EQUAL(mat.column3.z, 1.0f);
    BOOST_CHECK_EQUAL(mat.column4.w, 1.0f);

    mat.Scale(2.0f, 2.0f, 2.0f);

    BOOST_CHECK_EQUAL(mat.column1.x, 2.0f);
    BOOST_CHECK_EQUAL(mat.column2.y, 2.0f);
    BOOST_CHECK_EQUAL(mat.column3.z, 2.0f);
    BOOST_CHECK_EQUAL(mat.column4.w, 1.0f);

    mat.Scale(TM::Vector4(5.0f, 4.0f, 3.0f, 0.0f));

    BOOST_CHECK_EQUAL(mat.column1.x, 5.0f);
    BOOST_CHECK_EQUAL(mat.column2.y, 4.0f);
    BOOST_CHECK_EQUAL(mat.column3.z, 3.0f);
    BOOST_CHECK_EQUAL(mat.column4.w, 1.0f);
    
    TM::Vector2 vec{2.0f, 3.0f};

    mat.Scale(vec);

    BOOST_CHECK_EQUAL(mat.column1.x, 2.0f);
    BOOST_CHECK_EQUAL(mat.column2.y, 3.0f);
    BOOST_CHECK_EQUAL(mat.column3.z, 1.0f);
    BOOST_CHECK_EQUAL(mat.column4.w, 1.0f);

    TM::Vector3 vec3d{10.0f, 20.0f, 5.0f};

    mat.Scale(vec3d);

    BOOST_CHECK_EQUAL(mat.column1.x, 10.0f);
    BOOST_CHECK_EQUAL(mat.column2.y, 20.0f);
    BOOST_CHECK_EQUAL(mat.column3.z, 5.0f);
    BOOST_CHECK_EQUAL(mat.column4.w, 1.0f);
}

BOOST_AUTO_TEST_CASE(Matrix4Rotation)
{
    TM::Matrix4 mat{1.0f};

    mat.RotateX(-22.0f);

    BOOST_CHECK_EQUAL(mat.column1.x, 1.0f);
    BOOST_CHECK_EQUAL(mat.column1.y, 0.0f);
    BOOST_CHECK_EQUAL(mat.column1.z, 0.0f);
    BOOST_CHECK_EQUAL(mat.column1.w, 0.0f);

    BOOST_CHECK_EQUAL(mat.column2.x, 0.0f);
    BOOST_CHECK_EQUAL(RoundFloat(mat.column2.y), 0.92718f);
    BOOST_CHECK_EQUAL(RoundFloat(mat.column2.z), 0.37461f);
    BOOST_CHECK_EQUAL(mat.column2.w, 0.0f);
    
    BOOST_CHECK_EQUAL(mat.column3.x, 0.0f);
    BOOST_CHECK_EQUAL(RoundFloat(mat.column3.y), -0.37461f);
    BOOST_CHECK_EQUAL(RoundFloat(mat.column3.z), 0.92718f);
    BOOST_CHECK_EQUAL(mat.column3.w, 0.0f);

    BOOST_CHECK_EQUAL(mat.column4.x, 0.0f);
    BOOST_CHECK_EQUAL(mat.column4.y, 0.0f);
    BOOST_CHECK_EQUAL(mat.column4.z, 0.0f);
    BOOST_CHECK_EQUAL(mat.column4.w, 1.0f);

    mat.MakeIdentity();
    mat.RotateY(30.0f);

    BOOST_CHECK_EQUAL(RoundFloat(mat.column1.x), 0.86603f);
    BOOST_CHECK_EQUAL(mat.column1.y, 0.0f);
    BOOST_CHECK_EQUAL(RoundFloat(mat.column1.z),0.50000f);
    BOOST_CHECK_EQUAL(mat.column1.w, 0.0f);
    
    BOOST_CHECK_EQUAL(mat.column2.x, 0.0f);
    BOOST_CHECK_EQUAL(mat.column2.y, 1.0f);
    BOOST_CHECK_EQUAL(mat.column2.z, 0.0f);
    BOOST_CHECK_EQUAL(mat.column2.w, 0.0f);
    
    BOOST_CHECK_EQUAL(RoundFloat(mat.column3.x), -0.50000f);
    BOOST_CHECK_EQUAL(mat.column3.y, 0.0f);
    BOOST_CHECK_EQUAL(RoundFloat(mat.column3.z), 0.86603f);
    BOOST_CHECK_EQUAL(mat.column3.w, 0.0f);

    BOOST_CHECK_EQUAL(mat.column4.x, 0.0f);
    BOOST_CHECK_EQUAL(mat.column4.y, 0.0f);
    BOOST_CHECK_EQUAL(mat.column4.z, 0.0f);
    BOOST_CHECK_EQUAL(mat.column4.w, 1.0f);

    mat.RotateZ(26.0f);

    BOOST_CHECK_EQUAL(RoundFloat(mat.column1.x), 0.89879f);
    BOOST_CHECK_EQUAL(RoundFloat(mat.column1.y), -0.43837f);
    BOOST_CHECK_EQUAL(mat.column1.z, 0.0f);
    BOOST_CHECK_EQUAL(mat.column1.w, 0.0f);
    
    BOOST_CHECK_EQUAL(RoundFloat(mat.column2.x), 0.43837f);
    BOOST_CHECK_EQUAL(RoundFloat(mat.column2.y), 0.89879f);
    BOOST_CHECK_EQUAL(mat.column2.z, 0.0f);
    BOOST_CHECK_EQUAL(mat.column2.w, 0.0f);
    
    BOOST_CHECK_EQUAL(mat.column3.x, 0.0f);
    BOOST_CHECK_EQUAL(mat.column3.y, 0.0f);
    BOOST_CHECK_EQUAL(mat.column3.z, 1.0f);
    BOOST_CHECK_EQUAL(mat.column3.w, 0.0f);

    BOOST_CHECK_EQUAL(mat.column4.x, 0.0f);
    BOOST_CHECK_EQUAL(mat.column4.y, 0.0f);
    BOOST_CHECK_EQUAL(mat.column4.z, 0.0f);
    BOOST_CHECK_EQUAL(mat.column4.w, 1.0f);
}


BOOST_AUTO_TEST_CASE(Matrix4Transpose)
{
    TM::Matrix4 mat
    {
        1.0f, 1.0f, 1.0f, 1.0f,
        2.0f, 2.0f, 2.0f, 2.0f,
        3.0f, 3.0f, 3.0f, 3.0f,
        4.0f, 4.0f, 4.0f, 4.0f
    };

    mat.Transpose();

    BOOST_CHECK_EQUAL(mat.column1.x, 1.0f);
    BOOST_CHECK_EQUAL(mat.column1.y, 2.0f);
    BOOST_CHECK_EQUAL(mat.column1.z, 3.0f);
    BOOST_CHECK_EQUAL(mat.column1.w, 4.0f);
    
    BOOST_CHECK_EQUAL(mat.column2.x, 1.0f);
    BOOST_CHECK_EQUAL(mat.column2.y, 2.0f);
    BOOST_CHECK_EQUAL(mat.column2.z, 3.0f);
    BOOST_CHECK_EQUAL(mat.column2.w, 4.0f);
    
    BOOST_CHECK_EQUAL(mat.column3.x, 1.0f);
    BOOST_CHECK_EQUAL(mat.column3.y, 2.0f);
    BOOST_CHECK_EQUAL(mat.column3.z, 3.0f);
    BOOST_CHECK_EQUAL(mat.column3.w, 4.0f);

    BOOST_CHECK_EQUAL(mat.column4.x, 1.0f);
    BOOST_CHECK_EQUAL(mat.column4.y, 2.0f);
    BOOST_CHECK_EQUAL(mat.column4.z, 3.0f);
    BOOST_CHECK_EQUAL(mat.column4.w, 4.0f);
}

BOOST_AUTO_TEST_CASE(Matrix4ComponentMultiplication)
{
    TM::Matrix4 mat1
    {
        1.0f, 1.0f, 1.0f, 1.0f,
        2.0f, 2.0f, 2.0f, 2.0f,
        3.0f, 3.0f, 3.0f, 3.0f,
        4.0f, 4.0f, 4.0f, 4.0f
    };

    TM::Matrix4 mat2{5.0f};

    mat1.ComponentMulti(mat2);

    BOOST_CHECK_EQUAL(mat1.column1.x, 5.0f);
    BOOST_CHECK_EQUAL(mat1.column1.y, 0.0f);
    BOOST_CHECK_EQUAL(mat1.column1.z, 0.0f);
    BOOST_CHECK_EQUAL(mat1.column1.w, 0.0f);
    
    BOOST_CHECK_EQUAL(mat1.column2.x, 0.0f);
    BOOST_CHECK_EQUAL(mat1.column2.y, 10.0f);
    BOOST_CHECK_EQUAL(mat1.column2.z, 0.0f);
    BOOST_CHECK_EQUAL(mat1.column2.w, 0.0f);
    
    BOOST_CHECK_EQUAL(mat1.column3.x, 0.0f);
    BOOST_CHECK_EQUAL(mat1.column3.y, 0.0f);
    BOOST_CHECK_EQUAL(mat1.column3.z, 15.0f);
    BOOST_CHECK_EQUAL(mat1.column3.w, 0.0f);

    BOOST_CHECK_EQUAL(mat1.column4.x, 0.0f);
    BOOST_CHECK_EQUAL(mat1.column4.y, 0.0f);
    BOOST_CHECK_EQUAL(mat1.column4.z, 0.0f);
    BOOST_CHECK_EQUAL(mat1.column4.w, 4.0f);
}

BOOST_AUTO_TEST_CASE(Matrix4Determinate)
{
    TM::Matrix4 mat
    {
        12.0f, 6.0f, 65.0f, 0.0f,
        3.0f, 52.0f, 8.0f, 0.0f,
        5.0f, 4.0f, 2.0f, 0.0f, 
        45.0f, 8.0f, 4.0f, 1.0f 
    };

    BOOST_CHECK_EQUAL(mat.Determinate(), -15052.00000f);

    TM::Matrix4 mat2
    {
        1.0f, 6.0f, 6.0f, 0.0f,
        3.0f, 5.0f, 8.0f, 0.0f,
        5.0f, 4.0f, 2.0f, 0.0f, 
        5.0f, 8.0f, 4.0f, 1.0f 
    };

    BOOST_CHECK_EQUAL(mat2.Determinate(), 104.00000f);
}

BOOST_AUTO_TEST_CASE(Matrix4Inverse)
{
    TM::Matrix4 mat1 
    { 
        3.0f, 18.0f, 1.0f, 0.0f,
        8.0f, 0.0f, 9.0f, 0.0f,
        1.0f, 2.0f, 0.0f, -1.0f,
        7.0f, 3.0f, 9.0f, 1.0f
    };

    mat1.SetInverse();

    BOOST_CHECK_EQUAL(RoundFloat(mat1.column1.x), 0.47368f);
    BOOST_CHECK_EQUAL(RoundFloat(mat1.column1.y), 1.65263f);
    BOOST_CHECK_EQUAL(RoundFloat(mat1.column1.z), -1.70526f);
    BOOST_CHECK_EQUAL(RoundFloat(mat1.column1.w), -1.70526f);
    
    BOOST_CHECK_EQUAL(RoundFloat(mat1.column2.x), 0.0f);
    BOOST_CHECK_EQUAL(RoundFloat(mat1.column2.y), -0.2f);
    BOOST_CHECK_EQUAL(RoundFloat(mat1.column2.z), 0.2f);
    BOOST_CHECK_EQUAL(RoundFloat(mat1.column2.w), 0.2f);
    
    BOOST_CHECK_EQUAL(RoundFloat(mat1.column3.x), -0.42105f);
    BOOST_CHECK_EQUAL(RoundFloat(mat1.column3.y), -1.35789f);
    BOOST_CHECK_EQUAL(RoundFloat(mat1.column3.z), 1.51579f);
    BOOST_CHECK_EQUAL(RoundFloat(mat1.column3.w), 1.51579f);

    BOOST_CHECK_EQUAL(RoundFloat(mat1.column4.x), 0.47368f);
    BOOST_CHECK_EQUAL(RoundFloat(mat1.column4.y), 1.25263f);
    BOOST_CHECK_EQUAL(RoundFloat(mat1.column4.z), -2.30526f);
    BOOST_CHECK_EQUAL(RoundFloat(mat1.column4.w), -1.30526f);

    TM::Matrix4 mat3
    {
        8.0f, 6.0f, 7.0f, 0.0f, 
        6.0f, 7.0f, 8.0f, 0.0f,
        7.0f, 8.0f, 6.0f, 0.0f,
        8.0f, 6.0f, 7.0f, 1.0f
    };

    TM::Matrix4 mat4 = mat3.GetInverse();

    BOOST_CHECK_EQUAL(RoundFloat(mat4.column1.x), 0.34921f);
    BOOST_CHECK_EQUAL(RoundFloat(mat4.column1.y), -0.31746f);
    BOOST_CHECK_EQUAL(RoundFloat(mat4.column1.z), 0.01587f);
    BOOST_CHECK_EQUAL(RoundFloat(mat4.column1.w), 0.0f);
    
    BOOST_CHECK_EQUAL(RoundFloat(mat4.column2.x), -0.31746f);
    BOOST_CHECK_EQUAL(RoundFloat(mat4.column2.y), 0.01587f);
    BOOST_CHECK_EQUAL(RoundFloat(mat4.column2.z), 0.34921f);
    BOOST_CHECK_EQUAL(RoundFloat(mat4.column2.w), 0.0f);
    
    BOOST_CHECK_EQUAL(RoundFloat(mat4.column3.x), 0.01587f);
    BOOST_CHECK_EQUAL(RoundFloat(mat4.column3.y), 0.34921f);
    BOOST_CHECK_EQUAL(RoundFloat(mat4.column3.z), -0.317460001f);
    BOOST_CHECK_EQUAL(RoundFloat(mat4.column3.w), 0.0);

    BOOST_CHECK_EQUAL(RoundFloat(mat4.column4.x), -1.0f);
    BOOST_CHECK_EQUAL(RoundFloat(mat4.column4.y), 0.0f);
    BOOST_CHECK_EQUAL(RoundFloat(mat4.column4.z), 0.0f);
    BOOST_CHECK_EQUAL(RoundFloat(mat4.column4.w), 1.0f);
}

BOOST_AUTO_TEST_CASE(Matrix4Transform3x3)
{
    TM::Matrix4 matA
    {
        1.0f, 1.0f, 2.0f, 10.0f,
        4.0f, 3.0f, 1.0f, 20.0f, 
        5.0f, 9.0f, 2.0f, 30.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    TM::Matrix4 matB
    {
        1.0f, 1.0f, 7.0f, 2.0f, 
        4.0f, 6.0f, 0.0f, 3.0f,
        9.0f, 3.0f, 6.0f, 400.0f,
        0.0f, 0.0f, 0.0f, 0.0f
    };

    TM::Matrix4 matC = matA.Transform3x3(matB);

    BOOST_CHECK_EQUAL(matC.column1.x, 40.0f);
    BOOST_CHECK_EQUAL(matC.column1.y, 67.0f);
    BOOST_CHECK_EQUAL(matC.column1.z, 17.0f);
    BOOST_CHECK_EQUAL(matC.column1.w, 0.0f);
    
    BOOST_CHECK_EQUAL(matC.column2.x, 28.0f);
    BOOST_CHECK_EQUAL(matC.column2.y, 22.0f);
    BOOST_CHECK_EQUAL(matC.column2.z, 14.0f);
    BOOST_CHECK_EQUAL(matC.column2.w, 0.0f);
    
    BOOST_CHECK_EQUAL(matC.column3.x, 51.0f);
    BOOST_CHECK_EQUAL(matC.column3.y, 72.0f);
    BOOST_CHECK_EQUAL(matC.column3.z, 33.0f);
    BOOST_CHECK_EQUAL(matC.column3.w, 0.0f);

    BOOST_CHECK_EQUAL(matC.column4.x, 0.0f);
    BOOST_CHECK_EQUAL(matC.column4.y, 0.0f);
    BOOST_CHECK_EQUAL(matC.column4.z, 0.0f);
    BOOST_CHECK_EQUAL(matC.column4.w, 1.0f);
}