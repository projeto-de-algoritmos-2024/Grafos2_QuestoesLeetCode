class Solution(object):
    def minDays(self, grid):
        def esta_conectado(matriz):
            linhas, colunas = len(matriz), len(matriz[0])
            visitado = [[False] * colunas for _ in range(linhas)]

            def dfs(x, y):
                if x < 0 or x >= linhas or y < 0 or y >= colunas or matriz[x][y] == 0 or visitado[x][y]:
                    return
                visitado[x][y] = True
                for dx, dy in ((0, 1), (1, 0), (0, -1), (-1, 0)):
                    dfs(x + dx, y + dy)

            encontrado = False
            for i in range(linhas):
                for j in range(colunas):
                    if matriz[i][j] == 1 and not visitado[i][j]:
                        if encontrado:
                            return False
                        dfs(i, j)
                        encontrado = True
            return encontrado

        if not esta_conectado(grid):
            return 0

        linhas, colunas = len(grid), len(grid[0])

        for i in range(linhas):
            for j in range(colunas):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    if not esta_conectado(grid):
                        grid[i][j] = 1
                        return 1
                    grid[i][j] = 1

        for i in range(linhas):
            for j in range(colunas):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    for x in range(linhas):
                        for y in range(colunas):
                            if grid[x][y] == 1:
                                grid[x][y] = 0
                                if not esta_conectado(grid):
                                    grid[x][y] = 1
                                    grid[i][j] = 1
                                    return 2
                                grid[x][y] = 1
                    grid[i][j] = 1

        return 2
