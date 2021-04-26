#include <iostream>
using namespace std;

void my_sort(int list[], int num);

int main() {
    int list[10] = {23, 11, 15, 8, 17, 33, 7, 14, 19, 21};
    int i;
    my_sort(list, 10); // 배열 list의 원소 10개를 sort하는 함수
    for (i = 0; i < 10; i++)
        cout << list[i] << "\n";
    return 0;
}

void my_sort(int list[], int num) {
    int i, j, temp, max;

    for(i=0;i<num;i++) {
        max = i;    //assign first...num(th) index to max
        for(j=i+1;j<num;j++) {
            if(list[max] < list[j]) { //if component is bigger than max
                temp = list[j];
                list[j] = list[max];
                list[max] = temp;    //assign j index to max
            }
        }
        /*** switching ***/
    }
}