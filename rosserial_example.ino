
 //-------------------------------Rosserial---------------------------------
 #include <ros.h>
 #include <std_msgs/Float32.h>

//---------------------------ROS Functions--------------------------------------
std_msgs::Float32 msg;
ros::Publisher pub("data", &msg);

//-------------------------------MAIN CODE ------------------------------------
void setup(){
  Serial.begin(57600);

  //ros start
  nh.initNode();
  nh.advertise(pub);   

}

void loop() {
  //publish data
  msg.data = 10.0;
  pub.publish(&msg);
 }
}
