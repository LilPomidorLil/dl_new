//
// Copyright (c) 2022 xsDNN Inc. All rights reserved.
//


#ifndef XSDNN_FULLYCONNECTEDCORE_H
#define XSDNN_FULLYCONNECTEDCORE_H

#include "FullyConnected_DIRECT.h"

namespace internal {
    namespace fc {
        typedef Eigen::Matrix<Scalar, Eigen::Dynamic, 1> Vector;

        /// Прямое распространение полносвязного слоя
        /// \tparam Activation функция активации
        /// \param prev_data выходы предыдущего слоя
        /// \param w матрица весов
        /// \param b вектор смещений
        /// \param z значения нейронов текущего слоя до активации
        /// \param a значения нейронов текущего слоя после активации
        /// \param bias использовать смещение?
        /// \param out_size output dimension
        template<typename Activation>
        inline void computeForward(const Matrix& prev_data,
                                   Matrix& w,
                                   Vector& b,
                                   Matrix& z,
                                   Matrix& a,
                                   bool    bias,
                                   const int out_size) {
            internal::fc::algorithm::compute_forward_direct<Activation>(prev_data,
                                                                        w,
                                                                        b,
                                                                        z,
                                                                        a,
                                                                        bias,
                                                                        out_size);
        }

        /// Обратное распространение полносвязного слоя
        /// \tparam Activation функция активации
        /// \param prev_data значения нейронов предыдущего слоя
        /// \param next_grad значения градиентов следующего слоя
        /// \param w матрица весов
        /// \param dw матрица производных весов
        /// \param db вектор производных смещений
        /// \param din матрица производных выходов нейронов
        /// \param z значения нейронов до активации
        /// \param a значения нейронов после активации
        /// \param bias применять смещение?
        /// \param in_size входной размер текущего слоя
        template<typename Activation>
        inline void computeBackward(const Matrix& prev_data,
                                    const Matrix& next_grad,
                                    Matrix& w,
                                    Matrix& dw,
                                    Vector& db,
                                    Matrix& din,
                                    Matrix& z,
                                    Matrix& a,
                                    bool    bias,
                                    const int in_size) {
            internal::fc::algorithm::compute_backward_direct<Activation>(
                    prev_data,
                    next_grad,
                    w,
                    dw,
                    db,
                    din,
                    z,
                    a,
                    bias,
                    in_size
                    );
        }
    } // end namespace fc
} // end namespace internal

#endif //XSDNN_FULLYCONNECTEDCORE_H
