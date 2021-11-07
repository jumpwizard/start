class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto money : bills){
            switch (money){
                case 5 :
                    five++;
                    break;
                case 10 :
                    ten++;
                    five--;
                    if (five < 0){
                        return false;
                    }
                    break;
                case 20 :
                    if (ten > 0 && five > 0){
                        ten--;
                        five--;
                    }else{
                        five = five - 3;
                        if (five < 0){
                        return false;
                        }
                    }
                    break;
            }
        }
    return true;
    } 
};
