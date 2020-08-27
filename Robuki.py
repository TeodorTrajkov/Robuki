import serial
import rospy
import std_msgs
import kobuki_msgs.msg
import sensor_msgs.msg
from geometry_msgs.msg import Twist
import time
from math import radians
import subprocess
from pynput.keyboard import Key, Listener

#subprocess.call("chmod 755 Launch.sh", shell=True)
#subprocess.call("nohup ./Launch.sh &", shell=True)

rospy.init_node("kobuki")
ard = serial.Serial('/dev/ttyACM0', 9600)
print(ard)

pub = rospy.Publisher('loginfo', std_msgs.msg.String, queue_size=10)
cmd_vel = rospy.Publisher('mobile_base/commands/velocity', Twist, queue_size=10)
led1 = rospy.Publisher('mobile_base/commands/led1', kobuki_msgs.msg.Led, queue_size=10)
led2 = rospy.Publisher('mobile_base/commands/led2', kobuki_msgs.msg.Led, queue_size=10)

back = False

def processBump(data):
        if data.bumper == 0 and data.state == 0:
                rospy.loginfo("Left Bumper Released")
        if data.bumper == 0 and data.state == 1:
                rospy.loginfo("Left Bumper Pressed")
        if data.bumper == 1 and data.state == 0:
                rospy.loginfo("Front Bumper Released")
        if data.bumper == 1 and data.state == 1:
                rospy.loginfo("Front Bumper Pressed")
        if data.bumper == 2 and data.state == 0:
                rospy.loginfo("Right Bumper Released")
        if data.bumper == 2 and data.state == 1:
                rospy.loginfo("Right Bumper Pressed")
                
rospy.Subscriber('mobile_base/events/bumper', kobuki_msgs.msg.BumperEvent, processBump)

def processButt(data):
        if data.button == 0 and data.state == 0:
                rospy.loginfo("Button 0 Released")
        if data.button == 0 and data.state == 1:
                rospy.loginfo("Button 0 Pressed")
        if data.button == 1 and data.state == 0:
                rospy.loginfo("Button 1 Released")
        if data.button == 1 and data.state == 1:
                rospy.loginfo("Button 1 Pressed")
        if data.button == 2 and data.state == 0:
                rospy.loginfo("Button 2 Released")
        if data.button == 2 and data.state == 1:
                rospy.loginfo("Button 2 Pressed")

rospy.Subscriber('mobile_base/events/button', kobuki_msgs.msg.ButtonEvent, processButt)

def processBatt(data):
        if data.event == 4:
                led2.publish(2)
                rospy.loginfo("LOW BATTERY")
        if data.event == 5:
                led2.publish(3)
                rospy.loginfo("!CRITICAL BATTERY!")

rospy.Subscriber('mobile_base/events/power_system', kobuki_msgs.msg.PowerSystemEvent, processBatt)

def processWheelDrop(data):
        if data.wheel == 0 and data.state == 0:
                rospy.loginfo("Left Wheel Raised")
        if data.wheel == 0 and data.state == 1:
                rospy.loginfo("Left Wheel Dropped")
        if data.wheel == 1 and data.state == 0:
                rospy.loginfo("Right Wheel Raised")
        if data.wheel == 1 and data.state == 1:
                rospy.loginfo("Right Wheel Dropped")
                
rospy.Subscriber('mobile_base/events/wheel_drop', kobuki_msgs.msg.WheelDropEvent, processWheelDrop)

def shutdown():
	led1.publish(2)
	time.sleep(0.3)
	led1.publish(0)
	time.sleep(0.3)
	led1.publish(2)
	time.sleep(0.3)
	led1.publish(0)
	rospy.loginfo("STOP!")
	cmd_vel.publish(Twist())
	rospy.sleep(1)

rospy.on_shutdown(shutdown)

move_cmd = Twist()

def MoveForward():
        move_cmd.linear.x = 0.3
        cmd_vel.publish(move_cmd)
        
def MoveBackward():
        move_cmd.linear.x = -0.3
        cmd_vel.publish(move_cmd)

def StopLinear():
        move_cmd.linear.x = 0
        cmd_vel.publish(move_cmd)
        
def TurnLeft():
        if back == False:
                move_cmd.angular.z = radians(70)
                cmd_vel.publish(move_cmd)
        if back == True:
                move_cmd.angular.z = -radians(70)
                cmd_vel.publish(move_cmd)
        
def TurnRight():
        if back == False:
                move_cmd.angular.z = -radians(70)
                cmd_vel.publish(move_cmd)
        if back == True:
                move_cmd.angular.z = radians(70)
                cmd_vel.publish(move_cmd)

def StopAngular():
        move_cmd.angular.z = 0
        cmd_vel.publish(move_cmd)

def on_press(key):
        if key.char == 'g':
                ard.write(b'1')
                
        if key.char == 'k':
                ard.write(b'2')
                
        if key.char == 'h':
                ard.write(b'3')
                
        if key.char == '-':
                ard.write(b'4')
                
        if key.char == 'o':
                ard.write(b'5')
                
        if key.char == 'u':
                ard.write(b'6')
                
        if key.char == 't':
                ard.write(b'7')
                
        if key.char == 'i':
                ard.write(b'8')
                
        if key.char == 'y':
                ard.write(b'9')
                
        if key.char == '=':
                ard.write(b'a')
                
        if key.char == 'l':
                ard.write(b'b')
                
        if key.char == 'j':
                ard.write(b'c')

#-----------------------------------------

        if key.char == 'w':
                MoveForward()
        if key.char == 's':
                global back
                back = True
                MoveBackward()
        if key.char == 'a':
                TurnLeft()
        if key.char == 'd':
                TurnRight()
        
def on_release(key):
        if key.char == 't' or key.char == 'y' or  key.char == 'u' or  key.char == 'i' or  key.char == 'o':
                ard.write(b'S')
        if key.char == 'g' or  key.char == 'h' or  key.char == 'j' or  key.char == 'k' or  key.char == 'l':
                ard.write(b'S')
        if key.char == '-' or  key.char == '=':
                ard.write(b'S')
                
        if key.char == 'w':
                StopLinear()
        if key.char == 's':
                global back
                back = False
                StopLinear()
        if key.char == 'a' or key.char == 'd':
                StopAngular()
        

listen = Listener(on_press=on_press, on_release = on_release)
listen.start()

while not rospy.is_shutdown():
       led1.publish(3) # color: 0 - 3
       time.sleep(1)
       led1.publish(1) # color: 0 - 3
       time.sleep(1)
"""        for x in range(3):
                move_cmd.linear.x = 0.1
                cmd_vel.publish(move_cmd)
                time.sleep(0.5)
        for x in range(3):
                move_cmd.linear.x = -0.1
                cmd_vel.publish(move_cmd)
                time.sleep(0.5)
"""
