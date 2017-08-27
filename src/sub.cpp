//Inspired from: http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29

#include "ros/ros.h"

//Customized message
#include <performance_tests/SuperAwesome.h>

using namespace ros;

int rate = 0;
Time begin;

void Subscribe_function(const performance_tests::SuperAwesome msg) {
	//Count the number of messages received
	rate++;

	//If a second has passed, the number of messages received so far is the rate
	if(Time::now().toSec()-begin.toSec() > 1) {
		std::cout << "Rate: " << rate << std::endl;
		rate = 0;
		begin = Time::now();
	}
}

int main(int argc, char **argv) {
	//Make sure an input is given
	if (argc == 1) {
		std::cout << "Please provide a topic name" << std::endl;
		return -1;
	}

	// Initialize ROS
	init(argc, argv, "Subscriber_cpp");
	NodeHandle n;

	//Create subscriber object
	Subscriber sub = n.subscribe(argv[1], 1000, Subscribe_function);
	begin = Time::now();

	spin();

	return 0;
}