class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int ,int> mp;

        for(auto seat : reservedSeats){
            
            if(mp.find(seat[0]) != mp.end()){
                mp[seat[0]] |= 1 << seat[1];
            }else{
                mp[seat[0]] = 1 << seat[1];
            }
        }  

        int result = (n - mp.size()) * 2 ;

        for(auto& [row , bookedSeat] : mp){

            bool groupA = !(mp[row] & ( 1<<2 | 1<<3 | 1<<4 | 1<<5));
            bool groupB = !(mp[row] & ( 1<<4 | 1<<5 | 1<<6 | 1<<7));
            bool groupC = !(mp[row] & ( 1<<6 | 1<<7 | 1<<8 | 1<<9));

            if(groupA && groupC){
                result += 2;
            }else if(groupA || groupB || groupC){
                result += 1;
            }else{
                result += 0;
            }

        }
        return result;
    }
};