#include <iostream>
#include "Tree.h"
using namespace std;

// Kelvin to Celsius
float operator"" _Kelvin(unsigned long long kelvin) {
    return static_cast<float>(kelvin - 273.15);
}

// Fahrenheit to Celsius
float operator"" _Fahrenheit(unsigned long long fahrenheit) {
    return static_cast<float>((fahrenheit - 32) * 5.0 / 9.0);
}

int main() {
    // Ex. 1
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    cout << "300K = " << a << " C\n";
    cout << "120F = " << b << " C\n";

    // Ex. 2
    Tree<int> intTree;

    intTree.add_node(nullptr, 1);
    TreeNode<int>* root = intTree.get_node(nullptr);

    intTree.add_node(root, 2);
    intTree.add_node(root, 3);
    intTree.add_node(root->children[0], 4);
    intTree.add_node(root->children[0], 5);

    TreeNode<int>* foundNode = intTree.find(root, [](const int& value) { return value == 3; });
    if (foundNode) {
        cout << "Found node with value: " << foundNode->value << "\n";
    }

    size_t totalCount = intTree.count(root);
    cout << "Total number of nodes: " << totalCount << "\n";
    return 0;
}