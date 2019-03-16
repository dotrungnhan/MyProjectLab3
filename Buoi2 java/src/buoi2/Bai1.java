<<<<<<< .mine/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package buoi2;
import java.io.*;
import java.util.*;
/**
 *
 * @author Administrator
 */
public class Bai1 {
    private static Scanner x = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.print("Nhap a: ");
        int a = x.nextInt();
        System.out.print("Nhap b: ");
        int b = x.nextInt();
        System.out.print("Nhap c: ");
        int c = x.nextInt();
        PTB2(a,b,c);
    }
    public static void PTB2(int a, int b, int c){
        if (a==0){
            if(b==0){
                System.out.println("ptvn!");
            }else{
                System.out.println("pt co 1 ng: " +(-c/b));
            }
            return;
        }
        float delta = b*b - 4*a*c;
        float x1,x2;
        if(delta > 0){
            x1 = (float) ((-b + Math.sqrt(delta))/(2*a));
            x2 = (float) ((-b - Math.sqrt(delta))/(2*a));
            System.out.println("pt co 2 ng la: "+x1+x2);
        }else if (delta == 0){
            x1 = (-b/(2*a));
            System.out.println("pt co ng kep: "+x1);
        }else{
            System.out.println("ptvn!");
        }
    }
}
////////////////////
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package buoi2;
import java.util.*;
/**
 *
 * @author dell
 */
public class Bai5 {
    public static void timChuoiMax(String strInput)
    {
        StringTokenizer strToken = new StringTokenizer(strInput,",\t,\r");
        int Max,i=1,lengthStr;
        Max = strToken.nextToken().length();
        int vitriMax = i;
        while(strToken.hasMoreTokens())
        {
            lengthStr= strToken.nextToken().length();
            i++;
            if(Max < lengthStr)
            {
                Max = lengthStr;
                vitriMax = i;
            }
        }
        System.out.println("do dai chuoi lon nhat la: " + Max + " o vi tri " + vitriMax);
    }
        public static void main(String[] args)
        {
            Scanner s = new Scanner(System.in);
        System.out.print("nhap 1 chuoi: ");
        String strInput = s.nextLine();
            timChuoiMax(strInput);
        }
    }

=======/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package buoi2;
import java.io.*;
import java.util.*;
/**
 *
 * @author Administrator
 */
public class Bai1 {
    private static Scanner x = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.print("Nhap a: ");
        int a = x.nextInt();
        System.out.print("Nhap b: ");
        int b = x.nextInt();
        System.out.print("Nhap c: ");
        int c = x.nextInt();
        PTB2(a,b,c);
    }
    public static void PTB2(int a, int b, int c){
        if (a==0){
            if(b==0){
                System.out.println("ptvn!");
            }else{
                System.out.println("pt co 1 ng: " +(-c/b));
            }
            return;
        }
        float delta = b*b - 4*a*c;
        float x1,x2;
        if(delta > 0){
            x1 = (float) ((-b + Math.sqrt(delta))/(2*a));
            x2 = (float) ((-b - Math.sqrt(delta))/(2*a));
            System.out.println("pt co 2 ng la: "+x1+x2);
        }else if (delta == 0){
            x1 = (-b/(2*a));
            System.out.println("pt co ng kep: "+x1);
        }else{
            System.out.println("ptvn!");
        }
    }
}>>>>>>> .theirs