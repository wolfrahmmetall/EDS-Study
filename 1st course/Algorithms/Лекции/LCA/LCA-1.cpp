#include<iostream>
#include<vector>

std::vector<std::vector<int> > gr; // граф в виде списка смежности
std::vector<std::vector<int> > dp; // таблица для нахождения предков вершин на различных уровнях
std::vector<int> h; // содержит высоты вершин
std::vector<int> used; // отслеживаем посещенность вершин для DFS
int lgn = 19;

void dfs(int v) {
    used[v] = true;
    h[v] = h[dp[v][0]] + 1;
    for (auto to : gr[v]) {
        dfs(to);
    }
}

int lca(int u, int v) {
    /*
    Если высота вершины v меньше высоты вершины u, меняем их местами
    */
    if (h[v] < h[u]) std::swap(v, u);

    /*
    Цикл по всем уровням предков от lgn−1 до 0,
    чтобы поднять вершину v на уровень вершины u
    */
    for (int j = lgn - 1; j >= 0; --j) {
        int k = dp[v][j];
        if (h[k] >= h[u]) {
            v = k;
        }
    }

    /*
    Если вершины совпадают, возвращаем одну из них
    */
    if (u == v) return v;
    
    /*
    Если вершины не совпадают, продолжаем подниматься по дереву, 
    пока не найдём их общего предка
    */
    for (int j = lgn - 1; j >= 0; --j) {
        if (dp[v][j] != dp[u][j]) {
            v = dp[v][j];
            u = dp[u][j];
        }
    }
    return dp[v][0];
}

int main() {
    int n, m = 0;
    std::cin >> n >> m;
    gr.resize(n);
    h.resize(n);
    used.resize(n);
    dp = std::vector<std::vector<int> > (n, std::vector<int>(lgn, 0));
    for (int i = 1; i < n; ++i) {
        int v = 0;
        std::cin >> v;
        gr[i].push_back(v);
        gr[v].push_back(i);
        dp[i][0] = v;
    }
    for (int j = 1; j < lgn; ++j) {
        for (int i = 0; i < n; ++i) {
           dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
    dfs(0);




    return 0;
}
