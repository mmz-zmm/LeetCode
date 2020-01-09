class Solution {
public:
    /*
        Majority Voting Algorithm
    */
    vector<int> majorityElement(vector<int>& nums) {
        int candiate1{INT_MAX};
        int candiate2{INT_MAX};
        int counter1{0};
        int counter2{0};

        for(const auto& num : nums){
            if(num == candiate1){
                counter1++;
            }else if(num == candiate2){
                counter2++;
            }else if(counter1 == 0){
                candiate1 = num;
                counter1 = 1;
            }else if(counter2 == 0){
                candiate2 = num;
                counter2 = 1;
            }else{
                counter1--;
                counter2--;
            }
        }

        counter1 = 0;
        counter2 = 0;
        for(const auto &num :nums){
            if(num == candiate1){
                counter1++;
            }else if(num == candiate2){
                counter2++;
            }
        }
        vector<int> result;
        if(counter1 > nums.size() /3){
            result.push_back(candiate1);
        }
        if(counter2 > nums.size() /3){
            result.push_back(candiate2);
        }
        return result;
    }
};