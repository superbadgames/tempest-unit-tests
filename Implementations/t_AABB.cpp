/*------------------------------------------------------------
The AABB is a Bounding Volume used 
in the Killer Collision engine. 

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
#include <Engine/Atom.h>
#include <Engine/AABB.h>
#include <Engine/Point3.h>

namespace TC = TempestCollisions;
namespace TM = TempestMath;

BOOST_AUTO_TEST_CASE(AABBConstructors)
{
    TC::AABB box {  };

    BOOST_CHECK_EQUAL(box.GetCenter().x, 0.0f);
    BOOST_CHECK_EQUAL(box.GetCenter().y, 0.0f);
    BOOST_CHECK_EQUAL(box.GetCenter().z, 0.0f);
    BOOST_CHECK_EQUAL(box.GetWidth(), 0.0f);
    BOOST_CHECK_EQUAL(box.GetHeight(), 0.0f);
    BOOST_CHECK_EQUAL(box.GetDepth(), 0.0f);

    TC::AABB box2 { TM::Point3(4.0f, 53.0f, 20.0f), 1.0f, 2.0f, 3.0f };

    BOOST_CHECK_EQUAL(box2.GetCenter().x, 4.0f);
    BOOST_CHECK_EQUAL(box2.GetCenter().y, 53.0f);
    BOOST_CHECK_EQUAL(box2.GetCenter().z, 20.0f);
    BOOST_CHECK_EQUAL(box2.GetWidth(), 1.0f);
    BOOST_CHECK_EQUAL(box2.GetHeight(), 2.0f);
    BOOST_CHECK_EQUAL(box2.GetDepth(), 3.0f);
    BOOST_CHECK_EQUAL(box2.GetHalfWidth(), 0.5f);
    BOOST_CHECK_EQUAL(box2.GetHalfHeight(), 1.0f);
    BOOST_CHECK_EQUAL(box2.GetHalfDepth(), 1.5f);
}

BOOST_AUTO_TEST_CASE(AABBAccessors)
{
    TC::AABB box { };
    
    box.SetCenter(TM::Point3(2.0f, 5.0f, 3.0f));

    BOOST_CHECK_EQUAL(box.GetCenter().x, 2.0f);
    BOOST_CHECK_EQUAL(box.GetCenter().y, 5.0f);
    BOOST_CHECK_EQUAL(box.GetCenter().z, 3.0f);

    box.SetCenter(14.0f, 30.0f, 150.0f);

    BOOST_CHECK_EQUAL(box.GetCenter().x, 14.0f);
    BOOST_CHECK_EQUAL(box.GetCenter().y, 30.0f);
    BOOST_CHECK_EQUAL(box.GetCenter().z, 150.0f);

    box.SetHalfWidth(5.0f);
    BOOST_CHECK_EQUAL(box.GetHalfWidth(), 5.0f);
    BOOST_CHECK_EQUAL(box.GetWidth(), 10.0f);

    box.SetWidth(30.0f);
    BOOST_CHECK_EQUAL(box.GetHalfWidth(), 15.0f);
    BOOST_CHECK_EQUAL(box.GetWidth(), 30.0f);

    box.SetHalfHeight(40.0f);
    BOOST_CHECK_EQUAL(box.GetHalfHeight(), 40.0f);
    BOOST_CHECK_EQUAL(box.GetHeight(), 80.0f);

    box.SetHeight(200.0f);
    BOOST_CHECK_EQUAL(box.GetHalfHeight(), 100.0f);
    BOOST_CHECK_EQUAL(box.GetHeight(), 200.0f);

    box.SetHalfDepth(300.0f);
    BOOST_CHECK_EQUAL(box.GetHalfDepth(), 300.0f);
    BOOST_CHECK_EQUAL(box.GetDepth(), 600.0f);

    box.SetDepth(30.0f);
    BOOST_CHECK_EQUAL(box.GetHalfDepth(), 15.0f);
    BOOST_CHECK_EQUAL(box.GetDepth(), 30.0f);

    box.SetHalfDimensions(40.0f, 25.0f, 80.0f);
    BOOST_CHECK_EQUAL(box.GetHalfWidth(), 40.0f);
    BOOST_CHECK_EQUAL(box.GetHalfHeight(), 25.0f);
    BOOST_CHECK_EQUAL(box.GetHalfDepth(), 80.0f);
    BOOST_CHECK_EQUAL(box.GetWidth(), 80.0f);
    BOOST_CHECK_EQUAL(box.GetHeight(), 50.0f);
    BOOST_CHECK_EQUAL(box.GetDepth(), 160.0f);

    box.SetDimensions(100.0f, 300.0f, 450.0f);
    BOOST_CHECK_EQUAL(box.GetHalfWidth(), 50.0f);
    BOOST_CHECK_EQUAL(box.GetHalfHeight(), 150.0f);
    BOOST_CHECK_EQUAL(box.GetHalfDepth(), 225.0f);
    BOOST_CHECK_EQUAL(box.GetWidth(), 100.0f);
    BOOST_CHECK_EQUAL(box.GetHeight(), 300.0f);
    BOOST_CHECK_EQUAL(box.GetDepth(), 450.0f);

}

BOOST_AUTO_TEST_CASE(AABBIntersectAABBTest)
{
    TC::AABB box1 { TM::Point3(0.0f, 0.0f, 0.0f), 4.0f, 4.0f, 4.0f };
    TC::AABB box2 { TM::Point3(3.0f, 3.0f, 0.0f), 4.0f, 4.0f, 4.0f };

    BOOST_CHECK_EQUAL(box1.TestCollision(box2), true);
    BOOST_CHECK_EQUAL(box2.TestCollision(box1), true);

    box1.SetCenter(-2.0f, 0.0f, 0.0f);

    BOOST_CHECK_EQUAL(box1.TestCollision(box2), false);
    BOOST_CHECK_EQUAL(box2.TestCollision(box1), false);

    box2.SetCenter(-5.0f, -3.0f, 0.0f);

    BOOST_CHECK_EQUAL(box1.TestCollision(box2), true);
    BOOST_CHECK_EQUAL(box2.TestCollision(box1), true);

    box1.SetCenter(0.0f, 0.0f, 2.0f);
    box2.SetCenter(0.0f, 0.0f, 3.0f);	

    BOOST_CHECK_EQUAL(box1.TestCollision(box2), true);
    BOOST_CHECK_EQUAL(box2.TestCollision(box1), true);

    box2.SetCenter(0.0f, 0.0f, 10.0f);

    BOOST_CHECK_EQUAL(box1.TestCollision(box2), false);
    BOOST_CHECK_EQUAL(box2.TestCollision(box1), false);
}