S = 8
board = [[0] * S for _ in range(S)]

def fill(x, y, v, p):
    board[x][y] = v
    board[x][y+1] = v
    board[x+1][y] = v
    board[x+1][y+1] = v
    if p == 0:
        board[x][y] = -1
    elif p == 1:
        board[x+1][y] = -1
    elif p == 2:
        board[x+1][y+1] = -1
    else:
        board[x][y+1] = -1

def fit(s, x, y, p):
    v = (x+2) * S + y
    if s == 2:
        fill(x, y, v, p)
        return
    s //= 2
    if p == 0:
        fit(s, x, y, 0)
        fit(s, x+s, y, 3)
        fit(s, x, y+s, 1)
        fit(s, x+s, y+s, 0)
    elif p == 1:
        fit(s, x, y, 2)
        fit(s, x+s, y, 1)
        fit(s, x, y+s, 1)
        fit(s, x+s, y+s, 0)
    elif p == 2:
        fit(s, x, y, 2)
        fit(s, x+s, y, 3)
        fit(s, x, y+s, 1)
        fit(s, x+s, y+s, 2)
    else:
        fit(s, x, y, 2)
        fit(s, x+s, y, 3)
        fit(s, x, y+s, 3)
        fit(s, x+s, y+s, 0)

fit(S, 0, 0, 0)
for i in range(S):
    print(board[i])
