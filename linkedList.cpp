#include <iostream>
#include <string>

using namespace std;

class node{
    public:
        string name;
        double score;
        node *link;
        void set_data(string s, double n);
};

class my_list {
    node *head, *tail;
    public: 
        my_list();
        void add_to_head(node t);
        void add_to_tail(node t);
        node delete_from_head();
        int num_nodes();
        bool list_empty();
        double score_sum();
        double get_score(string t_name);
        int remove_a_node(string t_name);
};

my_list::my_list() {
    head = NULL;
    tail = NULL;
}

void node::set_data(string s, double n){
    name = s;
    score = n;
}

void my_list::add_to_head(node t) {
    node *p;
    p = new node;
    (*p) = t;
    p->link = head;
    head = p;
    if(tail==NULL)
        tail = p;
}

void my_list::add_to_tail(node t) {
    node *p;
    p = new node;
    (*p) = t;
    p->link = NULL;
    if(tail!=NULL)
        tail->link = p;
    else
        head = p;
    tail = p;
    

}

node my_list::delete_from_head() {
    node tmp;
    node *t;
    t = head;
    tmp = *head;
    head = head->link;
    delete t;
    if(head == NULL)
        tail = NULL;
    return tmp;
}

int my_list::num_nodes() {
    node *t;
    int count = 0;
    for(t=head;t!=NULL;t=t->link)
        count++;
    return count;
}

bool my_list::list_empty() {
    if(head == NULL)
        return true;
    else return false;
}

double my_list::score_sum() {
    node *t;
    double sum=0;

    for(t=head;t!=NULL;t=t->link)
        sum += t->score;
    return sum;
}

double my_list::get_score(string t_name) {
    node *t;
    double s_score=0;

    for(t=head;t!=NULL;t=t->link)
        if(t->name == t_name)
            s_score = t->score;
    return s_score;
}

int my_list::remove_a_node(string t_name) {
    node *prev, *target;
    
    prev = NULL;
    target = head;

    while((target!=NULL) && (target->name!=t_name)) {
        prev = target;
        target = target->link;
    }
    if(target == NULL)
        return 0;

    //prev가 null이 아니면, (첫 node가 아니고 중간node이면)
    if(prev)
        prev->link = target->link;
    else
        head = target->link;
    //삭제 후 empty면
    if(head==NULL)
        tail = NULL;
    //끝node를 삭제했다면
    if(target==tail)
        tail = prev;
    delete target;
    return 1;
}

int main() {
    my_list a;
    node tmp;

    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);
    cout << a.num_nodes() << " : " << a.score_sum() << "\n"; //stage 1

    tmp.set_data("Park", 91.3);
    a.add_to_tail(tmp);
    cout << a.num_nodes() << " : " << a.score_sum() << "\n"; //stage 2

    tmp = a.delete_from_head();
    cout << tmp.name << " is deleted.\n"; //stage 3
    
    tmp.set_data("Choi", 85.1);
    a.add_to_tail(tmp);
    tmp.set_data("Ryu", 94.3);
    a.add_to_head(tmp);
    cout << a.num_nodes() << " : " << a.score_sum() << "\n"; 
    cout << "Park's score : " << a.get_score("Park") << "\n"; //stage 4

    if(a.remove_a_node("Kim")==1)
        cout << "Kim is deleted from the list. \n"; //stage 5
    
    cout << a.num_nodes() << " : " << a.score_sum() << "\n"; //last stage

    return 0;
}