#ifndef __POINT2D_H__
#define __POINT2D_H__

class Point2d{

public:

	float x, y;

public:

	Point2d operator+ (const Point2d& a) const;
	Point2d operator- (const Point2d& a) const;
	const Point2d& operator+= (const Point2d& a);
	const Point2d& operator-= (const Point2d& a);
	bool operator== (const Point2d& a) const;
	bool operator!= (const Point2d& a) const;
	bool IsZero () const;
	void SetZero ();
	float DistanceTo (const Point2d& a) const;
};

#endif