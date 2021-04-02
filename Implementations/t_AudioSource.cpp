/*------------------------------------------------------------
Written to test to AudioSource. This class represents the source of an audio
clip in OpenAL.

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
#include <Engine/AudioSource.h>
#include <Engine/AudioClip.h>

namespace TE = Tempest;


BOOST_AUTO_TEST_CASE(AudioSourceConstructor)
{
    TE::AudioSource source { };

    BOOST_CHECK_EQUAL(source.GetPlaying(), false);
    BOOST_CHECK_EQUAL(source.GetLooping(), false);
    BOOST_CHECK_GT((int)source.GetSourceID(), 0);
    BOOST_CHECK_EQUAL(source.GetPitch(), 1.0f);
    BOOST_CHECK_EQUAL(source.GetPosition().GetX(), 0.0f);
    BOOST_CHECK_EQUAL(source.GetPosition().GetY(), 0.0f);
    BOOST_CHECK_EQUAL(source.GetPosition().GetZ(), 0.0f);
    BOOST_CHECK_EQUAL(source.GetVelocity().GetX(), 0.0f);
    BOOST_CHECK_EQUAL(source.GetVelocity().GetY(), 0.0f);
    BOOST_CHECK_EQUAL(source.GetVelocity().GetZ(), 0.0f);
    BOOST_CHECK_EQUAL(source.GetClip(), nullptr);
}

BOOST_AUTO_TEST_CASE(AudioSourceAccessors)
{
    TE::AudioSource source { };

    //Looping
    source.SetLooping(true);

    int state;

    BOOST_CHECK_EQUAL(source.GetLooping(), true);

    alGetSourcei(source.GetSourceID(), AL_LOOPING, &state);

    bool stateConversion;
    if(state == 1)
        stateConversion = true;

    BOOST_CHECK_EQUAL(stateConversion, true);

    //Pitch
    source.SetPitch(0.5f);

    BOOST_CHECK_EQUAL(source.GetPitch(), 0.5f);

    F32 pitch;
    alGetSourcef(source.GetSourceID(), AL_PITCH, &pitch);

    BOOST_CHECK_EQUAL(pitch, 0.5f);

    //Gain
    source.SetGain(0.25f);

    BOOST_CHECK_EQUAL(source.GetGain(), 0.25f);

    F32 gain;
    alGetSourcef(source.GetSourceID(), AL_GAIN, &gain);

    BOOST_CHECK_EQUAL(gain, 0.25f);

    //Position
    source.SetPosition(2.0f, 3.0f, 4.0f);

    BOOST_CHECK_EQUAL(source.GetPosition().GetX(), 2.0f);
    BOOST_CHECK_EQUAL(source.GetPosition().GetY(), 3.0f);
    BOOST_CHECK_EQUAL(source.GetPosition().GetZ(), 4.0f);

    F32 xPos, yPos, zPos;

    alGetSource3f(source.GetSourceID(), AL_POSITION, &xPos, &yPos, &zPos);

    BOOST_CHECK_EQUAL(xPos, 2.0f);
    BOOST_CHECK_EQUAL(yPos, 3.0f);
    BOOST_CHECK_EQUAL(zPos, 4.0f);

    //Velocity
    source.SetVelocity(6.0f, 7.0f, 8.0f);

    BOOST_CHECK_EQUAL(source.GetVelocity().GetX(), 6.0f);
    BOOST_CHECK_EQUAL(source.GetVelocity().GetY(), 7.0f);
    BOOST_CHECK_EQUAL(source.GetVelocity().GetZ(), 8.0f);

    F32 xVel, yVel, zVel;

    alGetSource3f(source.GetSourceID(), AL_VELOCITY, &xVel, &yVel, &zVel);

    BOOST_CHECK_EQUAL(xVel, 6.0f);
    BOOST_CHECK_EQUAL(yVel, 7.0f);
    BOOST_CHECK_EQUAL(zVel, 8.0f);
}

//BOOST_AUTO_TEST_CASE(AudioSourceClipInterations)
//{
//
//    TE::AudioSource source { };
//
//    shared_ptr<TE::AudioClip> clip = make_shared<TE::AudioClip>();
//
//    clip->LoadWAV2("./Assets/Komiku_04_Skate.wav");
//
//    BOOST_CHECK_GT(static_cast<S32>(clip->GetBufferID()), 1);
//    
//    source.AddClip(clip);
//
//    shared_ptr<TE::AudioClip> clipCopy = source.GetClip();
//
//    BOOST_CHECK_NE(clipCopy, nullptr);
//    BOOST_CHECK_GT(static_cast<S32>(clipCopy->GetBufferID()), 1);
//}