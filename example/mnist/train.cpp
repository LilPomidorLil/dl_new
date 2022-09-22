# include "../../xsDNN//xsDNN.h"

int main()
{
    Matrix train_image, train_label;

    dataset::parse_mnist_image("../../datasets/mnist/train-images-idx3-ubyte",
                               train_image,
                               0,
                               1,
                               0,
                               0);

    dataset::parse_mnist_label("../../datasets/mnist/train-labels-idx1-ubyte", train_label);

    NeuralNetwork baseline;

    baseline    << new FullyConnected<init::Uniform, activate::ReLU>(784, 128)
                << new FullyConnected<init::Uniform, activate::Softmax>(128, 10);

    Output* criterion = new CrossEntropyLoss();
    baseline.set_output(criterion);

    std::vector< std::vector<Scalar> > init_params = {
            {-6.0 / (784.0 + 128.0), 6.0 / (784.0 + 128.0)},
            {-6.0 / (128.0 + 10.0), 6.0 / (128.0 + 10.0)}
    };

    SGD opt; opt.m_lrate = 0.01; opt.m_nesterov = true; opt.m_momentum = 0.63;

    baseline.fit(opt, train_image, train_label, 16, 5, 42, 10, init_params);
    baseline.export_net("example-mnist", "uniform_dist");
}