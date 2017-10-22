""" This module contains the function
    necessary for taking immediate inputs """

import sys
import tty
import termios
from random import randint


# Takes input immediately after a keypress
class GetchUnix:
    def __init__(self):
        pass

    def __call__(self):

        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
        try:
            tty.setraw(sys.stdin.fileno())
            ch = sys.stdin.read(1)
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
        return ch
