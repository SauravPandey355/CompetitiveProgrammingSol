#include<bits/stdc++.h>
#define int long long
using namespace std;
int min (int a,int b){
    if(a<b) return a;
    return b;
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
        int arr[n];
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int va = arr[0],cnt = n-1;
        for(int i = 1;i<n;i++){
            if(arr[i] == va){
                cnt--;
            }
        }
        cout<<cnt<<"\n";
    }
}