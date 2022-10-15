Vector - is something that represent angle (direction, were to look) and lenght (how far is it). Could be based on 2 or more scalar components, depending on what number of dimensions you want to operate. Also, its completly possible to use vector structure for other needs that you might have, sometimes such things as colors are represented in vector like structure (r, g, b, a).

representation of 3d vector:
$\vec{v}=\begin{bmatrix} x \\ y \\ z \end{bmatrix}$

code example for 3d vector:
```
struct vector
{
	float x, y, z;
};
```