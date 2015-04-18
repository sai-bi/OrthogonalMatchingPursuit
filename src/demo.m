x = [1; 0.5];
D = [1   0.5        -1/sqrt(2); ...
     0   sqrt(3)/2  1/sqrt(2) ];
treshold = 0.0001;

t = mp(x,D,treshold,0);


