#include <gtest/gtest.h>
#include <Eigen/Core>
#include "gm.hpp"
#include "target.hpp"

using namespace lmb;
using GaussianReport = GaussianReport_<2>;

TEST(SensorTests, Likelihood) {
    auto m = Eigen::Vector2d({1, 1});
    auto P = Eigen::Matrix2d::Identity();
    GaussianReport z(m, P, 1);
    auto a = Eigen::Vector2d({1, 1});
    auto Dinv = Eigen::Matrix2d::Identity().inverse();

    double res = z.likelihood(m - a, Dinv);
    EXPECT_FLOAT_EQ(res, 0.159155);

    a = Eigen::Vector2d({0, 0});

    res = z.likelihood(m - a, Dinv);
    EXPECT_FLOAT_EQ(res, 0.058549833);
}
