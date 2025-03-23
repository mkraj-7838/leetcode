class Solution {
public:
       int M=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        // u-->((v1,t1), (v2,t2));
        unordered_map<int, vector<pair<int,int >>> adj;
        for(auto &road :roads){
            int u=road[0];
            int v=road[1];
            int time=road[2];

            adj[u].push_back({v,time});
            adj[v].push_back({u,time}); // since it is a bidirectional graph
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long>ans(n,LONG_MAX); // initially all netries are infinity or very large
        vector<int>pathCount(n,0);
        ans[0]=0;
        pathCount[0]=1;
        pq.push({0,0}); // (time,node)
        while(!pq.empty()){
            long long currTime=pq.top().first;
            int currNode=pq.top().second;

            pq.pop();

            for(auto&vec:adj[currNode]){
                int ngbr=vec.first;
                long long roadTime=vec.second;

                if(currTime + roadTime < ans[ngbr]){
                    ans[ngbr]=currTime+roadTime;
                    pq.push({ans[ngbr],ngbr});
                    pathCount[ngbr]= pathCount[currNode];
                }
                else if(currTime + roadTime == ans[ngbr]){
                    pathCount[ngbr]=(pathCount[ngbr] + pathCount[currNode])%M;
                }
            }
        }
        return pathCount[n-1];
    }
};