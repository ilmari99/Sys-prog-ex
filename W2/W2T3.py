#https://stackoverflow.com/questions/3996026/what-is-the-default-encoding-for-c-strings
from ctypes import *
libc = CDLL("libc.dll.6")
libc.printf("hello everybody\n".encode('ascii'))    # Tämä pitää muuttaa ascii:ksi, koska C vaatii pääsääntöisesti ascii yhteensopivat stringit

