#include <bits/stdc++.h>
using namespace std;

struct Team {
    string name, lower;
    int pts=0, w=0, d=0, l=0, gf=0, ga=0, gp=0;
};

int main(){
    int N;
    if(!(cin >> N)) return 0;
    cin.ignore();
    for(int t=0; t<N; t++){
        string tname;
        getline(cin, tname);
        int T; cin >> T; cin.ignore();
        vector<Team> teams(T);
        map<string,int> idx;
        for(int i=0;i<T;i++){
            getline(cin, teams[i].name);
            teams[i].lower = teams[i].name;
            for(auto&c: teams[i].lower) c = tolower((unsigned char)c);
            idx[teams[i].name] = i;
        }
        int G; cin >> G; cin.ignore();
        for(int i=0;i<G;i++){
            string g; getline(cin, g);
            size_t p1 = g.find('#');
            size_t p2 = g.find('@', p1+1);
            size_t p3 = g.find('#', p2+1);
            string n1 = g.substr(0, p1);
            int g1 = stoi(g.substr(p1+1, p2-p1-1));
            int g2 = stoi(g.substr(p2+1, p3-p2-1));
            string n2 = g.substr(p3+1);
            int a = idx[n1], b = idx[n2];
            teams[a].gp++; teams[b].gp++;
            teams[a].gf += g1; teams[a].ga += g2;
            teams[b].gf += g2; teams[b].ga += g1;
            if(g1>g2){ teams[a].w++; teams[a].pts+=3; teams[b].l++; }
            else if(g1<g2){ teams[b].w++; teams[b].pts+=3; teams[a].l++; }
            else { teams[a].d++; teams[b].d++; teams[a].pts++; teams[b].pts++; }
        }
        vector<int> ord(T); iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int x, int y){
            const Team&A=teams[x]; const Team&B=teams[y];
            if(A.pts!=B.pts) return A.pts>B.pts;
            if(A.w!=B.w) return A.w>B.w;
            int gdA=A.gf-A.ga, gdB=B.gf-B.ga;
            if(gdA!=gdB) return gdA>gdB;
            if(A.gf!=B.gf) return A.gf>B.gf;
            if(A.gp!=B.gp) return A.gp<B.gp;
            return A.lower < B.lower;
        });
        cout << tname << "\n";
        for(int i=0;i<T;i++){
            const Team&A = teams[ord[i]];
            cout << (i+1) << ") " << A.name << " " << A.pts << "p, "
                 << A.gp << "g (" << A.w << "-" << A.d << "-" << A.l << "), "
                 << (A.gf-A.ga) << "gd (" << A.gf << "-" << A.ga << ")\n";
        }
        if(t+1<N) cout << "\n";
    }
    return 0;
}
