#ifndef CPP_EXEC_22
#define CPP_EXEC_22

class Stack final {
  static constexpr int ARRAY_SIZE{8};
  static int array[ARRAY_SIZE];
  static int count;

public:
  static Stack &instance(void);

  /**
   * @brief Pushes a value into stack.
   *
   * @param _value Integer to add.
   * @return `true` if successful.
   */
  bool push(int _value);

  /**
   * @brief Returns count.
   *
   * @return int
   */
  int getNumber(void);

  /**
   * @brief
   *
   * @param _int A integer to apply the popped value.
   * @return ``true if successful.
   */
  bool pop(int &_int);

  /**
   * @brief Check if stack is full
   *
   * @return `true` if full
   */
  bool checkFull(void);

  /**
   * @brief Checks if stack is empty by count.
   *
   * @return `true` if empty
   */
  bool checkEmpty(void);

  /**
   * @brief Resets counter
   *
   */
  void clear(void);
};

#endif