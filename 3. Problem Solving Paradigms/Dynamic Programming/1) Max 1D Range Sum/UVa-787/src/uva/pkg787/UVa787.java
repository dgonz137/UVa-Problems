/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package uva.pkg787;

import java.util.*;
import java.io.*;
import java.math.*;


/**
 *
 * @author David
 */
public class UVa787 {
    
    public static void main(String[] args)throws Exception {
        InputStreamReader sReader = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(sReader);
        StringTokenizer tok;
        BigInteger flag = BigInteger.valueOf(-999999);
        ArrayList<BigInteger> arr;
        String line;
        while((line = in.readLine()) != null){
            arr = new ArrayList();
            tok = new StringTokenizer(line," ");
            BigInteger k;
            while(tok.hasMoreTokens()){
                String s = tok.nextToken();
                k = new BigInteger(s);
                if(k.equals(flag)) break;
                arr.add(k);
            }
            BigInteger max_p = arr.get(0);
            for(int i = 0; i < arr.size()-1; i++){
                BigInteger p = BigInteger.ONE;
                for(int j = i; j >= 0; j--){
                    p = p.multiply(arr.get(j));
                    if(p.compareTo(max_p) > 0){
                        max_p = p;
                    }
                }
            }
            System.out.println(max_p.toString());
        }
        in.close();
    }
}
