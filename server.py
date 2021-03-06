import socket
import time
import serial

time.sleep(20)                                                 # Start-up script (need time delay in beginning of program to ensure functionality)
server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)      # create server socket object
ip = socket.gethostbyname(socket.gethostname())
port = 1234
address = (ip,port)                                            # create tuple address in order to bind to server object
server.bind(address)
server.listen(1)                                               # [listen]only allow 1 client on server at a time
print"Begin communication on", ip, ":", port
ser  = serial.Serial('/dev/ttyACM0', 9600)                      # ACM0

while True:
    client,addr = server.accept()                                  # for client.connect(('ip',port)) in client scrypt 
    client.send(str.encode('Connection located at ' + str(addr[0]) + ': ' + str(addr[1])) + ' \nAt any point in time, you may send off to turn off the devices.')
    device = client.recv(1024)
    if device == 'v': 
        client.send(str.encode("Please input a duration (in seconds) for the vibrational device \n"))
        duration = client.recv(1024)                                # At this point in time the client script sends the server an integer from the user signifying the duration
        ser.write(device.encode())                                  # ser.write() commands are used for serial communication between raspberry pi and arduino
        ser.write(duration.encode())                                
        if duration == 'off':
            ser.write('x'.encode())                                 # 'x' character decoded by arduino to shut off devices 
            client.close()
        client.send(str.encode("Please input a magnitude (l = low, m = medium, h = high) \n"))
        magnitude = client.recv(1024)                               # At this point in time the client script sends the server a character from the user signifying the magnitude
        if magnitude == 'off':
            ser.write('x'.encode())
            client.close()
        client.send(str.encode("You have selected the vibrational device for " + duration + " seconds at a magnitude of " + magnitude + ".\n"))
        ser.write(magnitude.encode())                               

    elif device == 'f':
        client.send(str.encode("Please input a duration (in seconds) for the force device \n"))
        duration = client.recv(1024)
        ser.write(device.encode())
        ser.write(duration.encode())
        if duration == 'off':
            ser.write('x'.encode())
            client.close()
        client.send(str.encode("Please input a magnitude (l = low, m = medium, h = high) \n"))
        magnitude = client.recv(1024)
        if magnitude == 'off':
            ser.write('x'.encode())
            client.close()
        client.send(str.encode("You have selected the force device for " + duration + " seconds at a magnitude of " + magnitude + ".\n"))
        ser.write(magnitude.encode())
    
    elif device == 'e':
        client.send(str.encode("Please input a duration (in seconds) for the electrotactile device \n"))
        duration = client.recv(1024)
        ser.write(device.encode())
        ser.write(duration.encode())
        if duration == 'off':
            ser.write('x'.encode())
            client.close()
        client.send(str.encode("Please input a magnitude (l = low, m = medium, h = high) \n"))
        magnitude = client.recv(1024)
        if magnitude == 'off':
            ser.write('x'.encode())
            client.close()
        client.send(str.encode("You have selected the electrotactile device for " + duration + " seconds at a magnitude of " + magnitude + ".\n"))
        ser.write(magnitude.encode())
        
    elif device == 'off':
        ser.write('x'.encode())
        client.close()
        
    else:
        client.close()
        



