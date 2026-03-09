FROM ubuntu:22.04

RUN apt update && apt install -y socat coreutils cpulimit && rm -rf /var/lib/apt/lists/*

WORKDIR /app

RUN useradd -m ctf

COPY challenge1 challenge1.c flag.txt libc.so.6 ld-linux-x86-64.so.2 ./

RUN chmod +x challenge1 && chown -R ctf:ctf /app

USER ctf

EXPOSE 10001

CMD socat TCP-LISTEN:10001,reuseaddr,fork EXEC:"./challenge1",stderr

