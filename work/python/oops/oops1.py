class Employ:
	def __init__(self):
		self.num=10
		self.name='sai'
		self.salary=2500.0

	def getsalary(self):
		return self.salary
	def getname(self):
		return self.name
	def printEmploy(self):
    		print 'num=',self.num,'name=',self.name,'sal=',self.salary

e1=Employ()
e2=Employ()	
'''e1.num=1234
e1.name='sai'
e1.salary=2500.50'''
#print e1.num,e1.name,e1.salary
print e1.printEmploy()
print e1.getname()
print e1.getsalary()
print id(e1),id(e2)
