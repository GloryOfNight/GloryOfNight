To find a direction going from $\alpha$ to $\beta$ substruct two vectors. Substruction done via substructing each component of destination substructed to a each component of origin vector. Note that destination must come first and origin the second.

base formula:
$\vec{\alpha\beta} = \beta - \alpha$
and breaking calculation components:

$\vec{\alpha\beta} = \begin{bmatrix} \beta_x - \alpha_x \\ \beta_y - \alpha_y \\ \beta_z - \alpha_z\end{bmatrix}$

code example:
`// a - origin, b - destination`
```vector direction(vec3 a, vec3 b) { return vector(b.x - a.x, b.y - a.y, b.z - a.z); }```

[[Vectors]]