def p_decorate(func):
    def func_wrapper(self):
        #return "<p>{0}<p>".format(func(self))
        return "<p>{0}<p>".format(func(*args,**kwargs))
    return func_wrapper


class person(object):
    def __init__(self):
        self.name="john"
        self.family="doe"


@p_decorate
def get_fullname(self):
    return self.name+""+self.family


my_person=person()













my_person=person()
