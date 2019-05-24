import socket
import sys



client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
port = 1234
ip = socket.gethostbyname(socket.gethostname())
client.connect((ip, port))

print client.recv(1024)

dev = raw_input('Please choose a device (v=vibrational, f=force, e=electrotactile) \n')
client.sendall(str.encode(dev))
if dev == 'off':
    print '**Turning Off**'

    client.close()

dur = raw_input(client.recv(1024))
client.sendall(str.encode(dur))
if dur == 'off':
    print '**Turning Off**'
    client.close()

mag = raw_input(client.recv(1024))
client.sendall(str.encode(mag))
if mag == 'off':
    print '**Turning Off**'
    client.close()


print client.recv(1024)



