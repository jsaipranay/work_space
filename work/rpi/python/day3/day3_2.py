'''for e in list:
    func(e)
map(func,list)  '''

def fun_square(x):
    return x*x
list=range(4,20,3)
print list

#mapped_list=map(fun_square,list)
#print mapped_list

def divisible_by_4(x):
    return not x%4
filter_list=filter(divisible_by_4,list)

print filter_list


def adder(x,y):
    return x+y

total=reduce(adder,list)
print total


def mul(x,y):
    return x*y

fact =reduce(mul,range(1,10))
print fact




