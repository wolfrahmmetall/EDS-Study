#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<algorithm>

/*
Алгоритм Джарвиса для вычисления выпуклой оболочки множества точек в двумерном пространстве
*/

class point {
public:
    int x = 0;
    int y = 0;
    point() {}
    point(int x, int y) : x(x), y(y) {}

    friend point operator+(const point& a, const point& b) {
        return point(a.x + b.x, a.y + b.y);
    }

    friend point operator-(const point& a, const point& b) {
        return point(a.x - b.x, a.y - b.y);
    }

    friend int operator*(const point& a, const point& b) {
        return a.x * b.x + a.y * b.y;
    }

    friend point operator*(int k, const point& a) {
        return point(k * a.x, k * a.y);
    }

    friend int operator^(const point& a, const point& b) {
        return a.x * b.y - b.x * a.y;
    }

    friend bool operator==(const point& a, const point& b) {
        return a.x == b.x && a.y == b.y;
    }

    friend bool operator!=(const point& a, const point& b) {
        return !(a == b);
    }

    friend std::istream& operator >> (std::istream& is, point& p) {
        is >> p.x >> p.y;
        return is;
    }

    friend std::ostream& operator << (std::ostream& os, const point& p) {
        os << p.x << ' ' << p.y;
        return os;
    }

    double len() {
        return sqrt(x * x + y * y);
    }

};

double dist(const point& a, const point& b) {
    return (a - b).len();
}


int main() {
    size_t n = 0;
    std::cin >> n;
    std::vector<point> points(n);
    for (auto& p : points) {
        std::cin >> p;
    }

    point p0 = points[0];

    for (auto& p : points) {
        if (p.y < p0.y) {
            p0 = p;
        } else if (p.y == p0.y && p.x < p0.x) {
            p0 = p;
        }
    }

    //std::sort()

    std::vector<point> hull = {p0};

    while(true) {
        point tmp;
        for (auto& p : points) {
            if (p != p0) {
                tmp = p;
                break;
            }
        }
        for (auto& p : points) {
            if (((p - p0) ^ (tmp - p0)) > 0) {
                tmp = p;
            }
        }
        if (tmp == hull[0])
            break;
        else {
            p0 = tmp;
            hull.push_back(tmp);
        }
    }

    for (auto& p : hull) {
        std::cout << p << '\n';
    }

    return 0;
}
