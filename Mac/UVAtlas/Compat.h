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

// SAL compat
#define _In_
#define _In_opt_
#define _Inout_
#define _Inout_opt_
#define _In_reads_(x)
#define _In_reads_opt_(x)
#define _In_reads_bytes_(x)
#define _Out_
#define _Out_opt_
#define _Out_writes_(x)
#define _Out_writes_bytes_(x)
#define _Inout_updates_all_(x)
#define _Use_decl_annotations_
#define _When_(cond, code)
#define _Success_(x)
#define __in_ecount(x)
#define __out_ecount(x)

// Return value compat
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

// Win API declaration compat
#define __cdecl
#define WINAPI
#define STDMETHOD(name) virtual HRESULT name
#define STDMETHODIMP HRESULT
#define PURE = 0

// DirectX compat
#define DWORD int
#define DXGI_FORMAT int
#define DXGI_FORMAT_R16_UINT 1
#define DXGI_FORMAT_R32_UINT 2

// Common
#define UNREFERENCED_PARAMETER(x)
float __min(float lhs, float rhs) { return fmin(lhs, rhs); }
#define _Analysis_assume_(x)
#define _finite(x) x

namespace DirectX
{
    const float XM_PI = 3.14159265359f;
    struct XMFLOAT2
    {
        union
        {
            float data[2];
            struct
            {
                float x;
                float y;
            };
        };

        XMFLOAT2() = default;
        XMFLOAT2(float x, float y) : x(x), y(y) {}
        float& operator [](int index) { return data[index]; }
    };

    struct XMFLOAT3
    {
        union
        {
            float data[3];
            struct
            {
                float x;
                float y;
                float z;
            };
        };

        XMFLOAT3() = default;
        XMFLOAT3(float x, float y, float z) : x(x), y(y), z(z) {}
        float& operator [](int index) { return data[index]; }
    };

    struct XMFLOAT4
    {
        union
        {
            float data[4];
            struct
            {
                float x;
                float y;
                float z;
                float w;
            };
        };

        XMFLOAT4() = default;
        XMFLOAT4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
        float& operator [](int index) { return data[index]; }
    };

    typedef XMFLOAT4 XMVECTOR;

