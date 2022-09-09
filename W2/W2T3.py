#https://stackoverflow.com/questions/3996026/what-is-the-default-encoding-for-c-strings

import sys
from ctypes import *
libc = CDLL("libc.dll.6")
# Tämä pitää muuttaa ascii:ksi, koska Pythonin C kirjastot vaativat pääsääntöisesti ascii yhteensopivat stringit
libc.printf("hello everybody\n".encode('ascii'))

# JOS tekstiä ei muuta ascii:ksi, saa OSError 8, joka on format error.

# Tämä printtaa Pythonin oman moduulin kautta, kun taas edellä printataan 'suoraan' C funktiolla
def printf(format, *args):
    sys.stdout.write(format % args)
    return
