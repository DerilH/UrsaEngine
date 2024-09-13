//
// Created by deril on 9/9/24.
//
#pragma once
#include <memory>

namespace Ursa {
    template<typename T>
    using Scope = std::unique_ptr<T>;

    template<typename T, typename... Args>
    constexpr Scope<T> CreateScope(Args &&... args) {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
        constexpr Scope<T> CreateDerivedScope(T* b) {
        return std::unique_ptr<T>(b);
    }

    template<typename T>
    using Ref = std::shared_ptr<T>;

    template<typename T, typename... Args>
    constexpr Ref<T> CreateRef(Args &&... args) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    constexpr Ref<T> CreateDerivedRef(T* b) {
        return std::shared_ptr<T>(b);
    }
}
