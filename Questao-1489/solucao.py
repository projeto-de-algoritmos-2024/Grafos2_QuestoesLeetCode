class Solution(object):
    def findCriticalAndPseudoCriticalEdges(self, n, edges):
        arestas = [(u, v, peso, i) for i, (u, v, peso) in enumerate(edges)]
        arestas.sort(key=lambda x: x[2])

        def encontrar(pai, x):
            if pai[x] != x:
                pai[x] = encontrar(pai, pai[x])
            return pai[x]

        def unir(pai, rank, x, y):
            raizX = encontrar(pai, x)
            raizY = encontrar(pai, y)
            if raizX != raizY:
                if rank[raizX] > rank[raizY]:
                    pai[raizY] = raizX
                elif rank[raizX] < rank[raizY]:
                    pai[raizX] = raizY
                else:
                    pai[raizY] = raizX
                    rank[raizX] += 1

        def kruskal(excluir_aresta=-1, incluir_aresta=-1):
            pai = list(range(n))
            rank = [0] * n
            peso_total = 0
            contagem = 0

            if incluir_aresta != -1:
                u, v, peso, _ = arestas[incluir_aresta]
                if encontrar(pai, u) != encontrar(pai, v):
                    unir(pai, rank, u, v)
                    peso_total += peso
                    contagem += 1

            for i, (u, v, peso, _) in enumerate(arestas):
                if i == excluir_aresta:
                    continue
                if encontrar(pai, u) != encontrar(pai, v):
                    unir(pai, rank, u, v)
                    peso_total += peso
                    contagem += 1
                    if contagem == n - 1:
                        break

            return peso_total if contagem == n - 1 else float('inf')

        peso_mst_original = kruskal()

        criticas = []
        pseudo_criticas = []

        for i in range(len(arestas)):
            if kruskal(excluir_aresta=i) > peso_mst_original:
                criticas.append(arestas[i][3])
            elif kruskal(incluir_aresta=i) == peso_mst_original:
                pseudo_criticas.append(arestas[i][3])

        return [criticas, pseudo_criticas]
