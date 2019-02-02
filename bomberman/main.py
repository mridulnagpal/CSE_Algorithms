""" This module is what brings all the components
    of the game together and runs the game """

import signal
import sys
import time
import os
from random import *
from gameplay import *
from entity import *
from alarmexception import *
from getchunix import *


getch = GetchUnix()


def alarmHandler(signum, frame):
    raise AlarmException


# Function for taking user input
def user_input(timeout=0.1):
    signal.signal(signal.SIGALRM, alarmHandler)
    signal.setitimer(signal.ITIMER_REAL, timeout)
    try:
        pass
        text = getch()
        signal.alarm(0)
        return text
    except AlarmException:
        pass
    signal.signal(signal.SIGALRM, signal.SIG_IGN)
    return ""


# Displays the Game Menu and lets user select level
def gameMenu():
    os.system("mpg123 --loop 9999 01-title-screen.mp3 &")
    os.system("clear")
    print("Welcome to Bomberman!!")
    print("\nThe objective of the game is to destroy ",
          "all enemies before you lose all your lives!")
    print("\nControls: ")
    print("Move up    =  w")
    print("Move down  =  s")
    print("Move right =  d")
    print("Move left  =  a")
    print("Drop Bomb  =  b")
    print("Quit game  =  q")
    print("Pause game =  p")
    print("\nHigher level = Tougher,faster and ",
          "greater number of enemies and obstacles")
    print("\nScore  =  level x ",
          "(number of bricks destroyed + number of enemies destroyed)")
    print("\nPress q to exit or")
    print("\nPlease type Level number to start level: 1 2 3 4")
    c = "h"
    while c not in ["1", "2", "3", "4", "q"]:
        c = user_input()
    level = c
    os.system("pkill mpg123")
    return level


# Pauses game
def pause():
    print("Game Paused! Press any key to continue!")
    c = getch()
    return c


# Controls the main running and configuration of the game
def gameLoop(lev):
    os.system("mpg123 --loop 9999 theme.mp3 &")
    level = int(lev)
    score = 0

    lives = 5
    bHealth = 3
    nBl = 20
    nEn = 5
    eHealth = 1
    gameSpeed = 12

    if level == 2:
        lives = 3
        nBl = 30
        nEn = 8
        eHealth = 1
        gameSpeed = 10

    elif level == 3:
        lives = 5
        nBl = 40
        nEn = 12
        eHealth = 2
        gameSpeed = 9

    elif level == 4:
        lives = 3
        nBl = 50
        nEn = 15
        eHealth = 3
        gameSpeed = 8

    board = [[0 for x in range(20)] for y in range(20)]
    blocks = []
    for i in range(nBl):
        x = choice(range(1, 18))
        y = choice(range(0, 18))
        while y % 2 == 1 and x % 2 == 1:
            x = choice(range(1, 18))
            y = choice(range(0, 18))
        blocks.append([x, y])
        board[x][y] = 1

    enemies = []

    for i in range(nEn):
        x = choice(range(7, 18, 2))
        y = choice(range(6, 18, 2))
        while [x, y] in blocks:
            x = choice(range(7, 18, 2))
            y = choice(range(6, 18, 2))
        enemies.append(Enemy(eHealth, [x, y]))

    bomb = Bomb(-1, [-1, -1])
    display = Display()
    counter = 0
    game = gamePlay()
    while lives > 0:
        dead = False
        blocation = [0, 1]
        bomber = Bomber(bHealth, blocation)
        injury = 0
        while not dead:
            flag = 0
            c = user_input()
            if c == "q":
                lives = 0
                dead = True
                break
            elif c == "w":
                x = bomber.moveUp(board)
                flag = 1
            elif c == "d":
                x = bomber.moveRight(board)
                flag = 1

            elif c == "a":
                x = bomber.moveLeft(board)
                flag = 1

            elif c == "s":
                x = bomber.moveDown(board)
                flag = 1

            elif c == "b" and bomb.health == -1:
                x = bomber.location[0]
                y = bomber.location[1]
                bomb = Bomb(3, [x, y])
                board[x][y] = 1
                flag = 1
            elif c == "p":
                if pause() == "q":
                    lives = 0
                    dead = True
                    break

            if counter % gameSpeed == 0:
                for enemy in enemies:
                    enemy.autoMove(board)
                bomber.health -= injury
                injury = 0
                if bomb.health > 0:
                    bomb.health -= 1
                elif bomb.health == 0:
                    bombLocations = [bomb.location]
                    bomb.explode(bombLocations, board)
                    for loc in bombLocations:
                        board[loc[0]][loc[1]] = 0
                    bomb.health = -1
                    bomb.location = [-1, -1]
                if bomb.health == 0:
                    bombLocations = [bomb.location]
                    bomb.explode(bombLocations, board)
                    os.system("aplay shot.wav &")
                    for loc in bombLocations:
                        board[loc[0]][loc[1]] = 2
                score += level * game.checkEnemy(board, enemies)
                score += level * game.checkBlocks(board, blocks)
                flag = 1

            if game.checkBomber(board, bomber):
                injury = 1

            if bomber.health <= 0:
                dead = True
                break

            counter += 1
            counter %= gameSpeed
            if len(enemies) == 0:
                os.system("clear")
                print("Game Over! You win!!")
                print("Your score is ", score)
                os.system("pkill mpg123")
                sys.exit()
            if flag:
                display.printBoard(board, blocks, score,
                                   bomber, enemies, bomb, lives)

        lives -= 1

    os.system("clear")
    print("Game Over!")
    print("Your score is ", score)
    os.system("pkill mpg123")

level = gameMenu()

if(level == "q"):
    os.system("clear")
    quit()

gameLoop(level)