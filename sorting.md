## Sorting

- sorting의 필요성 : 대량의 데이터를 다루는 다양한 응용에서 필요
  * ex ) search를 용이하게 함, list validation

### Sorting algorithm
```c
class s_record {
public:
  string s_id;  // 학번 (key)
  string name;  // 이름
  double score; // 점수
  s_record();
  s_record(string s1, string s2, double n);
}
```
#### Insertion sort
- 현 위치 보다 앞 쪽에서 자신보다 큰 값을 뒤로 이동
- 더 이상 큰 값이 없거나 맨 앞 위치에 도달하면 그곳에 원소를 넣음
```c
void insertion_sort(s_record a[], int n) {
  for (int j=1;j<n;j++) {   // 0번째는 이미 sorting 되었다고 가정
    s_record temp = a[j];
    int k = j-1;
    while((k >= 0) && (a[k].s_id > temp.s_id)) {    // 앞 쪽이 더 크면
      a[k+1] = a[k];
      k--;
    }
    a[k+1] = temp;
  }
}
```

#### Selection sort
- 대상 범위에서 가장 작은 값을 찾아
- 대상 범위의 첫 원소와 교환
```c
void selection_sort(s_record a[], int n) {
  s_record temp;
  for(int j=0;j<n;j++) {
    int min_i = j;
    for(int k=j+1;k<n;k++) {
      if(a[k].s_id < a[min_i].s_id)
        min_i = k;
      temp = a[j];
      a[j] = a[min_i];
      a[min_i] = a[j];
    }
  }
}
```

#### Bubble sort
- 인접한 두 원소를 비교, 앞 쪽이 크면 교환
- 범위를 1씩 감소시키며 반복
```c
void bubble_sort(s_record a[], int n) {
  s_record temp;

  for(int j=n-1;j>=1;j--) {
    for(int k=0;k<j;k++) {
      if(a[k].s_id > a[k+1].s_id) {
        temp = a[k];
        a[k] = a[k+1];
        a[k+1] = temp;
      }
    }
  }
}
```
- 위의 세 알고리즘(Insertion sort, Selection sort, Bubble sort)은 **O(n^2)** 의 time complexity가 걸림 
---
#### Quick sort

#### Merge sort

#### Heap sort
