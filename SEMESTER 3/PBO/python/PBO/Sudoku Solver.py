import tkinter as tk


def print_board(board):
    for i in range(9):
        if i % 3 == 0 and i != 0:
            print("-" * 21)
        row = board[i]
        formatted_row = [str(cell) if cell != 0 else "." for cell in row]
        print(" ".join(formatted_row[:3]) + " | " + " ".join(
            formatted_row[3:6]) + " | " + " ".join(formatted_row[6:]))
    print()


def input_sudoku():
    sudoku_board = []
    print("Enter the Sudoku puzzle row by row. Use 0 for empty cells.")
    for i in range(9):
        row = []
        while True:
            row_input = input(
                f"Enter row {i + 1} (9 numbers, e.g., '5 3 0 0 7 0 0 0 0'): ")
            row_values = row_input.split()
            if len(row_values) == 9:
                try:
                    row = [int(val) for val in row_values]
                    break
                except ValueError:
                    print("Invalid input. Please enter 9 numbers separated by spaces.")
            else:
                print("Invalid input. Please enter 9 numbers separated by spaces.")
        sudoku_board.append(row)
    return sudoku_board


def is_valid(board, row, col, num):
    # Check the row
    if num in board[row]:
        return False

    # Check the column
    if num in [board[i][col] for i in range(9)]:
        return False

    # Check the 3x3 subgrid
    start_row, start_col = 3 * (row // 3), 3 * (col // 3)
    for i in range(start_row, start_row + 3):
        for j in range(start_col, start_col + 3):
            if board[i][j] == num:
                return False

    return True


def solve_sudoku():
    def is_valid(board, row, col, num):
        # Check the row
        if num in board[row]:
            return False

        # Check the column
        if num in [board[i][col] for i in range(9)]:
            return False

        # Check the 3x3 subgrid
        start_row, start_col = 3 * (row // 3), 3 * (col // 3)
        for i in range(start_row, start_row + 3):
            for j in range(start_col, start_col + 3):
                if board[i][j] == num:
                    return False

        return True

    def solve(board):
        for row in range(9):
            for col in range(9):
                if board[row][col] == 0:
                    for num in range(1, 10):
                        if is_valid(board, row, col, num):
                            board[row][col] = num
                            if solve(board):
                                return True
                            board[row][col] = 0
                    return False
        return True

    if solve(sudoku_board):
        draw_sudoku()


def handle_click(event):
    x, y = event.x // cell_size, event.y // cell_size
    if event.num == 1:  # Left-click
        selected_cell[0] = y
        selected_cell[1] = x
    elif event.num == 3:  # Right-click
        sudoku_board[y][x] = 0  # Set the cell value to 0
    draw_sudoku()


def handle_key(event):
    key = event.keysym
    if key.isdigit() and 1 <= int(key) <= 9:
        if selected_cell[0] is not None and selected_cell[1] is not None:
            y, x = selected_cell[0], selected_cell[1]
            sudoku_board[y][x] = int(key)
        draw_sudoku()
    elif key == "Up":
        if selected_cell[0] > 0:
            selected_cell[0] -= 1
    elif key == "Down":
        if selected_cell[0] < 8:
            selected_cell[0] += 1
    elif key == "Left":
        if selected_cell[1] > 0:
            selected_cell[1] -= 1
    elif key == "Right":
        if selected_cell[1] < 8:
            selected_cell[1] += 1
    draw_sudoku()


def is_valid(board, row, col, num):
    # Check the row
    if num in board[row]:
        return False

    # Check the column
    if num in [board[i][col] for i in range(9)]:
        return False

    # Check the 3x3 subgrid
    start_row, start_col = 3 * (row // 3), 3 * (col // 3)
    for i in range(start_row, start_row + 3):
        for j in range(start_col, start_col + 3):
            if board[i][j] == num:
                return False

    return True


def solve_sudoku(board):
    for row in range(9):
        for col in range(9):
            if board[row][col] == 0:
                for num in range(1, 10):
                    if is_valid(board, row, col, num):
                        board[row][col] = num
                        if solve_sudoku(board):
                            return True
                        board[row][col] = 0
                return False
    return True


def draw_sudoku():
    canvas.delete("all")
    for row in range(9):
        for col in range(9):
            x1 = col * cell_size
            y1 = row * cell_size
            x2 = x1 + cell_size
            y2 = y1 + cell_size
            value = sudoku_board[row][col]
            if selected_cell[0] == row and selected_cell[1] == col:
                canvas.create_rectangle(x1, y1, x2, y2, fill="lightblue")
            else:
                canvas.create_rectangle(x1, y1, x2, y2, fill="white")
            if value != 0:
                canvas.create_text(x1 + cell_size // 2, y1 +
                                   cell_size // 2, text=str(value))

            # Draw thicker lines to separate 3x3 sections
            if col % 3 == 0:
                canvas.create_line(x1, y1, x1, y2, width=3)
            if row % 3 == 0:
                canvas.create_line(x1, y1, x2, y1, width=3)


root = tk.Tk()
root.title("Sudoku Solver")

cell_size = 50
canvas = tk.Canvas(root, width=cell_size * 9, height=cell_size * 9)
canvas.pack()
canvas.focus_set()  # Set focus on the canvas to capture key events

sudoku_board = [[0] * 9 for _ in range(9)]
selected_cell = [0, 0]  # Initialize selected cell at (0, 0)

canvas.bind("<Button-1>", handle_click)
canvas.bind("<Button-3>", handle_click)  # Right-click
canvas.bind("<Key>", handle_key)  # Keyboard input

solve_button = tk.Button(root, text="Solve", command=lambda: solve_sudoku(
    sudoku_board) and draw_sudoku())
solve_button.pack()

draw_sudoku()

root.mainloop()

sudoku_board = input_sudoku()

if solve_sudoku(sudoku_board):
    print("Solved Sudoku:")
    print_board(sudoku_board)
else:
    print("No solution exists.")
