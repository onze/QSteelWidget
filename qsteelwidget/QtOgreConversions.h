/*
 * QtOgreConversions.h
 *
 *  Created on: 2011-06-08
 *      Author: onze
 */

#ifndef QTOGRECONVERSIONS_H_
#define QTOGRECONVERSIONS_H_

#include <OgreVector3.h>
#include <OgreQuaternion.h>
#include <qvector3d.h>
#include <qvector4d.h>

template<class U,class V>
inline V convert(U &u);

// Ogre -> Qt
QVector3D convert(const Ogre::Vector3 &v);
QVector4D convert(const Ogre::Quaternion &q);

//Qt -> Ogre
Ogre::Vector3 convert(const QVector3D &v);
Ogre::Quaternion convert(const QVector4D &v);
Ogre::String toString(const QVector3D &v);
Ogre::String toString(const QVector4D &v);

#endif /* QTOGRECONVERSIONS_H_ */
