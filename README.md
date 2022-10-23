# ros2_publisher_subscriber
ROS Humble Examples

# Install Ros2 Humble
- Follow https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html
- Instead of `ros-humble-desktop` use `ros-humble-desktop-full`
- Inside of `~/.bashrc` add `source /opt/ros/humble/setup.bash` after installation of ros2

# Install Additional VSCode Extensions
- `sudo apt install clang-format`
- CMake
- CMake Tools
- Clang-Format
- C/C++ Extension Pack
- ROS
- XML Tools

# Setup VSCode
Inside of `Settings/Open Settings (JSON)` paste the following:
```json
{
    "ros.distro": "humble",
    "editor.formatOnSave": true,
    "editor.minimap.enabled": false,
    "editor.codeActionsOnSave": {
        "source.fixAll": true
    },
    "C_Cpp.intelliSenseEngine": "Default",
    "C_Cpp.default.includePath": [
        "${workspaceFolder}/**",
        "/opt/ros/humble/include/**"
    ],
    "clang-format.executable": "/usr/bin/clang-format",
    "clang-format.language.c.enable": true,
    "clang-format.language.cpp.enable": true,
    "clang-format.language.cuda.enable": true,
    "clang-format.style": "Microsoft",
    "[cpp]": {
        "editor.defaultFormatter": "xaver.clang-format",
        "editor.wordBasedSuggestions": false,
        "editor.suggest.insertMode": "replace",
        "editor.semanticHighlighting.enabled": true
    },
    "[c]": {
        "editor.defaultFormatter": "xaver.clang-format",
        "editor.wordBasedSuggestions": false,
        "editor.suggest.insertMode": "replace",
        "editor.semanticHighlighting.enabled": true
    },
    "[cuda-cpp]": {
        "editor.defaultFormatter": "xaver.clang-format",
        "editor.wordBasedSuggestions": false,
        "editor.suggest.insertMode": "replace",
        "editor.semanticHighlighting.enabled": true
    },
    "xmlTools.enableXmlTreeView": true,
    "xmlTools.xmlFormatterImplementation": "v2"
}
```

# How to set up this type of project
- `ros2 pkg create --build-type ament_cmake ${package_name} --dependencies ${list_of_dependencies}` (replace `${package_name}` with your own name, for example, `cpp_publisher_subscriber`, in my case, and `${list_of_dependencies}` with your dependencies, separated by space, for example `rclcpp example_interfaces`)

# How to build the package
- `cd cpp_publisher_subscriber` 
- Check for missing dependencies before building the package `rosdep install -i --from-path src --rosdistro humble -y`
- Build the package `colcon build --packages-select publisher_subscriber`