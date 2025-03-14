import serial
import time

import rclpy
from rclpy.node import Node
from control_msgs.msg import MecanumDriveControllerState

RAD_TO_RPM = 60 / (2 * 3.14159265358979)

# Adjust the serial port and baud rate to match STM32 settings
BAUD_RATE = 9600 # Adjust based on STM32 settings
SERIAL_PORT = ' '


class MecanumControllerNode(Node):
    def __init__(self):
        super().__init__('mecanum_controller_interface')
        
        # Subscribe to the mecanum controller state interface
        self.subscription = self.create_subscription(
            MecanumDriveControllerState,
            '/mecanum_cont/controller_state',  # Topic for controller interface
            self.radians_2_rpm_callback,
            10)
        
        """ 
        # Publisher for the TwistStamped message
        self.publisher = self.create_publisher(
            TwistStamped,
            'mecanum_cont/reference',
            10)
        """
        self.get_logger().info(f"Using Serial Port: {SERIAL_PORT}")

        # Open Serial Connection
        try:
            self.ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
            self.get_logger().info(f"Connected to {SERIAL_PORT}")
        except serial.SerialException as e:
            self.get_logger().error(f"Failed to open serial port: {str(e)}")
            return
        

        # mecanum_drive_controller_state_msg
    def radians_2_rpm_callback(self, state_msg):

        wheel_velocities_rpm = [
            state_msg.front_left_wheel_velocity * RAD_TO_RPM,
            state_msg.front_right_wheel_velocity * RAD_TO_RPM,
            state_msg.back_left_wheel_velocity * RAD_TO_RPM,
            state_msg.back_right_wheel_velocity * RAD_TO_RPM
        ]
        
        command_data = f'V {wheel_velocities_rpm}'
        self.get_logger().info(f'wheel velocities converted -> {wheel_velocities_rpm}')

    def read_data(self):
        """Read data from serial port and print it."""
        start = time.time()
        try:
            while True:
                now = time.time()
                if now - start > 5:
                    return None
                if self.ser.in_waiting > 0:
                    line = self.ser.readline().decode('utf-8').strip()
                    if line:
                        self.get_logger().info(f"Received: {line}")
                        return line
        except Exception as e:
            self.get_logger().error(f"Error reading from serial port: {str(e)}")
            
    def send_data(self, msg):
        """Send data to the STM32 via the serial port."""
        try:
            data = msg + '\n'  # Ensure newline for STM32 to parse correctly
            self.ser.write(data.encode('utf-8'))
            self.get_logger().info(f"Sent: {msg}")
        except Exception as e:
            self.get_logger().error(f"Error writing to serial port: {str(e)}")

    def cleanup(self):
        if self.ser.is_open:
            self.ser.close()
            
def main(args=None):
    rclpy.init(args=args)
    node = MecanumControllerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()