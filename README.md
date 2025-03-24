# SLAM_AGV
This repository encapsulates code for an AGV robot controlled with ROS  and uses LiDAR to achieve Simultaneous Localization and Mapping (SLAM)

## BUILDING THE WORKSPACE 🔨
1. Clone the repository
    
    ```
    git clone --recurse-submodules https://github.com/Trevor369-ad/SLAM_AGV.git
    ```
2. This project depends on packages that are not pulled as submodules, get them:
    ```
    sudo apt update
    sudo apt install ros-humble-ros2-control
    sudo apt install ros-humble-teleop-twist-joy
    sudo apt install ros-humble-teleop-twist-keyboard
    sudo apt install libserial-dev
    ```
3. Start building the packages, building without the --packages-select argument will make colcon build the entire 
    ros2_controllers submodule.
    1. First run the rosdep command
        ```
        cd workspace
        rosdep install --from-paths src --ignore-src -r -y


        ```
    2. Build the packages,
        for systems with less than 4GB of RAM, I recommend building with the ```--executor sequential``` argument to limit resource use, for those with 8GB of RAM ```--parallel-workers 2``` will do.
        ```
        colcon build --symlink-install --packages-select ros2_controllers_test_nodes  mecanum_drive_controller joint_state_broadcaster serial mecanum_drive_stm twist_converter joy_tester columbus
        ```
    
## LAUNCHING THE ROBOT 🚀
1.  First source the environment
    ```
    source install/setup.bash  
    ```
    Launch the joystick controller with
    ```
    ros2 launch columbus joystick.launch.py
    ```
    Edit the /workspace/src/columbus/config/joystick.yaml to match your controller and prefered controls,
        read more about it [here](https://wiki.ros.org/teleop_twist_joy)

    Run ```ros2 run joy joy_enumerate_devices``` to find the device ID of your controller.
    
    Use the included [joy_tester](https://github.com/joshnewans/joy_tester) to test the joystick

2. Run the twist_converter
    ```
    ros2 run twist_converter twist_converter
    ```
    This node converts the Twist type message published by the Joystick controller node and converts it to TwistStamped 
    message type that the mecanum_drive_controller accepts.
3. Launch the robot
    ```
    ros2 launch columbus launch_robot.launch.py
    ```
    Edit the /workspace/src/columbus/description/ros2_control.xacro parameters to connect to your stm controller.

    **Make sure you have the right permissions to access the specified port otherwise the controller manager will fail**
    
    Run ```sudo chmod a+rw <device-port>``` to give all users read and write permissions to the specified port (adjust this according to your needs), this allows our
    hardware interface to communicate with the microcontroller.

That's it the robot your robot is up and running! 🎉


    ```

6. Run the "Hello World" node:
    ```bash
    ros2 run hello_world hello_world_node
    ```

You should see the following output in your terminal:
 ```
This example demonstrates how to create and run a basic ROS 2 node. 🎉 ```
