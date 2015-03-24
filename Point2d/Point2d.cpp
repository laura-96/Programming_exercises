#include "Point2d.h"
#include <math.h>

Point2d Point2d::operator+ (const Point2d& a) const{

	Point2d b;
	b.x = x + a.x;
	b.y = y + a.y;
	return(b);
}

Point2d Point2d::operator- (const Point2d& a) const{

	Point2d b;
	b.x = x - a.x;
	b.y = y - a.y;
	return(b);
}

const Point2d& Point2d::operator+= (const Point2d& a){

	x += a.x;
	y += a.y;
	return (*this);
}

const Point2d& Point2d::operator-= (const Point2d& a){

	x -= a.x;
	y -= a.y;
	return (*this);
}

bool Point2d::operator== (const Point2d& a) const{

	return((a.x == x) && (a.y == y));
}

bool Point2d::operator!= (const Point2d& a) const{

	return((a.x != x) || (a.y != y));
}

bool Point2d::IsZero() const{

	return ((x == 0) && (y == 0));
}

void Point2d::SetZero(){

	x = 0;
	y = 0;
}

float Point2d::DistanceTo(const Point2d& a) const{

	float distance;
	float vx = a.x - x;
	float vy = a.y - y;
	distance = sqrtf((vx*vx) + (vy*vy));
	return distance;
}