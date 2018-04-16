import re

patterns=['this','that']
text='does this text match the pattern?'

for pattern in patterns:
    print 'looking for "%s" in "%s"->'%(pattern,text),

if re.search(pattern,text):
    print 'found tha match!'
else:
    print 'no match'

