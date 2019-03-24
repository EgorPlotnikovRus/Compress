#include "head.h"

class Node
{
public:
    int a;
    char c;
    Node *left, *right;

    Node(){left = right = NULL;}

    Node(Node *L, Node *R)
    {
        left = L;
        right = R;
        a = L -> a + R -> a;
    }

};

struct MyCompare
{
    bool operator()(const Node* l, const Node* r) const { return l -> a < r -> a; }
};

vector<bool> code;
map<char, vector<bool>> tbl;

void BuildTable(Node *root)
{
    if(root -> right != NULL)
    {
        code.push_back(1);
        BuildTable(root -> right);
    }

    if(root -> left != NULL)
    {
        code.push_back(0);
        BuildTable(root -> left);
    }

    if(root -> left == NULL && root -> right == NULL)
        tbl[root -> c] = code;

    code.pop_back();
}

void compress(string InF, string OuF)
{
    map <char, int> table;
    map <char, int>::iterator it;

    ifstream file;
    file.open(InF);

    while (!file.eof())
    {
       char c = file.get();
       if(!file.eof() && c != '\n')
       ++table[c];
    }

    file.close();

    list<Node*> t;

    for(it = table.begin(); it != table.end(); ++it)
    {
        Node *p = new Node;
        p -> c = it -> first;
        p -> a = it -> second;
        t.push_back(p);

    }

    while(t.size() != 1)
    {
        t.sort(MyCompare());

        Node *SonL = t.front();
        t.pop_front();
        Node *SonR = t.front();
        t.pop_front();

        Node *parent = new Node(SonL, SonR);
        t.push_back(parent);
    }

    Node *root = t.front();

    BuildTable(root);

    ofstream g;
    g.open(OuF);
    file.open(InF);

    int count = 0;
    char buf = 0;
    while (!file.eof())
    {
        char c = file.get();
        vector<bool> x = tbl[c];
        for(int n=0; n < x.size(); ++n)
            {buf = buf | x[n] << (7 - count);
        count++;
        if (count == 8) {count = 0; g << buf; buf = 0; }
       }
    }

    map<char, vector<bool> >::iterator iter = tbl.begin();
    for(++iter; iter != tbl.end(); ++iter)
        g << iter -> first << iter -> second;

    file.close();
    g.close();
}
