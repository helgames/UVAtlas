//
//  Compat.h
//  UVAtlas
//
//  Created by Paul Schulze on 25.02.2018.
//  Copyright © 2018 Hel Games. All rights reserved.
//

#pragma once

#include "math.h"
#include "stdint.h"
#include <cstring>
#include "sal.h"

// Return values
#define HRESULT int32_t
#define S_OK 0
#define E_POINTER 1
#define E_OUTOFMEMORY 2
#define ERROR_INVALID_DATA 3
#define E_INVALIDARG 4
#define E_UNEXPECTED 5
#define E_FAIL 6
#define E_ABORT 7
#define HRESULT_FROM_WIN32(x) x
#define ERROR_NOT_SUPPORTED 4
#define ERROR_ARITHMETIC_OVERFLOW 5
#define FAILED(cond) ((cond) != S_OK)
#define SUCCEEDED(cond) ((cond) == S_OK)

// Win API declaration
#define __cdecl
#define __declspec(x)
#define WINAPI
#define STDMETHOD(name) virtual HRESULT name
#define STDMETHODIMP HRESULT
#define PURE = 0

#define UNREFERENCED_PARAMETER(x)
float __min(float lhs, float rhs) { return fmin(lhs, rhs); }
#define _Analysis_assume_(x)
#define _finite(x) x

// DirectX
#define DWORD int
#define DXGI_FORMAT int
#define DXGI_FORMAT_R16_UINT 1
#define DXGI_FORMAT_R32_UINT 2

#define _XM_NO_INTRINSICS_
#include "DirectXMath.h"

namespace DirectX
{
	XMVECTOR operator +(XMVECTOR lhs, XMVECTOR rhs)
	{
		return XMVectorAdd(lhs, rhs);
	}
	
	XMVECTOR operator -(XMVECTOR lhs, XMVECTOR rhs)
	{
		return XMVectorSubtract(lhs, rhs);
	}
	
	XMVECTOR operator *(XMVECTOR lhs, float rhs)
	{
		return XMVectorScale(lhs, rhs);
	}
	
	XMVECTOR operator /(XMVECTOR lhs, float rhs)
	{
		return XMVectorScale(lhs, 1.0f/rhs);
	}
	
	XMVECTOR& operator +=(XMVECTOR& lhs, XMVECTOR rhs)
	{
		lhs = XMVectorAdd(lhs, rhs);
		return lhs;
	}
	
	XMVECTOR& operator -=(XMVECTOR& lhs, XMVECTOR rhs)
	{
		lhs = XMVectorSubtract(lhs, rhs);
		return lhs;
	}
	
	XMVECTOR& operator *=(XMVECTOR& lhs, float rhs)
	{
		lhs = XMVectorScale(lhs, rhs);
		return lhs;
	}
	
	XMVECTOR& operator /=(XMVECTOR& lhs, float rhs)
	{
		lhs = XMVectorScale(lhs, 1.0f / rhs);
		return lhs;
	}
}

// Mutex compat
struct MutexHandle
{
    // TODO: Stub, should contain the actual handle
};

#define CREATE_MUTEX_INITIAL_OWNER 1
#define SYNCHRONIZE 2
#define WAIT_OBJECT_0 0
#define FALSE 0
#define TRUE 1

typedef MutexHandle* HANDLE;

HANDLE CreateMutexEx(int* dontCare1, int* dontCare2, int someParam1, int someParam2)
{
    // TODO: Stub
    return nullptr;
}

void CloseHandle(HANDLE handle)
{
    // TODO: Stub
}

HRESULT WaitForSingleObjectEx(HANDLE handle, int someParam1, bool someParam2)
{
    // TODO: Stub
    return WAIT_OBJECT_0;
}

HRESULT ReleaseMutex(HANDLE handle)
{
    // TODO: Stub
    return S_OK;
}

void SwitchToThread()
{
    // TODO: Stub
}

HRESULT GetLastError()
{
    // TODO: Stub
    return S_OK;
}
