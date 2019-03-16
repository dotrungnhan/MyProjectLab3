/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package buoi2;
/**
 *
 * @author Administrator
 */
import java.util.*;
import java.lang.*;

public class Bai3 {
    public static void main(String[] args) {
        Scanner x = new Scanner(System.in);     
        System.out.print("Nhap so dong: ");
        int n = x.nextInt();
        System.out.print("Nhap so cot: ");
        int m = x.nextInt();
        
        int a[][] = new int[n][m];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                a[i][j] = (int)(Math.random()*100);
            }
        }
        
        System.out.println("Xuat chuoi: ");
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                System.out.print(a[i][j] + " ");
            }
            
            System.out.println("");
        }
        
        System.out.print("Nhap so phan tu tren dong thu k: ");
        int k = x.nextInt();
        int s = 0;
        
        for(int j=0; j<m; j++){
            s = s + a[k][j];
        }     
        
        System.out.print("Tong: " + s);
    }
}
