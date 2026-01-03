/*
1411. Number of Ways to Paint N × 3 Grid

You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors:
Red, Yellow, or Green while making sure that no two adjacent cells have the same color
(i.e., no two cells that share vertical or horizontal sides have the same color).

Given n the number of rows of the grid, return the number of ways you can paint this grid.
As the answer may grow large, the answer must be computed modulo 109 + 7.

*/


class Solution {
public:
    int numOfWays(int n) {
        long long x = 6;
        long long y = 6;
        int mod = 1e9 + 7;
        for (int i = 2; i <= n; i++) {
            long long new_x = (x * 3 + y * 2) % mod;
            long long new_y = (x * 2 + y * 2) % mod;
            x = new_x;
            y = new_y;
        }
        return (x + y) % mod;
    }
};
