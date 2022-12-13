#pragma once
#include <cmath>
namespace statpp {
    /// @brief Represents an array
    /// @tparam T type of data in the array.
    template <typename T> class array {
    protected:
        T* data;
        size_t size;
    public:
        /// @brief Initialise a new array.
        /// @param size of the dataset.
        array(size_t size) : size(size) {
            data = new T[size];
        }
        ~array() {
            delete[] data;
        }
        /// @brief returns an element at the specified index
        /// @param index index of the element.
        /// @return a reference to index-th element.
        T& operator[](size_t index) {
            return data[index];
        }
        /// @brief the size of the dataset.
        /// @return size of the dataset.
        size_t length() {
            return size;
        }
    };
    /// @brief a set of `doubles`
    class array<double> {
    protected:
        double* data;
        size_t size;
    public:
        /// @brief calculate the average of the array
        /// @return the mean of the data set.
        double mean() {
            double sum;
            for(int i = 0; i < this->size; i++) {
                sum += this->data[i];
            }
            return sum;
        }
        /// @brief calculate the median of the array
        /// @return the median of the data set.
        double median() {
            if(this->size % 2 == 1)
                return this->data[this->size/2];
            
            return (this->data[this -> size / 2] + this->data[this -> size / 2 + 1])/2;
        }

        /// @brief calculate standard deviation
        /// @return standard deviation of the data set.
        double stddev() {
            double sum = 0;
            double mean = this->mean();
            for(int i = 0; i < this->size; i++) {
                sum += (this->data[i] - mean) * (this->data[i] - mean);
            }
            return sqrt(sum / this->size);
        }

        /// @brief finds maximum value in the data set.
        /// @return maximum value in the data set.
        double max() {
            double val = data[0];
            for(int i = 0; i < this->size; i++) if(val < data[i]) val = data[i];
            
            return val;
        }

        /// @brief finds minimum value in the data set.
        /// @return minimum value in the data set.
        double min() {
            double val = data[0];
            for(int i = 0; i < this->size; i++) if(val > data[i]) val = data[i];
            
            return val;
        }

        /// @brief calculate distance of the data set.
        /// @return distance of the data set.
        double distance() {
            return this->max() - this->min();
        }
    };
}