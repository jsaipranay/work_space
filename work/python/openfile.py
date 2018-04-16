'''try:
    open(file)
    do something
except:
    handler exception
finally:
    close file'''
with open('num.txt','r')as my_file:
    for lines in my_file:
        print lines
y_file.readlines()
