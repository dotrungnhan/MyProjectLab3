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
public class Bai2 {
    public static void main(String[] args) {
        Scanner x = new Scanner(System.in);
        System.out.print("Nhap n: ");
        int n = x.nextInt();
        int a[] = new int[n];
        nhapmang(a,n);
        System.out.println("Mang sau khi random la: ");
        xuatmang(a,n);  
    }
    static int ktnt(int n){
        int dem =0 ;
        for(int i=1;i<=n;i++){
            if(n%i==0)
                dem++;
        }
        if(dem==2)
            return 1;
        else
            return 0;
    }
    public static void nhapmang(int[]a,int n){
        Random x = new Random();
        for(int i=0;i<n;i++){
            a[i]=x.nextInt(100);
        }
    }
    public static void xuatmang(int[]a,int n){
        for(int i=0;i<n;i++){
            System.out.println(""+a[i]);
        }
        System.out.println("phan tu so ngto: ");
        for(int i=0;i<a.length;i++){
           if(a[i]>0){
               if(ktnt(a[i])==1)
                   System.out.print("\t"+a[i]);
           }
        }
    }
}
