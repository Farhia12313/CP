#include<bits/stdc++.h>
using namespace std;

struct Team {
    string name;
    string lowerName;
    int points = 0, played = 0, scored = 0, suffered = 0, gd = 0;

    void setLowerName() {
        lowerName = name;
        for (char &c : lowerName) c = tolower(c);
    }
};

bool compareTeams(const Team &a, const Team &b) {
    if (a.points != b.points) return a.points > b.points;
    if (a.gd != b.gd) return a.gd > b.gd;
    if (a.scored != b.scored) return a.scored > b.scored;
    return a.lowerName < b.lowerName;
}

int main() {
    int T, G;
    bool firstCase = true;

    while (cin >> T >> G && (T != 0 || G != 0)) {
        if (!firstCase) cout << endl; // কেসগুলোর মাঝে ফাঁকা লাইন
        firstCase = false;

        map<string, int> nameToIndex;
        vector<Team> teams(T);

        for (int i = 0; i < T; i++) {
            cin >> teams[i].name;
            teams[i].setLowerName();
            nameToIndex[teams[i].name] = i;
        }

        for (int i = 0; i < G; i++) {
            string home, away, dash;
            int hGoal, aGoal;
            cin >> home >> hGoal >> dash >> aGoal >> away;

            int hIdx = nameToIndex[home];
            int aIdx = nameToIndex[away];

            teams[hIdx].played++;
            teams[aIdx].played++;
            teams[hIdx].scored += hGoal;
            teams[hIdx].suffered += aGoal;
            teams[aIdx].scored += aGoal;
            teams[aIdx].suffered += hGoal;

            if (hGoal > aGoal) teams[hIdx].points += 3;
            else if (aGoal > hGoal) teams[aIdx].points += 3;
            else {
                teams[hIdx].points += 1;
                teams[aIdx].points += 1;
            }
        }

        for (int i = 0; i < T; i++) teams[i].gd = teams[i].scored - teams[i].suffered;

        sort(teams.begin(), teams.end(), compareTeams);

        for (int i = 0; i < T; i++) {
            
            if (i > 0 && teams[i].points == teams[i-1].points && 
                teams[i].gd == teams[i-1].gd && 
                teams[i].scored == teams[i-1].scored) {
                cout << "   "; 
            } else {
                cout << setw(2) << right << i + 1 << ".";
            }

            cout << " " << setw(15) << left << teams[i].name;
            cout << setw(3) << right << teams[i].points;
            cout << setw(3) << right << teams[i].played;
            cout << setw(3) << right << teams[i].scored;
            cout << setw(3) << right << teams[i].suffered;
            cout << setw(3) << right << teams[i].gd;

            if (teams[i].played == 0) {
                cout << "    N/A" << endl;
            } else {
                double pct = (teams[i].points * 100.0) / (teams[i].played * 3.0);
                cout << fixed << setprecision(2) << setw(7) << right << pct + 1e-9 << endl;
            }
        }
    }
    return 0;
}