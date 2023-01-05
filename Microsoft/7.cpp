//Course Sheduling  
// Problem Link: https://leetcode.com/problems/course-schedule/description/ 

class Solution {
public:
//topologocal sort problem 
    bool DfSrec(int s,vector<bool>& visited,vector<bool>& currVisited,vector<int> adj[]){
        visited[s]=true;
        currVisited[s]=true; 

        for(auto x:adj[s]){ 
            if(!visited[x]){ 
                if(DfSrec(x,visited,currVisited,adj)){
                    return true;    //cycle is present 
                }
            } 
            else if(visited[x] && currVisited[x]){
                return true; 
            }
        }
        currVisited[s]=false; 
        return false;    //if not visited, no cycle present 
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses; 
        vector<bool> visited(n,false), currVisited(n,false); 
        //creating adjacenecy list 
        vector<int> adj[n]; 
        for(auto x:prerequisites){ 
            vector<int> data=x; 
            int a=data[0];
            int b=data[1];
            adj[a].push_back(b); 
        }

        for(int i=0;i<n;i++){ 
            if(!visited[i]){ 
                if(DfSrec(i,visited,currVisited,adj)){
                    return false;     //if cycle is detected 
                }
            }
        }
        return true; 
    }
};