import subprocess

print "=== Cmd run programm ===="

cmdout = subprocess.Popen("ls", shell=True, stdout=subprocess.PIPE).stdout.read()

print cmdout
