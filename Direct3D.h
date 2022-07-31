#pragma once

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

#include <d3d11.h>
#include <DirectXMath.h>

//�ELEARN�FComPtr���ĉ��H
#include <wrl/client.h>
using Microsoft::WRL::ComPtr;

//�EDirect3D�̗B��̃C���X�^���X���ȒP�Ɏ擾���邽�߂̃}�N��
#define D3D Direct3D::GetInstance()

class Direct3D {
public:
    /** @brief Direct3D�f�o�C�X */
    ComPtr<ID3D11Device> m_device;
    /** @brief Direct3D�f�o�C�X�R���e�L�X�g */
    ComPtr<ID3D11DeviceContext> m_deviceContext;
    /** @brief �X���b�v�`�F�C�� */
    ComPtr<IDXGISwapChain> m_swapChain;
    /** @brief �o�b�N�o�b�t�@��RT�r���[ */
    ComPtr<ID3D11RenderTargetView> m_backBufferView;

    /**
     * @brief Direct3D�����������A�g�p�ł���悤�ɂ��邽�߂̊֐�
     * @param (hWnd) �E�B���h�E�n���h��
     * @param (width) ��ʂ̕�
     * @param (height) ��ʂ̍���
     * @return LEARN�F�H�H�H
     */
    bool Initialize(HWND hWnd, int width, int height);


    //=========================================
    // �V���O���g�[���p�^�[���̎���
    //=========================================
private:
    /** @brief �B��̃C���X�^���X�p�̃|�C���^ */
    static inline Direct3D* s_instance;
    /** @brief �R���X�g���N�^ */
    Direct3D() = default;

public:
    /**
     * @brief �C���X�^���X�̍쐬
     */
    static void CreateInstance() {
        DeleteInstance();
        s_instance = new Direct3D();
    }
    /**
     * @brief �C���X�^���X�̍폜
     */
    static void DeleteInstance() {
        if (s_instance != nullptr) {
            delete s_instance;
            s_instance = nullptr;
        }
    }
    /**
     * @brief �B��̃C���X�^���X���擾
     */
    static Direct3D& GetInstance() {
        return *s_instance;
    }
};