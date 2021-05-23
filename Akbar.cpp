#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> arr;
vector<int> str;
vector<int> original_protection;
vector<bool>visited;
void dfs(int node,int parent_node,int strength){
    if(strength>0){
        visited[node] = true;
        for(int i:arr[node]){
            if(i != parent_node && !visited[i]){
                visited[i] = true;
                original_protection[i] += 1;
                dfs(i,node,strength-1);
            }
            if(i != parent_node && visited[i]){
                dfs(i,node,strength-1);
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,r,m;
        cin>>n>>r>>m;
        arr.assign(n+1,vector<int>());
        str.assign(n+1,-1);
        original_protection.assign(n+1,0);
        int a,b;
        for(int i = 0;i<r;i++){
            cin>>a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        for(int i = 0;i<m;i++){
            cin>>a>>b;
            str[a] = b;
        }
        for(int i = 1;i<=n;i++){
            if(str[i] == 0){
                original_protection[i] += 1;
                if(original_protection[i] >1){
                    break;
                }
            }
            else if(str[i] == 1){
                original_protection[i] += 1;
                for(int j:arr[i]){
                    original_protection[j] += 1;
                    if(original_protection[j] >1){
                        break;
                    }
                }
            }
            else if(str[i]>1){
                original_protection[i]+=1;
                    if(original_protection[i] >1){
                        break;
                    }
                visited.assign(n+1,false);
                dfs(i,i,str[i]);
            }
        }
        bool ans = true;
        for(int i = 1;i<=n;i++){
            // cout<<visited[i]<<" ";
            if(original_protection[i]!=1){
                ans = false;
                break;
            }
        }
        if(ans){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
}