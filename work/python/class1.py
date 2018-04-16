class vechicle:
    def __init__(self,speed,number,color):
        self.speed=speed
	self.number=number
	self.color=color
     
    def start(self):
        print "strating"

    def stop(self):
        print "stoping"

    def accerelate(self):
       print"accerelate"

    def break_(self):
        print "breaking. ."



class plane(vechicle):#inheritance from vechicle
        #def __init__(self,speed,number,color):
        #vechicle.__init__(self,speed,number,color)
	def fly(self):
            print "flying"

plane = plane(300,707,'blue')

plane.start()

