class Solution {
public:

   struct trieNode{
     trieNode* left;
     trieNode* right;
      trieNode(){
        left = NULL;
        right = NULL;
      }
   };
   void insert(trieNode* main  , int num ){

       trieNode* curr = main;

       for(int i = 31 ; i >= 0 ; i-- ){
           int currBit = ( num >> i ) & 1;

           if(currBit ){
               trieNode * right = curr->right;
               if(!right){
                  right = new trieNode();
                  curr->right = right;
               }
                   curr = curr->right;
               
           }else{

               trieNode* left = curr->left;

               if(!left){
                   left = new trieNode();

                   curr->left = left;
               }
               curr = curr->left;

           }
              
       }

   }

   int  maxXor(trieNode* main , int n1 ){
       trieNode* curr = main;
       int ans = -1;
       int num = 0;

       if(!(curr->right || curr->left))return -1;
        for(int i = 31 ; i >= 0 ; i-- ){
            int currBit  = ( n1 >> i ) & 1;

            if(currBit){ // currBit is 1 then go for 0 if possible
                
                if(curr->left){
                   num |= 1<<i;
                   curr = curr->left;
                }else{
                   curr = curr->right;
                }
            } else{ //  currBit is 0 then go for 1 if possible
                
                if(curr->right){
                    num |= 1 << i;
                    curr = curr->right;
                }else{
                    curr = curr->left;
                }
            }
       }
       return num;
   }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        trieNode* head = new trieNode();
        int n = queries.size();
        vector<vector<int>>q; // modified queries
        for(int i = 0 ; i < queries.size() ; i++ ){
            int num = queries[i][0];
            int mx  = queries[i][1];
            int idx = i;

            q.push_back({mx , num , idx});
        }
        auto comparator = [&](vector<int>& a , vector<int>& b){
               return a[0] < b[0];
        };
        sort(nums.begin() , nums.end());
        sort( q.begin() , q.end()  , comparator);

        vector<int>ans( n , -1);
        int i = 0;
        for(auto qry : q){

            int mx = qry[0];
            int num   = qry[1];
            int idx  = qry[2];
            while(i < nums.size() && nums[i] <= mx ){
                insert(head , nums[i]);
                i++;
            }
            ans[idx] = maxXor(head , num );
        }

        return ans;
    }
};