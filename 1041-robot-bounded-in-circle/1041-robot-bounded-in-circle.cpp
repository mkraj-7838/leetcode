class Solution {
public:
    bool isRobotBounded(string inst) {
        int n = inst.size();
        int dX = 0, dY = 1;
        int x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            if (inst[i] == 'G') {
                x = x + dX;
                y = y + dY;
            } else if (inst[i] == 'L') {
                int temp = dX;
                dX = -dY;
                dY = temp;
            } else if (inst[i] == 'R') {
                int temp = dX;
                dX = dY;
                dY = -temp;
            }
        }
        if(x==0 && y==0 || dX!=0 || dY!=1){
            return true;
        }else{
            return false;
        }
    }
};