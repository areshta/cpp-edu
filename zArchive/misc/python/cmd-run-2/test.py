#!/usr/bin/env python
import subprocess
text = '5'
proc = subprocess.Popen(
    './double',stdout=subprocess.PIPE,
    stdin=subprocess.PIPE)
proc.stdin.write(text.encode())
proc.stdin.close()
result = proc.stdout.read()
print (result)
proc.wait()
