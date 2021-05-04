#include<bits/stdc++.h>
#define Int long long
using namespace std;
#define m 1000000
int n0[m],n1[m];
int dp0[m+5],dp1[m+5];
char ans[1000000];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.length();
        int k =  -1;
        for(int i = 0;i<n;i++){
            if(s[i]=='0'){
                for(int j = k+1;j<=i;j++){
                    n0[j] = i;
                    k = i;
                }
            }
        }
        for(int i =k+1;i<n;i++){
            n0[i] = n;
        }
        if(n0[0]==n){
            cout<<0<<endl;
        }
        else{
            k = -1;
            for(int i = 0;i<n;i++){
            if(s[i]=='1'){
                for(int j = k+1;j<=i;j++){
                    n1[j] = i;
                    k = i;
                }
            }
        }
        for(int i =k+1;i<n;i++){
            n1[i] = n;
        }
        dp0[n] = 0;
        dp1[n] = 0;
        for(int i = n-1;i>-1;i--){
            dp0[i] = dp0[i+1];
            if(s[i]=='0' and n1[i]<n){
                dp0[i] = max(dp0[i],dp0[n1[i]+1]+1);
            }
            if(s[i] == '1' and n0[i]<n){
                dp0[i] = max(dp0[i],dp0[n0[i]+1]+1);
            }
            dp1[i] = dp1[i+1];
            if(n1[i]<n){
                dp1[i] = max(dp1[i],dp0[n1[i]+1]+1);
            }
        }
        // for(int i = 0;i<n;i++){
        //     cout<<n1[i]<<" ";
        // }
        int x = dp1[0] +1,count = n1[0]+1;
        ans[0] = '1';
        k = 1;
        for(int i= 1;i<x;i++){
            if(count >=n){
                ans[k++]='0';
                // cout<<"l";
                continue;
            }
            if(n0[count]>=n){
                ans[k++] = '0';
                count = n0[count]+1;
                // cout<<"S";
                continue;
            }
            if(dp0[n0[count]+1]<x-i-1){
                ans[k++]='0';
                count = n0[count]+1;
                // cout<<"a";
            }
            else{
                ans[k++]='1';
                count = n1[count]+1;
                // cout<<"s";
            }
        }
        for(int i = 0;i<k;i++){
            cout<<ans[i];
        }
        cout<<endl;
        }
        }
    }