#include "stdafx.h"
#include "doorCloseingSecurity.h"

int doorCloseingSecurity::main(int isDoorClosed, int reverser) {
	// �˕ۈ�
	if (isDoorClosed) {
		return reverser;
	}
	else {
		return 0;
	}
}