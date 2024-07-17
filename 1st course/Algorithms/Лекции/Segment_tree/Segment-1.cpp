#include<iostream>
#include<vector>

class SegmentTree {
    std::vector<int> tree;
    std::vector<int> arr;
    void build(int v, int left, int right) {
        if (left + 1 == right) {
            tree[v] = arr[left];
        } else {
            int m = (left + right) / 2;
            build(2 * v, left, m);
            build(2 * v + 1, m, right);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    int get(int v, int left, int right, int qleft, int qright) {
        if (qright <= left || right <= qleft) {
            return 0;
        } else if (qleft <= left && right <= qright) {
            return tree[v];
        } else {
            int m = (left + right) / 2;
            return  get(2 * v, left, m, qleft, qright) +
                    get(2 * v + 1, m, right, qleft, qright);
        }
    }

public:
    SegmentTree(const std::vector<int>& arr) {
        this->arr = arr;
        tree.assign(arr.size() * 4, 0);
        int k = 1;
        while (this->arr.size() > k) {
            k = k * 2;
        }
        while (this->arr.size() < k){
            this->arr.push_back(0);
        }
        build(1, 0, this->arr.size());
    }

    int get(int qleft, int qright) {
        return get(1, 0, this->arr.size(), qleft, qright);
    }

};

int main() {
    std::vector<int> v = {3, -1, 2, 3, -2, 5, 1, 4, 5, 6, 7};
    SegmentTree st(v);
    std::cout << st.get(4, 10);
    return 0;
}
