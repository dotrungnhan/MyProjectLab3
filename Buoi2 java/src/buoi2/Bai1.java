/*
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