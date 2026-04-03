#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long A;
    if(cin >> A){
        string s = to_string(A);
        string result = "";
        int count = 0;
        for(int i = s.size()-1;i>=0;i--){
            result += s[i];
            count ++;
            if(count % 3 == 0 && i!=0){result +=",";
            }
        }
        reverse(result.begin(),result.end());
        cout << result <<endl;
    }
    return 0;
}