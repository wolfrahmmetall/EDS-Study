#include<iostream>
#include<vector>
#include<algorithm>

const int inf = 1 << 30;

class Segment_tree {
private:
    struct Node{
        int summ = 0;
        int assign = -inf;
        Node* left = nullptr;
        Node* right = nullptr;
        int begin = 0;
        int end = 0;
        Node(int begin, int end) : begin(begin), end(end) {
            if (begin + 1 < end) {
                int m = (begin + end) / 2;
                left = new Node(begin, m);
                right = new Node(m, end);
            }
        }

        void push() {
            if (assign != -inf) {
                summ = (end - begin) * assign;
                if (begin + 1 < end) {
                    left->assign = assign;
                    right->assign = assign;
                }
            }
            assign = -inf;
        }

        void set(int ql, int qr, int v) {
            push();
            if (ql <= begin && end <= qr) {
                assign = v;
            } else if (qr <= begin || end <= ql) {
                return;
            } else {
                left->set(ql, qr, v);
                right->set(ql, qr, v);
            }
        }


        int get(int ql, int qr) {
            push();
            if (qr <= begin || end <= ql) {
                return 0;
            } else if (ql <= begin && end <= qr) {
                return summ;
            } else {
                return left->get(ql, qr) + right->get(ql, qr);
            }
        }


        ~Node() {
            delete left;
            delete right;
        }
    } *root = nullptr;

public:
    Segment_tree(int begin, int end) {
        root = new Node(begin, end);
    }

    void set(int ql, int qr, int v) {
        root->set(ql, qr, v);
    }

    int get(int ql, int qr) {
       return root->get(ql, qr);
    }

    ~Segment_tree() {
        delete root;
    }

};

int main() {
    Segment_tree st(0, 10);
    st.set(0, 5, 2);
    st.set(3, 7, 1);
    std::cout << st.get(0, 9);

    return 0;
}
