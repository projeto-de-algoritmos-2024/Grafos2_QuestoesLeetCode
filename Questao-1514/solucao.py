from collections import defaultdict
import heapq

class Solution(object):
    def maxProbability(self, n, edges, succProb, start_node, end_node):
        grafo = defaultdict(list)
        for (a, b), probabilidade in zip(edges, succProb):
            grafo[a].append((b, probabilidade))
            grafo[b].append((a, probabilidade))
        
        fila_prioridade = [(-1.0, start_node)]
        probabilidades = [0.0] * n
        probabilidades[start_node] = 1.0
        
        while fila_prioridade:
            prob_atual, no = heapq.heappop(fila_prioridade)
            prob_atual = -prob_atual
            
            if no == end_node:
                return prob_atual
            
            for vizinho, prob_aresta in grafo[no]:
                nova_prob = prob_atual * prob_aresta
                if nova_prob > probabilidades[vizinho]:
                    probabilidades[vizinho] = nova_prob
                    heapq.heappush(fila_prioridade, (-nova_prob, vizinho))
        
        return 0.0