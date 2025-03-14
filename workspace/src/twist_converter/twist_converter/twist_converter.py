import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, TwistStamped

class TwistToTwistStampedNode(Node):
    def __init__(self):
        super().__init__('twist_to_twiststamped_converter')
        
        # Subscribe to the standard teleop_twist_keyboard output
        self.subscription = self.create_subscription(
            Twist,
            '/cmd_vel',  # Default topic for teleop_twist_keyboard
            self.twist_callback,
            10)
            
        # Publisher for the TwistStamped message
        self.publisher = self.create_publisher(
            TwistStamped,
            'mecanum_cont/reference',
            10)
    
    def twist_callback(self, twist_msg):
        # Create a new TwistStamped message
        stamped_msg = TwistStamped()
        
        # Set the timestamp to current time
        stamped_msg.header.stamp = self.get_clock().now().to_msg()
        stamped_msg.header.frame_id = "base_link"
        
        # Copy the twist data
        stamped_msg.twist = twist_msg
        
        # Publish the TwistStamped message
        self.publisher.publish(stamped_msg)
        self.get_logger().info('Converting twist to twiststamped')

def main(args=None):
    rclpy.init(args=args)
    node = TwistToTwistStampedNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
