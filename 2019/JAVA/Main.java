import java.io.*; 
import java.util.Scanner;
class Main {
    public static void main(String args[]) throws Exception {
        File file = new File("input.txt"); 
        BufferedReader br = new BufferedReader(new FileReader(file)); 
            String line =  br.readLine(); 
            String[] n = line.split(" ");
            System.out.println("age: "+n[1]); 
    }
}