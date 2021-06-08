## AVL Tree

### AVL Tree 정의
- Binary Search Tree의 특수한 경우 (**Binary Search Tree + Height-Balanced Tree**)
- **Height-Balanced Tree** : Left subtree와 Right subtree의 height 차이가 1보다 작거나 같음

### 특성
- Balance factor : Left subtree의 height - Right subtree의 Height
- AVL Tree의 모든 node의 balance factor는 {-1, 0, 1} 중 하나

### 추가 연산
- Binary Search Tree에서 원소 추가 연산과 유사
- 원소 추가 후 tree의 형태가 balanced tree 조건이 위배되면 tree의 구조를 balanced tree가 되도록 구성

### Unbalaned tree의 판단
- imbalance 가 발생한 minimal subtree에 대하여 다음 4가지 형태로 구분
**< minimal subtree의 root를 기준으로 하여>**
  * left subtree의 left가 길어진 경우 : LL type
  * left subtree의 right가 길어진 경우 : LR type
  * right subtree의 left가 길어진 경우 : RL type
  * right subtree의 right가 길어진 경우 : RR type


### Rotate 연산
- unbalnced tree -> balanced tree 변환
- imbalance 가 발생한 반대 방향으로 rotate
