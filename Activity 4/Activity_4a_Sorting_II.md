Adding all the actions below together gives you 20 total actions. The Big O Notation for the insertion sort time complexity can also be applied here with O(N^2). O(6^2) = 36. Since the number of swaps is 9, it can be represented as (N^2)/4.

[5, 2, 4, 6, 1, 3] compare 5 and 2 (1 action)
[2, 5, 4, 6, 1, 3] insert 2 (1 action)
[2, 5, 4, 6, 1, 3] compare 5 and 4; 2 and 4 (2 actions)
[2, 4, 5, 6, 1, 3] insert 4 (1 action)
[2, 4, 5, 6, 1, 3] compare 6 and 5 (1 action)
[2, 4, 5, 6, 1, 3] compare 1 and 6; 1 and 5; 1 and 4; 2 and 1 (4 actions)
[1, 2, 4, 5, 6, 3] insert 1 at beginning (4 actions)
[1, 2, 4, 5, 6, 3] compare 3 and 6; 3 and 5; 3 and 4 (3 actions)
[1, 2, 3, 4, 5, 6] insert 3 (3 actions)



Counting the number of operations below reveals that there are indeed 20. This matches the predicted worst case scenario, which is also represented by O(N^2). (N^2 - N)

[5, 4, 3, 2, 1] compare 4 and 5
[4, 5, 3, 2, 1] swap 4 and 5
[4, 5, 3, 2, 1] compare 3 and 5
[4, 3, 5, 2, 1] swap 3 and 5
[4, 3, 5, 2, 1] compare 3 and 4
[3, 4, 5, 2, 1] swap 3 and 5
[3, 4, 5, 2, 1] compare 2 and 5
[3, 4, 2, 5, 1] swap 2 and 5
[3, 4, 2, 5, 1] compare 2 and 4
[3, 2, 4, 5, 1] swap 2 and 4
[3, 2, 4, 5, 1] compare 2 and 3
[2, 3, 4, 5, 1] swap 2 and 3
[2, 3, 4, 5, 1] compare 1 and 5
[2, 3, 4, 1, 5] swap 1 and 5
[2, 3, 4, 1, 5] compare 1 and 4
[2, 3, 1, 4, 5] swap 1 and 4
[2, 3, 1, 4, 5] compare 1 and 3
[2, 1, 3, 4, 5] swap 1 and 3
[2, 1, 3, 4, 5] compare 1 and 2
[1, 2, 3, 4, 5] swap 1 and 2



 function containsX(string) {
	foundX = false;
	for(let i = 0; i < string.length; i++) { 
		if (string[i] === "X") {
			foundX = true; 
		}
	}
	return foundX; 
}

This function’s time complexity regarding Big O Notation is O(N). This is because there is a for loop which runs “n” times, however doesn’t have another loop nested in it, which would make it O(N^2).
 
function containsX(string) {
    for (let i = 0; i < string.length; i++) {
        if (string[i] === "X") {
            return true;
        }
    }
    return false;}

This version is slightly more efficient by immediately returning true if X is found.
