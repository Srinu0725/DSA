class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // long long start = pow(10,num-1);
        // long long end = pow(10,num);

        // long long bestNum = -1;
        // long long maxScore = -1;

        // for(long long i = start;i<end;i++){
        //     long long temp = i;
        //     long long digitSum = 0;
        //     long long score = 0;


        //     while(temp >0){
        //         int digit = temp%10;
        //         digitSum += digit;
        //         score += digit *digit;
        //         temp/=10;

        //     }

        //     if(digitSum == sum){
        //         if(score > maxScore || score == maxScore && i > bestNum){
        //             maxScore = score;
        //             bestNum = i;
        //         }

        //     }
        // }

        // return bestNum == -1 ? "" : to_string(bestNum);

        if(sum > 9*num) return "";
        string ans = "";
        for(int i=0;i<num;i++){
            int digit = min(sum,9);
            ans += to_string(digit);
            sum -= digit;
        }

        return ans;

    }
};