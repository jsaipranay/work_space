class circle:
    def __init__(self,rad):
        self.radius =rad
    def area(self):
        return 3.14*self.radius*self.radius 


circle1=circle(10)
circle2=circle(20)
circle1.colour ="blue"

print circle1.colour
print dir(circle1)
print dir(circle2)
#print circle2.colour
print circle1.__dict__
print circle.__dict__
