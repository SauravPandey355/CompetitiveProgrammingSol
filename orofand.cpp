#include<bits/stdc++.h>
#define Int long long
using namespace std;
Int calculate(Int arr[]){
    Int result = 0;
    for(int i = 0;i<32;i++){
        if(arr[i]!=0)
        result += 1<<i;
    }
    return result;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        Int arr[n],ans[32];
        for(int i = 0;i<32;i++){
            ans[i] = 0;
        }
        for(int i = 0;i<n;i++){
            int x;
            cin>>x;
            arr[i] = x;
            int j = 0;
            while(x){
                if((x&1)==1)ans[j]++;
                x = x>>1;
                j++;
            }
        }
        cout<<calculate(ans)<<endl;
        while(q--){
        int pos,val;
        cin>>pos>>val;
        int x = arr[pos-1],j = 0;
        while(x){
                if((x&1)==1)ans[j]--;
                x = x>>1;
                j++;
            }
        arr[pos-1] = val;
        x = val;j = 0;
        while(x){
                if((x&1)==1)ans[j]++;
                x = x>>1;
                j++;
            }
        cout<<calculate(ans)<<endl;
        }
    }
}