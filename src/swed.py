import csv
import sys
import os.path
import re

# Kontrollime, kas sisendfail on käsurealt antud
if len(sys.argv) < 2:
    print("Sisendfaili nimi peab olema ette antud käsureal")
    sys.exit(1)

sisendfail = sys.argv[1]

# Kontrollime, kas fail eksisteerib
if not os.path.isfile(sisendfail):
    print("Faili", sisendfail, "ei eksisteeri")
    sys.exit(1)

# Kontrollime, kas fail on CSV-vormingus
try:
    with open(sisendfail, 'r') as input_file:
        csv_reader = csv.reader(input_file, delimiter=';')
        for row in csv_reader:
            pass
except csv.Error:
    print("Fail", sisendfail, "pole CSV-vormingus")
    sys.exit(1)

# Loeme sisendfaili
with open(sisendfail, 'r') as input_file:
    csv_reader = csv.reader(input_file, delimiter=';')

    # Ava standardväljund
    csv_writer = csv.writer(sys.stdout, delimiter=';')

    # Lisame standardväljundi päise
    # csv_writer.writerow(["Kuupäev", "Selgitus", "", "", "Kulu", "Tulu"])

    # Loeme sisendfaili ridu
    for row in csv_reader:
        # Kui reatüüp on "T", siis jätkame järgmise reaga
        if row[1] != "20":
            continue

        # Võtame välja vajalikud väljad
        kuupaev = row[2]
        selgitus = re.split(r'\d+', row[3])[0].rstrip()
        summa = row[5].replace(",", ".")
        debet_kreedit = row[7]

        # Kontrollime, kas tegemist on "Kulu" või "Tulu" reaga
        if debet_kreedit == "D":
            kulu = summa
            tulu = ""
        elif debet_kreedit == "K":
            kulu = ""
            tulu = summa
        else:
            kulu = ""
            tulu = ""

        # Kirjutame standardväljundi uue rea
        csv_writer.writerow([kuupaev, selgitus, "", "", kulu, tulu])
