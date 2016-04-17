#ifndef CMOCK_TEST_FOO_MOCK_H__
#define CMOCK_TEST_FOO_MOCK_H__

#include "cmock/cmock.h"
#include "foo.h"

DECLARE_FUNCTION_MOCK1(FooFunctionMock, foo, int(callback));

#endif
