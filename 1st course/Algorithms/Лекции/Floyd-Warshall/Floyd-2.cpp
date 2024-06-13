#include<iostream>
#include<vector>
#include<cmath>

/*
В первой строке входного файла записано единственное число: N (1 <= N <= 100 ) — количество вершин графа
В следующих N строках по N чисел — матрица смежности графа (j-е число в i-й строке соответствует весу ребра из вершины i в вершину j): 
число 0 обозначает отсутствие ребра, а любое другое число — наличие ребра соответствующего веса. 

Выведите N строк по N чисел. 
j-е число в i-й строке должно соответствовать кратчайшему пути из вершины i в вершину j. 
Число должно быть равно 0, если пути не существует, 1, если существует кратчайший путь, и 2, 
если пути существуют, но бывают пути сколь угодно маленького веса.
*/

const int inf = (1 << 20);

int main() {
    size_t n = 0;
    std::cin >> n;
    std::vector<std::vector<int> > gr(n, std::vector<int>(n, 0));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> gr[i][j];
            if (gr[i][j] == 0) {
                gr[i][j] = inf;
            }
        }
        gr[i][i] = 0;
    }
    for (size_t k = 0; k < n; ++k) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (gr[i][k] == inf || gr[k][j] == inf) continue;
                gr[i][j] = std::min(gr[i][j], gr[i][k] + gr[k][j]);
            }
        }
    }
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            //std::cout << gr[i][j] << ' ';
            if (gr[i][j] == inf) {
                std::cout << 0 << ' ';
            } else if (gr[i][j] >= 0) {
                std::cout << 1 << ' ';
            } else {
                std::cout << 2 << ' ';
            }
        }
        std::cout << '\n';
    }
    return 0;
}
