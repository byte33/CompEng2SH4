public class Point {
    private int x;
    private int y;
    private static int count = 0;

    public Point(int xV, int yV) {
        set(xV,yV);
        count++;
    }

    public void set(int xV, int yV) {x = xV;y = yV;}
    public int getX() {return x;}
    public int getY() {return y;}
    public static int getCount() {return count;}
}