#pragma once

#ifndef CML_HEADER




namespace cml {

#ifndef M_PI
#define M_PI           3.14159265358979323846  /* pi */
#endif

	const double epsilon = 4.37114e-05;
	#define EPSILON epsilon

	bool cmpf(float A, float B)
	{
		return (fabs(A - B) < EPSILON);
	}
	bool cmpf(double A, double B)
	{
		return (fabs(A - B) < EPSILON);
	}


}


#endif // !CML_HEADER