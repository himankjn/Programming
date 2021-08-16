
//The java runs out of heap space when N is >=pow(2,12)
//The first program didnt have this problem because the garbage collector was collecting the unused memory when new array is created every time
//We can increase JVM Heap size by:
//-Xms<size>        set initial Java heap size
//-Xmx<size>        set maximum Java heap size
//-Xss<size>        set java thread stack size

//java -Xms16m -Xmx64m ClassName

public class Test1 {
    public static void main (String args[] ) {
        int N = (int)Math.pow(2,10);
        int M = 100000;
        int[][] boxes=new int[N][];
        for(int i =0; i< N; i++) {
            int[] box = new int[M];
            boxes[i]=box;
        }
    }
}
