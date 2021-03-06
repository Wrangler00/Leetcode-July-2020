The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.

       
//cpp my solution
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        for (int i = 31; i >= 0; i--)
            ans+=((x >> i)&1) != ((y >> i)&1);
        
        return ans;
    }
};


//cpp builtin xor solution

class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x^y);
    }
};

//cpp using xor and bitwise & operator

class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0, n = x ^ y;
        while (n) {
            ++dist;
            n &= n - 1;
        }
        return dist;
    }
};
