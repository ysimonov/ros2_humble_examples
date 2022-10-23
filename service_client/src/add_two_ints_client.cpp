#include "example_interfaces/srv/add_two_ints.hpp"
#include "rclcpp/rclcpp.hpp"

#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
    // Initialize ROS 2 C++ client library
    rclcpp::init(argc, argv);

    // Check the number of command line arguments
    if (argc != 3)
    {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "usage: add_two_ints_client X Y");
        return 1;
    }

    // Create a node named add_two_ints_client
    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_two_ints_client");

    // Create a client named add_two_ints for that node that listens to
    // service response on topic add_two_ints
    rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedPtr client =
        node->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");

    // Create a request. Its structure is defined by the .srv
    auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
    request->a = atoll(argv[1]);
    request->b = atoll(argv[2]);

    // The while loop gives the client 1 second to search for service nodes in the network.
    while (!client->wait_for_service(1s))
    {
        if (!rclcpp::ok())
        {
            // If the client is canceled (e.g. by you entering Ctrl+C into the terminal),
            // it will return an error log message stating it was interrupted.
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
            return 0;
        }

        // If it can’t find any, it will continue waiting.
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
    }

    auto result = client->async_send_request(request);
    // Wait for the result.
    if (rclcpp::spin_until_future_complete(node, result) == rclcpp::FutureReturnCode::SUCCESS)
    {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sum: %ld", result.get()->sum);
    }
    else
    {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service add_two_ints");
    }

    rclcpp::shutdown();
    return 0;
}