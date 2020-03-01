/*
You have a set of tiles, where each tile has one letter tiles[i] printed on it.  Return the number of possible non-empty sequences of letters you can make.

Example 1:

Input: "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
Example 2:

Input: "AAABBC"
Output: 188
 

Note:

1 <= tiles.length <= 7
tiles consists of uppercase English letters.
*/

class Solution {
public:
    void dfs(int depth, int num, string &tiles, vector<bool> &used, int &count)
    {
        if(depth >= num)
        {
            ++count;
            return;
        }
        
        for(int i = 0; i < tiles.size(); ++i)
        {
            if(used[i])
                continue;
            
            if(i > 0 && tiles[i] == tiles[i - 1] && !used[i - 1])
                continue;
            
            used[i] = true;
            dfs(depth + 1, num, tiles, used, count);
            used[i] = false;
        }
    }
    
    int numTilePossibilities(string tiles) {
        std::sort(tiles.begin(), tiles.end());
        int count = 0;
        vector<bool> used(tiles.size(), false);
        
        for(int i = 1; i <= tiles.size(); ++i)
            dfs(0, i, tiles, used, count);
        return count;
    }
};
