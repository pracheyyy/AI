
def solve_n_queens(n):
    board = [[0] * n for _ in range(n)]

    def is_safe(row, col):
       
        for i in range(row):
            if board[i][col] == 1:
                return False
            
        i, j = row - 1, col - 1
        while i >= 0 and j >= 0:
            if board[i][j] == 1:
                return False
            i -= 1
            j -= 1

        i, j = row - 1, col + 1
        while i >= 0 and j < n:
            if board[i][j] == 1:
                return False
            i -= 1
            j += 1

        return True

    def solve(row):
        if row == n:
            for r in board:
                print(r)
            print()
            return True

        found = False

        for col in range(n):
            if is_safe(row, col):
                board[row][col] = 1

                if solve(row + 1):
                    found = True

                board[row][col] = 0

        return found

    if not solve(0):
        print("No solution exists")


n = int(input("Enter N: "))
solve_n_queens(n)
