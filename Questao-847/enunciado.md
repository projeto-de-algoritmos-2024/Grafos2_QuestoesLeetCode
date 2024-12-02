# 847. [Shortest Path Visiting All Nodes](https://leetcode.com/problems/shortest-path-visiting-all-nodes/)

**Status:** Solved  
**Difficulty:** Hard  
**Topics:** Graph, Breadth-First Search, Bitmasking  


You are given an undirected, connected graph with `n` nodes labeled from `0` to `n - 1`. The graph is represented by an array `graph` where `graph[i]` is a list of all the nodes connected to node `i` by an edge.

Return the length of the shortest path that visits every node. You can start and stop at any node, revisit nodes multiple times, and reuse edges.

---

## Example 1:

![Exemplo 1](assents/exemplo1.jpg)

### Input:  
`graph = [[1,2,3],[0],[0],[0]]`

### Output:  
`4`

### Explanation:  
One possible path is `[1,0,2,0,3]`.

---

## Example 2:

![Exemplo 2](assents/exemplo2.jpg)

### Input:  
`graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]`

### Output:  
`4`

### Explanation:  
One possible path is `[0,1,4,2,3]`.

---

## Constraints:

- `n == graph.length`
- `1 <= n <= 12`
- `0 <= graph[i].length < n`
- `graph[i]` does not contain `i`.
- If `graph[a]` contains `b`, then `graph[b]` contains `a`.
- The input graph is always connected.
