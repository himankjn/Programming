import java.util.*;

class structs{
    public static void main(String args[]){
        //Stack
        Stack<Integer> stk=new Stack<Integer>();
        stk.push(10);
        stk.push(20);
        stk.push(30);
        stk.pop();
        stk.pop();
        stk.pop();
        if(stk.empty()==true){
            System.out.println("empty");
        }

        //Queue
        Queue<Integer> q=new LinkedList<Integer>();
        q.add(20);
        q.add(40);
        q.add(30);
        q.remove();

        //minheap
        PriorityQueue<Integer> heap = new PriorityQueue<Integer>();
        //maxheap
        //PriorityQueue<Integer> heap = new PriorityQueue<>(Comparator.reverseOrder());
        heap.add(10);
        heap.add(20);
        heap.remove();
        if(heap.remove()==null){
            System.out.println("empty");
        }

        //List
        ArrayList<Integer> A=new ArrayList<Integer>();
        A.add(1);
        A.add(2);
        A.add(3);
        System.out.println(A.get(2));
        A.set(2,10);
        A.remove(1);//idx
        A.size();
        //arraylist to array of objects
        Object B[]=A.toArray();
    
        
        //hashmap

        HashMap<Integer,Integer> m=new HashMap<Integer,Integer>();
        m.put(1,2);
        m.get(1);
        m.getOrDefault(2, 0);
        m.isEmpty();

        
    }

}