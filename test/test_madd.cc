//
// Created by rozhin on 29.08.2023.
// Copyright (c) 2021-2023 xsdnn. All rights reserved.
//

#include "xsdnn.h"
#include "test_utils.h"

TEST(madd, size_16) {
    size_t size = 16;
    xsdnn::mat_t Buffer(size * dtype2sizeof(kXsFloat32));
    utils::value_init_fp32(Buffer, 0);
    gsl::span<float> BufferSpan = GetMutableDataAsSpan<float>(&Buffer);
    mmpack::MmAdd(1.0f, BufferSpan.data(), size);
    for (size_t i = 0; i < size; ++i) {
        utils::xsAssert_eq(BufferSpan[i], 1.0f, kXsFloat32);
    }
}

TEST(madd, size_17) {
    size_t size = 17;
    xsdnn::mat_t Buffer(size * dtype2sizeof(kXsFloat32));
    utils::value_init_fp32(Buffer, 0);
    gsl::span<float> BufferSpan = GetMutableDataAsSpan<float>(&Buffer);
    mmpack::MmAdd(1.0f, BufferSpan.data(), size);
    for (size_t i = 0; i < size; ++i) {
        utils::xsAssert_eq(BufferSpan[i], 1.0f, kXsFloat32);
    }
}

TEST(madd, size_18) {
    size_t size = 18;
    xsdnn::mat_t Buffer(size * dtype2sizeof(kXsFloat32));
    utils::value_init_fp32(Buffer, 0);
    gsl::span<float> BufferSpan = GetMutableDataAsSpan<float>(&Buffer);
    mmpack::MmAdd(1.0f, BufferSpan.data(), size);
    for (size_t i = 0; i < size; ++i) {
        utils::xsAssert_eq(BufferSpan[i], 1.0f, kXsFloat32);
    }
}

TEST(madd, size_19) {
    size_t size = 19;
    xsdnn::mat_t Buffer(size * dtype2sizeof(kXsFloat32));
    utils::value_init_fp32(Buffer, 0);
    gsl::span<float> BufferSpan = GetMutableDataAsSpan<float>(&Buffer);
    mmpack::MmAdd(1.0f, BufferSpan.data(), size);
    for (size_t i = 0; i < size; ++i) {
        utils::xsAssert_eq(BufferSpan[i], 1.0f, kXsFloat32);
    }
}

TEST(madd, size_20) {
    size_t size = 20;
    xsdnn::mat_t Buffer(size * dtype2sizeof(kXsFloat32));
    utils::value_init_fp32(Buffer, 0);
    gsl::span<float> BufferSpan = GetMutableDataAsSpan<float>(&Buffer);
    mmpack::MmAdd(1.0f, BufferSpan.data(), size);
    for (size_t i = 0; i < size; ++i) {
        utils::xsAssert_eq(BufferSpan[i], 1.0f, kXsFloat32);
    }
}

TEST(madd, size_21) {
    size_t size = 21;
    xsdnn::mat_t Buffer(size * dtype2sizeof(kXsFloat32));
    utils::value_init_fp32(Buffer, 0);
    gsl::span<float> BufferSpan = GetMutableDataAsSpan<float>(&Buffer);
    mmpack::MmAdd(1.0f, BufferSpan.data(), size);
    for (size_t i = 0; i < size; ++i) {
        utils::xsAssert_eq(BufferSpan[i], 1.0f, kXsFloat32);
    }
}

TEST(madd, size_22) {
    size_t size = 22;
    xsdnn::mat_t Buffer(size * dtype2sizeof(kXsFloat32));
    utils::value_init_fp32(Buffer, 0);
    gsl::span<float> BufferSpan = GetMutableDataAsSpan<float>(&Buffer);
    mmpack::MmAdd(1.0f, BufferSpan.data(), size);
    for (size_t i = 0; i < size; ++i) {
        utils::xsAssert_eq(BufferSpan[i], 1.0f, kXsFloat32);
    }
}

TEST(madd, size_23) {
    size_t size = 23;
    xsdnn::mat_t Buffer(size * dtype2sizeof(kXsFloat32));
    utils::value_init_fp32(Buffer, 0);
    gsl::span<float> BufferSpan = GetMutableDataAsSpan<float>(&Buffer);
    mmpack::MmAdd(1.0f, BufferSpan.data(), size);
    for (size_t i = 0; i < size; ++i) {
        utils::xsAssert_eq(BufferSpan[i], 1.0f, kXsFloat32);
    }
}

