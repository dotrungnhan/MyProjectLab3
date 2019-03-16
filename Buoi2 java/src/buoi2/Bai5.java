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

