import bge
from ctypes import*
cont=bge.logic.getCurrentController()
owner=bge.logic.getCurrentController().owner
own=cont.owner
mydll= cdll.LoadLibrary("C:\\Users\\pierr\\Desktop\Ecole\\tpe\\open cv test\\Open cv tracking 1\\x64\\Debug\\dllquimarche1.dll")
x=0
rotationspeed=0
timer=own['timer']
def main():
	x=mydll.returnx()
	print(x)
	if x>50:
        rotationspeed=0.005
	if x<-50:
        rotationspeed=-0.005
	if x<50 and x>-50:
        rotationspeed=0  
	i=0
	while (i==0):
    	if timer==0:
        	if own["delay"] >= (own["start"] + own["break"]):
                own['p'] ==0.002
        	
                own['start']=own['delay']
            	print (own['p'] ) 
                owner.applyRotation([0,0,rotationspeed])
    	else:
            owner.applyRotation([0,0,rotationspeed])
    	i+=1
main()	
