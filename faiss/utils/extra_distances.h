/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// -*- c++ -*-

#ifndef FAISS_distances_h
#define FAISS_distances_h

/** In this file are the implementations of extra metrics beyond L2
 *  and inner product */

#include <stdint.h>

#include <faiss/Index.h>
#include <functional>

#include <faiss/utils/Heap.h>



namespace faiss {

typedef std::function<bool(uint64_t, void *)> ANNFilterFunc;

void pairwise_extra_distances (
                     int64_t d,
                     int64_t nq, const float *xq,
                     int64_t nb, const float *xb,
                     MetricType mt, float metric_arg,
                     float *dis,
                     int64_t ldq = -1, int64_t ldb = -1, int64_t ldd = -1);


void knn_extra_metrics (
        const float * x,
        const float * y,
        size_t d, size_t nx, size_t ny,
        MetricType mt, float metric_arg,
        float_maxheap_array_t * res);

void knn_extra_metrics (
        const float * x,
        const float * y,
        size_t d, size_t nx, size_t ny,
        MetricType mt, float metric_arg,
        float_maxheap_array_t * res,
        const ANNFilterFunc &ann_filter_func,
        void* user_data);

/** get a DistanceComputer that refers to this type of distance and
 *  indexes a flat array of size nb */
DistanceComputer *get_extra_distance_computer (
        size_t d,
        MetricType mt, float metric_arg,
        size_t nb, const float *xb);

}


#endif