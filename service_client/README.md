### How to run (bash window 1)
- Source setup files `. install/setup.bash`
- Run service node `ros2 run service_client server`

### How to run (bash window 2)
- Source setup files `. install/setup.bash`
- Run listener node `ros2 run service_client client 3 5` which will return response from service node `8`
