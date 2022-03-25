#pragma once

#include <string>


namespace Exc
{


	class EStack
	{
	public:
		EStack(const std::string& msg);
		EStack(const EStack& otherStack);

		virtual ~EStack();

		const char* what() const;
	private:
		std::string errMsg;
	};


	class EStackEmpty : public EStack
	{
	public:
		EStackEmpty(const std::string& msg);
		EStackEmpty(const EStackEmpty& otherStack);
		~EStackEmpty() override;
	};


	class EStackOverflow : public EStack
	{
	public:
		EStackOverflow(const std::string& msg);
		EStackOverflow(const EStackEmpty& otherStack);
		~EStackOverflow() override;
	};


} // namespace Exc
