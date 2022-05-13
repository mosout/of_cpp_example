
#include "oneflow/api.h"
#include <iostream>
#include <vector>

using namespace oneflow_api;

int main(int argh, char *argv[]) {
  if (argh != 2) {
    std::cout << "Usage: " << argv[0] << " <model_dir>" << std::endl;
    return 1;
  }
  // initialize oneflow runtime
  initialize();
  // spcify device
  Device device("cpu");
  // load model
  Graph graph = Graph::Load(argv[1], device);
  // construct input data
  std::vector<float> input_data(3 * 224 * 224);
  std::fill(input_data.begin(), input_data.end(), 1);
  std::vector<Tensor> inputs{Tensor::from_buffer(
      input_data.data(), Shape({1, 3, 224, 224}), device, DType::kFloat)};
  // forward
  const auto output = graph.Forward(inputs).ToTensor();
  // get output data
  std::vector<float> result(1000);
  output.copy_to(result.data());
  // output result
  for (auto i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";
    if ((i + 1) % 40 == 0) {
      std::cout << std::endl << std::endl;
    }
  }
  // release oneflow runtime
  release();
  return 0;
}
