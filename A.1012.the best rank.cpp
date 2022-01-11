#include <bits/stdc++.h>
using namespace std;
struct info{
    int id;
    pair<int ,int> cour[4];
};

int main(){
    int n ,m;
    cin >> n >> m;
    vector<info> mem(n);
    for(auto &elem : mem){
        cin >> elem.id;
        int sum = 0;
        for(int i = 1 ;i < 4 ;i ++){
            cin >> elem.cour[i].first;
            sum += elem.cour[i].first;
        }
        elem.cour[0].first = sum / 3;
    }
    for(int tag = 0 ;tag < 4 ;tag ++){
        sort(begin(mem) ,end(mem) ,[&](const auto &a ,const auto &b){
            if(a.cour[tag].first == b.cour[tag].first) return a.id < b.id;
            else return a.cour[tag].first > b.cour[tag].first;
        });
        mem[0].cour[tag].second = 1;
        for(int i = 1 ;i < n ;i ++){
            mem[i].cour[tag].second = (mem[i].cour[tag].first == mem[i - 1].cour[tag].first?
            mem[i - 1].cour[tag].second : i + 1);
        }
    }
    map<int ,int> mp;
    for(int i = 0 ;i < n ;i ++){
        mp[mem[i].id] = i;
    }
    while(m --){
        int wd;
        cin >> wd;
        if(mp.find(wd) == mp.end()) cout << "N/A\n";
        else{
            info temp = mem[mp[wd]];
            int brt = min_element(temp.cour ,temp.cour + 4 ,[](const auto &a ,const auto &b){
                return a.second < b.second;}) - temp.cour;
                string Cour = {'A' ,'C' ,'M' ,'E'};
            cout << temp.cour[brt].second << " " << Cour[brt] << '\n';
        }
    }
}
