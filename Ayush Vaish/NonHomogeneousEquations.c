// To solve the system of Non-Homogeneous Equation and to calculate the values of x,y,z

import java.util.*;
class hacktober2
{
    int cal(int a[][])  //To calculate value of the determinant
    {
         int result = 0;
         result = a[0][0] * ((a[1][1]*a[2][2]) - (a[2][1]*a[1][2])) -a[0][1] * (a[1][0] * a[2][2] - a[2][0] * a[1][2]) + a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);
         return result;
    }
    int[][] change(int b[][], int pos, int r1, int r2, int r3)  // To get the determinants of delta1, delta2, delta3
    {
         b[pos][0] = r1;
         b[pos][1] = r2;
         b[pos][2] = r3;
         return b;
    }
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        hacktober2 ob = new hacktober2();
        System.out.println("Enter the coefficients of x, y,z all the equations");
        int a[][] = new int[3][3];
        for(int i = 0; i < 3; i++)      //To input values in 2-D array
        {
            for(int j = 0; j<3; j++)
            a[i][j] = sc.nextInt();
        }
        System.out.println("Enter the solutions of all the equations");
        int r1 = sc.nextInt();
        int r2 = sc.nextInt();
        int r3 = sc.nextInt();
        int del = ob.cal(a);                              // To find the determinants of Delta 1, Delta 2, Delta 3
        int[][] d1 = ob.change(a, 0, r1, r2, r3);       // And also to calculate their value stored in del1, del2, del3
        int del1 = ob.cal(d1);
        int[][] d2 = ob.change(a, 1, r1, r2, r3);       // And also to calculate their value stored in del1, del2, del3
        int del2 = ob.cal(d2);
        int[][] d3 = ob.change(a, 2, r1, r2, r3);       // And also to calculate their value stored in del1, del2, del3
        int del3 = ob.cal(d3);
        System.out.println(del);
    
        if(del!=0)                                      // To check if the equations are consistent or not
        {
            System.out.println("value of x = "+(del1/del));
            System.out.println("value of y = "+(del2/del));
            System.out.println("value of z = "+(del3/del));
        }
        else
        {
            if(del==0&&del1==0&&del2==0&&del3==0)
                System.out.println("System has infinitely many solution or no solution");
            else if((del==0)&&(((del1==del2)&&(del3!=0))||((del2==del3)&&(del1!=0))||((del1==del3)&&(del2!=0))))
                System.out.println("System has no solution");
        }
    }
}

