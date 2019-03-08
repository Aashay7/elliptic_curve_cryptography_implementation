# elliptic_curve_cryptography_implementation

If we're talking about an elliptic curve in Fp, what we're talking about is a cloud of points which fulfill the "curve equation". This equation is:
 
Here, y, x, a and b are all within Fp, i.e. they are integers modulo p. The coefficients a and b are the so-called characteristic coefficients of the curve -- they determine what points will be on the curve.
Note that the curve coefficients have to fulfill one condition:
 
This condition guarantees that the curve will not contain any singularities.
Point representation

 
Point Operations
To do any meaningful operations on a elliptic curve, one has to be able to do calculations with points of the curve. The two basic operations to perform with on-curve points are:
1.	Point addition: R = P + Q
2.	Point doubling: R = P + P

Out of these operations, there's one compound operation, scalar point multiplication, which can be implemented by the two above. This will also be described. Note that adding any point to the special point at infinity yields the point, or mathematically speaking:

This is the basic implementation of El-Gamal Elliptic Curve Cryptography Scheme in C++.
