#include "trajectories.h"
#include <avr/pgmspace.h>

// length = 629

const float trajectoryElevator[TRAJECTORY_LENGTH] PROGMEM = {
0.000, 
0.000, 
0.000, 
0.001, 
0.002, 
0.002, 
0.003, 
0.004, 
0.005, 
0.007, 
0.008, 
0.010, 
0.012, 
0.014, 
0.016, 
0.018, 
0.021, 
0.023, 
0.026, 
0.029, 
0.032, 
0.035, 
0.038, 
0.042, 
0.045, 
0.049, 
0.053, 
0.057, 
0.061, 
0.065, 
0.070, 
0.075, 
0.079, 
0.084, 
0.089, 
0.094, 
0.100, 
0.105, 
0.111, 
0.117, 
0.123, 
0.129, 
0.135, 
0.141, 
0.148, 
0.154, 
0.161, 
0.168, 
0.175, 
0.182, 
0.189, 
0.196, 
0.204, 
0.212, 
0.219, 
0.227, 
0.235, 
0.244, 
0.252, 
0.260, 
0.269, 
0.278, 
0.286, 
0.295, 
0.304, 
0.314, 
0.323, 
0.332, 
0.342, 
0.351, 
0.361, 
0.371, 
0.381, 
0.391, 
0.401, 
0.412, 
0.422, 
0.433, 
0.443, 
0.454, 
0.465, 
0.476, 
0.487, 
0.498, 
0.509, 
0.521, 
0.532, 
0.544, 
0.556, 
0.567, 
0.579, 
0.591, 
0.603, 
0.615, 
0.628, 
0.640, 
0.652, 
0.665, 
0.677, 
0.690, 
0.703, 
0.716, 
0.729, 
0.742, 
0.755, 
0.768, 
0.781, 
0.794, 
0.808, 
0.821, 
0.835, 
0.848, 
0.862, 
0.875, 
0.889, 
0.903, 
0.917, 
0.931, 
0.945, 
0.959, 
0.973, 
0.987, 
1.001, 
1.016, 
1.030, 
1.044, 
1.059, 
1.073, 
1.088, 
1.102, 
1.117, 
1.132, 
1.146, 
1.161, 
1.176, 
1.191, 
1.205, 
1.220, 
1.235, 
1.250, 
1.265, 
1.280, 
1.295, 
1.310, 
1.325, 
1.340, 
1.355, 
1.370, 
1.385, 
1.400, 
1.415, 
1.430, 
1.446, 
1.461, 
1.476, 
1.491, 
1.506, 
1.521, 
1.537, 
1.552, 
1.567, 
1.582, 
1.597, 
1.612, 
1.627, 
1.642, 
1.657, 
1.673, 
1.688, 
1.703, 
1.718, 
1.733, 
1.748, 
1.763, 
1.778, 
1.792, 
1.807, 
1.822, 
1.837, 
1.852, 
1.867, 
1.881, 
1.896, 
1.911, 
1.925, 
1.940, 
1.954, 
1.969, 
1.983, 
1.998, 
2.012, 
2.026, 
2.040, 
2.055, 
2.069, 
2.083, 
2.097, 
2.111, 
2.125, 
2.139, 
2.152, 
2.166, 
2.180, 
2.193, 
2.207, 
2.220, 
2.234, 
2.247, 
2.260, 
2.273, 
2.286, 
2.299, 
2.312, 
2.325, 
2.338, 
2.351, 
2.363, 
2.376, 
2.388, 
2.400, 
2.413, 
2.425, 
2.437, 
2.449, 
2.461, 
2.473, 
2.484, 
2.496, 
2.507, 
2.519, 
2.530, 
2.541, 
2.552, 
2.563, 
2.574, 
2.585, 
2.596, 
2.606, 
2.617, 
2.627, 
2.637, 
2.647, 
2.657, 
2.667, 
2.677, 
2.687, 
2.696, 
2.706, 
2.715, 
2.724, 
2.733, 
2.742, 
2.751, 
2.760, 
2.768, 
2.777, 
2.785, 
2.793, 
2.801, 
2.809, 
2.817, 
2.825, 
2.832, 
2.840, 
2.847, 
2.854, 
2.861, 
2.868, 
2.875, 
2.881, 
2.888, 
2.894, 
2.900, 
2.906, 
2.912, 
2.918, 
2.924, 
2.929, 
2.935, 
2.940, 
2.945, 
2.950, 
2.955, 
2.959, 
2.964, 
2.968, 
2.972, 
2.976, 
2.980, 
2.984, 
2.988, 
2.991, 
2.995, 
2.998, 
3.001, 
3.004, 
3.006, 
3.009, 
3.011, 
3.014, 
3.016, 
3.018, 
3.020, 
3.021, 
3.023, 
3.024, 
3.026, 
3.027, 
3.028, 
3.028, 
3.029, 
3.029, 
3.030, 
3.030, 
3.030, 
3.030, 
3.030, 
3.029, 
3.029, 
3.028, 
3.027, 
3.026, 
3.025, 
3.023, 
3.022, 
3.020, 
3.018, 
3.017, 
3.014, 
3.012, 
3.010, 
3.007, 
3.005, 
3.002, 
2.999, 
2.996, 
2.992, 
2.989, 
2.985, 
2.982, 
2.978, 
2.974, 
2.970, 
2.965, 
2.961, 
2.956, 
2.951, 
2.947, 
2.942, 
2.936, 
2.931, 
2.926, 
2.920, 
2.914, 
2.908, 
2.902, 
2.896, 
2.890, 
2.883, 
2.877, 
2.870, 
2.863, 
2.856, 
2.849, 
2.842, 
2.835, 
2.827, 
2.820, 
2.812, 
2.804, 
2.796, 
2.788, 
2.779, 
2.771, 
2.762, 
2.754, 
2.745, 
2.736, 
2.727, 
2.718, 
2.709, 
2.699, 
2.690, 
2.680, 
2.670, 
2.661, 
2.651, 
2.640, 
2.630, 
2.620, 
2.610, 
2.599, 
2.588, 
2.578, 
2.567, 
2.556, 
2.545, 
2.534, 
2.522, 
2.511, 
2.500, 
2.488, 
2.476, 
2.465, 
2.453, 
2.441, 
2.429, 
2.417, 
2.404, 
2.392, 
2.380, 
2.367, 
2.355, 
2.342, 
2.329, 
2.316, 
2.303, 
2.291, 
2.277, 
2.264, 
2.251, 
2.238, 
2.224, 
2.211, 
2.198, 
2.184, 
2.170, 
2.157, 
2.143, 
2.129, 
2.115, 
2.101, 
2.087, 
2.073, 
2.059, 
2.045, 
2.031, 
2.016, 
2.002, 
1.988, 
1.973, 
1.959, 
1.944, 
1.930, 
1.915, 
1.901, 
1.886, 
1.871, 
1.857, 
1.842, 
1.827, 
1.812, 
1.797, 
1.782, 
1.767, 
1.752, 
1.737, 
1.722, 
1.707, 
1.692, 
1.677, 
1.662, 
1.647, 
1.632, 
1.617, 
1.602, 
1.587, 
1.572, 
1.556, 
1.541, 
1.526, 
1.511, 
1.496, 
1.481, 
1.466, 
1.450, 
1.435, 
1.420, 
1.405, 
1.390, 
1.375, 
1.360, 
1.345, 
1.330, 
1.315, 
1.300, 
1.285, 
1.270, 
1.255, 
1.240, 
1.225, 
1.210, 
1.195, 
1.181, 
1.166, 
1.151, 
1.136, 
1.122, 
1.107, 
1.093, 
1.078, 
1.063, 
1.049, 
1.035, 
1.020, 
1.006, 
0.992, 
0.978, 
0.963, 
0.949, 
0.935, 
0.921, 
0.907, 
0.894, 
0.880, 
0.866, 
0.852, 
0.839, 
0.825, 
0.812, 
0.798, 
0.785, 
0.772, 
0.759, 
0.746, 
0.733, 
0.720, 
0.707, 
0.694, 
0.681, 
0.669, 
0.656, 
0.644, 
0.631, 
0.619, 
0.607, 
0.595, 
0.583, 
0.571, 
0.559, 
0.548, 
0.536, 
0.524, 
0.513, 
0.502, 
0.491, 
0.479, 
0.468, 
0.458, 
0.447, 
0.436, 
0.425, 
0.415, 
0.405, 
0.394, 
0.384, 
0.374, 
0.364, 
0.354, 
0.345, 
0.335, 
0.326, 
0.316, 
0.307, 
0.298, 
0.289, 
0.280, 
0.272, 
0.263, 
0.255, 
0.246, 
0.238, 
0.230, 
0.222, 
0.214, 
0.206, 
0.199, 
0.191, 
0.184, 
0.177, 
0.170, 
0.163, 
0.156, 
0.150, 
0.143, 
0.137, 
0.131, 
0.124, 
0.119, 
0.113, 
0.107, 
0.102, 
0.096, 
0.091, 
0.086, 
0.081, 
0.076, 
0.071, 
0.067, 
0.062, 
0.058, 
0.054, 
0.050, 
0.046, 
0.043, 
0.039, 
0.036, 
0.033, 
0.030, 
0.027, 
0.024, 
0.021, 
0.019, 
0.017, 
0.014, 
0.012, 
0.011, 
0.009, 
0.007, 
0.006, 
0.005, 
0.004, 
0.003, 
0.002, 
0.001, 
0.001, 
0.000, 
0.000, 
-0.000, 
};

