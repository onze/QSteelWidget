
#include "unittests.h"
#include <iostream>
#include "assert.h"
#include "QtOgreConversions.h"

void unitMain()
{
	std::cout<<"== STARTING UNIT TESTS =="<<std::endl;

	QVector3D v3_qt(1.,2.,3.);
	Ogre::Vector3 v3_ogre(1.,2.,3.);

	assert(v3_qt==convert(v3_ogre));
	assert(v3_ogre==convert(v3_qt));
	assert(v3_qt==convert(convert(v3_qt)));
	assert(v3_ogre==convert(convert(v3_ogre)));


	float x=1.f,y=2.f,z=3.f,w=4.f;
	QVector4D v4_qt=QVector4D(x,y,z,w);
	Ogre::Quaternion v4_ogre=Ogre::Quaternion(w,x,y,z);

	assert(v4_qt==convert(v4_ogre));
	assert(v4_ogre==convert(v4_qt));
	assert(v4_qt==convert(convert(v4_qt)));
	assert(v4_ogre==convert(convert(v4_ogre)));

	std::cout<<"== ALL TESTS OKAY =="<<std::endl;
}
