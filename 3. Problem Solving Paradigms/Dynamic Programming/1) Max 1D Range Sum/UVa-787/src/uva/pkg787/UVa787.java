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
 * Used DP implementation to reduce the number of multiplications.
 */
public class UVa787 {
    public static void main(String[] args)throws Exception {
        InputStreamReader sReader = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(sReader);
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer tok;
        BigInteger flag = BigInteger.valueOf(-999999);
        BigInteger p;
        ArrayList<BigInteger> arr;
        BigInteger[][] dp;
        int n;
        String line;
        while((line = in.readLine()) != null && !line.isEmpty()){
            arr = new ArrayList();
            tok = new StringTokenizer(line," ");
            BigInteger k;
            while(tok.hasMoreTokens()){
                String s = tok.nextToken();
                k = new BigInteger(s);
                if(k.equals(flag)) break;
                arr.add(k);
            }
            n = arr.size();
            dp = new BigInteger[n][n];
            BigInteger max_p = arr.get(0);
            for(int i = 0; i < n; i++){
                for(int j = i; j>= 0; j--){
                    p = arr.get(i);
                    if(i!=j) p = p.multiply(dp[i-1][j]); 
                    dp[i][j] = p;
                    if(p.compareTo(max_p) > 0) max_p = p;
                }
            }
            out.println(max_p.toString());
        }
        in.close();
        out.close();
    }
}
