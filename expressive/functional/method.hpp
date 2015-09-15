#pragma once

namespace expressive
{
namespace functional
{

template<class Pointer, class T>
struct method_wrapper;

template<class Pointer, class Result, class Class, class... Args>
struct method_wrapper<Pointer, Result (Class::*)(Args...) const>
{
    method_wrapper(Pointer object, Result (Class::* method)(Args...) const) : object(object), method(method)
    {
    }

    auto operator() (Args... args)
    {
        return ((*object).*method)(args...);
    }

private:
    Pointer object;
    Result (Class::* method)(Args...) const;
};

template<class Pointer, class Method>
auto method(Pointer object, Method p) -> method_wrapper<Pointer, Method>
{
    return method_wrapper<Pointer, Method>{object, p};
}

} // namespace functional
} // namespace expressive
