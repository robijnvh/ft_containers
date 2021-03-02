#include "vector.hpp"

// int main(void)
// {
// 	// ft::Vector<int> v(5);

// 	ft::Vector<int>::size_type sz;

	// return (0);
// }

template<typename T>
void	printVector(const ft::Vector<T>& vector)
{
	for (size_t i = 0; i < vector.size() ; ++i)
		std::cout << vector[i] << std::endl;
	std::cout << "------------------" << std::endl;
}

int main (void)
{
  ft::Vector<int>::size_type sz;

  ft::Vector<int> foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  for (int i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }

  return 0;
}