    XMVECTOR operator +(XMVECTOR lhs, XMVECTOR rhs)
    {
        return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w };
    }

    XMVECTOR operator -(XMVECTOR lhs, XMVECTOR rhs)
    {
        return { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w };
    }

    XMVECTOR operator *(XMVECTOR lhs, float rhs)
    {
        return { lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs };
    }

    XMVECTOR operator /(XMVECTOR lhs, float rhs)
    {
        return { lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs };
    }

    XMVECTOR& operator +=(XMVECTOR& lhs, XMVECTOR rhs)
    {
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        lhs.z += rhs.z;
        lhs.w += rhs.w;
        return lhs;
    }

    XMVECTOR& operator -=(XMVECTOR& lhs, XMVECTOR rhs)
    {
        lhs.x -= rhs.x;
        lhs.y -= rhs.y;
        lhs.z -= rhs.z;
        lhs.w -= rhs.w;
        return lhs;
    }

    XMVECTOR& operator *=(XMVECTOR& lhs, float rhs)
    {
        lhs.x *= rhs;
        lhs.y *= rhs;
        lhs.z *= rhs;
        lhs.w *= rhs;
        return lhs;
    }

    XMVECTOR& operator /=(XMVECTOR& lhs, float rhs)
    {
        lhs.x /= rhs;
        lhs.y /= rhs;
        lhs.z /= rhs;
        lhs.w /= rhs;
        return lhs;
    }

    XMVECTOR XMVectorZero() { return { 0.0f, 0.0f, 0.0f, 0.0f }; }
    XMVECTOR XMVectorSet(float x, float y, float z, float w) { return { x, y, z, w }; }
    XMVECTOR XMLoadFloat2(const XMFLOAT2 v) { return { v.x, v.y, 0.0f, 0.0f }; }
    XMVECTOR XMLoadFloat2(const XMFLOAT2* v) { return { v->x, v->y, 0.0f, 0.0f }; }
    XMVECTOR XMLoadFloat3(const XMFLOAT3 v) { return { v.x, v.y, v.z, 0.0f }; }
    XMVECTOR XMLoadFloat3(const XMFLOAT3* v) { return { v->x, v->y, v->z, 0.0f }; }
    XMVECTOR XMLoadFloat4(const XMFLOAT4 v) { return { v.x, v.y, v.z, v.w }; }
    XMVECTOR XMLoadFloat4(const XMFLOAT4* v) { return { v->x, v->y, v->z, v->w }; }

    void XMStoreFloat2(XMFLOAT2* dest, XMVECTOR src)
    {
        dest->x = src.x;
        dest->y = src.y;
    }

    void XMStoreFloat3(XMFLOAT3* dest, XMVECTOR src)
    {
        dest->x = src.x;
        dest->y = src.y;
        dest->z = src.z;
    }

    void XMStoreFloat4(XMFLOAT4* dest, XMVECTOR src)
    {
        dest->x = src.x;
        dest->y = src.y;
        dest->z = src.z;
        dest->w = src.w;
    }

    float XMVectorGetX(XMVECTOR v) { return v.x; }
    float XMVectorGetY(XMVECTOR v) { return v.y; }
    float XMVectorGetZ(XMVECTOR v) { return v.z; }
    float XMVectorGetW(XMVECTOR v) { return v.w; }

    XMVECTOR& XMVectorSetX(XMVECTOR& v, float value) { v.x = value; return v; }
    XMVECTOR& XMVectorSetY(XMVECTOR& v, float value) { v.y = value; return v; }
    XMVECTOR& XMVectorSetZ(XMVECTOR& v, float value) { v.z = value; return v; }
    XMVECTOR& XMVectorSetW(XMVECTOR& v, float value) { v.w = value; return v; }

    bool roughlyEqual(float lhs, float rhs)
    {
        return fabsf(lhs - rhs) < 0.00001f;
    }

    bool XMVector3Equal(XMVECTOR& lhs, XMVECTOR& rhs)
    {
        return roughlyEqual(lhs.x, rhs.x)
            && roughlyEqual(lhs.y, rhs.y)
            && roughlyEqual(lhs.z, rhs.z)
            && roughlyEqual(lhs.w, rhs.w);
    }

    XMVECTOR XMVector2Length(XMVECTOR v)
    {
        float l = sqrtf(v.x * v.x + v.y * v.y);
        return { l, l, l, l };
    }

    XMVECTOR XMVector2LengthSq(XMVECTOR v)
    {
        float l = v.x * v.x + v.y * v.y;
        return { l, l, l, l };
    }

    XMVECTOR XMVector3LengthSq(XMVECTOR v)
    {
        float l = v.x * v.x + v.y * v.y + v.z * v.z;
        return { l, l, l, 0.0f };
    }

    XMVECTOR XMVector3Length(XMVECTOR v)
    {
        float l = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
        return { l, l, l, 0.0f };
    }

    XMVECTOR XMVector2Normalize(XMVECTOR v)
    {
        float l = sqrtf(v.x * v.x + v.y * v.y);
        return { v.x / l, v.y / l, 0.0, 0.0f };
    }

    XMVECTOR XMVector3Normalize(XMVECTOR v)
    {
        float l = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
        return { v.x / l, v.y / l, v.z / l, 0.0f };
    }

    XMVECTOR XMVector3Cross(XMVECTOR& lhs, XMVECTOR& rhs)
    {
        return
        {
            lhs.y * rhs.z - lhs.z * rhs.y,
            lhs.z * rhs.x - lhs.x * rhs.z,
            lhs.x * rhs.y - lhs.y * rhs.x,
            0.0f
        };
    }

    XMVECTOR XMVector2Dot(XMVECTOR lhs, XMVECTOR rhs)
    {
        float dot = lhs.x * rhs.x + lhs.y * rhs.y;
        return { dot, dot, dot, dot };
    }

    XMVECTOR XMVector3Dot(XMVECTOR lhs, XMVECTOR rhs)
    {
        float dot = lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
        return { dot, dot, dot, dot };
    }

    struct XMFLOAT4X4
    {
        float data[16];
        float& operator [](int index) { return data[index]; }
    };

    typedef XMFLOAT4X4 XMMATRIX;
    XMMATRIX operator *(XMMATRIX lhs, XMMATRIX rhs)
    {
        // TODO Stub
        return {};
    }

    XMMATRIX XMMatrixIdentity() { XMMATRIX m = {}; m[15] = 1.0f; return m; }
    XMFLOAT4X4 XMLoadFloat4x4(XMFLOAT4X4* m)
    {
        XMMATRIX dest = {};
        for (int i = 0; i < 16; i++)
        {
            dest.data[i] = m->data[i];
        }

        return dest;
    }
    
    XMFLOAT4X4* XMStoreFloat4x4(XMFLOAT4X4* dest, XMMATRIX src)
    {
        for (int i = 0; i < 16; i++)
        {
            dest->data[i] = src.data[i];
        }

        return dest;
    }
    
    XMMATRIX XMMatrixTranslation(float x, float y, float z)
    {
        // TODO: Check actual DX matrix layout!
        XMMATRIX m = {};
        m[0] = x;
        m[1] = y;
        m[2] = z;
        m[15] = 1.0f;
        return m;
    }

    XMMATRIX XMMatrixRotationZ(float angle)
    {
        // TODO: Stub
        XMMATRIX m = {};
        m[15] = 1.0f;
        return m;
    }

    XMMATRIX XMMatrixScaling(float x, float y, float z)
    {
        // TODO: Stub
        XMMATRIX m = {};
        m[15] = 1.0f;
        return m;
    }

    XMVECTOR XMVector2TransformCoord(XMVECTOR v, XMMATRIX m)
    {
        // TODO: Stub
        return v;
    }

    XMFLOAT2* XMVector2TransformCoordStream(XMFLOAT2* dest, size_t destStride,
                                            const XMFLOAT2* src, size_t srcStride, size_t srcCount,
                                            XMMATRIX m)
    {
        // TODO: Stub
        return dest;
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
