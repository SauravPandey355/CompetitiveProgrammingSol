#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    char tt[4][4];
    while(t--){
        int nx=0,no=0;
        for(int i = 1;i<=3;i++){
            for(int j = 1;j<=3;j++){
                cin>>tt[i][j];
                if(tt[i][j]=='X'){
                 nx += 1;
                }
                else if(tt[i][j] == 'O'){
                    no+= 1;
                }}
        }
        if(nx-no > 1 or nx<no){
            cout<<"3\n";
        }
        else{
            int count,count1,nxw=0,now=0;
            for(int i=1;i<=3;i++){
                count1 = 0;
                count = 0;
                for(int j= 1;j<=3;j++){
                    if(tt[i][j] == 'X')count++;
                    else if(tt[i][j] == 'O') count1++;
                }
                if(count1 == 3){
                    now =1;
                }
                if(count == 3){
                    nxw = 1;
                }
            }for(int i=1;i<=3;i++){
                count1 = 0;
                count = 0;
                for(int j= 1;j<=3;j++){
                    if(tt[j][i] == 'X')count++;
                    else if(tt[j][i] == 'O') count1++;
                }
                if(count1 == 3){
                    now =1;
                }
                if(count == 3){
                    nxw = 1;
                }
            }
                count1 = 0;
                count = 0;
            for(int i=1;i<=3;i++){
                for(int j= 1;j<=3;j++){
                if(i == j){
                    if(tt[i][j] == 'X')count++;
                    else if(tt[i][j] == 'O') count1++;}
                }
                if(count1 == 3){
                    now =1;
                }
                if(count == 3){
                    nxw = 1;
                }
            }
                count1 = 0;
                count = 0;
            for(int i=1;i<=3;i++){
                for(int j= 1;j<=3;j++){
                if(i + j == 4){
                    if(tt[i][j] == 'X')count++;
                    else if(tt[i][j] == 'O') count1++;}
                }
                if(count1 == 3){
                    now =1;
                }
                if(count == 3){
                    nxw = 1;
                }
            }
            if(nxw == 1 and now == 1){
                cout<<"3\n";
            }
            else if((nxw == 1 && now == 0) or (now == 1 && nxw == 0) or(nx + no == 9)){
                if(nxw == 1){
                    if(nx>no){
                        cout<<"1\n";
                    }
                    else{
                        cout<<"3\n";
                    }
                }
                else if(now == 1){
                    if(no == nx){
                        cout<<"1\n";
                    }
                    else{
                        cout<<"3\n";
                    }
                }
                else{
                cout<<"1\n";}
            }
            else{
                cout<<"2\n";
            }
        }
    }
}