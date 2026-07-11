class Solution {
public:
    struct trieNode { // left-> 0 right -> 1
        trieNode* left;
        trieNode* right;
    };

    void insert (trieNode* head , int num){ 
         
        trieNode* curr = head;
        for( int i = 31 ; i >= 0 ; i-- ) {
            int currBit = (num >> i) & 1;

            if(currBit){ //currBit = 1;
                
                if(curr->right){
                     curr = curr->right;
                     continue;
                }
                trieNode* right = new trieNode();
                curr->right = right;
                curr = curr->right;
            }else{ // currBit = 0;
                 if(curr->left){
                     curr = curr->left;
                     continue;
                }
                trieNode* left = new trieNode();
                curr->left = left;
                curr = curr->left;
            }
        }


    }
    int maxXor (trieNode * head , int num){
        trieNode* curr = head;
        int ans = 0;
        for( int i = 31 ; i >= 0 ; i-- ){

            int currBit = ( num >> i ) & 1;

            if(currBit ){      
                   if(curr->left ){
                       ans += 1<<i;
                       curr = curr->left;
                   }else{
                       curr = curr->right; 
                   }
            }
            else{
                 if(curr->right ){
                     ans += 1<<i;
                     curr = curr->right;
                 }else{
                    curr = curr->left;
                 }
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
       trieNode * main = new trieNode();
       for(auto num : nums){
           insert(main, num);
       }


       int ans = 0;
       for(auto num : nums){

        ans = max(ans , maxXor(main , num));
       }

      return ans;

     }
};