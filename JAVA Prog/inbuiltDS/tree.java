
class node {
    int val;
    node left;
    node right;

    node(int data){
        this.val=data;
    }
}

class bst{
    node root;
    bst(){
        this.root=null;
    }

    node insert(node temp,int ele){
        if(temp==null){
            return new node(ele);
        }

        if(ele<temp.val){
            temp.left=insert(temp.left,ele);
        }
        else{
            temp.right=insert(temp.right,ele);
        }
        return temp;

    }
}

public class tree{

    public static void main(String args[]){
        bst t=new bst();
        t.root=t.insert(t.root,10);
        t.root=t.insert(t.root,5);
        t.root=t.insert(t.root,20);

        System.out.println(t.root.right.val);
    }
}