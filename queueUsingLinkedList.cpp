#include <iostream>
#include <string>
using namespace std;

#define Q_SIZE 100
class node{
    public:
    string name;
    double score;
    node *link;
    void set_data(string s, double n);
};

class my_queue {
    node *front, *rear;
    public: 
        my_queue();
        void insert_q(node t);
        node delete_q();
        bool empty();
};

my_queue::my_queue() {
    front = 0;
    rear  = 0;
}

int main() {
    my_queue  a;
    node tmp;

    tmp.set_data("KIM", 22.2);
    a.insert_q(tmp);
    tmp.set_data("LEE", 33.3);
    a.insert_q(tmp);
    tmp.set_data("PARK", 44.4);
    a.insert_q(tmp);
    tmp.set_data("CHOI", 55.5);
    a.insert_q(tmp);
    
    tmp = a.delete_q();
    cout << tmp.name << " : " << tmp.score << "\n";
    tmp = a.delete_q();
    cout << tmp.name << " : " << tmp.score << "\n";

    return 0;
}

void node::set_data(string s, double n) {
    name = s;
    score = n;

}

void my_queue::insert_q(node t){
    node *p;
    p = new node;
    (*p) = t;
    p->link = NULL;
    if(rear != NULL)
        rear->link = p;
    else
        front = p;
    rear = p;
}

node my_queue::delete_q() {
    node tmp;
    node *t;
    if(empty()) {
        cout << "Queue is Empty~!!!\n";
        return tmp;
    }
    else {
        tmp = (*front);
        t = front;
        front = front->link;
        delete t;
        if(front == NULL)
            rear = NULL;
        return tmp;
    }
}

bool my_queue::empty() {
    if(front == rear) {
        return true;
    }
    else return false;
}