#include <bits/stdc++.h>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;
    Node(int val) : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;
    void LL(Node* gp) //LL Rotation
    {
        Node* p = gp->right;
        Node* ggp = gp->parent;
        if (p->left != nullptr) 
        {
            p->left->parent = gp;
            gp->right = p->left;
        } else 
        {
            gp->right = nullptr;
        }
        p->parent = ggp;
        gp->parent = p;
        p->left = gp;
        if (ggp == nullptr) 
        {
            root = p;
        } else 
        {
            if (ggp->left == gp) 
            {
                ggp->left = p;
            } 
            else 
            {
                ggp->right = p;
            }
        }
        p->color = BLACK;
        gp->color = RED;
    }

    void RR(Node* gp) //RR roatation
    {
        Node* ggp = gp->parent;
        Node* p = gp->left;
        if (p->right != nullptr) 
        {
            p->right->parent = gp;
            gp->left = p->right;
        } 
        else {
            gp->left = nullptr;
        }
        p->parent = ggp;
        gp->parent = p;
        if (ggp == nullptr) {
            root = p;
        } else {
            if (ggp->left == gp) {
                ggp->left = p;
            } else {
                ggp->right = p;
            }
        }
        p->color = BLACK;
        gp->color = RED;
    }

    void RL(Node* gp) //RL rotation
    {
        Node* p = gp->right;
        Node* c = p->left;
        c->parent = gp;
        c->right = p;
        p->parent = c;
        gp->right = c;
        LL(gp);
    }

    void LR(Node* gp) //LR rotation
    {
        Node* p = gp->left;
        Node* c = p->right;
        c->parent = gp;
        c->left = p;
        p->parent = c;
        gp->left = c;
        RR(gp);
    }

    void fixInsertion(Node* newNode)//To check if the node is balanced
    {
        if(newNode==root){
            newNode->color=BLACK;
            return;
        }
        else if(newNode->parent->color==BLACK)return;//parent is black so return 
        Node* uncle;
        if (newNode->parent == newNode->parent->parent->left) {
            uncle = newNode->parent->parent->right;
        } else {
            uncle = newNode->parent->parent->left;
        }
        if (uncle != nullptr && uncle->color == RED) //Uncle is red so switching colors till grand parent
        {
            newNode->parent->color = BLACK;
            uncle->color = BLACK;
            newNode->parent->parent->color = RED;
            fixInsertion(newNode->parent->parent);
        }
        else//uncle color black so ratations
        {
        Node* p = newNode->parent;
        if (newNode == p->right) {
            if (p == p->parent->right) {
                LL(p->parent);
            } else {
                RL(p->parent);
            }
        } else {
            if (p == p->parent->left) {
                RR(p->parent);
            } else {
                LR(p->parent);
            }
        }
        }
    }
     void deleteNodes(Node* node) {
        if (node == nullptr)
            return;

        deleteNodes(node->left);
        deleteNodes(node->right);
        delete node;
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int val) //BST insertion
    {
        Node* newNode = new Node(val);
        Node* parent = nullptr;
        Node* current = root;

        while (current != nullptr) {
            parent = current;
            if (val < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        newNode->parent = parent;

        if (parent == nullptr) {
            root = newNode;
        } else if (val < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        fixInsertion(newNode);
    }

    vector<pair<int,Color>>level()//Level wise traversal
    {
        vector<pair<int,Color>>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                
                Node* u=q.front();
                ans.push_back({u->data,u->color});
                if(q.front()->left)
                {
                    q.push(q.front()->left);
                }
                if(q.front()->right)
                {
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }
        return ans;
    }
    ~RedBlackTree()
    {
        deleteNodes(root);
    }
};
