/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package buoi2;

import java.util.Scanner;

/**
 *
 * @author Lenovo
 */
public class Chuanchuoi {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        nhap();
    }
   
    static void chuanhoa(String s){
            s=s.toLowerCase();
            String s2="";
            String []ss;
            ss=s.split(" ");
            for(int i=0;i<ss.length;i++){
                String s1="";
                if(ss[i].length()!=0){
                       s1+=Character.toUpperCase(ss[i].charAt(0));
                       if(ss[i].length()>1)s1+=ss[i].substring(1);
                       s2+=s1;
                       if(i<ss.length)s2+=" ";
            }
        }
            if(s2.charAt(s2.length()-1)==' ')s2+="\b";
            System.out.println("\bChuoi sau khi chuan hoa:" +s2);
    }
    static void nhap(){
       String str;
       Scanner sc=new Scanner(System.in);
       System.out.print("Nhap chuoi: ");
       str=sc.nextLine();      
       chuanhoa(str);
   }
    
}
