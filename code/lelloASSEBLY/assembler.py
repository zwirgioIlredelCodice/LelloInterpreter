import sys

nome_file = sys.argv[1]

file = open(nome_file,"r")
contenuto = file.read()
file.close()

array_out = []

contenuto_ar_righe = contenuto.split("\n")

for x in contenuto_ar_righe:
    riga_ar = x.split(" ")
    comando = riga_ar[0]

    if comando == "alloca":
        array_out.append(0)
        array_out.append(int(riga_ar[1]))
        array_out.append(int(riga_ar[2]))
    
    elif comando == "carica":
        array_out.append(1)
        array_out.append(int(riga_ar[1]))
        array_out.append(int(riga_ar[2]))
    
    elif comando == "somma":
        array_out.append(2)
        array_out.append(int(riga_ar[1]))
        array_out.append(int(riga_ar[2]))
    
    elif comando == "vai":
        array_out.append(3)
        array_out.append(int(riga_ar[1]))
        array_out.append(0)
    
    elif comando == "vai_vero":
        array_out.append(4)
        array_out.append(int(riga_ar[1]))
        array_out.append(int(riga_ar[2]))
    
    elif comando == "vai_falso":
        array_out.append(5)
        array_out.append(int(riga_ar[1]))
        array_out.append(int(riga_ar[2]))
    
    elif comando == "scrivi":
        array_out.append(6)
        array_out.append(int(riga_ar[1]))
        array_out.append(0)
    
    elif comando == "immetti":
        array_out.append(7)
        array_out.append(int(riga_ar[1]))
        array_out.append(int(riga_ar[2]))
    
    elif comando == "fine":
        array_out.append(8)
        array_out.append(0)
        array_out.append(0)
    
    else:
        print("comando non trovato")



print(array_out)