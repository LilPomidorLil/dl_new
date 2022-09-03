//
// Copyright (c) 2022 xsDNN Inc. All rights reserved.
//
namespace activate{
    /*!
    \brief Класс функции активации - ReLU
    \author __[shuffle-true](https://github.com/shuffle-true)__
	\version 0.0
	\date Март 2022 года
    */
    class ReLU
    {
    public:

        /// __Алгоритм__:
        /// \code
        /// int relu_forward(const Matrix& Z, Matrix& A){
        ///
        ///     for (int i = 0; i < Z.size(); i++)
        ///     {
        ///         A[i] = Z[i] > 0 ? Z[i] : 0;
        ///     }
        ///
        /// }
        /// \endcode
        /// \param Z значения нейронов до активации
        /// \param A значения нейронов после активации
        static inline void activate(const Matrix& Z, Matrix& A)
        {
            A.array() = Z.array().cwiseMax(Scalar(0));
        }

        /// Операция матричного дифференцирования.

        /// __Алгоритм__:
        /// \code
        /// int relu_backprop(const Matrix& Z, const Matrix& A,
        ///		const Matrix& F, Matrix& G) {
        ///
        ///     for (int i = 0; i < A.size(); i++)
        ///     {
        ///         G[i] = A[i] > 0 ? F[i] : 0;
        ///     }
        ///
        /// }
        /// \endcode
        /// \param Z нейроны слоя до активации.
        /// \param A нейроны слоя после активации.
        /// \param F нейроны следующего слоя.
        /// \param G значения, которые получаются после backprop.
        static inline void apply_jacobian(const Matrix& Z, const Matrix& A,
                                          const Matrix& F, Matrix& G)
        {
            G.array() = (A.array() > Scalar(0)).select(F, Scalar(0));
        }

        ///
        /// \return Тип активации.
        static std::string return_type()
        {
            return "ReLU";
        }
    };
}
