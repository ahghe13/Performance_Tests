//Inspired from: http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29

#include "ros/ros.h"

//Customized message
#include <performance_tests/SuperAwesome.h>

using namespace ros;

int main(int argc, char** argv) {
	//Make sure an input is given
	if (argc == 1) {
		ROS_INFO("Please provide a publish rate");
		return -1;
	}

	// Initialize ROS
	init(argc, argv, "Publisher_cpp");
	NodeHandle n;

	//Create the publisher topic
	Publisher pub = n.advertise<performance_tests::SuperAwesome>("pub_cpp", 1000);

	//Set the publish rate
	Rate loop_rate(atoi(argv[1]));

	//Create a message to send
	performance_tests::SuperAwesome msg;
	msg.message = "Hello Blue Ocean Robotics! This is the c++ publisher";

	while(ok()) {
		//Publish the message
		pub.publish(msg);

		spinOnce();
		loop_rate.sleep();
	}

	// Spin
	spin ();
}
