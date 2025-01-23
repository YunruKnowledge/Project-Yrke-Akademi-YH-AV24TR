/**
 * @file TCircularBuffer.hpp
 * @author Khanh Tran (88000687+YunruKnowledge@users.noreply.github.com)
 * @brief Uncopyable circular buffer array of template type.
 * @version 0.1
 * @date 2025-01-23
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef TCircularBuffer_H
#define TCircularBuffer_H

#include <iostream>

/**
 * @brief Class for a circular buffer. 
 * Arithmetic types will have access to getAvarage();
 * 
 * @tparam T type of data.
 * @tparam N size of buffer, `size_t`.
 */
template <typename T, size_t N> class Buffer {
  T array[N];
  size_t size{N};
  size_t head{0};
  size_t tail{0};
  size_t count{0};
  static constexpr size_t MIN_SIZE{4};

public:
  Buffer(const Buffer &) = delete;
  Buffer &operator=(const Buffer &) = delete;

  friend std::ostream &operator<<(std::ostream &_os, const Buffer &_instance) {
    if (_instance.count == 0) {
      _os << "[Empty]";
    } else {
      _os << "[";
      for (size_t i = 0; i < _instance.count; i++) {
        size_t temp{0};
        if ((_instance.tail + i) >= _instance.size) {
          temp = (_instance.tail + i) - _instance.size;
        } else {
          temp = _instance.tail + i;
        }

        if (i == _instance.count - 1) {
          _os << _instance.array[temp];
        } else {
          _os << _instance.array[temp] << " -> ";
        }
      }
      _os << "]";
    }

    return _os;
  };

  Buffer() {
    if (N < MIN_SIZE) {
      try {
        throw std::range_error("Below minimun size.");
      } catch (...) {
        throw;
      }
    }
  }

public:
  /**
   * @brief Reads a value from the buffer.
   *
   * @param _var variable for applying the value to.
   * @return `true` upon success.
   */
  bool read(T &_var) {
    bool status{false};

    if (count > 0) {
      _var = array[tail];

      // increments tail, loops if reaches end.
      if (tail >= size - 1) {
        tail = 0;
      } else {
        tail++;
      }

      count--;
      status = true;
    } else {
      ;
    }

    return status;
  }

  /**
   * @brief Add a value into the buffer. *Will overwrite upon full.
   *
   * @param _value value to add.
   * @return `false` when a data has been overwritten.
   */
  bool write(const T _value) {
    bool status{true};

    array[head] = _value;

    // increments tail if head catches tail.
    if (head == tail && count > 0) {
      if (tail >= size - 1) {
        tail = 0;
      } else {
        tail++;
      }
      status = false;
    }

    // increments head loops if reaches end.
    if (head >= size - 1) {
      head = 0;
    } else {
      if (head == tail && count > 0) {
        tail++;
      }
      head++;
    }

    // increments count, not if more than size.
    if (count < size) {
      count++;
    }

    return status;
  }

  /**
   * @brief Resets buffer to empty.
   *
   */
  void clear(void) {
    head = 0;
    tail = 0;
    count = 0;
  }

  /**
   * @brief Bool status for if buffer is fully filled.
   *
   * @return `true` if count matches size. E.g. full.
   */
  bool isFull() { return (count == size); }

  /**
   * @brief Gets the amount of data inside buffer.
   *
   * @return size_t
   */
  size_t getCount() { return count; }

  /**
   * @brief Gets the avarage value of all data currently in the buffer.
   * Arithmetic values only
   *
   * @tparam Arithmetic_type
   * @return double
   */
  template <typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
  double getAvarage(void) {
    double sum{0};
    double avarage;

    if (count == 0) {
      avarage = 0;
    } else if (count == 1) {
      avarage = array[tail];
    } else {
      for (size_t i = 0; i < count; i++) {
        size_t temp{0};
        if ((tail + i) >= size) {
          temp = (tail + i) - size;
        } else {
          temp = tail + i;
        }
        sum += array[temp];
      }
      avarage = sum / static_cast<double>(count);
    }

    return avarage;
  }
};

#endif