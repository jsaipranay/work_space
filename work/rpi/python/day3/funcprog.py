#for e in lst:
#    func(e)
#map(func,lst) 


#map
def fun_square(x):
    return x*x


lst=range(4,20,3)
print lst

maped_list=map(fun_square,lst)
print maped_list

#filter

def divisible_by_4(x):
    return not x%4
filter_list=filter(divisible_by_4,lst)
print filter_list


#filter



def adder(x,y):
    return x+y
def mul(x,y):
    return x*y
fact=reduce(mul,range(1,10))
print fact


#lambda

x=range(15,28)
y=[str(a*a)[1:] for a in x]

print x
print y

z=zip(x,y)
print z

print z.sort(key=lambda x:x[1])
print z


