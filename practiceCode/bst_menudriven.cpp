#include <iostream>
#include <string>

#define INSERT      1
#define FIND        2
#define SHOW_ALL    3
#define QUIT        4

using namespace std;

class bst_node {
public:
    string name;
    string phone;
    string birth;
    bst_node* left, *right;
    bst_node();
    bst_node(string s1, string s2, string n);
    void set_data(string s1, string s2, string n);
};

bst_node::bst_node() {
	name = "None";
    phone = "010-0000-0000";
	birth = "0000";
}

bst_node::bst_node(string s1, string s2, string n)
{
	name = s1;
	phone = s2;
	birth = n;
}

void bst_node::set_data(string s1, string s2, string n) {
    name = s1;
    phone = s2;
    birth = n;
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
        if(p->birth == t.birth) {
            cout << "Insertion Failed: the Key" << t.birth << " already exist.\n";
            return;
        }
        if(p->birth < t.birth) {
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
void inorder(bst_node *p) {
    if(p==NULL) return;

    inorder(p->left);
    cout << p->name << " : " << p->birth << " : " << p->phone << "\n";
    inorder(p->right);

}

void bst_tree::show_inorder() {
    inorder(root);
}

bst_node bst_tree::search(string tid) {
    bst_node* p;
	p = root;
	if (root == NULL)
	{
		bst_node tmp;
		tmp.set_data("None", "010-0000-0000", "0000");
		cout << "The key " << tid << " does not exist.\n";
		return tmp;
	}
	while (1)
	{
		if (p->birth == tid)
			return (*p);

		if (p->birth < tid) {
			if (p->right == NULL)
			{
				bst_node tmp;
				tmp.set_data("None", "010-0000-0000", "0000");
				cout << "The key " << tid << " does not exist.\n";
				return tmp;
			}
			else
				p = p->right;
		}

        else {
			if (p->left == NULL)
			{
				bst_node tmp;
				tmp.set_data("None", "010-0000-0000", "0000");
				cout << "The key " << tid << " does not exist.\n";
				return tmp;
			}
			else
				p = p->left;
		}
		
	}
}
int get_a_cmd() {
    int n;
    cout << "\n\n1. Insert a node\n";
    cout << "2. Find a node\n";
    cout << "3. show all nodes in tree\n";
    cout << "4. Quit\n";
    cout << "\n> Select a command : ";

    cin >> n;
    return n;
}

int main()
{
    bst_node temp;
    bst_tree t1;
    int cmd;
    string newname, newphone, newbirth, s_key;

    do {
        cmd = get_a_cmd();
        switch(cmd) {
            case INSERT:
                cout << "name: ";
                cin >> newname;
                cout << "phone: ";
                cin >> newphone;
                cout << "birth: ";
                cin >> newbirth;
                temp.set_data(newname, newphone, newbirth);
                t1.insert_node(temp);
                break;
            case FIND:
                cout << "want to find (birth): ";
                cin >> s_key;
                temp = t1.search(s_key);
                cout << "\n -- " << s_key << "'s record ---\n";
                cout << " birth     : " << temp.birth << "\n";
                cout << " name      : " << temp.name << "\n";
                cout << " phone     : " << temp.phone << "\n";
                break;
            case SHOW_ALL:
                t1.show_inorder();
                break;
            case QUIT:
                cout << "Bye!!\n";
        }

    }while(cmd != QUIT);

    return 0;
}