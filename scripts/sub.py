#!/usr/bin/env python
#Inspired from: http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28python%29

import rospy, sys
from performance_tests.msg import SuperAwesome

rate = 0
begin = 0

def Subscriber_Function(data):
	global rate
	global begin

	#Count the number of messages received
	rate += 1

	#If a second has passed, the number of messages received so far is the rate
	if rospy.get_rostime().secs-begin > 0:
		print "Rate: ", rate
		rate = 0
		begin = rospy.get_rostime().secs


def listener():
	#Initialize ROS
	rospy.init_node('Subscriber_python', anonymous=True)

	#Subscribe the desired topic
	rospy.Subscriber(sys.argv[1], SuperAwesome, Subscriber_Function)

	#Initialize the begin time parameter
	global begin
	begin = rospy.get_rostime().secs

	rospy.spin()

if __name__ == '__main__':	
	listener()