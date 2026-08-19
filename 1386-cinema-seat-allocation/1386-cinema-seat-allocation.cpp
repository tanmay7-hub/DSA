class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int ,unordered_set<int>> mp;

        for(auto seat : reservedSeats){
            mp[seat[0]].insert(seat[1]);
        }  

        int result = (n - mp.size()) * 2 ;

        for(auto& [row , bookedSeat] : mp){
            auto isAvail = [&](int a){
                return bookedSeat.find(a) == bookedSeat.end();
            };
            bool groupA = isAvail(2) && isAvail(3) && isAvail(4) && isAvail(5);
            bool groupB = isAvail(4) && isAvail(5) && isAvail(6) && isAvail(7);
            bool groupC = isAvail(6) && isAvail(7) && isAvail(8) && isAvail(9);

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