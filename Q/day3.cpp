#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> func(vector<vector<int>> teams) {
    // you have to implement the func() only

    vector<vector<int>> stats;
    //froming stats for each team
    for(auto team:teams){
        int mvpKill=0;
        int totKill=0;
        for(auto kills:team){
            mvpKill = max(mvpKill,kills);
            totKill += kills;
        }

        stats.push_back({totKill,mvpKill});
    }

    // for(auto ele:ulti){
    //     for(auto i:ele){
    //         cout<<i<<" ";
    //     }cout<<endl;
    // }

    int maxTot = 0, maxMvp = 0;
    //now finding max. tot kills and their corresponding mvp
    for(auto stat:stats){
        if(stat[0]>maxTot || (stat[0]==maxTot && stat[1]>maxMvp)){
            maxTot = stat[0];
            maxMvp = stat[1];
        }
    }

    //now finding teams with same max and storing them
    vector<vector<int>> ans;
    for(int i=0;i<stats.size();i++){
        if(stats[i][0]==maxTot && stats[i][1]==maxMvp){
            ans.push_back({i+1,maxTot,maxMvp});
        }
    }

    return ans;
}

int main() {
    // initial code 
    vector<vector<int>> teams;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int team_size;
        cin >> team_size;
        vector<int> team(team_size);
        for (int j = 0; j < team_size; j++) {
            cin >> team[j];
        }
        teams.push_back(team);
    }
    // you have to implement the func() only
    vector<vector<int>> result = func(teams);

    // print the result(please don't modify this)
    for(int i = 0; i < result.size(); i++) {
        if(i == result.size() - 1) {
            cout << result[i][0] << " " << result[i][1] << " " << result[i][2];
        } else {
            cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
        }
    }   
    // end of initial code
    return 0;
}