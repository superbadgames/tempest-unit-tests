/*------------------------------------------------------------
The Bounding Sphere is a Bounding Volume used in the Killer Collision 
engine. 

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
#include <Engine/BoundingSphere.h>
#include <Engine/Point3.h>

namespace TC = TempestCollisions;
namespace TM = TempestMath;

BOOST_AUTO_TEST_CASE(BoundingSphereConstructors)
{
    TC::BoundingSphere sphere1 { };

    BOOST_CHECK_EQUAL(sphere1.GetCenter().x, 0.0f);
    BOOST_CHECK_EQUAL(sphere1.GetCenter().y, 0.0f);
    BOOST_CHECK_EQUAL(sphere1.GetCenter().z, 0.0f);
    BOOST_CHECK_EQUAL(sphere1.GetRadius(), 0.0f);

    TC::BoundingSphere sphere2 { TM::Point3(2.0f, 5.0f, 1.0f), 25.0f };

    BOOST_CHECK_EQUAL(sphere2.GetCenter().x, 2.0f);
    BOOST_CHECK_EQUAL(sphere2.GetCenter().y, 5.0f);
    BOOST_CHECK_EQUAL(sphere2.GetCenter().z, 1.0f);
    BOOST_CHECK_EQUAL(sphere2.GetRadius(), 25.0f);

    //Combination test will be more difficult
    //TC::BoundingSphere sphere3 { TM::Point3() }
}

BOOST_AUTO_TEST_CASE(BoundingSphereAccessors)
{
    TC::BoundingSphere sphere { TM::Point3(10.0f, 10.0f, 0.0f), 5.0f };

    BOOST_CHECK_EQUAL(sphere.GetCenter().x, 10.0f);
    BOOST_CHECK_EQUAL(sphere.GetCenter().y, 10.0f);
    BOOST_CHECK_EQUAL(sphere.GetCenter().z, 0.0f);
    BOOST_CHECK_EQUAL(sphere.GetRadius(), 5.0f);

    sphere.SetCenter(TM::Point3(35.0f, 1.0f, 2.0f));
    sphere.SetRadius(2.5f);

    BOOST_CHECK_EQUAL(sphere.GetCenter().x, 35.0f);
    BOOST_CHECK_EQUAL(sphere.GetCenter().y, 1.0f);
    BOOST_CHECK_EQUAL(sphere.GetCenter().z, 2.0f);
    BOOST_CHECK_EQUAL(sphere.GetRadius(), 2.5f);

    sphere.SetCenter(26.0f, 15.0f, 23.0f);

    BOOST_CHECK_EQUAL(sphere.GetCenter().x, 26.0f);
    BOOST_CHECK_EQUAL(sphere.GetCenter().y, 15.0f);
    BOOST_CHECK_EQUAL(sphere.GetCenter().z, 23.0f);
}

BOOST_AUTO_TEST_CASE(BoundingShereIntersectBoundingSphere)
{
    TC::BoundingSphere sphere1 { TM::Point3(0.0f, 0.0f, 0.0f), 4.0f };
    TC::BoundingSphere sphere2 { TM::Point3(2.0f, 2.0f, 2.0f), 4.0f };

    BOOST_CHECK_EQUAL(sphere1.TestCollision(sphere2), true);
    BOOST_CHECK_EQUAL(sphere2.TestCollision(sphere1), true);

    sphere2.SetCenter(-2.0f, 0.0f, 0.0f);

    BOOST_CHECK_EQUAL(sphere1.TestCollision(sphere2), true);
    BOOST_CHECK_EQUAL(sphere2.TestCollision(sphere1), true);

    sphere1.SetCenter(10.0f, 5.0f, 8.0f);

    BOOST_CHECK_EQUAL(sphere1.TestCollision(sphere2), false);
    BOOST_CHECK_EQUAL(sphere2.TestCollision(sphere1), false);
}

BOOST_AUTO_TEST_CASE(BoudningSphereGetGrowth)
{
    //Note, only checking relative sizes, since size prediction is not
    //really important. 

    TC::BoundingSphere sphere1 { TM::Point3(0.0f, 0.0f, 0.0f), 8.0f };
    TC::BoundingSphere sphere2 { TM::Point3(0.0f, 0.0f, 0.0f), 10.0f };

    //Check if the growth from 2 would be bigger than 1 is now. 
    BOOST_CHECK_GT(sphere1.GetGrowth(sphere2), sphere1.GetRadius());

    TC::BoundingSphere sphere3 { TM::Point3(10.0f, 10.0f, 0.0f), 10.0f };

    //Check if 3, a sphere the same size of 2, but in a different place
    //would have a larger growth, being further away.
    BOOST_CHECK_GT(sphere1.GetGrowth(sphere3), sphere1.GetGrowth(sphere2));

    TC::BoundingSphere sphere4 { TM::Point3(5.0f, 5.0f, 0.0f), 2.0f };
    
    //Check if a smaller, but further away sphere would have less growth
    //than a bigger, but closer sphere. 
    BOOST_CHECK_GT(sphere1.GetGrowth(sphere2), sphere1.GetGrowth(sphere4));	
}