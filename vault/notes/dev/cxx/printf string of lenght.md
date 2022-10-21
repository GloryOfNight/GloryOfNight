Its possible to printf string without relying on '\0' terminator at the end, by using `%.*s` as a expression. 
Note: be aware of length not being > then string it self, otherwise undefined behavior is upon you.

example:
```
printf("%.*s", len, chars);
```
if length known beforehand, it possible to use:
```
// where 10 is known length of string
printf("%.10s", chars);
```