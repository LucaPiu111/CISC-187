# Questions



1.
        return if low > high
This serves as the base case function because it works to determine whether the recursion should continue or not. It sets a goal for the program, so that once it reaches the desired goal, the recursion terminates. If the code did not have this function, it would continue repeating indefinitely.



2. Since the function now follows (n - 2) instead of (n - 1), it skips one number each recursion. For example, running factorial(10) normally result as (10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1), however, the new function, it will be (10 * 8 * 6 * 4 * 2).



3.
        def sum(low, high)
            return low if low == high
            return high + sum(low, high - 1)
        end
This is the corrected code with the base case because it continues until it reaches “low”. Without this base case, the program would keep on recursing into the negatives. This helps stop the program from repeating too much.