TEST(madd, size_24) {
    size_t size = 24;
    xsdnn::mat_t Buffer(size * dtype2sizeof(kXsFloat32));
    utils::value_init_fp32(Buffer, 0);
    gsl::span<float> BufferSpan = GetMutableDataAsSpan<float>(&Buffer);
    mmpack::MmAdd(1.0f, BufferSpan.data(), size);
    for (size_t i = 0; i < size; ++i) {
        utils::xsAssert_eq(BufferSpan[i], 1.0f, kXsFloat32);
    }
}

TEST(madd, size_25) {
    size_t size = 25;
    xsdnn::mat_t Buffer(size * dtype2sizeof(kXsFloat32));
    utils::value_init_fp32(Buffer, 0);
    gsl::span<float> BufferSpan = GetMutableDataAsSpan<float>(&Buffer);
    mmpack::MmAdd(1.0f, BufferSpan.data(), size);
    for (size_t i = 0; i < size; ++i) {
        utils::xsAssert_eq(BufferSpan[i], 1.0f, kXsFloat32);
    }
}

TEST(madd, size_26) {
    size_t size = 26;
    xsdnn::mat_t Buffer(size * dtype2sizeof(kXsFloat32));
    utils::value_init_fp32(Buffer, 0);
    gsl::span<float> BufferSpan = GetMutableDataAsSpan<float>(&Buffer);
    mmpack::MmAdd(1.0f, BufferSpan.data(), size);
    for (size_t i = 0; i < size; ++i) {
        utils::xsAssert_eq(BufferSpan[i], 1.0f, kXsFloat32);
    }
}

TEST(madd, size_27) {
    size_t size = 27;
    xsdnn::mat_t Buffer(size * dtype2sizeof(kXsFloat32));
    utils::value_init_fp32(Buffer, 0);
    gsl::span<float> BufferSpan = GetMutableDataAsSpan<float>(&Buffer);
    mmpack::MmAdd(1.0f, BufferSpan.data(), size);
    for (size_t i = 0; i < size; ++i) {
        utils::xsAssert_eq(BufferSpan[i], 1.0f, kXsFloat32);
    }
}

TEST(madd, size_28) {
    size_t size = 28;
    xsdnn::mat_t Buffer(size * dtype2sizeof(kXsFloat32));
    utils::value_init_fp32(Buffer, 0);
    gsl::span<float> BufferSpan = GetMutableDataAsSpan<float>(&Buffer);
    mmpack::MmAdd(1.0f, BufferSpan.data(), size);
    for (size_t i = 0; i < size; ++i) {
        utils::xsAssert_eq(BufferSpan[i], 1.0f, kXsFloat32);
    }
}

TEST(madd, size_29) {
    size_t size = 29;
    xsdnn::mat_t Buffer(size * dtype2sizeof(kXsFloat32));
    utils::value_init_fp32(Buffer, 0);
    gsl::span<float> BufferSpan = GetMutableDataAsSpan<float>(&Buffer);
    mmpack::MmAdd(1.0f, BufferSpan.data(), size);
    for (size_t i = 0; i < size; ++i) {
        utils::xsAssert_eq(BufferSpan[i], 1.0f, kXsFloat32);
    }
}

TEST(madd, size_30) {
    size_t size = 30;
    xsdnn::mat_t Buffer(size * dtype2sizeof(kXsFloat32));
    utils::value_init_fp32(Buffer, 0);
    gsl::span<float> BufferSpan = GetMutableDataAsSpan<float>(&Buffer);
    mmpack::MmAdd(1.0f, BufferSpan.data(), size);
    for (size_t i = 0; i < size; ++i) {
        utils::xsAssert_eq(BufferSpan[i], 1.0f, kXsFloat32);
    }
}

TEST(madd, size_31) {
    size_t size = 31;
    xsdnn::mat_t Buffer(size * dtype2sizeof(kXsFloat32));
    utils::value_init_fp32(Buffer, 0);
    gsl::span<float> BufferSpan = GetMutableDataAsSpan<float>(&Buffer);
    mmpack::MmAdd(1.0f, BufferSpan.data(), size);
    for (size_t i = 0; i < size; ++i) {
        utils::xsAssert_eq(BufferSpan[i], 1.0f, kXsFloat32);
    }
}
