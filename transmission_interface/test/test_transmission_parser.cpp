// Copyright 2020 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <gmock/gmock.h>
#include <string>
#include <vector>

#include "transmission_interface/transmission_parser.hpp"

using namespace ::testing;  // NOLINT

class TestTransmissionParser : public Test
{
public:
  void SetUp() override
  {
    valid_urdf_xml_ =
      R"(
    <?xml version="1.0" ?>
<!-- =================================================================================== -->
<!-- |    This document was autogenerated by xacro from rrbot.urdf.xacro        | -->
<!-- |    EDITING THIS FILE BY HAND IS NOT RECOMMENDED                                 | -->
<!-- =================================================================================== -->
<robot name="rrbot" xmlns:xacro="http://www.ros.org/wiki/xacro">
  <!-- Build your comprehensive robot -->
  <link name="world"/>
  <gazebo reference="world">
    <static>true</static>
  </gazebo>
  <joint name="rrbot_fixed" type="fixed">
    <origin rpy="0 0 0" xyz="0 0 0"/>
    <parent link="world"/>
    <child link="rrbot_link1"/>
  </joint>
  <link name="rrbot_link1">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 1.0"/>
      <geometry>
        <box size="0.1 0.1 2"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 1.0"/>
      <geometry>
        <box size="0.1 0.1 2"/>
      </geometry>
      <material name="RRBOT/orange"/>
    </visual>
    <inertial>
      <origin rpy="0 0 0" xyz="0 0 1.0"/>
      <mass value="1"/>
      <inertia ixx="1.0" ixy="0.0" ixz="0.0" iyy="1.0" iyz="0.0" izz="1.0"/>
    </inertial>
  </link>
  <joint name="rrbot_joint1" type="continuous">
    <parent link="rrbot_link1"/>
    <child link="rrbot_link2"/>
    <origin rpy="0 0 0" xyz="0 0.1 1.95"/>
    <axis xyz="0 1 0"/>
    <dynamics damping="0.7"/>
  </joint>
  <link name="rrbot_link2">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <geometry>
        <box size="0.1 0.1 1"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <geometry>
        <box size="0.1 0.1 1"/>
      </geometry>
      <material name="RRBOT/black"/>
    </visual>
    <inertial>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <mass value="1"/>
      <inertia ixx="1.0" ixy="0.0" ixz="0.0" iyy="1.0" iyz="0.0" izz="1.0"/>
    </inertial>
  </link>
  <joint name="rrbot_joint2" type="continuous">
    <parent link="rrbot_link2"/>
    <child link="rrbot_link3"/>
    <origin rpy="0 0 0" xyz="0 0.1 0.9"/>
    <axis xyz="0 1 0"/>
    <dynamics damping="0.7"/>
  </joint>
  <link name="rrbot_link3">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <geometry>
        <box size="0.1 0.1 1"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <geometry>
        <box size="0.1 0.1 1"/>
      </geometry>
      <material name="RRBOT/orange"/>
    </visual>
    <inertial>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <mass value="1"/>
      <inertia ixx="1.0" ixy="0.0" ixz="0.0" iyy="1.0" iyz="0.0" izz="1.0"/>
    </inertial>
  </link>
  <joint name="rrbot_hokuyo_joint" type="fixed">
    <axis xyz="0 1 0"/>
    <origin rpy="0 0 0" xyz="0 0 0.975"/>
    <parent link="rrbot_link3"/>
    <child link="rrbot_hokuyo_link"/>
  </joint>
  <link name="rrbot_hokuyo_link">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <box size="0.1 0.1 0.1"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <box size="0.1 0.1 0.1"/>
      </geometry>
    </visual>
    <inertial>
      <mass value="1e-5"/>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <inertia ixx="1e-6" ixy="0" ixz="0" iyy="1e-6" iyz="0" izz="1e-6"/>
    </inertial>
  </link>
  <joint name="rrbot_camera_joint" type="fixed">
    <axis xyz="0 1 0"/>
    <origin rpy="0 0 0" xyz="0.05 0 0.9"/>
    <parent link="rrbot_link3"/>
    <child link="rrbot_camera_link"/>
  </joint>
  <link name="rrbot_camera_link">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <box size="0.05 0.05 0.05"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <box size="0.05 0.05 0.05"/>
      </geometry>
      <material name="RRBOT/red"/>
    </visual>
    <inertial>
      <mass value="1e-5"/>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <inertia ixx="1e-6" ixy="0" ixz="0" iyy="1e-6" iyz="0" izz="1e-6"/>
    </inertial>
  </link>
  <transmission name="rrbot_tran1">
    <type>transmission_interface/SimpleTransmission</type>
    <joint name="rrbot_joint1">
      <hardwareInterface>PositionJointInterface</hardwareInterface>
    </joint>
    <actuator name="rrbot_motor1">
      <mechanicalReduction>1</mechanicalReduction>
      <hardwareInterface>PositionJointInterface</hardwareInterface>
    </actuator>
  </transmission>
  <transmission name="rrbot_tran2">
    <type>transmission_interface/SimpleTransmission</type>
    <joint name="rrbot_joint2">
      <hardwareInterface>VelocityJointInterface</hardwareInterface>
    </joint>
    <actuator name="rrbot_motor2">
      <mechanicalReduction>60</mechanicalReduction>
      <hardwareInterface>VelocityJointInterface</hardwareInterface>
    </actuator>
  </transmission>
  <gazebo reference="rrbot_link1">
    <material>Gazebo/Orange</material>
  </gazebo>
  <gazebo reference="rrbot_link2">
    <mu1>0.2</mu1>
    <mu2>0.2</mu2>
    <material>Gazebo/Black</material>
  </gazebo>
  <gazebo reference="rrbot_link3">
    <mu1>0.2</mu1>
    <mu2>0.2</mu2>
    <material>Gazebo/Orange</material>
  </gazebo>
  <gazebo>
    <plugin name="gazebo_ros_control" filename="libgazebo_ros_control.so">
    </plugin>
  </gazebo>
</robot>
  )";

