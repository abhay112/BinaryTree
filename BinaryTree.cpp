#include <bits/stdc++.h>
using namespace std;

template <typename t>
class BinaryTreeNode{
    public:
    t data;
    BinaryTreeNode *left;
    BinaryTreeNode * right;
    BinaryTreeNode(t data){
        left = NULL;
        right = NULL;
        this -> data = data;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
    
};

void printTree(BinaryTreeNode<int>*root){
    if(!root)    
        return ;
    cout<< root -> data <<", ";
    if(root->left!=NULL){
        cout << " L: "<< root->left->data;
    }if(root->right){
        cout << " R: "<< root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int>*takeInput(){
    int rootData;
    cout << "Enter Data: " << endl;
    cin >> rootData;
    if(rootData==-1)
        return NULL;
    BinaryTreeNode<int>*root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>*leftChild = takeInput();
    BinaryTreeNode<int>*rightChild = takeInput();
    root ->left = leftChild;
    root->right = rightChild;
    return root;
}
BinaryTreeNode<int>* takeInputLevelWise(){
    int rootdata;
    cout << "Enter root Data "<< endl;
    cin >> rootdata;
    if(rootdata ==-1)
        return NULL;
        
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left Child of "<< front->data << endl;
        int leftChildData; cin >> leftChildData;
        if(leftChildData!=-1){
            BinaryTreeNode<int>*child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter Right Child of "<< front->data << endl;
        int rightChildData; cin >> rightChildData;
        if(rightChildData!=-1){
            BinaryTreeNode<int>*child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void inorder(BinaryTreeNode<int>* root){
   if(root==NULL)
        return;
   inorder(root->left);
   cout<<root->data<<" ";
   inorder(root->right);

}

void preOrder(BinaryTreeNode<int> *root) {
    if(root==NULL)
            return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTreeNode<int> *root) {
    if(root==NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

}
int height(BinaryTreeNode<int>* root){
    if(root == NULL)
        return 0;
   return max(height(root->left),height(root->right))+1;
}
void printLevelWise(BinaryTreeNode<int>* root,int k){
    if(root == NULL)
        return ;
    if(k == 1){
        cout << root -> data <<" ";
        return;
    }
    printLevelWise(root->left,k-1);
    printLevelWise(root->right,k-1);
}
void printKthLevel(BinaryTreeNode<int>* root){
    int h = height(root);
    for(int i = 1;i <= h; i++){
        printLevelWise(root,i);
        cout << endl;
    }
}

// print level wise using Iterative approach
// breath first search
void bfs(BinaryTreeNode<int>*root){
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>* front = q.front();
        cout << front -> data <<" ";
        q.pop();
        if(front->left){
            q.push(front->left);
        }
        if(front->right)
            q.push(front->right);
        
    }
    return;
}

void bfsNextLine(BinaryTreeNode<int>*root){
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BinaryTreeNode<int>* front = q.front();
        if(front == NULL){
            cout << endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << front -> data <<" ";
            q.pop();
            if(front->left){
                q.push(front->left);
            }
            if(front->right)
                q.push(front->right);
        }
        
    }
    return;
}

// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
int main() {
    // BinaryTreeNode<int>*root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>*node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>*node2 = new BinaryTreeNode<int>(9);

    // root->left = node1;
    // root->right = node2;
  //  BinaryTreeNode<int>*root= takeInput();
     BinaryTreeNode<int>* root = takeInputLevelWise();
       /*  printTree(root);
		cout  << endl;
        cout << endl<<"InOrderd ";
        inorder(root);
        cout << endl<<"preOrderd ";
        preOrder(root);
        cout << endl<<"postOrderd ";
        postOrder(root);
        */
        
       printKthLevel(root);
       cout << endl;
       bfs(root);
       cout << endl;
       
        bfsNextLine(root);
        cout << endl;
}
