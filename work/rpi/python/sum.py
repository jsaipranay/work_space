def find_sum():
    x=open('num.txt','r')
    for line in x:
        total=0
        numbers_as_strings = line.strip().split()
        for each_num_string in numbers_as_strings:
            total=total+int(each_num_string)
        print total
find_sum()
'''
def find_sum():
    x=open('num.txt','r')
    for line i x:
        print sum([int (num_string) for num_string in line,strip().split()])
'''
