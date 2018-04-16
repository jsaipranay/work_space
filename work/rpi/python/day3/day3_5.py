''' def great(name):
    return "hi",name
num=range
print num(10)


'''
'''
#fun inside a func
def greet(name):
    def get_msg():
        return "hello"
    result=get_msg()+name
    return result
print  greet("john")

'''
'''#func can be passed as parameter to other func
def greet(name):
    return "hello"+name
def call_func(func):
    other_name="john"
    return func(other_name)

print call_func(greet)



'''


#dunc can return othrt func

def compose_greet_func(name):
    def get_message():
        return "hello there!"+name+"!"
    return get_message
greet=compose_greet_func('john')
print greet()

