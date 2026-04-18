#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;
    while(cin >> k && k != 0){
        int n,m;
        cin >> n >> m;
        for(int i=0;i<k;i++){
            int x,y;
            cin >> x >> y;
            if(x == n || y == m){
                cout << "divisa" <<endl; 
            }
            else if(x > n && y > m){
                cout << "NE" <<endl;
            }
            else if(x < n && y > m){
                cout << "NO" <<endl;
            }
            else if(x > n && y < m){
                cout << "SE" <<endl;
            }
            else if(x < n && y < m){
                cout << "SO" <<endl;
            }
        }
    }
    return 0;
}