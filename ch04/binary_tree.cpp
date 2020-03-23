#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <random>
#include <queue>

using namespace std;

class Node
{
public:
    Node *left_child, *right_child;
    int data;

    Node()
    {
        left_child = NULL;
        right_child = NULL;
        data = -1;
    }
};

class BinarySearchTree
{
public:
    Node* root;

    BinarySearchTree()
    {
        root = new Node();
    }

    Node* search(int key)
    {
        Node* current = root;
        while (current != NULL)
        {
            if (current->data == key)
            {
                break;
            }
            else if (current->data > key)
            {
                current = current->left_child;
            }
            else
            {
                current = current->right_child;
            }
        }
        return current;
    }

    void insert(int d)
    {
        Node* current = root;
        // root has no data
        if (current->data == -1)
        {
            current->data = d;
            return;
        }
        while (!(current == NULL))
        {
            if (current->data > d)
            {
                if (current->left_child == NULL)
                {
                    Node* new_node = new Node();
                    new_node->data = d;
                    current->left_child = new_node;
                    break;
                }
                else // (current has a left_child)
                {
                    current = current->left_child;
                }
            }
            else // (current->data <= d)
            {
                if (current->right_child == NULL)
                {
                    Node* new_node = new Node();
                    new_node->data = d;
                    current->right_child = new_node;
                    break;
                }
                else // (current has a right_child)
                {
                    current = current->right_child;
                }
            }
        }
        return;
    }

    void erase(int key)
    {
        Node* current = root;
        Node* parent = NULL;
        while (current->data != key && current != NULL)
        {
            parent = current;

            if (current->data > key)
            {
                if (current->left_child == NULL) break;
                else current = current->left_child;
            }
            else
            {
                if (current->right_child == NULL) break;
                else current = current->right_child;
            }
        }
        // no node which has key data
        if (current == NULL) return;

        // current is a leaf
        if (current->left_child == NULL && current->right_child == NULL)
        {
            if (current == parent->left_child)
            {
                parent->left_child = NULL;
            }
            else if (current == parent->right_child)
            {
                parent->right_child = NULL;
            }
            delete current;
        }
        // current has a child
        else if (current->left_child == NULL || current->right_child == NULL)
        {
            if (current->left_child == NULL)
            {
                if (current == parent->left_child)
                {
                    parent->left_child = current->right_child;
                }
                else if (current == parent->right_child)
                {
                    parent->right_child = current->right_child;
                }
            }
            else // current has a left child
            {
                if (current == parent->left_child)
                {
                    parent->left_child = current->left_child;
                }
                else // (current == parent->right_child)
                {
                    parent->right_child = current->left_child;
                }
            }
        }
        // current has both left and right children
        else
        {
            // the node which substitutes for the deletion node
            Node* sub_node = current->right_child;
            while (sub_node->left_child != NULL)
            {
                parent = sub_node;
                sub_node = sub_node->left_child;
            }
            current->data = sub_node->data;
            // the right_child of the node for deletion has no left child 
            if (sub_node == current->right_child)
            {
                current->right_child = sub_node->right_child;
            }
            else
            {
                parent->left_child = sub_node->right_child;
            }
            delete sub_node;
        }
    }

    // traverse tree nodes by bsf and print the data
    void print_tree()
    {
        Node* current;
        queue<Node*> q;
        cout << root->data << endl;
        if (root->left_child  != NULL) q.push(root->left_child);
        if (root->right_child != NULL) q.push(root->right_child);
        while (!q.empty())
        {
            current = q.front(); q.pop();
            cout << current->data << endl;
            if (current->left_child  != NULL) q.push(current->left_child);
            if (current->right_child != NULL) q.push(current->right_child);
        }
    }

    int min()
    {
        Node* current = root;
        while (current->left_child != NULL)
        {
            current = current->left_child;
        }
        return current->data;
    }
};

void shuffle_vector(vector<int>&);
int random_number(int, int);
void random_number(vector<int>&, int, int);
void quick_sort(vector<int>&, const int, const int);
int binary_search(vector<int>&, int key);
void print_array(vector<int>&);
void output_plotdata(const char* filename, vector<int>&);

int main()
{
    BinarySearchTree *BST = new BinarySearchTree();
    int S[11] = {59, 38, 7, 42, 16, 81, 4, 32, 95, 18, 25};
    for (int i = 0; i < 11; i++)
    {
        BST->insert(S[i]);
    }
    BST->insert(23);
    BST->erase(38);
    BST->print_tree();
    cout << "---" << endl;
    BST->erase(59);
    BST->print_tree();
    cout << "min :" << BST->min() << endl;
    BST->erase(4);
    cout << "erase 4" << endl;
    BST->print_tree();
    cout << "---" << endl;
    cout << "min :" << BST->min() << endl;
    return 0;
}

void shuffle_vector(vector<int>& v)
{
    random_device seed_gen;
    mt19937 engine(seed_gen());
    shuffle(v.begin(), v.end(), engine);
}

int random_number(int min, int max)
{
    int r;
    random_device seed_gen;
    mt19937 engine(seed_gen());
    uniform_int_distribution<> rand(min, max);
    r = rand(engine);
    return r;
}

void random_number(vector<int>& v, int min, int max)
{
    random_device seed_gen;
    mt19937 engine(seed_gen());
    uniform_int_distribution<> rand(min+1, max+1);
    for (int i = 0; i < v.size(); i++) v[i] = rand(engine);
}

void quick_sort(vector<int>& v, const int left, const int right)
{
    int left_idx = left + 1, right_idx = right;
    int pivot_idx = left;
    int partition;
    if (left < right)
    {
        while (left_idx <= right_idx)
        {
            while (v[left_idx] < v[pivot_idx]) left_idx++;
            while (v[right_idx] > v[pivot_idx]) right_idx--;
            if (left_idx <= right_idx)
            {
                swap(v[left_idx++], v[right_idx--]);
            }
        }
        partition = right_idx;
        swap(v[pivot_idx], v[partition]);
        quick_sort(v, left, partition - 1);
        quick_sort(v, partition + 1, right);
    }
}

int binary_search(vector<int>& v, int key)
{
    int pos = -1;
    int left, right, mid;
    left = 0;
    right = v.size() - 1;
    mid = (right + left) / 2;
    while (left <= right)
    {
        if (v[mid] == key)
        {
            pos = mid;
            break;
        }
        else
        {
            if (v[mid] > key)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
            mid = (right + left) / 2;
        }
    }
    return pos;
}

void print_array(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void output_plotdata(const char* filename, vector<int>& v)
{
    ofstream ofs(filename);
    for (int i = 0; i < v.size(); i++)
    {
        ofs << i+1 << " " << v[i] << endl;
    }
}