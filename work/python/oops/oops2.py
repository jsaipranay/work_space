class Employ:
	def  __init__(self,num,name,salary):
		self.num=num
		self.name=name
		self.salary=salary
	def printdata(self):
		print'empid:{},empname:{},empsalary:{}'.format(self.num,self.name,self.salary)
	def calculatetax(self):
		slab=(self.salary*12)-3000
		tax=0;
		if slab>0:
			tax=slab*0.1
			print "tax for empid:{} is{}".format(self.num,tax)


e1=Employ(1234,'sai',2500)
e2=Employ(5678,'pranay',3500)
e1.printdata()
e2.printdata()
e1.calculatetax()
e2.calculatetax()









