import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class phonelist {

    static  boolean checkConsistency(ArrayList<String> phoneBook,int length){

        for (int i = 0; i < length -1; i++) {
            if(phoneBook.get(i+1).startsWith(phoneBook.get(i))){
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        ArrayList<String> phoneBook = new ArrayList<String>();
        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();
        
        for (int i = 0; i < cases; i++){

            int length = in.nextInt();
            if(length > 0){
                for (int j = 0; j < length; j++){

                    phoneBook.add(in.next());
                } 
                Collections.sort(phoneBook);
                if(checkConsistency(phoneBook,length)){
                    System.out.println("YES");
                }
                else{
                    System.out.println("NO");
                }
                phoneBook.clear();
            }
        }
    }
}