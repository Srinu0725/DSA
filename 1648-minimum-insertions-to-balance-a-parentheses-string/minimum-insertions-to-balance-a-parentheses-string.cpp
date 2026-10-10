class Solution {
public:
    int minInsertions(string s) {
        int close=0;
        int open = 0;
        int ans =0;

        for(char ch : s){
            if(ch == '('){
                if(close%2 ==1){
                    ans+=1;
                    close--;
                }
                open++;
                close+=2;

            }else{
                close--;
                if(close < 0){
                    ans++;
                    open+=1;
                    close =1;
                }
            }
        }

        return ans + close;
    }
};