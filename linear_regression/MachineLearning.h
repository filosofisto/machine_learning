#ifndef _MACHINE_LEARNING_H_
#define _MACHINE_LEARNING_H

#include <vector>

template<typename T>
class MachineLearning
{
public:
    explicit MachineLearning() = default;
    virtual ~MachineLearning() = default;

    MachineLearning& operator<<(const T& item);
    
    template<typename Func>
    double mean(Func extractor) const;

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

    double sum = 0.0;

    for (auto& item: data) {
        sum += extractor(item);
    }

    return sum / data.size();
}
#endif
