# ft_containers

Welcome to ft_containers! This project aims to implement various container classes from the C++ Standard Library, including vector, list, map, stack, and queue. By implementing these containers, you'll gain a deeper understanding of their underlying data structures and operations.

## Implemented Containers

- **Vector**: Dynamic array with similar functionality to `std::vector`.
- **List**: Doubly linked list with similar functionality to `std::list`.
- **Map**: Associative container that stores key-value pairs, similar to `std::map`.
- **Stack**: LIFO (Last-In, First-Out) container similar to `std::stack`.
- **Queue**: FIFO (First-In, First-Out) container similar to `std::queue`.

## Getting Started

1. Clone this GitHub repository to your local machine:

  git clone https://github.com/Cavallucci/ft_containers.git

2. Navigate to the project directory:

  cd ft_containers

3. Compile the project using the provided Makefile:

  make

4. Run the provided tests to validate the functionality of the implemented containers:

./ft_containers_tests

## Usage

Once the project is compiled and the tests pass successfully, you can start using the implemented containers in your own code. Here's an example of how to use the vector container:

```cpp
#include <iostream>
#include "vector.hpp"

int main() {
 ft::vector<int> vec;

 // Add elements to the vector
 vec.push_back(10);
 vec.push_back(20);
 vec.push_back(30);

 // Access elements using the subscript operator or iterators
 std::cout << "Elements in the vector: ";
 for (size_t i = 0; i < vec.size(); ++i) {
     std::cout << vec[i] << " ";
 }
 std::cout << std::endl;

 return 0;
}
```

Feel free to explore the other implemented containers in a similar manner.

This project is licensed under the MIT License.
Credits

ft_containers is brought to you by the following contributors:

    Laura Cavallucci

I would like to express my gratitude to the open-source community for their valuable libraries, resources, and inspiration.

For more detailed information about the project, including implementation details, usage examples, and additional container classes, please refer to the project's wiki.
