## MST(Minimum Spanning Tree)

### Spanning Trees
- graph의 모든 vertex를 연결하는 cycle이 없는 subgraph -> Tree
- vertex가 n인 spanning tree는 n-1 개의 edge를 가짐

### Minimum Spanning Tree
- **weighted graph에서 cost의 합이 최소인 spanning tree를 찾는 문제**
1) **Kruskal's algorithm** : 전체 edge 집합을 cost 순서로 sort하고 (increasing), cost 순서대로 edge를 판단
    * 전체 edge의 집합을 cost 순서로 Sorting
    * cost 순서로 해당 edge가 cycle을 이루지 않으면 선택 (safe edge)
    * n-1개의 edge가 선택될 때까지 반복


2) **Prim's algorithm** : source vertex에서 시작하여 현재 유지되고 있는 connected component 와 연결된 edge를 고려
    * source vertex로부터 시작
    * 현재 구성되는 connected component와 (외부로) 연결된 edge 중에서 최소 cost edge를 선택 (cycle check할 필요 x)
    * n-1개의 edge가 선택될 때까지 반복