    wrong_urdf_xml_ =
      R"(
    <?xml version="1.0" ?>
<!-- =================================================================================== -->
<!-- |    This document was autogenerated by xacro from rrbot.urdf.xacro        | -->
<!-- |    EDITING THIS FILE BY HAND IS NOT RECOMMENDED                                 | -->
<!-- =================================================================================== -->
<robot name="rrbot" xmlns:xacro="http://www.ros.org/wiki/xacro">
  <!-- Build your comprehensive robot -->
  <link name="world"/>
  <gazebo reference="world">
    <static>true</static>
  </gazebo>
  <joint name="rrbot_fixed" type="fixed">
    <origin rpy="0 0 0" xyz="0 0 0"/>
    <parent link="world"/>
    <child link="rrbot_link1"/>
  </joint>
  <link name="rrbot_link1">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 1.0"/>
      <geometry>
        <box size="0.1 0.1 2"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 1.0"/>
      <geometry>
        <box size="0.1 0.1 2"/>
      </geometry>
      <material name="RRBOT/orange"/>
    </visual>
    <inertial>
      <origin rpy="0 0 0" xyz="0 0 1.0"/>
      <mass value="1"/>
      <inertia ixx="1.0" ixy="0.0" ixz="0.0" iyy="1.0" iyz="0.0" izz="1.0"/>
    </inertial>
  </link>
  <joint name="rrbot_joint1" type="continuous">
    <parent link="rrbot_link1"/>
    <child link="rrbot_link2"/>
    <origin rpy="0 0 0" xyz="0 0.1 1.95"/>
    <axis xyz="0 1 0"/>
    <dynamics damping="0.7"/>
  </joint>
  <link name="rrbot_link2">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <geometry>
        <box size="0.1 0.1 1"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <geometry>
        <box size="0.1 0.1 1"/>
      </geometry>
      <material name="RRBOT/black"/>
    </visual>
    <inertial>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <mass value="1"/>
      <inertia ixx="1.0" ixy="0.0" ixz="0.0" iyy="1.0" iyz="0.0" izz="1.0"/>
    </inertial>
  </link>
  <joint name="rrbot_joint2" type="continuous">
    <parent link="rrbot_link2"/>
    <child link="rrbot_link3"/>
    <origin rpy="0 0 0" xyz="0 0.1 0.9"/>
    <axis xyz="0 1 0"/>
    <dynamics damping="0.7"/>
  </joint>
  <link name="rrbot_link3">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <geometry>
        <box size="0.1 0.1 1"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <geometry>
        <box size="0.1 0.1 1"/>
      </geometry>
      <material name="RRBOT/orange"/>
    </visual>
    <inertial>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <mass value="1"/>
      <inertia ixx="1.0" ixy="0.0" ixz="0.0" iyy="1.0" iyz="0.0" izz="1.0"/>
    </inertial>
  </link>
  <joint name="rrbot_hokuyo_joint" type="fixed">
    <axis xyz="0 1 0"/>
    <origin rpy="0 0 0" xyz="0 0 0.975"/>
    <parent link="rrbot_link3"/>
    <child link="rrbot_hokuyo_link"/>
  </joint>
  <link name="rrbot_hokuyo_link">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <box size="0.1 0.1 0.1"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <box size="0.1 0.1 0.1"/>
      </geometry>
    </visual>
    <inertial>
      <mass value="1e-5"/>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <inertia ixx="1e-6" ixy="0" ixz="0" iyy="1e-6" iyz="0" izz="1e-6"/>
    </inertial>
  </link>
  <joint name="rrbot_camera_joint" type="fixed">
    <axis xyz="0 1 0"/>
    <origin rpy="0 0 0" xyz="0.05 0 0.9"/>
    <parent link="rrbot_link3"/>
    <child link="rrbot_camera_link"/>
  </joint>
  <link name="rrbot_camera_link">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <box size="0.05 0.05 0.05"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <box size="0.05 0.05 0.05"/>
      </geometry>
      <material name="RRBOT/red"/>
    </visual>
    <inertial>
      <mass value="1e-5"/>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <inertia ixx="1e-6" ixy="0" ixz="0" iyy="1e-6" iyz="0" izz="1e-6"/>
    </inertial>
  </link>
  <transmission name="rrbot_tran1">
    <type>transmission_interface/SimpleTransmission</type>
    <actuator name="rrbot_motor1">
      <mechanicalReduction>1</mechanicalReduction>
    </actuator>
  </transmission>
  <gazebo reference="rrbot_link1">
    <material>Gazebo/Orange</material>
  </gazebo>
  <gazebo reference="rrbot_link2">
    <mu1>0.2</mu1>
    <mu2>0.2</mu2>
    <material>Gazebo/Black</material>
  </gazebo>
  <gazebo reference="rrbot_link3">
    <mu1>0.2</mu1>
    <mu2>0.2</mu2>
    <material>Gazebo/Orange</material>
  </gazebo>
  <gazebo>
    <plugin name="gazebo_ros_control" filename="libgazebo_ros_control.so">
    </plugin>
  </gazebo>
</robot>
  )";
  }

  std::string valid_urdf_xml_;
  std::string wrong_urdf_xml_;
};

