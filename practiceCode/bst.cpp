#include <iostream>
#include <string>
using namespace std;

class bst_node {
public:
    string name;
    string s_id;
    double score;
    bst_node *left, *right;
    void set_data(string s1, string s2, double n);
};

void bst_node::set_data(string s1, string s2, double n) {
    name = s1;
    s_id = s2;
    score = n;
}

class bst_tree {
    bst_node* root;
    int csize;
public: 
    bst_tree();
    void insert_node(bst_node t);
    void show_inorder();
    bst_node search(string tid);
};

bst_tree::bst_tree() {
    csize = 0;
}

void bst_tree::insert_node(bst_node t) {
    bst_node *p;
    bst_node *tmp;

    tmp = new bst_node;
    *tmp = t;
    tmp->left = NULL;
    tmp->right = NULL;

    if(root==NULL) {
        root = tmp;
        return;
    }
    p = root;
    while(1) {
        if(p->s_id == t.s_id) {
            cout << "Insertion Failed: the Key" << t.s_id << " already exist.\n";
            return;
        }
        if(p->s_id < t.s_id) {
            if(p->right == NULL) {
                p->right = tmp;
                return;
            }
            else p = p->right;
        }
        else {
            if(p->left == NULL) {
                p->left = tmp;
                return;
            }
            else p = p->left;
        }
    }
}

void bst_tree::show_inorder() {
    bst_node *p;

    

}

bst_node bst_tree::search(string tid) {
    bst_node *p;
    p = root;

    if(root==NULL) {
        bst_node tmp;
        tmp.set_data("00000000", "None", -1);
        cout << "The key" << tid << " does not exist.\n";
        return tmp;
    }
    while(1) {
        if(p->s_id == tid)
            return (*p);
        if(p->s_id < tid) {
            if(p->right == NULL) {
                bst_node tmp;
                tmp.set_data("00000000", "None", -1);
                cout << "The key" << tid << " does not exist.\n";
                return tmp;
            }
            else p = p->right;
        }
        if(p->s_id > tid) {
            if(p->left == NULL) {
                bst_node tmp;
                tmp.set_data("00000000", "None", -1);
                cout << "The key" << tid << " does not exist.\n";
                return tmp;
            }
            else p = p->left;
        }
    }
}



int main()
{
    bst_node temp;
    bst_tree t1;
    temp.set_data("21900013", "Kim", 6.5);
    t1.insert_node(temp);
    temp.set_data("21900136", "Lee", 8.8);
    t1.insert_node(temp);
    temp.set_data("21900333", "Park", 9.2);
    t1.insert_node(temp);
    temp.set_data("21800442", "Choi", 7.1);
    t1.insert_node(temp);
    temp.set_data("21900375", "Ryu", 5.4);
    t1.insert_node(temp);
    temp.set_data("21700248", "Cho", 6.3);
    t1.insert_node(temp);

    cout << "\n\n Node List : inorder sequence \n";
    //t1.show_inorder();

    string s_key = "21800442";
    temp = t1.search(s_key);

    cout << "\n -- " << s_key << "'s record ---" << endl;
    cout << " Student ID   : " << temp.s_id << endl;
    cout << " Student Name : " << temp.name << endl;
    cout << " Score        : " << temp.score << endl;

    return 0;
}