#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <rclcpp/qos.hpp>


class PublisherNode : public rclcpp::Node {
    private: 





    public:
        PublisherNode(): Node("publisher"){
            auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
            auto rmw = qos_profile.get_rmw_qos_profile();
            std::string reliability = (rmw.reliability == RMW_QOS_POLICY_RELIABILITY_RELIABLE) ? "Reliable" : "Best Effort";

            auto msg = std_msgs::msg::String();

            std::stringstream ss;
            ss << reliability;
            msg.data = ss.str();

            RCLCPP_INFO(this->get_logger(), "%s", msg.data.c_str());
        }


};


int main(int argc, char** argv){

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PublisherNode>());
    rclcpp::shutdown();
    return 0;



}