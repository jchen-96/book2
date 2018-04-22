#include <cstdio>
#include <cstdlib>
#include <cstring>

// 实现一个双向链表

struct Node {
  int key;
  Node *next, *pre;
};

Node *nil;

Node *listSearch(int key) {
  Node *cur = nil->next;
  while (cur && cur->key != key) {
    cur = cur->next;
  }

  return cur;
}

void init() {
  nil = (Node *)malloc(sizeof(Node));
  nil->next = nil;
  nil->pre = nil;
}

void printlist() {
  Node *cur = nil->next;
  int isf = 0;
  while (1) {
    if (cur == nil)
      break;
    if (isf++ > 0)
      printf(" ");
    printf("%d", cur->key);

    cur = cur->next;
  }
  printf("\n");
}

void deleteNode(Node *t) {
  if (t == nil) {
    return;
  }
  t->pre->next = t->next;
  t->next->pre = t->pre;

  free(t);
}

void deleteFirst() { deleteNode(nil->next); }

void deleteLast() { deleteNode(nil->pre); }

void deleteKey(int key) { deleteNode(listSearch(key)); }

void insert(int key) {
  Node *x = (Node *)malloc(sizeof(Node));
  x->key = key;
  x->next = nil->next;
  nil->next = x;
  x->pre = nil;
}

int main() {
  int key, n, i;
  int size = 0;
  char com[20];
  int np = 0, nd = 0;
  scanf("%d", &n);

  init();
  for (int i = 0; i < n; i++) {
    scanf("%s%d\n", com, &key);
    if (com[0] == 'i') {
      insert(key);
      np++;
      size++;
    } else if (com[0] == 'd') {
      if (strlen(com) > 6) {
        if (com[6] == 'F')
          deleteFirst();
        else if (com[6] == 'L')
          deleteLast();
      } else {
        deleteKey(key);
        nd++;
      }
      size--;
    }
  }
  printlist();
  return 0;
}