const float trajectoryAileron[TRAJECTORY_LENGTH] PROGMEM = {
0.000, 
-0.015, 
-0.030, 
-0.045, 
-0.061, 
-0.076, 
-0.091, 
-0.106, 
-0.121, 
-0.136, 
-0.151, 
-0.166, 
-0.181, 
-0.196, 
-0.211, 
-0.226, 
-0.241, 
-0.256, 
-0.271, 
-0.286, 
-0.301, 
-0.316, 
-0.330, 
-0.345, 
-0.360, 
-0.375, 
-0.389, 
-0.404, 
-0.418, 
-0.433, 
-0.447, 
-0.462, 
-0.476, 
-0.491, 
-0.505, 
-0.519, 
-0.533, 
-0.547, 
-0.561, 
-0.575, 
-0.589, 
-0.603, 
-0.617, 
-0.631, 
-0.645, 
-0.658, 
-0.672, 
-0.685, 
-0.699, 
-0.712, 
-0.725, 
-0.739, 
-0.752, 
-0.765, 
-0.778, 
-0.791, 
-0.804, 
-0.816, 
-0.829, 
-0.842, 
-0.854, 
-0.867, 
-0.879, 
-0.891, 
-0.903, 
-0.915, 
-0.927, 
-0.939, 
-0.951, 
-0.963, 
-0.974, 
-0.986, 
-0.997, 
-1.008, 
-1.020, 
-1.031, 
-1.042, 
-1.052, 
-1.063, 
-1.074, 
-1.084, 
-1.095, 
-1.105, 
-1.115, 
-1.126, 
-1.136, 
-1.145, 
-1.155, 
-1.165, 
-1.174, 
-1.184, 
-1.193, 
-1.202, 
-1.211, 
-1.220, 
-1.229, 
-1.238, 
-1.246, 
-1.255, 
-1.263, 
-1.271, 
-1.279, 
-1.287, 
-1.295, 
-1.303, 
-1.310, 
-1.318, 
-1.325, 
-1.332, 
-1.339, 
-1.346, 
-1.353, 
-1.359, 
-1.366, 
-1.372, 
-1.378, 
-1.384, 
-1.390, 
-1.396, 
-1.402, 
-1.407, 
-1.413, 
-1.418, 
-1.423, 
-1.428, 
-1.433, 
-1.437, 
-1.442, 
-1.446, 
-1.450, 
-1.454, 
-1.458, 
-1.462, 
-1.466, 
-1.469, 
-1.472, 
-1.475, 
-1.478, 
-1.481, 
-1.484, 
-1.487, 
-1.489, 
-1.491, 
-1.493, 
-1.495, 
-1.497, 
-1.499, 
-1.500, 
-1.502, 
-1.503, 
-1.504, 
-1.505, 
-1.506, 
-1.506, 
-1.507, 
-1.507, 
-1.507, 
-1.507, 
-1.507, 
-1.507, 
-1.507, 
-1.506, 
-1.505, 
-1.504, 
-1.503, 
-1.502, 
-1.501, 
-1.499, 
-1.498, 
-1.496, 
-1.494, 
-1.492, 
-1.489, 
-1.487, 
-1.485, 
-1.482, 
-1.479, 
-1.476, 
-1.473, 
-1.470, 
-1.466, 
-1.462, 
-1.459, 
-1.455, 
-1.451, 
-1.447, 
-1.442, 
-1.438, 
-1.433, 
-1.429, 
-1.424, 
-1.419, 
-1.413, 
-1.408, 
-1.403, 
-1.397, 
-1.391, 
-1.385, 
-1.379, 
-1.373, 
-1.367, 
-1.360, 
-1.354, 
-1.347, 
-1.340, 
-1.333, 
-1.326, 
-1.319, 
-1.312, 
-1.304, 
-1.296, 
-1.289, 
-1.281, 
-1.273, 
-1.264, 
-1.256, 
-1.248, 
-1.239, 
-1.231, 
-1.222, 
-1.213, 
-1.204, 
-1.195, 
-1.185, 
-1.176, 
-1.166, 
-1.157, 
-1.147, 
-1.137, 
-1.127, 
-1.117, 
-1.107, 
-1.097, 
-1.086, 
-1.076, 
-1.065, 
-1.054, 
-1.043, 
-1.032, 
-1.021, 
-1.010, 
-0.999, 
-0.988, 
-0.976, 
-0.964, 
-0.953, 
-0.941, 
-0.929, 
-0.917, 
-0.905, 
-0.893, 
-0.881, 
-0.868, 
-0.856, 
-0.844, 
-0.831, 
-0.818, 
-0.806, 
-0.793, 
-0.780, 
-0.767, 
-0.754, 
-0.741, 
-0.728, 
-0.714, 
-0.701, 
-0.687, 
-0.674, 
-0.660, 
-0.647, 
-0.633, 
-0.619, 
-0.605, 
-0.592, 
-0.578, 
-0.564, 
-0.550, 
-0.535, 
-0.521, 
-0.507, 
-0.493, 
-0.478, 
-0.464, 
-0.450, 
-0.435, 
-0.421, 
-0.406, 
-0.392, 
-0.377, 
-0.362, 
-0.348, 
-0.333, 
-0.318, 
-0.303, 
-0.288, 
-0.273, 
-0.259, 
-0.244, 
-0.229, 
-0.214, 
-0.199, 
-0.184, 
-0.169, 
-0.154, 
-0.139, 
-0.123, 
-0.108, 
-0.093, 
-0.078, 
-0.063, 
-0.048, 
-0.033, 
-0.018, 
-0.002, 
0.013, 
0.028, 
0.043, 
0.058, 
0.073, 
0.088, 
0.104, 
0.119, 
0.134, 
0.149, 
0.164, 
0.179, 
0.194, 
0.209, 
0.224, 
0.239, 
0.254, 
0.269, 
0.284, 
0.299, 
0.314, 
0.328, 
0.343, 
0.358, 
0.373, 
0.387, 
0.402, 
0.417, 
0.431, 
0.446, 
0.460, 
0.475, 
0.489, 
0.503, 
0.518, 
0.532, 
0.546, 
0.560, 
0.574, 
0.588, 
0.602, 
0.616, 
0.630, 
0.644, 
0.658, 
0.671, 
0.685, 
0.698, 
0.712, 
0.725, 
0.738, 
0.752, 
0.765, 
0.778, 
0.791, 
0.804, 
0.817, 
0.829, 
0.842, 
0.855, 
0.867, 
0.880, 
0.892, 
0.904, 
0.916, 
0.929, 
0.941, 
0.952, 
0.964, 
0.976, 
0.988, 
0.999, 
1.010, 
1.022, 
1.033, 
1.044, 
1.055, 
1.066, 
1.077, 
1.087, 
1.098, 
1.108, 
1.119, 
1.129, 
1.139, 
1.149, 
1.159, 
1.169, 
1.179, 
1.188, 
1.198, 
1.207, 
1.216, 
1.225, 
1.234, 
1.243, 
1.252, 
1.260, 
1.269, 
1.277, 
1.285, 
1.293, 
1.301, 
1.309, 
1.317, 
1.324, 
1.332, 
1.339, 
1.346, 
1.353, 
1.360, 
1.367, 
1.373, 
1.380, 
1.386, 
1.393, 
1.399, 
1.405, 
1.410, 
1.416, 
1.421, 
1.427, 
1.432, 
1.437, 
1.442, 
1.447, 
1.452, 
1.456, 
1.460, 
1.465, 
1.469, 
1.473, 
1.476, 
1.480, 
1.484, 
1.487, 
1.490, 
1.493, 
1.496, 
1.499, 
1.501, 
1.504, 
1.506, 
1.508, 
1.510, 
1.512, 
1.514, 
1.515, 
1.517, 
1.518, 
1.519, 
1.520, 
1.521, 
1.522, 
1.522, 
1.522, 
1.523, 
1.523, 
1.522, 
1.522, 
1.522, 
1.521, 
1.520, 
1.520, 
1.519, 
1.517, 
1.516, 
1.515, 
1.513, 
1.511, 
1.509, 
1.507, 
1.505, 
1.503, 
1.500, 
1.497, 
1.495, 
1.492, 
1.488, 
1.485, 
1.482, 
1.478, 
1.474, 
1.471, 
1.467, 
1.462, 
1.458, 
1.454, 
1.449, 
1.444, 
1.440, 
1.435, 
1.429, 
1.424, 
1.419, 
1.413, 
1.407, 
1.401, 
1.395, 
1.389, 
1.383, 
1.377, 
1.370, 
1.363, 
1.357, 
1.350, 
1.342, 
1.335, 
1.328, 
1.320, 
1.313, 
1.305, 
1.297, 
1.289, 
1.281, 
1.273, 
1.264, 
1.256, 
1.247, 
1.238, 
1.229, 
1.220, 
1.211, 
1.202, 
1.193, 
1.183, 
1.173, 
1.164, 
1.154, 
1.144, 
1.134, 
1.124, 
1.113, 
1.103, 
1.092, 
1.082, 
1.071, 
1.060, 
1.049, 
1.038, 
1.027, 
1.016, 
1.004, 
0.993, 
0.981, 
0.970, 
0.958, 
0.946, 
0.934, 
0.922, 
0.910, 
0.898, 
0.886, 
0.873, 
0.861, 
0.848, 
0.836, 
0.823, 
0.810, 
0.797, 
0.784, 
0.771, 
0.758, 
0.745, 
0.731, 
0.718, 
0.705, 
0.691, 
0.678, 
0.664, 
0.650, 
0.637, 
0.623, 
0.609, 
0.595, 
0.581, 
0.567, 
0.553, 
0.539, 
0.524, 
0.510, 
0.496, 
0.482, 
0.467, 
0.453, 
0.438, 
0.424, 
0.409, 
0.394, 
0.380, 
0.365, 
0.350, 
0.336, 
0.321, 
0.306, 
0.291, 
0.276, 
0.261, 
0.246, 
0.231, 
0.216, 
0.201, 
0.186, 
0.171, 
0.156, 
0.141, 
0.126, 
0.111, 
0.096, 
0.081, 
0.065, 
0.050, 
0.035, 
0.020, 
0.005, 
};
