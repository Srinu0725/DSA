class Solution {
public:
static int getDigitSum(int num){
    int sum = 0;
    while(num >0){
        sum += num%10;
        num/=10;
    }
    return sum;
};
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>afterS(nums);


        auto lambda=[](int num1,int num2){
            int digitNum1 = getDigitSum(num1);
            int digitNum2 = getDigitSum(num2);

            if(digitNum1 != digitNum2){
                return digitNum1 < digitNum2;
            }

            return num1 < num2;

        };
        sort(afterS.begin(),afterS.end(),lambda);
        unordered_map<int,int>valtoIdx;
        for(int i=0;i<n;i++){
            valtoIdx[nums[i]] = i;
        }
        int swaps = 0;
        for(int i=0;i<n;i++){
            int expected = afterS[i];
            int currVal = nums[i];
            if(expected == currVal){
                continue;
            }
            int idx = valtoIdx[expected];
            nums[i] = expected;
            nums[idx] = currVal;
            valtoIdx[expected] = i;
            valtoIdx[currVal] = idx;
            swaps++;
        }
        return swaps;
    }
};