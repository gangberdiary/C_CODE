#pragma once

#include <iostream>
#include <queue>

using namespace std;

template<class W>
struct HuffumanTreeNode
{
	HuffumanTreeNode(const W& weight = W())
		: parent_(nullptr)
		, left_(nullptr)
		, right_(nullptr)
		, weight_(weight)
	{}
	HuffumanTreeNode<W>* parent_;
	HuffumanTreeNode<W>* left_;
	HuffumanTreeNode<W>* right_;
	W weight_;
};

template<class W>
class HuffumanTree
{
	typedef HuffumanTreeNode<W> Node;
public:
	HuffumanTree()
		:root_(nullptr)
	{}

	~HuffumanTree()
	{
		Destory(root_);
	}

	struct Compare
	{
		bool operator()(const Node* left, const Node* right)
		{
			return left->weight_ > right->weight_;
		}
	};

	//建立哈夫曼树
	Node* CreatHuffumanTree(const std::vector<W>& weights, const W& invalid)
	{
		priority_queue<Node*, vector<Node*>, Compare> q;
		for (auto e : weights)
		{
			//出现次数为0则不进入队列
			if (e == invalid)
				continue;

			q.push(new Node(e));
		}

		while (q.size() > 1)
		{
			Node* left = q.top();
			q.pop();

			Node* right = q.top();
			q.pop();

			Node* parent = new Node(left->weight_ + right->weight_);
			parent->left_ = left;
			parent->right_ = right;

			left->parent_ = parent;
			right->parent_ = parent;
			q.push(parent);
		}

		root_ = q.top();
		return root_;
	}

	//获取根节点
	Node* GetRoot()
	{
		return root_;
	}

private:
	//销毁
	void Destory(Node* Proot)
	{
		if (Proot)
		{
			Destory(Proot->left_);
			Destory(Proot->right_);
			delete Proot;
			Proot = nullptr;
		}
	}

private:
	Node* root_;
};