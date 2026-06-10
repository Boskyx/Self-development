import rclpy
from rclpy.node import Node

from std_msgs.msg import String


class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(String, 'topic', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = String()
        msg.data = 'Hello World: %d' % self.i
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)
        self.i += 1


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()



import rclpy
from rclpy.node import Node
# Using a standard service type that requires no input and returns a success flag and a message
from std_srvs.srv import Trigger 

class HelloServiceServer(Node):
    def __init__(self):
        super().__init__('hello_service_server')
        # 1. Create the service: service type, service name, callback function
        self.srv = self.create_service(Trigger, 'get_hello_service', self.hello_callback)
        self.get_logger().info('Hello Service Server started. Waiting for requests...')

    def hello_callback(self, request, response):
        # The request is received, now we prepare the response
        response.success = True # Set the success flag
        response.message = "Hello ROS 2 (Service Response)" # The "hello" string response
        
        self.get_logger().info('Incoming request received. Responding with "Hello ROS 2".')
        return response

def main(args=None):
    rclpy.init(args=args)
    hello_server = HelloServiceServer()
    rclpy.spin(hello_server)
    rclpy.shutdown()

if __name__ == '__main__':
    main()