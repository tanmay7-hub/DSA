class Solution {
public:
    long long solve(int n){
        string s=to_string(n);
        string s1="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='0')s1+=s[i];
        }
        return stoi(s1);
    }
    long long sum(int n){
        long long sm=0;
         while(n){
             sm+=n%10;
             n/=10;
         }
         return sm;
    }
    long long sumAndMultiply(int n) {
        if(n==0)return 0;
         long long x=solve(n);
         long long sm=sum(x);
         return  x*1LL*sm;
    }
};