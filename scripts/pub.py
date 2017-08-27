#!/usr/bin/env python
#Inspired from: http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28python%29

import rospy, sys
from performance_tests.msg import SuperAwesome

def publish_function():
    #Initialize ROS
    rospy.init_node('Publisher_py', anonymous=True)

    #Create a publisher
    pub = rospy.Publisher('pub_py', SuperAwesome, queue_size=10)

    #Specify the rate
    rate = rospy.Rate(int(sys.argv[1]))

    #Set a message
    message = "Hello Blue Ocean Robotics! This is the Python publisher"

    #Keep publishing messages
    while not rospy.is_shutdown():
        pub.publish(message)
        rate.sleep()

if __name__ == '__main__':
    try:
        publish_function()
    except rospy.ROSInterruptException:
        pass