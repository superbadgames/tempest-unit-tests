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

#include <boost/test/unit_test.hpp>
#include <Engine/Atom.h>
#include <Engine/GameObject.h>
#include <Engine/State.h>
#include <Engine/StateMachine.h>

namespace TE = Tempest;

//==========================================================================================================================
// Defined version of the GameObject for testing
//==========================================================================================================================
class DefinedObject : public TE::GameObject
{
public:
	DefinedObject(void)
		:
		_stateMachine(shared_ptr<DefinedObject>(this)),
		_enterState(false),
		_executeIncrement(0)
	{  }

	~DefinedObject(void)
	{  }

	void v_Update(void)
	{
		_stateMachine.Update();
	}

	void SetState(TE::p_State<DefinedObject> state)
	{
		_stateMachine.ChangeState(state);
	}
	
	bool GetEnterState(void) const
	{
		return _enterState;
	}

	void SetEnterState(bool state)
	{
		_enterState = state;
	}

	void Increment(U32 inc)
	{
		_executeIncrement += inc;
	}

	U32 GetIncrement(void) const
	{
		return _executeIncrement;
	}

private:
	TE::StateMachine<DefinedObject> _stateMachine;
	bool _enterState;
	U32 _executeIncrement;
};
typedef shared_ptr<DefinedObject> p_DefinedObject;


//==========================================================================================================================
//Defined version of the State for testing
//==========================================================================================================================
class IncrementOneState : public TE::State<DefinedObject>
{
public:
	IncrementOneState(void)
	{  }

	~IncrementOneState(void) final
	{  }

	static shared_ptr<IncrementOneState> Instance(void)
	{
		if(_instance == nullptr)
		{
			_instance = shared_ptr<IncrementOneState>(new IncrementOneState());
		}
		return _instance;
	}
	
	void v_Enter(p_DefinedObject obj) final
	{
		obj->SetEnterState(true);
	}

	void v_Execute(p_DefinedObject obj) final
	{
		obj->Increment(1);
	}

	void v_Exit(p_DefinedObject obj) final
	{
		obj->SetEnterState(false);
	}

private:
	static shared_ptr<IncrementOneState> _instance;
};

shared_ptr<IncrementOneState> IncrementOneState::_instance = nullptr;

//==========================================================================================================================
//Defined version of the State for testing
//==========================================================================================================================
class IncrementTwoState : public TE::State<DefinedObject>
{
public:
	IncrementTwoState(void)
	{  }

	~IncrementTwoState(void) final
	{  }

	static shared_ptr<IncrementTwoState> Instance(void)
	{
		if(_instance == nullptr)
		{
			_instance = shared_ptr<IncrementTwoState>(new IncrementTwoState());
		}
		return _instance;
	}

	void v_Enter(p_DefinedObject obj) final
	{
		obj->SetEnterState(true);
	}

	void v_Execute(p_DefinedObject obj) final
	{
		obj->Increment(2);
	}

	void v_Exit(p_DefinedObject obj) final
	{
		obj->SetEnterState(false);
	}

private:
	static shared_ptr<IncrementTwoState> _instance;
};

//==========================================================================================================================
//Tests
//==========================================================================================================================
BOOST_AUTO_TEST_CASE(StateMachineFirstGo)
{
	DefinedObject obj { };

	BOOST_CHECK_EQUAL(obj.GetIncrement(), 0);
	BOOST_CHECK_EQUAL(obj.GetEnterState(), false);

	obj.SetState(IncrementOneState::Instance());

	BOOST_CHECK_EQUAL(obj.GetIncrement(), 0);
	BOOST_CHECK_EQUAL(obj.GetEnterState(), true);

	obj.v_Update();

	BOOST_CHECK_EQUAL(obj.GetIncrement(), 1);
	BOOST_CHECK_EQUAL(obj.GetEnterState(), true);


}