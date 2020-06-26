
import java.util.*;

public class temp {
    static int n;

    static int[] add10(int[] arr) {
        int len = arr.length;
        int[] newarr = new int[len];
        if(arr[0]%2==0 && arr[0] > 100) newarr[0] = 0;
        else newarr[0] = arr[0];
        for(int i=1; i<len; ++i)
            if(arr[i]%2==0 && arr[i-1] > 100) newarr[i] = 0;
            else newarr[i] = arr[i];
        return newarr;

    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int[] a = new int[n];
        for(int i=0; i<n; ++i) a[i] = in.nextInt();

        int[] something = add10(a);
        for(int i=0; i<n; ++i) System.out.printf("%d ", something[i]);
        System.out.println();

        in.close();
    }
}
