#include <algorithm>
#include <cstdio>
#include <list>
using namespace std;

// list 常用函数
/**
size()
begin 表头的迭代器
end 返回指向表尾的迭代器
push_front 在表的开头添加元素
push_back 在表的末尾添加元素
pop_front 在表头删除元素
pop_back 在表的末尾删除元素
inset(p,x) 在表的位置p插入元素x
erase(p) 删除表中位置p的元素
clear 删除表中的所有元素
**/

int main() {
  int q, x;
  char com[20];
  list<int> v;
  scanf("%d", &q);

  for (int i = 0; i < q; i++) {
    scanf("%s", com);
    if (com[0] == 'i') {
      scanf("%d", &x);
      v.push_front(x);
    } else if (com[6] == 'L') {
      v.pop_back();
    } else if (com[6] == 'F') {
      v.pop_front();
    } else if (com[0] == 'd') {
      scanf("%d", &x);
      for (list<int>::iterator it = v.begin(); it != v.end(); it++) {
        if (*it == x) {
          //传入位置的迭代器，删除元素
          v.erase(it);
          break;
        }
      }
    }
  }
  int i = 0;
  for (list<int>::iterator it = v.begin(); it != v.end(); it++) {
    if (i++)
      printf(" ");
    printf("%d", *it);
  }
  printf("\n");
  return 0;
}
