import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/jowi/dev_ws/install/ros2_controllers_test_nodes'
