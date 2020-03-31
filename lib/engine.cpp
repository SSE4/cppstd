#include "engine.h"

#define CHECK_IMPL(type) \
template<> \
void check(const type & value, size_t expected_size, size_t expected_alignment) \
{ \
    std::cout << "checking " << typeid(type).name() << std::endl; \
    size_t actual_size = sizeof(type); \
    if (actual_size != expected_size) \
        throw std::runtime_error("type size doesn't match!"); \
    size_t actual_alignment = type_alignof(type); \
    if (actual_alignment != expected_alignment && actual_alignment != 0 && expected_alignment != 0) \
        throw std::runtime_error("type alignment doesn't match"); \
}

#define IMPL
#include "checks.h"

void init()
{
#undef IMPL
#include "checks.h"
}
