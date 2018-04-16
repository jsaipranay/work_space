def tags(tag_name):
    def tags_decorator(func):
        def func_wrapper(name):
            return "<{0}>{1}<{0}>".format(tag_name,func(name))
        return func_wrapper
    return tags_decorator

@tags("p")
def get_text(name):
    return "hello"+name



print get_text("john")











print get_text("john")