using transmission_interface::parse_transmissions_from_urdf;
using transmission_interface::TransmissionInfo;

TEST_F(TestTransmissionParser, successfully_parse_valid_urdf)
{
  const auto transmissions = parse_transmissions_from_urdf(valid_urdf_xml_);

  ASSERT_THAT(transmissions, SizeIs(2));

  // first transmission
  EXPECT_EQ("rrbot_tran1", transmissions[0].name);
  EXPECT_EQ("transmission_interface/SimpleTransmission", transmissions[0].type);

  ASSERT_THAT(transmissions[0].joints, SizeIs(1));
  ASSERT_THAT(transmissions[0].joints[0].interfaces, SizeIs(1));
  EXPECT_EQ("rrbot_joint1", transmissions[0].joints[0].name);
  EXPECT_EQ("PositionJointInterface", transmissions[0].joints[0].interfaces[0]);

  ASSERT_THAT(transmissions[0].actuators, SizeIs(1));
  ASSERT_THAT(transmissions[0].actuators[0].interfaces, SizeIs(1));
  EXPECT_EQ("rrbot_motor1", transmissions[0].actuators[0].name);
  EXPECT_EQ("PositionJointInterface", transmissions[0].actuators[0].interfaces[0]);
  EXPECT_EQ(1, transmissions[0].actuators[0].mechanical_reduction);

  // second transmission
  EXPECT_EQ("rrbot_tran2", transmissions[1].name);
  EXPECT_EQ("transmission_interface/SimpleTransmission", transmissions[1].type);

  ASSERT_THAT(transmissions[1].joints, SizeIs(1));
  ASSERT_THAT(transmissions[1].joints[0].interfaces, SizeIs(1));
  EXPECT_EQ("rrbot_joint2", transmissions[1].joints[0].name);
  EXPECT_EQ("VelocityJointInterface", transmissions[1].joints[0].interfaces[0]);

  ASSERT_THAT(transmissions[1].actuators, SizeIs(1));
  ASSERT_THAT(transmissions[1].actuators[0].interfaces, SizeIs(1));
  EXPECT_EQ("rrbot_motor2", transmissions[1].actuators[0].name);
  EXPECT_EQ("VelocityJointInterface", transmissions[1].actuators[0].interfaces[0]);
  EXPECT_EQ(60, transmissions[1].actuators[0].mechanical_reduction);
}

TEST_F(TestTransmissionParser, empty_string_throws_error)
{
  ASSERT_THROW(
    transmission_interface::parse_transmissions_from_urdf(""),
    std::runtime_error);
}

TEST_F(TestTransmissionParser, empty_urdf_returns_empty)
{
  const auto transmissions = transmission_interface::parse_transmissions_from_urdf(
    "<?xml version=\"1.0\"?><robot name=\"robot\" xmlns=\"http://www.ros.org\"></robot>");
  ASSERT_THAT(transmissions, IsEmpty());
}

TEST_F(TestTransmissionParser, wrong_urdf_throws_error)
{
  EXPECT_THROW(
    transmission_interface::parse_transmissions_from_urdf(wrong_urdf_xml_),
    std::runtime_error);
}
