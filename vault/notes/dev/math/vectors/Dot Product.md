Dot Product - is a product of two vectors, that could be used to determine how much vectors is in same direction. opearation could be done with 2d vectors and 3d. 

base formula:
$\vec{\alpha} * \vec{\beta} = \alpha_1*\beta_1 + \alpha_2*\beta_2 + \alpha_3*\beta_3 = scalar$

code example:
```float dot_product(vec3 a, vec3 b) { return a.x * bx + a.y * b.y + a.z * b.z; }```

Result of dot product is a scalar value, that if provided vectors were [[Normalized]], would be in range of  -1 . . . 1. The resulting value of 1 will idicate, that both vectors point in same direction. Resulting value of -1 will indicate, that vectors point in opposite directions. And value of 0 will indicate, that vectors are perdendicular to each other and pointing to left or right.

[[Vectors]]