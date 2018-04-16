import threading
import time

def worker():
    print threading.currentThread().getName(),'staring'
    time.sleep(2)
    print threading.currentThread().getName(),'Exiting'

def my_service():
    print threading.currentThread().getName(),'staring'
    time.sleep(3)
    print threading.currentThread().getName(),'Exiting'
 

t=threading.Thread(name='my_service',target=my_service)
w=threading.Thread(name='worker',target=worker)
w2=threading.Thread(target=worker) #use dafult name


w.start()
w2.start()
t.start()

'''Thread-1 staring
my_service staring
Thread-1 Exiting
my_service Exiting
'''
