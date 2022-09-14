//
// Copyright (c) 2022 xsDNN Inc. All rights reserved.
//

#ifndef XSDNN_CONSTANT_H
#define XSDNN_CONSTANT_H

namespace init {
    class Constant {
    private:
        static void check_distribution_param(const std::vector<Scalar> &params) {
            if (params.size() != 1)
                throw std::length_error("[class Uniform] Uniform distribution have 2 params."
                                        " Check input data.");
        }

    public:
        /// Заполнить массив указанным числом
        /// \param arr указатель на массив
        /// \param n размер массива
        /// \param rng ГСЧ
        /// \param params вектор параметров распределения
        static void set_random_data(Scalar *arr,
                                    const int n,
                                    RNG &rng,
                                    const std::vector<Scalar> &params) {
            check_distribution_param(params);

            const Scalar constant = params[0];

            for (int i = 0; i < n; i++) {
                arr[i] = constant;
            }
        }

        ///
        /// \return тип распределения
        static std::string return_type() {
            return "Constant";
        }
    };
}

#endif //XSDNN_CONSTANT_H
