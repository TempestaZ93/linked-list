#include "LinkedList.hpp"
#include <iostream>

using namespace llist;
using namespace std;

int main (int argc, char* argv[]){
    LinkedList<int> ll;

    ll.insert(3);
    ll.insert(5);
    ll.insert(6);
    ll.insert(7);
    ll.insert(8);

    for(int i = 0; i < ll.size(); i ++){
        cout << ll.at(i) << endl;
    }
    

}