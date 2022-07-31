#pragma once

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

#include <d3d11.h>
#include <DirectXMath.h>

//・LEARN：ComPtrって何？
#include <wrl/client.h>
using Microsoft::WRL::ComPtr;

//・Direct3Dの唯一のインスタンスを簡単に取得するためのマクロ
#define D3D Direct3D::GetInstance()

class Direct3D {
public:
    /** @brief Direct3Dデバイス */
    ComPtr<ID3D11Device> m_device;
    /** @brief Direct3Dデバイスコンテキスト */
    ComPtr<ID3D11DeviceContext> m_deviceContext;
    /** @brief スワップチェイン */
    ComPtr<IDXGISwapChain> m_swapChain;
    /** @brief バックバッファのRTビュー */
    ComPtr<ID3D11RenderTargetView> m_backBufferView;

    /**
     * @brief Direct3Dを初期化し、使用できるようにするための関数
     * @param (hWnd) ウィンドウハンドル
     * @param (width) 画面の幅
     * @param (height) 画面の高さ
     * @return LEARN：？？？
     */
    bool Initialize(HWND hWnd, int width, int height);


    //=========================================
    // シングルトーンパターンの実装
    //=========================================
private:
    /** @brief 唯一のインスタンス用のポインタ */
    static inline Direct3D* s_instance;
    /** @brief コンストラクタ */
    Direct3D() = default;

public:
    /**
     * @brief インスタンスの作成
     */
    static void CreateInstance() {
        DeleteInstance();
        s_instance = new Direct3D();
    }
    /**
     * @brief インスタンスの削除
     */
    static void DeleteInstance() {
        if (s_instance != nullptr) {
            delete s_instance;
            s_instance = nullptr;
        }
    }
    /**
     * @brief 唯一のインスタンスを取得
     */
    static Direct3D& GetInstance() {
        return *s_instance;
    }
};