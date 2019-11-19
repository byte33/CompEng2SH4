public class quiz6 {
    
    private String name;
    private String dateOfBirth;
    private int year;
    private String[] courses;

    public quiz6(String a, String b, int c, String[] d) {

        this.name = a;
        this.dateOfBirth = b;
        this.year = c;
        this.courses = d;
        
    }
    public String getName() {return this.name;}
    public String[] getCourses() {return this.courses;}

    public static void main(String[] args) {
        String[] course = {"2sh4","2di4","2ci5"};
        quiz6 test = new quiz6("matteo","october 16th",2,course);

        String s = test.getName();
        String[] a = test.getCourses();
        System.out.println(s);
        for (int i=0;i<a.length;i++) {System.out.println(a[i]);}
        



    }
}