import java.util.*;

class rectangle{

    int l;
    int b;

    rectangle(int l,int b){
        this.l=l;
        this.b=b;    
    }

    int area(){
        return this.l*this.b;
    }

    public String toString(){
        return Integer.toString(l)+" "+Integer.toString(b);
    }
}


//comparator function must implement Comparator interface
class mycomp implements Comparator<rectangle>{
    public int compare(rectangle r1, rectangle r2){
        return r1.l-r2.l;
    }
}

public class sorts {
    public static void main(String args[]){
        ArrayList<rectangle> R=new ArrayList<rectangle>();
        R.add(new rectangle(10, 20));
        R.add(new rectangle(1,20));
        R.add(new rectangle(30,20));

        Collections.sort(R,new mycomp());
        for (Iterator<rectangle> it=R.iterator(); it.hasNext();){
            System.out.println(it.next());
        }
        
    }
}
