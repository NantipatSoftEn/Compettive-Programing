import java.io.*; 
import java.util.Scanner;
class Main {
    public static void main(String args[]) throws Exception {
        File file = new File("input.txt"); 
        BufferedReader br = new BufferedReader(new FileReader(file)); 
        

            String age =  br.readLine(); 
            String[] g = age.split(" ");
            System.out.println("age: "+g[1]); 

    
  

        
    }
}