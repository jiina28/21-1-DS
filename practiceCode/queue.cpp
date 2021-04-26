#include <iostream>
#include <string>
using namespace std;

#define Q_SIZE 100

class element {
    public:
        string s_title;
        int npages;
        int price;
        void set_data(string s, int n1, int n2);
};

class my_queue {
    int front, rear;
    public: 
        element q[Q_SIZE];
        my_queue();
        void insert_q(element x);
        element delete_q();
        bool full();
        bool empty();
};

my_queue::my_queue() {
    front = 0;
    rear  = 0;
}

int main() {
    my_queue  a;
    element  tmp;

    tmp.set_data("C++ Programming", 534, 35000);
    a.insert_q(tmp);
    tmp.set_data("Data Structure", 621, 42000);
    a.insert_q(tmp);
    tmp.set_data("JAVA Programming", 485, 38000);
    a.insert_q(tmp);
    tmp.set_data("Logic Design", 532, 44000);
    a.insert_q(tmp);
    
    while(!a.empty()) {
        tmp = a.delete_q();
        cout << tmp.s_title << " : " << tmp.npages << " : " << tmp.price << "\n";
    }
    return 0;
}

void element::set_data(string s, int n1, int n2) {
    s_title = s;
    npages = n1;
    price = n2;
}

void my_queue::insert_q(element x){
    if(!full()) {
        q[rear] = x;
        rear = (rear+1) % Q_SIZE;
    }
    else cout << "Queue is full!\n";
}

element my_queue::delete_q() {
    element tmp;
    if(!empty()) {
        tmp = q[front];
        front = (front+1) % Q_SIZE;
        return (tmp);
    }
    else {
        cout << "Queue is empty!\n";
        return tmp;
    }
}

bool my_queue::full() {
    if((rear+1) % Q_SIZE == front) {
        return true;
    }
    else return false;
}

bool my_queue::empty() {
    if(front == rear) {
        return true;
    }
    else return false;
}