def fab(n):
    if n in (0,1):
        return 1
    else:
        return fab(n-1)+fab(n-2)


'''print fab(0)
print fab(5)
for i in range(5):
    print fab(i)

'''
print fab(38)
