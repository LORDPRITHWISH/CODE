#include<iostream>
#include<cstdlib>


struct node
{
    public:
    int data;
    node *left=NULL;
    node *right=NULL;
};

node *add(node *curr,int val)
{
    if(curr==NULL)
    {
        node *tmp = new node();
        tmp->data = val;
        return tmp;
    }

    if(curr->data>val)
    {
        if(curr->left)
            add(curr->left,val);
        else 
            curr->left=add(curr->left,val);
    }        
    else
    {
        if(curr->right)
            add(curr->right,val);
        else 
            curr->right=add(curr->right,val);
    }
    return NULL;    
}

void printinorder(node *curr)
{
    if(curr==NULL)
        return;
    printinorder(curr->left);
    std::cout<<curr->data<<"\n";
    printinorder(curr->right);
}

int main()
{
    node *root = add(NULL,100);
    for(int i=0;i<10;i++)
        add(root,rand()%1000);

    printinorder(root);
    
    return 0;
}
