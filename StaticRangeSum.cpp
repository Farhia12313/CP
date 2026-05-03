//Prefix sum 
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int arr[N+1];
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    int prefix[N+1];
 prefix[0]=arr[0];
 for(int i=1;i<N;i++){
    prefix[i] = prefix[i-1] + arr[i];

 }
 int q;
 cin >> q;
 while(q--){
    int l,r;
    cin >> l >> r;
    if(l==0) cout << prefix[r]<< endl;
    else cout << prefix[r] -prefix[l-1] << endl;
 }
 for(int i=0;i<N;i++){
    cout << prefix[i] <<" ";
 }
 return 0;
}
