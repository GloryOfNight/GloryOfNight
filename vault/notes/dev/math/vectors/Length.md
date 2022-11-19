Length - is how much one point far from another.  Could be calculated by finding out [[Direction]], summarizing all components of a vector powered by 2, and square root the result.

base formula:
$|\alpha\beta| = \sqrt{\vec{\alpha\beta_x^2} + \vec{\alpha\beta_y^2} + \vec{\alpha\beta_z^2}} = scalar$

code example:
``` 
// lenght from a to b
float length(vec3 a, vec3 b) 
{ 
const auto v_direction = direction(a, b);
return sqrt(pow(v_direction.x, 2) + pow(v_direction.y, 2) + pow(v_direction.z, 2)) 
} 
```

Interesting note, when comparing length of two vectors sqrt operation is unnecessary, since sqrt cancel each other out.

[[Vectors]]