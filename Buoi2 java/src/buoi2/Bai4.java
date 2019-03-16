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
public class Bai4 {
    public static String ChuyenInHoa(String str)
    {
        String s,strOutput;
        s = str.substring(0,1);
        strOutput = str.replaceFirst(s,s.toUpperCase());
        return (strOutput);
    }
    public static String chuanHoa(String strInput)
    {
        String strOutput="";
        StringTokenizer strToken = new StringTokenizer(strInput,",\t,\r");
        strOutput+=""+ChuyenInHoa(strToken.nextToken());
        while(strToken.hasMoreTokens())
        {
            strOutput+=""+ChuyenInHoa(strToken.nextToken());
        }
        return(strOutput);
    }
    public static void main(String[] args)
    {
        //generated method
        Scanner s = new Scanner(System.in);
        System.out.println("nhap 1 chuoi:");
        String strInput = s.nextLine();
        System.out.println("Chuoi dc chuan hoa: " +chuanHoa(strInput));
    }
}
