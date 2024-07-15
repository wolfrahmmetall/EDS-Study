# https://informatics.msk.ru/mod/statements/view.php?chapterid=161#1
from collections import deque

def main():
    '''
    Задача про коня
    '''
    n = int(input())
    x1, y1 = [int(x) - 1 for x in input().split()]
    x2, y2 = [int(x) - 1 for x in input().split()]

    field = [[0] * n for i in range(n)]
    parent = [[[0, 0]] * n for i in range(n)]
    q = deque()

    field[x1][y1] = 1

    q.append([x1, y1])

    step = [[1, 2], [1, -2], [-1, 2], [-1, -2], [2, 1], [2, -1], [-2, 1], [-2, -1]]


    while q:
        x, y = q.popleft()
        for dx, dy in step:
            if x + dx < 0 or x + dx >= n or y + dy < 0 or y + dy >= n:
                continue
            if field[x + dx][y + dy] == 0:
                field[x + dx][y + dy] = field[x][y] + 1
                parent[x + dx][y + dy] = [x, y]
                q.append([x + dx, y + dy])

    print(*field, sep='\n')
    print(*parent, sep='\n')


if __name__ == '__main__':
    main()
