#include <cmock/cmock.h>

#include "foo_mock.h"

using namespace ::testing;
void cb_stub(void)
{
	printf("in test cb stub\n");
}

void cb_real(void)
{
	printf("in test cb real\n");
}

int foo_stub(callback cb)
{
	printf("calling foo_stub\n");
	cb();
	return 0;
}
TEST(FunctionMockersTest, TestCb)
{
	{
		FooFunctionMock mock;
		callback cb = cb_stub;
		EXPECT_FUNCTION_CALL(mock, (cb_real)).WillOnce(Invoke(foo_stub));
		ASSERT_EQ(0, foo(cb_real));
	}

	ASSERT_EQ(1, foo(cb_real));
}
