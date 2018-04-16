import re

text='abbaaabbbbaaaaa'
pattern='ab'

for match in re.findall(pattern,text):
    print 'found %s' %match
