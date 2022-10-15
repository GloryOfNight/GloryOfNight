Normalized vector (aka unit-length) - vector length of 1, that used to find general direction of a vector (were vector is looking).

base formula:
$\hat{\alpha\beta} = \frac{\vec{\alpha\beta}}{|\alpha\beta|} = \frac{Direction}{Length}$ 
where $\vec{\alpha\beta}$ [[Direction]]
and $|\alpha\beta|$ [[Length]]

breaked to components, formula looks like:
$\hat{\alpha\beta} = \begin{bmatrix} \frac{\vec{\alpha\beta}_x}{|\alpha\beta|} \\ \frac{\vec{\alpha\beta}_y}{|\alpha\beta|} \\ \frac{\vec{\alpha\beta}_z}{|\alpha\beta|} \end{bmatrix}$

code example:
```
vector normalize(vec3 a, vec3 b)
{
const auto v_direction = direction(a, b);
const auto v_length = length(a, b);
return vector(v_direction.x / v_length, v_direction.y / v_length, v_direction.z / v_length);
}
```

[[Vectors]]