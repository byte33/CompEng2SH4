import java.util.Scanner;

public class Example2 {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int num1,num2,sum;

        System.out.println("Enter two integers");
        try {
            num1 = input.nextInt();
            num2 = input.nextInt();
            sum = num1+num2;
            System.out.printf("Sum is %d\n",sum);
        } catch(Exception e) {
            System.out.println("Error");
        }

        input.close();
        
    }
}