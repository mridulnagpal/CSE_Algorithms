""" This module contains the class which simply
    returns the current situation of the game board """


class Board:

    # Checks the board and returns what is present on that specific coordinate
    def checkBoard(self, x, y, board):

        if x > len(board) - 4 or x < 0 or y < 0 or y > len(board) - 4:
            return 1
        elif y % 2 == 1 and x % 2 == 1:
            return 1
        return board[x][y]
