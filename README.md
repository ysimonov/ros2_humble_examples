# ros2_publisher_subscriber
Example of ros2 publisher / subscriber in C++

# How to set up this type of project
- `ros2 pkg create --build-type amend_cmake ${package_name}` (replace `${package_name}` with your own name, for example, `cpp_publisher_subscriber`, in my case)

# How to build the package
- `cd cpp_publisher_subscriber` 
- To install required packages from src `rosdep install -i --from-path src --rosdistro humble -y`
- Build the package `colcon build --packages-select cpp_publisher_subscriber`

# How to run (bash window 1)
- Source setup files `. install/setup.bash`
- Run talker node `ros2 run cpp_publisher_subscriber talker`

# How to run (bash window 2)
- Source setup files `. install/setup.bash`
- Run listener node `ros2 run cpp_publisher_subscriber listener`