import threading
import logging

logging.basicConfig(leve;=logging.DEBUG,format='%(threadName)-10s)%(message)s',)
class mythread(threading.Thread):

    def run(self):
        logging.debug('running')
        return


for in in range(5):
    t=mythread()
    t.start()
