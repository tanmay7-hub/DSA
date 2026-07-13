class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {       
        
        string s ="123456789";


        string l = to_string(low);
        string r = to_string(high);
        vector<int>ans;
        for(int i = l.size() ; i <= r.size() ; i++ ){

            for(int j = 0 ; j <= 9 - i ; j++ ){
                string n = s.substr(j , i);

                int num = stoi(n);

                if(num >= low && num <= high){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    
    }
};