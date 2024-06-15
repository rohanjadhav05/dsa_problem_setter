import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class solution1 {

    public static boolean isIsomorphic(String s, String t){
        Map<Character,Character> map = new HashMap<>();
        for(int i = 0; i < s.length(); i++){
            if(!map.containsKey(s.charAt(i))){
                if(map.containsValue(t.charAt(i))){
                    return false;
                }else{
                    map.put(s.charAt(i),t.charAt(i));
                }
            }else if(map.get(s.charAt(i)) != t.charAt(i)){
                return false;
            }
        }
        return true;
    }

    public static void main(String []args){
        try {
            File file = new File("test.txt");
            Scanner scanner = new Scanner(file);

            int testCaseNumber = 1;
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine().trim();
                if (line.isEmpty() || line.startsWith("//")) {
                    continue;
                }

                String[] parts = line.split("Output : ");
                String input = parts[0].trim();
                boolean expectedOutput = Boolean.parseBoolean(parts[1].trim());
                
                String[] inputs = input.split(",");
                String s = inputs[0];
                String t = inputs[1];

                boolean result = isIsomorphic(s, t);
                if(result == expectedOutput){
                    System.out.println("Test Case Passed : "+testCaseNumber+" -> Input : [ s = "+s+", t = "+t+" ], Output : "+result);
                }
                else{
                    System.out.println("Test Case Failed : "+testCaseNumber+", Expected : "+expectedOutput+", Output : "+result+" [FAILED]");
                }
                testCaseNumber++;
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            System.err.println("File 'test.txt' not found.");
            e.printStackTrace();
        }
    }
}
