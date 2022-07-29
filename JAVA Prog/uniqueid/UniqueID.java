package uniqueid;
import java.util.HashMap;
import java.util.Random;

class IdGenerator{
    
    HashMap<Integer,Integer> map;
    IdGenerator(){
        this.map=new HashMap<>();
    }

    String getNextId(int year){
        int lastid=map.getOrDefault(year,0);
        int newid=lastid+1;
        map.put(year,newid);
        return Integer.toString(year)+"-"+String.format("%06d",newid);
    }
}

public class UniqueID{
    public static int getYear(){
        Random rand=new Random();
        //generate random year between 2010 and 2030
        int year=rand.nextInt(2030-2010)+2010;
        return year;
    }
    public static void main(String args[]){
        IdGenerator id=new IdGenerator();
        for(int i=0;i<10;i++){
        int year=getYear();
        System.out.println(id.getNextId(year));
        }
    }
}

// We can delete id of years older than 5 years from today to keep memory from running out.