//STL优先队列priority_queue


#include<iostream>
#include<queue>
//加这个文件是因为杭电的oj不行
#include<string>
using namespace std;

struct Node{
    int n, p;
    bool operator < (const Node &t) const {
        if (p == t.p) return n > t.n;
        return p < t.p;
    }
}node;

int main() {
    int n, id, doc;
    string temp;
    //没有输入scanf返回-1
    while (~scanf("%d", &n)) {
        id = 0;
        priority_queue<Node> q[3];
        while (n--) {
            cin>>temp;
            if (temp == "IN") {
                scanf("%d%d", &doc, &node.p);
                node.n = ++id;
                q[doc - 1].push(node);
            }else {
                scanf("%d", &doc);
                if (q[doc - 1].empty())
                    cout << "EMPTY" << endl;
                else {
                    node = q[doc - 1].top();
                    q[doc - 1].pop();
                    cout << node.n<<endl;
                }
            }
        }
    }
    return 0;
}
