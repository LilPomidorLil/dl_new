//
// Created by rozhin on 31.03.23.
// Copyright (c) 2021-2023 xsdnn. All rights reserved.
//

#ifndef XSDNN_NETWORK_H
#define XSDNN_NETWORK_H

#include <vector>
#include <thread>
#include "../layers/layer.h"
#include "nodes.h"
#include "config.h"

namespace xsdnn {

template<typename Net>
class network {
public:
    typedef std::vector<layer*>::iterator iterator;
    typedef std::vector<layer*>::const_iterator const_iterator;

    network() : network_name_("default_name") {}
    explicit network(const std::string network_name) : network_name_(network_name) {}
    network(const network&) = default;
    network& operator=(const network&) = default;
    ~network() = default;

    template<typename L>
    network& operator<<(L &&layer) {
        net_.owner_nodes_.push_back(std::make_shared<typename std::remove_reference<L>::type>(layer));
        net_.nodes_.push_back(net_.owner_nodes_.back().get());

        if (net_.nodes_.size() > 1) {
            auto last_node = net_.nodes_[net_.nodes_.size() - 2];
            auto next_node = net_.nodes_[net_.nodes_.size() - 1];
            auto data_idx = find_data_idx(last_node->out_types(), next_node->in_types());
            connect(last_node, next_node, data_idx.first, data_idx.second);
        }
        net_.check_connectivity();
        return *this;
    }

    const layer *operator[](size_t index) const { return net_[index]; }
    layer *operator[](size_t index) { return net_[index]; }

public:
    void init_weight();
    void set_num_threads(size_t num_threads) noexcept;
    bool empty() const;

    tensor_t predict(const tensor_t& in);
    BTensor predict(const BTensor & in);
    std::vector<BTensor> predict(const std::vector<BTensor>& in);

    void save(const std::string filename);
    void load(const std::string filename);

protected:

    friend bool operator == (network<Net>& lhs, network<Net>& rhs) {
        /*
         * Check topological sorted vector
         */
        if (lhs.net_.size() != rhs.net_.size()) {
            return false;
        }

        for (size_t i = 0; i <  lhs.net_.size(); ++i) {
            layer* lhs_layer = lhs.net_[i];
            layer* rhs_layer = rhs.net_[i];
            if (lhs_layer->layer_type() != rhs_layer->layer_type()) {
                return false;
            }
        }

        /*
         * Check weights data
         */

        for (size_t i = 0; i <  lhs.net_.size(); ++i) {
            layer* lhs_layer = lhs.net_[i];
            layer* rhs_layer = rhs.net_[i];

            std::vector<tensor_t*> lhs_weights = lhs_layer->weights();
            std::vector<tensor_t*> rhs_weights = rhs_layer->weights();

            if (lhs_weights.size() != rhs_weights.size()) {
                return false;
            }

            for (size_t j = 0; j < lhs_weights.size(); ++j) {
                gsl::span<const float> LhsWeightsSpan = lhs_weights[j]->template GetDataAsSpan<float>();
                gsl::span<const float> RhsWeightsSpan = rhs_weights[j]->template GetDataAsSpan<float>();

                if (LhsWeightsSpan != RhsWeightsSpan) {
                    return false;
                }
            }
        }
        return true;
    }

    friend void construct_graph(network<graph>& net,
                                const std::vector<layer*>& input,
                                const std::vector<layer*>& out);

protected:
    tensor_t fprop(const tensor_t& in);
    BTensor fprop(const BTensor & in);
    std::vector<BTensor> fprop(const std::vector<BTensor>& in);

private:
    Net net_;
    std::string network_name_;
    friend class InfSession;
};

    void construct_graph(network<graph>& net,
                         const std::vector<layer*>& input,
                         const std::vector<layer*>& out);

} // xsdnn

#endif //XSDNN_NETWORK_H
