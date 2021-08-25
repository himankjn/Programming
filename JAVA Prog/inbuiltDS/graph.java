import java.util.*;

class Grph{
    public HashMap<String,HashMap<String,Integer>> m;
    Grph(){
        m=new HashMap<String,HashMap<String,Integer>>();
    }

    void addedge(String src,String dest,int wt){
        //weighted directed edge.
        //inner hashmap(dest)
        HashMap<String,Integer> val=m.getOrDefault(src, new HashMap<String,Integer>());
        val.put(dest,wt);
        //outer key(src)
        m.put(src,val);
    }
}
public class graph {
    public static void main(String args[]){
        Grph g=new Grph();
        g.addedge("A", "B", 2);
        g.addedge("B", "C", 3);
        g.addedge("A","C", 4);
        
        System.out.println(g.m);
        
    }
}
