import java.util.*;

public class pppp {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        int[] something = new int[10];
        for(int i=1; i<=10; ++i) something[i-1] = i;

        for(int i=0; i<5; ++i) {
            int temp = something[i];
            something[i] = something[9-i];
            something[9-i] = temp;
        }

        for(int i=0; i<10; ++i) System.out.printf("%d ", something[i]);
        System.out.println();

        in.close();
    }
}
