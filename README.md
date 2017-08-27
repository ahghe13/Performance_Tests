# Performance_Tests

Four nodes are written in this project:
- Publisher written in C++
- Publisher written in Python
- Subscriber written in C++
- Subscriber written in Python

The C++ publisher publishes the message: "Hello Blue Ocean Robotics! This is the c++ publisher" on the topic: "pub_cpp".
The Python publisher publishes the message: "Hello Blue Ocean Robotics! This is the Python publisher" on the topic: "pub_py".
The publisher nodes take the publishing rate as an input argument.

The subscribers takes the topic as an input argument. Then, they count the rate at which the publishers publishes their messages.


The goal is to find the maximum rate, at which each publisher is able to publish messages.

The results are to be found in the file: "Performance tests - Results.pdf"