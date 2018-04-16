import subprocess

ls=subprocess.Popen("ls",shell=False,stdout=subprocess.PIPE,stderr=subprocess.PIPE)

x=ls.stdout.readlines()
print x



