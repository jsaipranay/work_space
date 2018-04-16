x=range(100)
y=[a*a*a for a in x ]
#print y
z=(a*a*a for a in x)
print z

for a in z:
    print a,

