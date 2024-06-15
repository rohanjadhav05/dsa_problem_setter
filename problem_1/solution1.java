import java.io.*;
import java.util.*;

public class solution1{
    public static void main(String []args){
        try(BufferedReader br = new BufferedReader(new FileReader("test.txt"))){
            String line;
            while((line = br.readLine()) != null){
                String []part = line.split(" ");
                int size = Integer.parseInt(part[0]);
                int []arr = new int[size];
                
                for(int i = 0; i < size; i++){
                    arr[i] = Integer.parseInt(part[i+1]);
                }

                int sum = Integer.parseInt(part[size+1]);
                boolean expected = Boolean.parseBoolean(part[size+2]);
                boolean ans  = pairWithSum(arr, sum);

                if(ans == expected){
                    System.out.println("Test Case Passed -> Input : "+Arrays.toString(arr)+", Output : "+ans);
                }else{
                    System.out.println("Test Case Failed, Expected : "+expected+", Output : "+ans);
                }
            }
        }catch(IOException e){

            e.printStackTrace();
        }
    }

    public static boolean pairWithSum(int []arr, int sum){
        Set<Integer>  set = new HashSet<>();
        for(int i : arr){
            if(set.contains(i)){
                return true;
            }
            else{
                set.add(sum-i);
            }
        }
        return false;
    }
}