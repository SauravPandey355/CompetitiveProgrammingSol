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
        int min_diff = 9999999999;
        for(int i = 1;i<n;i++){
            if(arr[i]<=0){
                min_diff = min(min_diff,abs(arr[i]-arr[i-1]));
            }
        }
        int cnt = 0;
        for(int i = 0;i<n;i++){
         if(arr[i]<=0){
             cnt += 1;
         }
         else if(arr[i]>0 && arr[i]<= min_diff){
             cnt++;
             break;
         }
         else{
             break;
         }
        }
        cout<<cnt<<"\n";
    }
}