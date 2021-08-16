"""Node* new_node(int);
Node* insert(Node*,int);
void inorder(Node*);
Node* del(Node*,int key);
bool search(Node*,int key);
Node* inorder_succ(Node*);"""

class node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None
    
class bst:
    def __init__(self):
        self.root=None


    def insertele(self,x):

        def insert(root,x):
            if(root is None):
                return node(x)
            elif(x<root.data):
                root.left=insert(root.left,x)
            else:
                root.right=insert(root.right,x)
            return root
       
        root=self.root
        self.root=insert(root,x)

    
    
    def inorder_traversal(self):
        def inorder(root):
            if(root is None):
                return
            inorder(root.left)
            print(root.data)
            inorder(root.right)

        root=self.root
        inorder(root)

    def search(self,x):
        def searchintree(root,x):
            if(root is None):
                return None
            if(root.data==x):
                return root
            elif(x<root.data):
                return searchintree(root.left,x)
            else:
                return searchintree(root.right,x)
        
        root=self.root
        return searchintree(root,x)
    
        
    def inordersuccessor(self,root):
        root=root.right
        if(root is None):
            return root
        while(root.left is not None):
            root=root.left
        return root
    
    def deleteele(self,x):

        def delete(root,x):
            if(root is None):
                #x doesnt exist in tree
                return None
            if(x<root.data):
                root.left=delete(root.left,x)
            elif(x>root.data):
                root.right=delete(root.right,x)
            else:
                #delete this root ele
                #Note: if any of the left or right subtree is None. just make this the other subtree as root. no need to find inorder succ
                #Note: u only need to find inorder succ to delete when both left and right subtrees exist
                if(root.left is None):
                    return root.right
                elif(root.right is None):
                    return root.left
                else:
                    ino_succ=self.inordersuccessor(root)
                    root.data=ino_succ.data
                    delete(root.right,ino_succ.data)

        root=self.root
        root=delete(root,x)






        
        


        
T=bst()

T.insertele(2)
T.insertele(1)
T.insertele(4)
T.insertele(3)


T.deleteele(2)
T.inorder_traversal()