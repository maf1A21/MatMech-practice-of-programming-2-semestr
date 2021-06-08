#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Search_tree
{
private:
    struct node
    {
        int key;
        node* parent = nullptr;
        node* heir1 = nullptr;
        node* heir2 = nullptr;
        node(int k, node* par =nullptr, node* h1 = nullptr, node* h2 = nullptr);
    };
    node * p;
    void destroy_tree(node *leaf);
    vector <int> sort(node *leaf, vector<int> &vec);
    void bfs(vector<vector<int> > &V, int depth=0, node*pv = nullptr);

public:
    void destroy_tree();
    Search_tree(int k);
    ~Search_tree();
    void insert(int k);
    bool find(int k);
    vector <int> sort();
    void bfs();
};

Search_tree::node::node(int k, node* par, node* h1, node* h2)
{
    this->key = k;
    this->parent = par;
    this->heir1 = h1;
    this->heir2 = h2;
}

Search_tree::Search_tree(int k)
{
    p = new node(k, nullptr, nullptr, nullptr);
}

Search_tree::~Search_tree()
{
    destroy_tree();
}

void Search_tree::destroy_tree(node *leaf)
{
    if (leaf != nullptr)
    {
        destroy_tree(leaf->heir1);
        destroy_tree(leaf->heir2);
        delete leaf;
    }
}

void Search_tree::destroy_tree()
{
    destroy_tree(p);
}


void Search_tree::insert(int k)
{
    node * tmp = p;
    while ((tmp->heir1 != nullptr) || (tmp->heir2 != nullptr))
    {
        if (k < tmp->key)
        {
            if (tmp->heir1 != nullptr)
                tmp = tmp->heir1;
            else
                break;
        }
        else
        {
            if (tmp->heir2 != nullptr)
                tmp = tmp->heir2;
            else
                break;
        }
    }

    node *new_node = new node(k, tmp, nullptr, nullptr);
    new_node->key = k;

    if (k < tmp->key)
        tmp->heir1 = new_node;
    else
        tmp->heir2 = new_node;
}


bool Search_tree::find(int k)
{
    node * tmp = p;
    while ((tmp->heir1 != nullptr) || (tmp->heir2 != nullptr))
    {
        if (tmp->key == k)
            break;
        if (k < tmp->key)
        {
            if (tmp->heir1 != nullptr)
                tmp = tmp->heir1;
            else
                break;
        }
        else
        {
            if (tmp->heir2 != nullptr)
                tmp = tmp->heir2;
            else
                break;
        }
    }
    if (tmp->key == k)
        return true;
    return false;
};

vector <int> Search_tree::sort(node *leaf, vector<int> & vec)
{
    if (leaf != nullptr)
    {
        if (leaf->heir1 != nullptr)
            vec = sort(leaf->heir1, vec);
        vec.push_back(leaf->key);
        if (leaf->heir2 != nullptr)
            vec = sort(leaf->heir2, vec);
    }
    return vec;

}

vector <int> Search_tree::sort()
{
    vector<int> vec;
    vector<int> res = sort(p, vec);
    return res;
}


void Search_tree::bfs(vector<vector<int>> &V, int depth, node* pv)
{
    if (pv == NULL)
        pv = p;
    if (depth == V.size()) V.push_back({});
    V[depth].push_back(pv->key);
    if (pv->heir1 != NULL)
        bfs(V, depth+1, pv->heir1);
    if (pv->heir2 != NULL)
        bfs(V, depth+1, pv->heir2);
}

void Search_tree::bfs()
{
    vector<vector<int>> res;
    bfs(res);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    return 0;
}
