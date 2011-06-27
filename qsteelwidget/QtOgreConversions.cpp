/*
 * QtOgreConversions.cpp
 *
 *  Created on: 2011-06-08
 *      Author: onze
 */

#include <Ogre.h>
#include "QtOgreConversions.h"
#include <iostream>

template<class U,class V>
V convert(U &u)
{
	std::cout<<"WARNING : default conversion used for template<class U,class V> V convert(U &u)"<<std::endl;
	return V(u);
}


QString convert(const Ogre::String &s)
{
	return QString(s.c_str());
}

QVector3D convert(const Ogre::Vector3 &v)
{
	return QVector3D(v.x,v.y,v.z);
}

QVector4D convert(const Ogre::Quaternion &q)
{
	return QVector4D(q.x,q.y,q.z,q.w);
}

Ogre::String convert(const QString &s)
{
	return Ogre::String(s.toStdString().c_str());
}

Ogre::Vector3 convert(const QVector3D &v)
{
	return Ogre::Vector3(v.x(),v.y(),v.z());
}

Ogre::Quaternion convert(const QVector4D &v)
{
	return Ogre::Quaternion(v.w(),v.x(),v.y(),v.z());
}

Ogre::String toString(const QVector3D &v)
{
	Ogre::String s="<QVector3D ";
	s+="x="+Ogre::StringConverter::toString((float)v.x())+", ";
	s+="y="+Ogre::StringConverter::toString((float)v.y())+", ";
	s+="z="+Ogre::StringConverter::toString((float)v.z());
	s+=">";
	return s;
}

Ogre::String toString(const QVector4D &v)
{
	Ogre::String s="<QVector4D ";
	s+="w="+Ogre::StringConverter::toString((float)v.w())+", ";
	s+="x="+Ogre::StringConverter::toString((float)v.x())+", ";
	s+="y="+Ogre::StringConverter::toString((float)v.y())+", ";
	s+="z="+Ogre::StringConverter::toString((float)v.z());
	s+=">";
	return s;

}

