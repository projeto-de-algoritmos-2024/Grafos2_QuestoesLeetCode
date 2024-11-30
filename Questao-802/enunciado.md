# 802. Find Eventual Safe States

**Status:** Solved  
**Difficulty:** Medium  
**Topics:** Graphs   

There is a directed graph with `n` nodes, labeled from `0` to `n - 1`. The graph is represented by a 2D integer array `graph`, where `graph[i]` is an array of integers representing the adjacent nodes to node `i`, meaning there is a directed edge from node `i` to each node in `graph[i]`.

A node is a **terminal node** if it has no outgoing edges. A node is **safe** if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes in ascending order.

---

## Example 1:
![Figura 1](assents/imagem_grafo.png)
### Input:  
`graph = [[1,2],[2,3],[5],[0],[5],[],[]]`

### Output:  
`[2,4,5,6]`

### Explanation:  
The graph provided is shown above. Nodes `5` and `6` are terminal nodes because they have no outgoing edges.  
Every path starting at nodes `2`, `4`, `5`, and `6` leads to nodes `5` or `6`.

---

## Example 2:

### Input:  
`graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]`

### Output:  
`[4]`

### Explanation:  
Only node `4` is a terminal node, and every path starting from node `4` leads back to node `4`.

---

## Constraints:

- `n == graph.length`  
- `1 <= n <= 10⁴`  
- `0 <= graph[i].length <= n`  
- `0 <= graph[i][j] <= n - 1`  
- `graph[i]` is sorted in strictly increasing order.  
- The graph may contain self-loops.  
- The number of edges in the graph is in the range `[1, 4 * 10⁴]`.
