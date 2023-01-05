// Bulls and cows 
// Problem Link:  https://leetcode.com/problems/bulls-and-cows/description/ 

class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size(); 
        int bulls=0; 
        int cows=0; 
        //creating hashing  
        vector<int> s(10),g(10); 
        for(int i=0;i<n;i++){ 
            if(secret[i]==guess[i]){   //if same, then bull 
                bulls++; 
            }
            else{ 
                s[secret[i]-'0']++; 
                g[guess[i]-'0']++; 
            }
        }
        for(int i=0;i<10;i++){ 
            cows+=min(s[i],g[i]); 
        } 
        string ans=""; 
        ans+=to_string(bulls); 
        ans+="A"; 
        ans+=to_string(cows); 
        ans+="B"; 

        return ans;  
    }
};