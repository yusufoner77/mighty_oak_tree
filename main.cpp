#include <iostream>
#include <string>

using namespace std;

class Squirrel {
  private:
    string name;

  public:
    Squirrel(string name) {
      this->name = name;
    }

    string get_name() {
      return this->name;
    }
};

class Node {
  public:
    Squirrel *data;
    Node *left;
    Node *right;
    
    Node(Squirrel *data) {
      this->data = data;
      this->left = nullptr;
      this->right = nullptr;
    }

    void set_left(Node *n) {
      left = n;
    }

    void set_right(Node *n) {
      right = n;
    }

    Node left_node() {
      return *left;
    }

    Node right_node() {
      return *right;
    }
};

int main() {
  Squirrel cheeks = Squirrel("Cheeks");
  Node node_one = Node(&cheeks);

  Squirrel squeaks = Squirrel("Squeaks");
  Node node_two = Node(&squeaks);

  Squirrel fluffybutt = Squirrel("Mr. Fluffy Butt");
  Node node_three = Node(&fluffybutt);

  node_one.set_left(&node_two);
  node_one.set_right(&node_three);

  Node retrieved_node_one = node_one.left_node(); // This should retrieve the left node
  Node retrieved_node_two = node_one.right_node(); // This should retrieve the right node

  cout << "The children of Cheeks are "
       << retrieved_node_one.data->get_name() 
       << " and "
       << retrieved_node_two.data->get_name()
       << endl;

  Squirrel peanuts = Squirrel("Peanuts");
  Node node_four = Node(&peanuts);

  Squirrel garden_destroyer = Squirrel("Garden Destroyer");
  Node node_five = Node(&garden_destroyer);

  node_three.set_left(&node_four);
  node_three.set_right(&node_five);

  cout << "The children of Mr. Fluffy Butt are "
       << node_one.right_node().right_node().data->get_name()
       << " and "
       << node_one.right_node().left_node().data->get_name()
       << endl;
}