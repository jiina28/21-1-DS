## Heap

### Max Heap이란?
- 다음을 만족하는 **binary tree**
  1) **complete binary tree**
  2) **max tree** : parent의 key값이 children의 key값 보다 큼

### Max Heap의 특징
> 저장된 원소 중 **key 값이 가장 큰 원소**를 제공하는 data structure
- 원소의 insert, delete가 O(log n)에 이루어짐
- 일반적으로 **array**를 사용하여 표현
  * root의 위치를 1로 했을 때, k번째 원소의
    1) left child : 2k번째 원소
    2) right child : 2k+1번째 원소
    3) parent : k/2번째 원소

### Max Heap의 연산
- **Insert** : heap의 마지막 부분에 원소를 넣고, 부모의 key와 비교하여 자리를 조정함
- **delete** : heap의 root에 해당하는 원소를 삭제하고, 마지막 원소를 root로 올린 후 자식의 key와 비교하여 자리를 조정함
