# Safety-Critical OpenGL Verification Framework

This repository serves as a testing portfolio for safety-critical graphics drivers, focusing on memory safety and state verification under DO-178C guidelines.

## 📊 Requirements Traceability Matrix (RTM)

| Requirement ID | Description | Test Case | Status |
| :--- | :--- | :--- | :--- |
| **LLR-GRAPHICS-003** | Driver must initialize and flag invalid display bounds. | `SafetyDisplayTest.VerifiesNormalInitialization` | PASS |
| **LLR-GRAPHICS-003** | Driver must safely reject and log an empty or zero size boundary. | `SafetyDisplayTest.RejectsInvalidZeroBoundaries` | PASS |

## 📉 Structural Code Coverage (DO-178C Compliance)
To satisfy DO-178C statement coverage requirements, this project uses **OpenCppCoverage** on Windows to measure test completeness.

* **Analysis Execution:** GoogleTest binaries run directly inside OpenCppCoverage to trace code lines executed during testing.
* **Target Objective:** Achieve 100% code statement coverage across `safety_display.c` to ensure no dead or hidden execution paths exist.
* **Reports:** HTML reports are auto-generated on every commit via the GitHub Actions CI pipeline.
