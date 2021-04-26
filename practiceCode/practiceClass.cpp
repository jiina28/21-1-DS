#include <iostream>
using namespace std;

class weight
{
    int kg;
    int g;
public: void set_weight(int n1, int n2);
        int get_weight();
};

weight add_weight(weight w1, weight w2);
int less_than(weight w1, weight w2);

int main() {
    weight w1, w2, w3;

    w1.set_weight(3, 400);
    w2.set_weight(2, 700); 
    w3 = add_weight(w1, w2);

    cout << w3.get_weight() << "grams\n";

    if (less_than(w1, w2))
        cout << "yes.\n";

    else
        cout << "no. \n";
}

void weight::set_weight(int n1, int n2) {
    kg = n1;
    g = n2;
}

int weight::get_weight() {
    int total = 0;
    total = (1000 * kg) + g;

    return total;
}

weight add_weight(weight w1, weight w2) {
    weight w3;
    int total = 0;
    int kg, g;
    
    total = w1.get_weight() + w2.get_weight();
    kg = total / 1000;
    g = total - (kg*1000);
    w3.set_weight(kg, g);

    return w3;
}
int less_than(weight w1, weight w2){
    int w1_total = w1.get_weight();
    int w2_total = w2.get_weight();
    if (w1_total < w2_total)
        return 1;
    else
        return 0;
    
}