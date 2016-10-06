#include "..\Fusion\Fusion.h"
#include <stdio.h>

int main() {

    // FusionTypes.h example tests
    {
        const FusionVector3 vector3 = FUSION_VECTOR3_ZERO;
        if (vector3.array[0] == 0) {
        } // avoid warning for unused variable

        const FusionQuaternion quaternion = FUSION_QUATERNION_IDENTITY;
        if (quaternion.array[0] == 0) {
        } // avoid warning for unused variable

        const FusionRotationMatrix rotationMatrix = FUSION_ROTATION_MATRIX_IDENTITY;
        if (rotationMatrix.array[0] == 0) {
        } // avoid warning for unused variable

        const FusionEulerAngles eulerAngles = FUSION_EULER_ANGLES_ZERO;
        if (eulerAngles.array[0] == 0) {
        } // avoid warning for unused variable

        {
            const FusionQuaternion quaternion = FUSION_QUATERNION_IDENTITY;
            const FusionRotationMatrix rotationMatrix = FusionQuaternionToRotationMatrix(quaternion);
            if (rotationMatrix.array[0] == 0) {
            } // avoid warning for unused variable
        }
        {
            const FusionQuaternion quaternion = FUSION_QUATERNION_IDENTITY;
            const FusionEulerAngles eulerAngles = FusionQuaternionToEulerAngles(quaternion);
            if (eulerAngles.array[0] == 0) {
            } // avoid warning for unused variable
        }
    }

    // FusionAhrs.c example tests
    {
        FusionAhrs fusionAhrs;
        FusionAhrsInitialise(&fusionAhrs, 0.5f, 20.0f, 70.0f); // valid magnetic field defined as 20 uT to 70 uT

        const FusionVector3 gyroscope = {
            .axis.x = 0.0f,
            .axis.y = 0.0f,
            .axis.z = 0.0f,
        }; // literal values should be replaced with sensor measurements

        const FusionVector3 accelerometer = {
            .axis.x = 0.0f,
            .axis.y = 0.0f,
            .axis.z = 1.0f,
        }; // literal values should be replaced with sensor measurements

        const FusionVector3 magnetometer = {
            .axis.x = 1.0f,
            .axis.y = 0.0f,
            .axis.z = 0.0f,
        }; // literal values should be replaced with sensor measurements

        FusionAhrsUpdate(&fusionAhrs, gyroscope, accelerometer, magnetometer, 0.01f); // assumes 100 Hz sample rate
        FusionAhrsUpdate(&fusionAhrs, gyroscope, accelerometer, FUSION_VECTOR3_ZERO, 0.01f); // alternative function call to ignore magnetometer
        FusionAhrsUpdate(&fusionAhrs, gyroscope, FUSION_VECTOR3_ZERO, FUSION_VECTOR3_ZERO, 0.01f); // alternative function call to ignore accelerometer and magnetometer

        const FusionVector3 earthAcceleration = FusionAhrsCalculateEarthAcceleration(&fusionAhrs);
        if (earthAcceleration.array[0] == 0) {
        } // avoid warning for unused variable

        if (FusionAhrsIsInitialising(&fusionAhrs) == true) {
            // AHRS algorithm is initialising
        } else {
            // AHRS algorithm is not initialising
        }

        FusionAhrsReinitialise(&fusionAhrs);

        FusionAhrsZeroYaw(&fusionAhrs);
    }

    // FusionBias.c example tests
    {
        FusionBias fusionBias;
        FusionBiasInitialise(&fusionBias, 50, 0.01f); // assumes 100 Hz sample rate

        FusionBiasUpdate(&fusionBias, 0, 0, 0); // literal values should be replaced with sensor measurements

        if (FusionBiasIsActive(&fusionBias) == true) {
            // Bias correction algorithm is active
        } else {
            // Bias correction algorithm is not active
        }
    }

    // FusionCompass.c example tests
    {
        const FusionVector3 accelerometer = {
            .axis.x = 0.0f,
            .axis.y = 0.0f,
            .axis.z = 1.0f,
        }; // literal values should be replaced with sensor measurements

        const FusionVector3 magnetometer = {
            .axis.x = 1.0f,
            .axis.y = 0.0f,
            .axis.z = 0.0f,
        }; // literal values should be replaced with sensor measurements

        const float heading = FusionCompassCalculateHeading(accelerometer, magnetometer);
        if (heading == 0) {
        } // avoid warning for unused variable
    }

    printf("Success!\r\n");
}
