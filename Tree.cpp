#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9+7;
vector<vector<int>> tree;
vector<int> vsize,sum;
priority_queue<int> q;
void DFS(int n,int m){
    if(sum[n] == -1){
        for(auto i = tree[n].begin();i != tree[n].end();i++){
            if(*i != m){
                DFS(*i,n);
            }
        }
        for(auto i = tree[n].begin();i != tree[n].end();i++){
            if(*i != m){
                q.push(sum[*i]);
            }
        }
        int cnt=0,val=1,temp;
    		while(!q.empty()) {
    			temp = q.top();
    			q.pop();
    			temp=(temp+1)*val;
    			val++;
    			cnt+=temp;
    		}
    		sum[n]=cnt;
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int u,v;
        tree.assign(n+1,vector<int>());
        vsize.assign(n+1,0);
        sum.assign(n+1,-1);
        for(int i = 1;i<n;i++){
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
            vsize[v] += 1;
            vsize[u] += 1;
        }
        for(int i = 2;i<n+1;i++){
            if(vsize[i] == 1){
                sum[i] = 0;
            }
            else{
                bool istrue = false;
                for(auto k = tree[n].begin();k != tree[n].end();k++){
                    if(vsize[*k]!=1){
                        istrue = true;
                        break;
                    }
                }
                if(!istrue){
                    sum[i] = (vsize[i]*(vsize[i]+1))/2;
                }
            }
        }
        DFS(1,1);
        sum[1]+=1;
        int ans = sum[1]%mod*x%mod;
        cout<<ans<<"\n";
    }
}