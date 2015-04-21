function [t] = mp(x, D, threshold, mode, max_iter)
% x: input signal
% D: dictionary, each column is an atom
% threshold: stop conditions
% mode:
%   0: stops when ||residual||_2 < threshold
%   1: stops when ||t||_0 > threshold
% max_iter: 
%   optional, maximum number of iterations
%   default: 100
% t:
%   output, a vector that stores the coefficient of each atom

if ~exist('max_iter', 'var')
    max_iter = 100;
end

dim = size(D,2);
t = zeros(dim, 1);
r = x; % residual
iter = 1;
while 1
    i = D' * r;
    [~, i] = max(abs(i));
    t(i) = t(i) + D(:,i)' * r;
    r = r - D(:,i)' * r * D(:,i);

    if(mode == 0 && norm(r,2) < threshold)
        break;
    elseif(mode == 1 && nnz(t) > threshold) 
        break;
    end

    fprintf('Iter %d, residual: %f\n', iter, norm(r,2));
    if iter > max_iter
        break;
    end
    iter = iter + 1;
end

