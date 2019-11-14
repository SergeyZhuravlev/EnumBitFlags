#pragma once
#include <functional>
#include <utility>

namespace exceptionsSupport
{
	class OnScopeExit
	{
	public:
		OnScopeExit() = delete;
		OnScopeExit(const OnScopeExit&) = delete;
		OnScopeExit& operator=(const OnScopeExit&) = delete;
		template<class T>
		OnScopeExit(T&& handler)
		: _handler(std::forward<T>(handler))
		{}
		~OnScopeExit() noexcept(false)
		{
			bool afterException = std::uncaught_exception();
			try
			{
				if(_handler)
					_handler();
			}catch(...)
			{
				if(!afterException)
					throw;
			}
		}
		
	private:
		std::function<void()> _handler;
	};
}