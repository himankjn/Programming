import java.io.*;
import java.util.*;
import mypackage.stack;

class Matchingpar{
    public static void main(String args[]) throws Exception{
        
        File file=new File("par.txt");
        Scanner input=new Scanner(file);
        String data="";

        while (input.hasNextLine()) {
        data = input.nextLine();
      }

        int loc=0;
        stack stk=new stack();
        for (char c:data.toCharArray()){
            if(c=='(' || c=='{' || c=='['){
                stk.push(c);
                loc+=1;
            }
            else{
                if(stk.empty()){
                    System.out.printf("%s : %d","unbalanced at loc",loc);
                    System.exit(0);
                }
                char top=stk.pop();
                if(c==')' && top!='(' || c==']' && top!='[' || c=='}' && top!='{'){
                    System.out.printf("%s : %d","unbalanced at loc",loc);
                    System.exit(0);
                }
                else{
                    loc+=1;
                }
            }
        }
        if(stk.empty()==true){
            System.out.println("Balanced");
        }
        else{
            System.out.printf("%s : %d","unbalanced at loc",loc);
        }
    }
}