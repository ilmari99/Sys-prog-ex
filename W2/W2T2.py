# Kutsumalla ohjelmaa, käyttöjärjestelmä aloittaa uuden prosessin (virtuaalinen prosessori, muisti).
# Käytetään käyttöjärjestelmän tarjoamaa compileria ajamaan Pythonin ohjeiksi kääntämä koodi
# Prosessi käynnistää Terminaalin tapaisen taustalla. Python avaa terminaalin ikkunassa.

import math # Käytetään 'math' standardikirjastoa, joka on C kielinen moduuli floating-point matikalle

print("Let's calculate some square roots!")     # Ulostetaan texti käyttöjärjestelmän terminaaliin

n = input("Gibe number: ")                      # Otetaan sisään textiä terminaalista, joka käyttää mm. ajuria näppäimistölle

print(math.sqrt(float(n)) if n.isnumeric() else "That's not a number!" )