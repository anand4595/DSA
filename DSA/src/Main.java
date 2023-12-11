public class Main {
    public static int usingBinarySearchIterative(int[] a, int n, int x) {
        int s = 0;
        int e = n - 1;
        int ans = -1;
        while (s <= e) {
            int mid = (s + e) / 2;
            System.out.println("- - - - -");
            System.out.println("s=" +  s + " mid=" + mid + " e=" + e);
            System.out.println("a[mid]= " + a[mid]);
            if (a[mid] == x) {
                return a[mid];
            } else if (a[mid] < x) {
                s = mid + 1;
            } else {
                ans = e;
                e = mid - 1;
            }
        }
        return ans == -1 ? -1 : a[ans];

    }
    public static void main(String[] args) {
        int x = 2;
        int n = 6;
        int []a  = {3 ,4, 4, 7, 8, 10};
        System.out.println(usingBinarySearchIterative(a,n, x));
    }
}