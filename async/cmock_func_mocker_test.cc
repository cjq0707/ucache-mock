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
		EXPECT_FUNCTION_CALL(mock, (_)).WillOnce(DoAll(InvokeArgument<0>(), Return(-1)));
		ASSERT_EQ(-1, foo(cb_real));
		EXPECT_FUNCTION_CALL(mock, (_)).WillOnce(Invoke(foo_stub));
		ASSERT_EQ(0, foo(cb_real));
		EXPECT_FUNCTION_CALL(mock, (_)).WillOnce(SetArgPointee<0>(cb_stub));
		ASSERT_EQ(1, foo(cb_real));
	}

	ASSERT_EQ(1, foo(cb_real));
}
