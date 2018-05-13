#include <iostream>
#include <string>
#include <queue>

using namespace std;


//默认的优先队列是一个最大堆，当然这个最大的基准可以自己设置
int main() {
    char com[20];

    priority_queue<int> pq;

    while (true) {
        int key;
        cin >> com;
        if (com[0] == 'i') {
            cin >> key;
            pq.push(key);
        } else if (com[1] == 'x') {
            cout << pq.top()<<endl;
            pq.pop();
        } else if (com[0] == 'e') {
            break;
        }
    }
    return 0;

}