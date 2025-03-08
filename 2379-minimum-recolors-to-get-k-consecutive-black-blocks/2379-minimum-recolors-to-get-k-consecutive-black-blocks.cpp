class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int recolor_cnt = 0, result = INT_MAX;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') recolor_cnt++;
        }
        result = recolor_cnt;
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i] == 'W') recolor_cnt++; 
            if (blocks[i - k] == 'W') recolor_cnt--; 
            
            result = min(result, recolor_cnt);
        }
        return result;
    }
};
