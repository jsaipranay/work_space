x=range(10)
print x

new_list=[]
for element in x:
    new_list.append(element * element)
print new_list

square= [element *element for element in x]

print "squares:",square


cube= [element *element*element for element in x]

print "cube:",cube

mul_3=[element for element in x if element%3==0]
print "mul_3:",mul_3
