
def cat_func():
    x=1
    while x:
        x= yield(x)
#        x+=1





cat=cat_func()
print cat.next()
