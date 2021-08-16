package mypackage;
public class stack{
    static final int Max=1000;
    char[] A;
    int top;
    stack(){
        this.top=-1;
        this.A=new char[Max];
    }

    void push(char c){
        A[top++]=c;
    }

    boolean isempty(){
        return (top==-1);
    }

    char pop(){
        if(top==-1){
            System.out.println("Stack Empty");
            return '-';
        }
        else{
            return A[top--];
        }
    }
    char peek(){
        if(top==-1){
            System.out.println("Stack Empty");
            return '-';
        }
        else{
            return A[top];
        }
    }
}