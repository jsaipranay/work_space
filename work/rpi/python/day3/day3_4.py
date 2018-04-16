x=range(10)
y=[a*a*a for a in x] 
z=(a*a*a for a in x)
print y
print z
for a in z:
    print a,
