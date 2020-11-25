package com.company.프로그래머스;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution_가장먼노드 {

    class nodeInfo{
        int n;
        int dist;
        public nodeInfo(int n, int dist){
            this.n = n;
            this.dist = dist;
        }
    }

    public int solution(int n, int[][] edge) {
        int answer = 0;

        List<List<Integer>> map = new ArrayList<>();
        int[] visited = new int[n+1];
        int[] dist = new int[n+1];
        Queue<nodeInfo> q = new LinkedList<>();
        int max = -1;

        for(int i = 0 ; i <= n; i++){
            map.add(new ArrayList<>());
        }

        for(int i = 0; i < edge.length;i++){
            map.get(edge[i][0]).add(edge[i][1]);
            map.get(edge[i][1]).add(edge[i][0]);
        }

        q.add(new nodeInfo(1,0));
        visited[1] = 1;

        while(!q.isEmpty()){
            nodeInfo search = q.poll();
            dist[search.n] = search.dist;
            max = search.dist;

            for(int i = 0 ; i < map.get(search.n).size(); i++){
                int next = map.get(search.n).get(i);
                if(visited[next] == 0){
                    q.add(new nodeInfo(next,search.dist+1));
                    visited[next] = 1;
                }
            }
        }

        for(int i  = 1; i <= n;i++){
            if(dist[i] == max) answer++;
        }
        return answer;
    }
}

public class 가장먼노드 {
    public static void main(String[] args){

    }
}
