/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package buoi2;
import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
/**
 *
 * @author dell
 */
public class Bai10 {
    public static void main(String[] args) throws Exception
    {
        String fileName ="";
        File f = new File("");
        fileName = f.getAbsolutePath() + "\\src\\Buoi2\\data.txt";
        f = new File(fileName);
        if(f.exists())
        {
            System.out.println("file ton tai");
            System.exit(0);
        }
        PrintWriter pw = new PrintWriter(f);
        pw.print("truong trung - ");
        pw.println(2019);
        pw.println("hutech");
        pw.close();
        System.out.println("da ghi file xog");
        System.out.println("Doc file!");
        Scanner inp = new Scanner(f);
        while(inp.hasNext())
        {
            String ten = inp.nextLine();
            System.out.println(ten+ " ");
        }
    }
}
