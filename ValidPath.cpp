#include<bits/stdc++.h>
#define int long long
using namespace std;
std::vector<vector<int>> tree;
vector<int> cnt,pref_sum;
int mod = 1e9+7,ex;
void dfs(int node,int par_node){
    for(int i:tree[node]){
        if(i!= par_node){
            dfs(i,node);
        }
    }
    int sze = 0,id = 0,ex_cnt = 0,ans = 0;
    for(int i : tree[node]){
        if(i!=par_node){
            ans += 2*cnt[i];
            sze++;
        }
    }
    ans += 1;
    pref_sum.assign(sze,0);
    cnt[node] = ans%mod;
    for(int i : tree[node]){
        if(i!=par_node){
            pref_sum[id] = cnt[i];
            id++;
        }
    }
    for(int i=1;i<sze;i++) {
			pref_sum[i]+=pref_sum[i-1];
		}
	id = 0;
	for(int i:tree[node]){
	    if(i!=par_node){
	     ex_cnt += ((pref_sum[sze-1]-pref_sum[id])*cnt[i]);
	     id++;
	    }
	}
	ex += (2*ex_cnt)%mod;
	ex%=mod;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ex = 0;
        tree.assign(n+1,vector<int>());
        cnt.assign(n+1,0);
        int u,v;
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        dfs(1,0);
        cout<<((cnt[1]%mod+ex%mod)%mod)<<"\n";
    }
}