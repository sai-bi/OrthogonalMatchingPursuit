Orthogonal Matching Pursuit
=========================

Implementations of `Orthogonal Matching Pursuit` algorithm. See `src/omp.m` for details.

### Demo:
```
dictionary = [1 0; 1/2 sqrt(3)/2; -1/sqrt(2) -1/sqrt(2)]';
x = [1 1/2]';
t = omp(x, dictionary, 2);
output_x = D * t; 
```

### References
[Matching Pursuit](http://en.wikipedia.org/wiki/Matching_pursuit)
[MP and OMP in MATLAB](http://www.mathworks.com/help/wavelet/ug/matching-pursuit-algorithms.html)