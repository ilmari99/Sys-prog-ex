# TEHTÄVÄV 2
# Kutsumalla ohjelmaa, käyttöjärjestelmä aloittaa uuden prosessin (virtuaalinen prosessori, muisti).
# Käytetään käyttöjärjestelmän tarjoamaa compileria ajamaan Pythonin ohjeiksi kääntämä koodi
# Prosessi käynnistää Terminaalin tapaisen taustalla. Python avaa terminaalin ikkunassa.

import math # Käytetään 'math' standardikirjastoa, joka on C kielinen moduuli floating-point matikalle

print("Let's calculate some square roots!")     # Ulostetaan texti käyttöjärjestelmän terminaaliin

n = input("Gibe number: ")                      # Otetaan sisään textiä terminaalista, joka käyttää mm. ajuria näppäimistölle

print(math.sqrt(float(n)) if n.isnumeric() else "That's not a number!" )



###################################################################################################
# TEHTÄVÄ 3

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
