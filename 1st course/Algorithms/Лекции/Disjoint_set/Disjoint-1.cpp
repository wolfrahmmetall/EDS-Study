#include<iostream>
#include<vector>
#include<string>


/*
https://informatics.msk.ru/mod/statements/view.php?chapterid=3558
*/

struct disjoint_sets {
    std::vector<int> p;

    disjoint_sets(size_t sz) {
        p = std::vector<int>(sz, -1);
    }

    int find(int v) {
        int r = v;
        while (p[r] != -1) {
            r = p[r];
        }
        while (p[v] != -1) {
            int t = p[v];
            p[v] = r;
            v = t;
        }
        return r;
    }

    void merge(int a, int b) {
        p[find(a)] = find(b);
    }

};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string cmd;
    disjoint_sets ds(10);
    while (std::cin >> cmd) {
        if (cmd == "RESET") {
            size_t sz = 0;
            std::cin >> sz;
            ds = disjoint_sets(sz);
            std::cout << "RESET DONE\n";
        } else if (cmd == "JOIN") {
            int a = 0, b = 0;
            std::cin >> a >> b;
            if (ds.find(a) == ds.find(b)) {
                std::cout << "ALREADY " << a << ' ' << b << '\n';
            } else {
                ds.merge(a, b);
            }
        } else if (cmd == "CHECK") {
            int a = 0, b = 0;
            std::cin >> a >> b;
            if (ds.find(a) == ds.find(b)) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        }
    }
    return 0;
}
