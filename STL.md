## STL 정리

### Stack
- push() : 원소 insert
- pop() : 원소 delete (void type 임)
- top() : 현재 top 위치의 원소 읽음
- size() : 현재 원소 개수
```c
#include <stack>

stack <int< s1;
stack <double> s2;
stack <s_record> s3;

s1.push(3);
s1.pop();
int n1 = s1.top();
int n2 = s1.size();
```

### Queue
- push() : 원소 insert
- pop() : 원소 delete (void type 임)
- front() : 현재 front 원소 읽음
- back() : 현재 rear 원소 읽음
- size() : 현재 원소 개수
```c
#include <queue>

queue <int> q1;
queue <double> q2;
queue <s_record> q3;

q1.push(2);
q1.pop();

int n1 = q1.front();
int n2 = q1.back();
```
