def fab(n):
    if n in (0,1):
        return 1
    else:
        return fab(n-1)+fab(n-2)



#print fab(5)

def cached_function(func):
    cached =dict()
    def wrapper(n):
        if n in cached:
            return cached[n]
        else:
            value=func(n)
            cached[n]=value
            return value
    return wrapper
@cached_function
def fab1(n):
    return 1 if n in (0,1) else fab(n-1)+fab(n-2)

print fab1(30)

import sys
dir(sys)
