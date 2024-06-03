#ifndef TREE_H
#define TREE_H

#include <vector>
#include <functional>
#include <algorithm>

template<typename T>
class TreeNode {
public:
	T value;
	std::vector<TreeNode*> children;

	TreeNode(T val) : value(val) {}

	~TreeNode() {
		for (auto child : children) {
			delete child;
		}
	}
};

template<typename T>
class Tree {
private:
	TreeNode<T>* root;
public:
	Tree() : root(nullptr) {}

	~Tree() {
		delete root;
	}

	void add_node(TreeNode<T>* parent, T value) {
		TreeNode<T>* newNode = new TreeNode<T>(value);
		if (parent == nullptr) {
			root = newNode;
		}
		else {
			parent->children.push_back(newNode);
		}
	}

	TreeNode<T>* get_node(TreeNode<T>* parent) {
		return parent == nullptr ? root : parent;
	}
	void delete_node(TreeNode<T>* node) {
		if (node == nullptr) return;

		if (node == root) {
			delete root;
			root = nullptr;
		}
		else {
			for (auto& child : node->children) {
				delete_node(child);
			}
			node->children.clear();
		}
	}

	TreeNode<T>* find(TreeNode<T>* node, std::function<bool(const T&)> predicate) {
		if (node == nullptr) return nullptr;

		if (predicate(node->value)) return node;

		for (auto child : node->children) {
			TreeNode<T>* result = find(child, predicate);
			if (result != nullptr) return result;
		}

		return nullptr;
	}

	void insert(TreeNode<T>* parent, size_t index, T value) {
		if (parent == nullptr) return;

		TreeNode<T>* newNode = new TreeNode<T>(value);
		if (index >= parent->children.size()) {
			parent->children.push_back(newNode);
		}
		else {
			parent->children.insert(parent->children.begin() + index, newNode);
		}
	}

	void sort(TreeNode<T>* node, std::function<bool(const T&, const T&)> compare = nullptr) {
		if (node == nullptr) return;

		if (compare) {
			std::sort(node->children.begin(), node->children.end(),
				[compare](TreeNode<T>* a, TreeNode<T>* b) { return compare(a->value, b->value); });
		}
		else {
			std::sort(node->children.begin(), node->children.end(),
				[](TreeNode<T>* a, TreeNode<T>* b) { return a->value < b->value; });
		}
	}

	size_t count(TreeNode<T>* node) {
		if (node == nullptr) return 0;

		size_t total = node->children.size();
		for (auto child : node->children) {
			total += count(child);
		}
		return total;
	}
};

#endif // !TREE_H


