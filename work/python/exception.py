try:
   	print xyz 
	y=1/0   
        x=(1,2,3)
	x.upper()
except ZeroDivisionError:
    print"pls dont divide by 0"
except AttributeError:
    print "no such attribute"

except NameError:
    print "no such name.."
import traceback
#try:
 #   1/0
#except Exception:
 #   print  traceback.formate_exec(3)
class custom_error(Exception):
    pass
try:
    1/0
except:
    raise custom_error

