import pytcp

tcp = pytcp.Tcp("127.0.0.1", 44444)

while True:
    x = tcp.read();
    if x:
        print(str(x))
