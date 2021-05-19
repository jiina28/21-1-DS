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
- 대상 범위의 원소 개수가 1 이하이면 return
- 대상 범위의 첫 원소를 기준 원소(pivot)로 하여
- pivot 보다 key 값이 큰 원소는 뒤로, 작은 원소는 앞으로 이동하여 list를 분리(partitioning)
- 앞 부분과 뒷 부분을 다시 quick sort 실행
```c
void quick_sort(s_record a[], int left, int right) {
  s_record pivot, temp;
  int i, j;
  if(left >= right) return;   // 원소 개수가 1 이하
  i = left;                   // 앞에서 뒤로
  j = right + 1;              // 뒤에서 앞으로
  pivot = a[left];
  do {
    do {
      i++;
    } while((i <= right) && (a[i].s_id < pivot.s_id));      // 크면 멈춰라
    do {
      j--;
    } while(a[j].s_id > pivot.s_id);                        // 작으면 멈춰라
    if(i < j) swap(a[i], a[j]);
  } while(i < j);                                           // 서로 교차할 때까지 반복
  swap(a[left], a[j]);
  quick_sort(a, left, j-1);
  quick_sort(a, j+1, right);
}
```

#### Merge sort
- 전체를 길이가 s인 sorted list가 연속된 형태로 고려하여, 두 개의 list를 한 개로 merge하는 과정을 반복
- s를 1로 시작하여 2배로 증가 시켜 반복
- s가 전체 길이가 되면 종료
```c
void merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4) {
  int i, j, k, t;
  i = n1;
  j = n3;
  k = n1;
  while((i <= n2) && (j <= n4)) {
    if(a[i].s_id <= a[j].s_id)
      b[k++] = a[i++];          // i 선택
    else
      b[k++] = a[j++];          // j 선택
  }
  if(i > n2) {
    for(t=j;t<=n4;t++)
       b[t] = a[t];
  }
  else {
    for(t = i;t<=n2;t++)
      b[k+t-i] = a[t];
  }
}
```

#### Heap sort
- 초기 heap 구성
- 다음을 n-1회 반복
  * heap에서 첫 원소와 끝 원소의 위치를 교환
  * heap의 size를 1 감소시킴
  * root를 기준으로 reheaping(adjust)
```c
void heap_sort(s_record a[], int n) {
  int i;
  s_record b[S_SIZE], temp;

  for(i=0;i<n;i++)        // 1부터 n번째까지로 위치 조정
    b[i+1] = a[i];

  for(i=n/2;i>0;i--)      // 주어진 입력에 대하여 heap 구성
    adjust(b, i, n);

  for(i=n-1;i>0;i--) {
    temp = b[1];
    b[1] = b[i+1];
    b[i+1] = temp;
    adjust(b, 1, i);
  }
}
```
