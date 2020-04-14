/*------------------------------------------------------------
A 2D "particle" used to hook into the physics engine.
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

#include <boost/test/unit_test.hpp>
#include <Engine/Atom.h>
#include <Engine/RigidBody2D.h>
#include <Engine/GameObject2D.h>
#include <Engine/Vector4.h>
#include <Engine/EngineFactory.h>
#include <Engine/ErrorManager.h>

namespace TE = Tempest;
namespace TM = TempestMath;
namespace TP =TempestPhysics;


class RigidBody2DDefinedObj : public TE::GameObject2D
{
public:
	RigidBody2DDefinedObj(void)
	: p_body(nullptr)
	{  }

	~RigidBody2DDefinedObj(void)
	{
		p_body.reset();
	}

	void v_Update(void) final
	{  }

	void SetBody(void)
	{
		p_body = TE::EngineFactory::Instance()->MakeRigidBody2D();
		p_body->SetObject(this);
	}

	TP::p_RigidBody2D p_body;
};

void IntegrateNTimes(RigidBody2DDefinedObj& obj, S32 n)
{
	for(S32 i = 0; i < n; ++i)
	{
		TM::Timer::Instance()->SingleStep();
		obj.p_body->Integrate();
		TE::ErrorManager::Instance()->DisplayErrors();
	}
}

BOOST_AUTO_TEST_CASE(RigidBody2DConstructor)
{
	TP::RigidBody2D body { };

	BOOST_CHECK_EQUAL(body.GetActive(), true);
	BOOST_CHECK_EQUAL(body.GetVelocity().x, 0.0f);
	BOOST_CHECK_EQUAL(body.GetVelocity().y, 0.0f);
	BOOST_CHECK_EQUAL(body.GetAcceleration().x, 0.0f);
	BOOST_CHECK_EQUAL(body.GetAcceleration().y, 0.0f);
	BOOST_CHECK_EQUAL(body.GetForces().x, 0.0f);
	BOOST_CHECK_EQUAL(body.GetForces().y, 0.0f);
	BOOST_CHECK_EQUAL(body.GetGravityForce().x, 0.0f);
	BOOST_CHECK_EQUAL(body.GetGravityForce().y, 0.0f);
	BOOST_CHECK_EQUAL(body.GetInverseMass(), 1.0f);
	BOOST_CHECK_EQUAL(body.GetMass(), 1.0f);
	BOOST_CHECK_EQUAL(body.HasFiniteMass(), true);
	BOOST_CHECK_EQUAL(body.GetLinearDamping(), 0.999f);
}

BOOST_AUTO_TEST_CASE(RigidBody2DGameObjectIntegration)
{
	RigidBody2DDefinedObj obj { };
	obj.SetBody();

	BOOST_CHECK_NE(obj.p_body, nullptr);

	obj.p_body->SetVelocity(1.0f, 1.0f);
	obj.p_body->SetAcceleration(-0.25f, 0.0f);
	obj.SetPosition(1.0f, 1.0f);

	IntegrateNTimes(obj, 100);

	BOOST_CHECK_GT(obj.GetPosition().x, 1.0f);
	BOOST_CHECK_GT(obj.GetPosition().y, 1.0f);

	BOOST_CHECK_LT(obj.p_body->GetVelocity().x, 100.0f);
	//Damping will reduce, hence Less Than, not Equal
	BOOST_CHECK_LT(obj.p_body->GetVelocity().y, 1.0f);
	
	BOOST_CHECK_EQUAL(obj.p_body->GetActive(), true);

	obj.SetActive(false);
	BOOST_CHECK_EQUAL(obj.p_body->GetActive(), false);
}


BOOST_AUTO_TEST_CASE(RigidBody2DZeroMass)
{
	RigidBody2DDefinedObj obj { };
	obj.SetBody();
	obj.p_body->SetInverseMass(0.0f);

	obj.SetPosition(15.0f, 12.0f);
	obj.p_body->SetVelocity(1.0f, 1.0f);

	IntegrateNTimes(obj, 1000);

	BOOST_CHECK_EQUAL(obj.GetPosition().x, 15.0f);
	BOOST_CHECK_EQUAL(obj.GetPosition().y, 12.0f);
}

BOOST_AUTO_TEST_CASE(RigidBody2DDampingTest)
{
	RigidBody2DDefinedObj obj { };
	obj.SetBody();

	obj.p_body->SetVelocity(10.0f, 20.0f);
	obj.p_body->SetLinearDamping(0.0f);

	IntegrateNTimes(obj, 1000);

	BOOST_CHECK_EQUAL(obj.p_body->GetVelocity().x, 0.0f);
	BOOST_CHECK_EQUAL(obj.p_body->GetVelocity().y, 0.0f);
}