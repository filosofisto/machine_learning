#ifndef _MACHINE_LEARNING_H_
#define _MACHINE_LEARNING_H

#include <vector>
#include <numeric>
#include <cmath>

template<typename T>
class MachineLearning
{
public:
    explicit MachineLearning() = default;
    virtual ~MachineLearning() = default;

    MachineLearning& operator<<(const T& item);
    
    template<typename Func>
    double mean(Func extractor) const;
    
    /**
     * Linear Regression equation: y = c + m*x
     * m -> slope line
     */
    template<typename GetX, typename GetY>
    double slope(GetX getX, GetY getY) const;

private:
    std::vector<T> data;
};

template<typename T>
MachineLearning<T>& MachineLearning<T>::operator<<(const T& item)
{
    data.push_back(item);
    return *this;
}

template<typename T>
template<typename Func>
double MachineLearning<T>::mean(Func extractor) const
{
    if (data.size() == 0) return 0.0;

    double sum = std::accumulate(data.begin(), data.end(), 0.0, [&](double acc, const T& item) {
        return acc + extractor(item);
    });

    return sum / data.size();
}

template<typename T>
template<typename GetX, typename GetY>
double MachineLearning<T>::slope(GetX getX, GetY getY) const
{
    double meanX = mean(getX);
    double meanY = mean(getY);

    return std::accumulate(data.begin(), data.end(), 0.0, [&](double acc, const T& item) {
        return acc + (getX(item) - meanX) * (getY(item) - meanY);
    }) / std::accumulate(data.begin(), data.end(), 0.0, [&](double acc, const T& item) {
        return acc + std::pow(getX(item) - meanX, 2.0);
    });
}
#endif
