#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> neighbours = {{-1,0},{0,-1},{1,0},{0,1}};
vector<int> exists_num;
int lastNumber = 0;
int wid = 0, hei = 0;

pair<int,int> find_next_pos(vector<vector<int>>& pa, int x, int y, int z) {
    for (int i = 0; i < 4; i++) {
        int a = x + neighbours[i][0];
        int b = y + neighbours[i][1];
        if (a >= 0 && a < wid && b >= 0 && b < hei) {
            if (pa[a][b] == z)
                return {a, b};
        }
    }
    return {-1, -1};
}

bool find_solution(vector<vector<int>>& pa, int x, int y, int z) {
    if (z > lastNumber) return true;

    // number is already fixed in grid
    if (exists_num[z] == 1) {
        auto s = find_next_pos(pa, x, y, z);
        if (s.first < 0) return false;
        return find_solution(pa, s.first, s.second, z+1);
    }

    // try neighbors
    for (int i = 0; i < 4; i++) {
        int a = x + neighbours[i][0];
        int b = y + neighbours[i][1];
        if (a >= 0 && a < wid && b >= 0 && b < hei) {
            if (pa[a][b] == 0) {
                pa[a][b] = z;
                bool r = find_solution(pa, a, b, z+1);
                if (r) return true;
                pa[a][b] = 0;
            }
        }
    }
    return false;
}

pair<bool, vector<vector<int>>> solve(string pz, int w, int h) {
    wid = w;
    hei = h;
    lastNumber = w*h;

    exists_num.assign(lastNumber+1, 0);

    vector<vector<int>> pa(w, vector<int>(h, 0));

    // split input by spaces
    vector<string> st;
    string tmp;
    stringstream ss(pz);
    while (ss >> tmp) st.push_back(tmp);

    int idx = 0;
    for (int j = 0; j < h; j++) {
        for (int i = 0; i < w; i++) {
            if (st[idx] != ".") {
                pa[i][j] = stoi(st[idx]);
                exists_num[pa[i][j]] = 1;
            }
            idx++;
        }
    }

    int x = 0, y = 0;
    int t = lastNumber + 1;

    // get smallest given number
    for (int j = 0; j < h; j++) {
        for (int i = 0; i < w; i++) {
            if (pa[i][j] != 0 && pa[i][j] < t) {
                t = pa[i][j];
                x = i;
                y = j;
            }
        }
    }

    bool ok = find_solution(pa, x, y, t+1);
    return {ok, pa};
}

void show_result(pair<bool, vector<vector<int>>> r) {
    bool ok = r.first;
    auto pa = r.second;

    if (ok) {
        for (int j = 0; j < hei; j++) {
            for (int i = 0; i < wid; i++) {
                cout << setw(3) << pa[i][j];
            }
            cout << "\n";
        }
    } else {
        cout << "No Solution!\n";
    }
    cout << "\n";
}

int main() {
    auto r1 = solve(
        ". . . . . . . . . . . 46 45 . 55 74 . . . 38 . . 43 . . 78 . . 35 . . . . . 71 . . . 33 . . . 59 . . . 17 "
        ". . . . . 67 . . 18 . . 11 . . 64 . . . 24 21 . 1 2 . . . . . . . . . . .",
        9, 9
    );
    show_result(r1);

    auto r2 = solve(
        ". . . . . . . . . . 11 12 15 18 21 62 61 . . 6 . . . . . 60 . . 33 . . . . . 57 . . 32 . . . . . 56 . . 37 "
        ". 1 . . . 73 . . 38 . . . . . 72 . . 43 44 47 48 51 76 77 . . . . . . . . . .",
        9, 9
    );
    show_result(r2);

    auto r3 = solve(
        "17 . . . 11 . . . 59 . 15 . . 6 . . 61 . . . 3 . . . 63 . . . . . . 66 . . . . 23 24 . 68 67 78 . 54 55 "
        ". . . . 72 . . . . . . 35 . . . 49 . . . 29 . . 40 . . 47 . 31 . . . 39 . . . 45",
        9, 9
    );
    show_result(r3);

    return 0;
}
