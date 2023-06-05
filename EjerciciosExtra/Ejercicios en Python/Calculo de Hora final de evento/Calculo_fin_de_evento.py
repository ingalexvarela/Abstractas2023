hour = int(input("Hora de inicio (horas): "))
mins = int(input("Minuto de inicio (minutos): "))
dura = int(input("Duración del evento (minutos): "))

# Escribe tu código aquí.
a = mins + dura
if a > 60:
    b = a // 60
    hour = hour + b
    c = a - (b * 60)
    while (hour > 24): 
        hour = hour - 24
    Fin_evento = str(hour) + ":" + str(c)
    print("El evento finaliza a las: ", Fin_evento)
else:
    if hour == 24 and a > 0:
        hour = 0
    Fin_evento = str(hour) + ":" + str(a)
    print("El evento finaliza a las: ", Fin_evento)
