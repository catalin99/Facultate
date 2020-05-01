/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab1optional;
import java.util.Random;
/**
 *
 * @author catal
 */
public class Lab1optional {

    /**
     * @param args the command line arguments
     */
    public static void shuffleArray(int[] ar) {
        Random rnd = new Random();
        for (int i = ar.length - 1; i > 0; i--) {
            int index = rnd.nextInt(i + 1);
            int a = ar[index];
            ar[index] = ar[i];
            ar[i] = a;
        }
    }
    
    public static int[][] completeGraph(int argum)
    {
        int Graph[][]=new int[argum+1][argum+1];
        for(int i=0; i<argum; i++)
            for(int j=0; j<argum; j++)
            {
                Graph[i][j]=1;
        
            }
        for (int i=0; i<argum; i++)
            Graph[i][i]=0;
        return Graph;
    }
    public static int[][] cyclicGraph(int argum)
    {
        int graph[][]=new int[argum+1][argum+1];
        int nodes[]=new int[argum+1];
        for (int i=0; i<argum; i++)
            nodes[i]=i;
        shuffleArray(nodes);
        for(int i=0; i<argum; i++)
            for(int j=0; j<argum; j++)
                graph[i][j]=0;
        for (int i = 0; i < argum - 1; i++) {
            graph[nodes[i]][nodes[i + 1]] = 1;
            graph[nodes[i + 1]][nodes[i]] = 1;
        }
        graph[nodes[argum - 1]][nodes[0]] = 1;
        graph[nodes[0]][nodes[argum - 1]] = 1;
        return graph;
    }
    public static int[][] randomGraph(int argum)
    {
        int graph[][]=new int[argum+1][argum+1];
        Random rand=new Random();
        
        for(int i=0; i<argum; i++)
            for(int j=0; j<argum; j++)
            {
                if(i<j)
                    graph[i][j]=rand.nextInt(2);
                else if(i==j)
                        graph[i][j]=0;
                else
                        graph[i][j]=graph[j][i];
            }
        return graph;
    }
    
    public static int showEdges(int matrix[][], int argum)
    {
        int count=0;
        for(int i=0; i<argum; i++)
            for(int j=0; j<argum; j++)
                if(matrix[i][j]==1)
                    count++;
        count/=2;
        //System.out.println();
        //System.out.println(count);
        return count;
    }
    
    public static void showMaxMinDegree(int matrix[][], int argum)
    {
        int min=argum+1;
        int max=-1;
        for(int i=0; i<argum; i++)
        {
            int count=0;
            for(int j=0; j<argum; j++)
                if(matrix[i][j]==1)
                    count++;
            if(count<min)
                min=count;
            if(count>max)
                max=count;
        }
        System.out.println();
        System.out.print("Δ(G): ");
        
        System.out.println(min);
        System.out.print("δ(G): ");
        System.out.println(max);
        if(min==max)
            System.out.println("Graful este regulat");
        else
            System.out.println("Graful nu este regulat");
    }
    
    public static boolean sumOfDegrees(int matrix[][], int argum)
    {
        int sum=0;
        for(int i=0; i<argum; i++)
            for(int j=0; j<argum; j++)
                if(matrix[i][j]==1)
                    sum++;
        if(sum==showEdges(matrix, argum)/2)
            return true;
        return false;
    }
    
    public static void main(String[] args) {
        //impar
        System.out.println("Am citit "+args[0]);
        Integer argum=Integer.parseInt(args[0]);
        if(argum%2==0)
        {
            System.out.println("Numărul este par");
        }
        else
        {
            System.out.println("Numărul valid");
        }
        int completeGraphVar[][]=completeGraph(argum);
        /*for(int i=0; i<argum; i++)
        {
            for(int j=0; j<argum; j++)
            {
                System.out.print(completeGraphVar[i][j]);
                System.out.print(' ');
            }
            System.out.println();
        }
        System.out.println(); */
        int cyclicGraphVar[][]=cyclicGraph(argum);
        /*for(int i=0; i<argum; i++)
        {
            for(int j=0; j<argum; j++)
            {
                System.out.print(cyclicGraphVar[i][j]);
                System.out.print(' ');
            }
            System.out.println();
        }
        System.out.println();*/
        int randomGraphVar[][]=randomGraph(argum);
        /*for(int i=0; i<argum; i++)
        {
            for(int j=0; j<argum; j++)
            {
                System.out.print(randomGraphVar[i][j]);
                System.out.print(' ');
            }
            System.out.println();
        }*/
        int nrEdges=showEdges(completeGraphVar, argum);
        System.out.println(nrEdges);
        showMaxMinDegree(randomGraphVar, argum);
        if(sumOfDegrees(cyclicGraphVar,argum)==true)
            System.out.println("sum of the degrees is equals the value 2 * m ");
        else
            System.out.println("sum of the degrees isn't equals the value 2 * m ");
        
            
    }
    
}
