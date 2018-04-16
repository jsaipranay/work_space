def get_text(name):
    return "hello,{0}".format(name)
@p_decorate

def p_decorate(func):
    def func_wrapper(name):
        return "<p>"+func(name)+"<p>"
    return func_wrapper

my_get_text=p_decorate(get_text)
print my_get_text("john")

'''
def p_decorate(func):
    def func_wrapper(name):
        return "<p>"+func(name)+"</p>"
    return func_wrapper

def strong_decorate(func):
    def func_wrapper(name):
        return "<strong>"+func(name)+"</strong>"
    return func_wrapper
#@div_decorate
@strong_decorate
@p_decorate

def get_text(name):
    return "hello,{0}".format(name)    

get_text=p_decorate(strong_decorate(get_text))
print get_text("john")


'''
