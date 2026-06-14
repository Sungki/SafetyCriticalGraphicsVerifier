#include <gtest/gtest.h>
#include "../include/safety_display.h"

// Test Suite named after our Low Level Requirement (LLR)
class SafetyDisplayTest : public ::testing::Test {
protected:
    SafetyDisplayDriver driver;
};

// Test Case 1: Validate normal window boundary values
TEST_F(SafetyDisplayTest, VerifiesNormalInitialization) {
    bool status = init_display_driver(&driver, 1920, 1080);
    
    EXPECT_TRUE(status);
    EXPECT_TRUE(driver.is_window_active);
    EXPECT_EQ(driver.error_count, 0);
}

// Test Case 2: Verification of Edge-Case Fault Handling (Robustness Testing)
TEST_F(SafetyDisplayTest, RejectsInvalidZeroBoundaries) {
    // Attempting to pass illegal zero parameters to the graphics driver
    bool status = init_display_driver(&driver, 0, 1080);
    
    // GoogleTest catches the error and verifies the driver handles it safely
    EXPECT_FALSE(status);
    EXPECT_FALSE(driver.is_window_active);
    EXPECT_EQ(driver.error_count, 1);
}
