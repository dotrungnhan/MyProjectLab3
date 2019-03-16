/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package buoi2;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

/**
 *
 * @author dell
 */
public class Bai9 {
    public static void main(String args[]) throws IOException
    {
        try(
            FileOutputStream os = new FileOutputStream("abc.txt")) {
         
            String s =" hello crush crush oi crush";
            for(int i=0;i<s.length();i++)
                os.write(s.charAt(i));
            }
        try(
            FileInputStream is = new FileInputStream("abc.txt")) {
            
            int ibyts = is.available();
            System.out.println("File co tat ca: " + ibyts + "ky tu");
            byte ibuf[] = new byte[ibyts];
            int byrd = is.read(ibuf,0,ibyts);
            System.out.println("tong so ky tu dem dc: " + byrd);
            System.out.println("chuoi ki tu  la:" + new String(ibuf));
               
        }
               
                 
        File f1 = new File("abc.txt");
        f1.delete();
    }
}
