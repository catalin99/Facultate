#include <iostream>
using namespace std;

struct TreeNode
{
int val;
TreeNode *left;
TreeNode *right;
};

struct Tati
{
    TreeNode vectortati[1000];
} *nivel[100];

int minDepth(TreeNode *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL || root->right==NULL)
        return 1;
    int i=0;
    int dimensiune=1;
    nivel[i].vectortati[0]->val=1; //retine dimensiunea vectorului de tati pe pozitia 0;
    nivel[i].vectortati[1]->val=root->val;
    int ok=1; int counter=1;
    while(ok)
    {
        for(int j=1; j<=nivel[i].vectortati[0]->val; j++)
            if(nivel[i].vectortati[j]->left==NULL || nivel[i].vectortati[j]->right==NULL)
            {
                ok=0;
                break;
            }
        if(ok)
        {
            i++;
            int k=1; j=1;
            while(k<=nivel[i-1].vectortati[0]->val)
            {
                 nivel[i].vectortati[j]->val=nivel[i-1].vectortati[k]->left->val;
                 k++;
                 j++;
                 nivel[i].vectortati[j->val]=nivel[i-1].vectortati[k]->right->val;
                 k++;
                 j++;
            }
            nivel[i].vectortati[0]->val=k-1;
        }
        counter++;
    }
    return counter;

}

TreeNode *creare()
{
    int x;
    cin>>x;
    TreeNode *q=new TreeNode;
    if(x!=0)
    {
        q->val=x;
        q->left=creare();
        q->right=creare();
    }
    else q=NULL;
    return q;
}

int main()
{
    TreeNode*q=new TreeNode;
    q=creare();
    return 0;
}
