import re

text='abbaababababaaaa'
pattern ='ab'

for match in re.finditer(pattern,text):
    s=match.start()
    e=match.end()
    print 'found "%s" at %d:%d' %(text[s:e],s,e)

