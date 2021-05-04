## Binary Search Tree

### Binary Search Tree 란?
- **empty**거나(empty일 때도 Binary Tree임), 다음을 만족하는 **Binary Tree**
    1) 각 node는 서로 다른 **unique한 key** 값을 가짐
    2) **Left subtree**에 속한 모든 node의 key 값은 **root의 key 값보다 작음**
    3) **Right subtree**에 속한 모든 node의 key 값은 **root의 key 값보다 큼**
    4) 모든 subtree는 Binary Search tree

### Binary Seach Tree의 연산
- **search** : root의 key 값과 주어진 key 값을 비교하여 (root의 key가 더 크면 Left subtree로, root의 key가 더 작으면 Right subtree로) 결과(주어진 key값을 갖는 원소의 data값) return
- **insert** : 값이 추가될 위치를 찾고(**NULL이어야함**), node를 생성하여 값을 넣고 연결
- **delete** : 삭제할 node가
    1) **terminal node (leaf node)** 이면 parent의 해당 link를 NULL로 변경
    2) **degree가 1인 node**이면 parent의 해당 link에 child를 연결
    3) **degree가 2인 node**이면 해당 노드를 Left subtree의 largest node 또는 Right subtree의 smallest node로 대체
