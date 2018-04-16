'''x=range(5)

def modify(y):
    y[0]=1000
    x=['abc']  
# print "x",x
print x  #[0,1,2,3,4]
modify(x) #[1000,1,2,3,4]
print x

'''
#passing by value
'''
def adder(x=10,y=20):
    return(x+y)
print adder(1,3)
print adder()
print adder(1)

#def get_student_info(name,age,class_,height=none):

print adder(y=1)
'''
#named parameters
'''
def divide(x=1,y=1):
    return x/y
print divide(y=10,x=100)
'''


'''

def get_student_info(name=None,age=None,**kwargs):
    print name,age,kwargs



get_student_info('Bob',20)
get_student_info('Alice',25,country='ind',state='KA')
'''
dict1={'name':'Alice','age':20}
print dict1
dict2={'name':'Alice','age':20}
print dict2
