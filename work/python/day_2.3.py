'''name ='sai'
def student1():
    name ='bob'   
    print name

student1()
print name 
'''
name ='sai'

def student2():
#    global name
    name ='bob'
    print "inside",name
student2()
print "outside",name
