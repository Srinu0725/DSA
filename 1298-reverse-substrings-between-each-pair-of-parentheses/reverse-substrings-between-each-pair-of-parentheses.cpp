class Solution {
public:
    string reverseParentheses(string s) {
        while(true){
            int i = s.length()-1;
            while(i>=0 && s[i] != '('){
                i--;
            }

            if(i < 0) break;

            int j = i+1;

            while(j<s.length() && s[j] != ')'){
                j++;
            }

            reverse(s.begin()+i+1 , s.begin()+j);

            s.erase(j,1);
            s.erase(i,1);

        }

        return s;

    }
}; 