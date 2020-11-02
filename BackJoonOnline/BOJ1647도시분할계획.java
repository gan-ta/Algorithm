package com.company.백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ1647도시분할계획 {

    static int[] parent = new int[100002];

    static int findParent(int search){
        if(parent[search] == search) return search;

        return parent[search] = findParent(parent[search]);
    }

    static void unionParent(int a, int b){
        int aParent = findParent(a);
        int bParent = findParent(b);

        parent[aParent] = bParent;
    }

    static class Edge{
        int node1;
        int node2;
        int weight;

        Edge(int node1, int node2, int weight){
            this.node1 = node1;
            this.node2 = node2;
            this.weight = weight;
        }
    }

    public static void main(String[] args) throws IOException {
	    int n;//노드
	    int m;//간선
        int edgeCount = 0;
        int result = 0;
        List<Edge> map = new ArrayList<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st= new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int j = 1; j <= m; j++) {
            st= new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            map.add(new Edge(a,b,c));
        }

	    for(int i = 0 ; i <= n; i++){
	        parent[i] = i;
        }

        //정렬
        map.sort((o1, o2) ->{
            if(o1.weight < o2. weight){
                return -1;
            }
            else if(o1.weight > o2.weight){
                return 1;
            }
            else{
                return 0;
            }
        });

        for(int i = 0 ; i < map.size(); i++){
            if(edgeCount == n -2) break;

            if(findParent(map.get(i).node1) != findParent(map.get(i).node2)){
                unionParent(map.get(i).node1,map.get(i).node2);
                edgeCount++;
                result += map.get(i).weight;
            }
        }

        System.out.println(result);
    }
}
