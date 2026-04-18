#include<bits/stdc++.h>
using namespace std;
struct Team{
    string name;
    string lowerName;
    int point = 0,games=0,scored=0,suffered=0;
    int goalDiff() const {
        return scored - suffered;
    }

};
string toLower(string s){
    for(char &c : s) c = tolower(c);
    return s;
}
bool compareTeams(const Team &a , const Team &b){
    if(a.point != b.point) return a.point > b.point;
    if(a.goalDiff() != b.goalDiff()) return a.goalDiff() > b.goalDiff();
    if(a.scored != b.scored) return a.scored > b.scored;    
    return a.lowerName < b.lowerName;
}
void solve(int t,int g,bool first){
    if(!first) cout << endl;
    map<string ,int > teamIndex;
    vector<Team> team(t);
    for(int i=0;i<t;i++){
        cin >> team[i].name;
        team[i].lowerName = toLower(team[i].name);
        teamIndex[team[i].name] = i;
    }
    for(int i=0;i < g;i++){
        string t1,dash,t2;
        int g1,g2;
        cin >> t1 >> g1 >> dash >> g2 >> t2;
        int i1=teamIndex[t1];
        int i2=teamIndex[t2];
        team[i1].games++;
         team[i2].games++;
         team[i1].scored += g1;
          team[i1].suffered += g2;
            team[i1].scored += g2;
             team[i2].suffered += g1;
             if(g1 > g2) team[i1].point += 3;
             else if(g2 > g1) team[i2].point += 3;
             else{
                team[i1].point += 1;
                team[i2].point += 1;
             }
             
        
    }
    sort(team.begin(),team.end(),compareTeams);
    for(int i=0;i<t;i++){
        if(i > 0 && team[i].point == team[i-1].point && team[i].goalDiff() == team[i - 1].goalDiff() && team[i].scored == team[i - 1].scored){
            cout <<"   ";
        }
        else{
            cout << setw(2) <<right <<i+1 <<".";
        }
        cout <<" " << setw(15) << left << team[i].name;
        cout << setw(3) <<right << team[i].point;
        cout << setw(3) <<right << team[i].games;
        cout << setw(3) <<right << team[i].scored;
        cout << setw(3) <<right << team[i].suffered;
        cout << setw(3) <<right << team[i].goalDiff();
        if(team[i].games == 0){
            cout <<"    N/A" << endl;
        }
        else{
            double pct = (team[i].point * 100.0)/(team[i].games * 3.0);
            cout << fixed << setprecision(2) << setw(7) << right << pct << endl;
        }
    }
}
int main(){
    int t,g;
    bool first = true;
    while(cin >> t >> g && (t != 0 || g != 0)){
        solve(t,g,first);
        first = false;
    }
    return 0;
}
