Some `expressive` c++ toys.

## Functional primitives

You can do pretty much everything with `std::bind` but this library tends to name things in more comprehensive way. Check out [this example](examples/advanced_function_composition.cpp) to see how to do the same thing in `std::bind` and `expressive` way.

* [`functional::compose`](examples/simple_function_composition.cpp) - variadic function composition
* `functional::curry` - partial application
* `functional::member` - member fetch function - `member(&some_struct::some_member) -> f(some_struct) -> decltype(some_struct::some_member)`
* `functional::method` - method bind, but without need for placeholders

## Container utilities
* [`enumerate`](examples/enumerate.cpp) - iterate over container with index
* [`map_element`](examples/map_element.cpp) - do something on map's element by typing map's name once
* `container_cast` - eg `auto set = container_cast<std::set<int>>(vector_of_ints)`

## More
* `match` - switch / if substitution which behaves like expression and can take predicates
* [`strong_type`](examples/strong_type_example.cpp) - strong typing for primitives
* [`factory`](examples/factory.cpp) - `std::make_shared` wrapper with usable [`mock`](tests/factory_mock.hpp)
* [`watch`](examples/watch.cpp) - "smart" variable which does something when its value really changes

## Metaprogramming utilities
* `nth_element_or` - gives nth element of template argument pack or other type if index is out of range
