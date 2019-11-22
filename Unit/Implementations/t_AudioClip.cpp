/*------------------------------------------------------------
Tests written for the AudioClip class. This is a buffer that is stored
from OpenAL that can be passed to an AudioSource to be played later.

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
#include <UnitTests/TestHelper.h>
#include <Engine/Atom.h>
#include <Engine/AudioClip.h>

#include <iostream>
#include <Windows.h>

namespace TE = Tempest;

BOOST_AUTO_TEST_CASE(AudioClipConstructor)
{
	TE::AudioClip clip {};

	BOOST_CHECK_EQUAL(clip.GetBufferID(), 0);
}

BOOST_AUTO_TEST_CASE(AudioClipLoadWAV)
{
	TE::AudioClip clip {};
	
	clip.LoadWAV2("./Assets/Komiku_04_Skate.wav");

	BOOST_CHECK_GT(static_cast<S32>(clip.GetBufferID()), 1);
}

