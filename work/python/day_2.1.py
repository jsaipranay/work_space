def adder(x,y,*arg):#def adder(*arg,x,y) error
   print x,y,arg


adder(1,2)

adder(1,2,3)

adder(1,2,3,4,5)

'''1 2 () tuple
1 2 (3,)
1 2 (3, 4, 5)
'''





