import socket, time

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
start = time.time()
s.connect(("127.0.0.1",1234))
mesaj = ''
while mesaj.strip() != 'exit':
    mesaj = input("Mesaj ce va fi trimis la server: ")
    s.send(mesaj.encode())
s.close()
file = open("lab9.txt", "w")
file.write("Timpul conexiunii este: ")
file.write(str(time.time()-start))
file.close()