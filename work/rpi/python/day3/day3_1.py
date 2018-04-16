'''
#list comprehensive
x=range(10)
print x
y=[]
for element in x:
    y.append(element*element)
print y


square=[element*element for  element in x]
print "square:",square

multiple_3=[element for element in x if element%3==0]
print "multiple_3",multiple_3

'''


'''
#dictionary comprehensive
x=[(1,1000),(2,2000),(3,3000)]

y={key:value for key,value in x if key%3==0}

print y
print dict(x)
'''


#set comprehension

x=range(10)+range(5)
print x

s={element for element in x}
print s
