//sphere.h
#ifndef _SPHERE_H_
#define _SPHERE_H_

#include <iostream>
using namespace std;
#include "object.h"
#include "ray.h"
#include "vector3D.h"
#include "color.h"
#include "lightsource.h"

#define degreeToRadians(X) ((X)*M_PI/180.0f)

#ifdef __APPLE__
	#include <OpenGL/gl3.h>
#endif

class Sphere : public Object
{
private:
	Vector3D position;
	double radius;


public:
	Sphere(const Vector3D& _pos, double _rad, Material* mat):
		Object(mat), position(_pos), radius(_rad)
	{
		isSolid = true;
		isMovement = true;
		drawShape(mat);
	}

	// void foo() {cout << "Reached" << endl;}
	void drawShape(Material* mat);
	virtual bool intersect(Ray& r) const;
	virtual Vector3D getPosition() const { return position; };
	void changePosition(Material* mat, Vector3D dtrans) {
		position = position + dtrans;
		cout << position[0] << " " << position[1] << " " << position[2] << endl;
		drawShape(mat);
	};
	void changeRadius(Material* mat, float scaleF) {
		if (radius + scaleF > 1.0) {
			radius = radius+scaleF;
			drawShape(mat);
		}
	}

};
#endif
