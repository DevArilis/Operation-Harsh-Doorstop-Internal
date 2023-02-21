#include "includes.h"
#include <cstdio>
#include "SDK.h"
#include "SDK/BasicTypes_Package.cpp"
#include "SDK/CoreUObject_Package.cpp"
#include "SDK/Engine_Package.cpp"
#include "SDK/DonkehFramework_Package.cpp"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
#define KP( k ) ( GetAsyncKeyState(k) & 0x8000 )
#define Nullcheck(x) if (x == NULL || x == nullptr) {return;}
Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

static bool showWindow = true;

bool InfiniteAmmoHack = false;
bool NoRecoilHack = false;
bool DeleteNukeHack = false;
bool ESPHack = false;
bool Chams = false;
bool FullAutoHack = false;
bool DebugHacks = false;
bool DeleteFireHack = false;
bool FireRateHack = false;
bool Speedhack = false;
float SpeedhackValue = 1.0f;
bool ShotsPerBurstHack = false;
int ShotsPerBurstValue = 3;
int Ticks = 0;
void Nuker() {
	CG::UWorld** p_uworld = reinterpret_cast<CG::UWorld**>(CG::UWorld::GWorld);
	Nullcheck(p_uworld);
	Nullcheck(*p_uworld);
	CG::UGameInstance* OwningGameInstance = (*p_uworld)->OwningGameInstance;
	Nullcheck(OwningGameInstance);
	auto GameState = (*p_uworld)->GameState;
	Nullcheck(GameState);
	CG::UWorld* gworld = CG::UWorld::GWorld[0];
	Nullcheck(gworld);
	CG::ULocalPlayer* localplayer = gworld->OwningGameInstance->LocalPlayers[0];
	Nullcheck(localplayer);

	auto pArray = GameState->PlayerArray;
	if (Ticks > 10000) {
		Ticks = 0;
	}
	else {
		Ticks++;
		if (pArray.Count() > 1 && Ticks % 2 == 0) {
			for (USHORT i = 0; i < pArray.Count(); i++) {
				auto& ent = pArray[i];
				if (ent != localplayer->PlayerController->PlayerState) {
					auto Character = static_cast<CG::AHDPlayerCharacter*>(ent->PawnPrivate);
					Nullcheck(Character);
					auto Location = Character->ReplicatedMovement.Location;
					CG::AHDPlayerCharacter* SelfPlayer = static_cast<CG::AHDPlayerCharacter*>(localplayer->PlayerController->AcknowledgedPawn);
					Nullcheck(SelfPlayer);
					if (Character->TeamNum != SelfPlayer->TeamNum) {
						auto BaseWeapon = reinterpret_cast<CG::AHDBaseWeapon*>(SelfPlayer->EquippedItem);
						Nullcheck(BaseWeapon);
						
						BaseWeapon->ServerFireProjectile(Location, {});
					}
				}
			}
		}
	}
}

void HackLoop() {
	CG::UWorld** p_uworld = reinterpret_cast<CG::UWorld**>(CG::UWorld::GWorld);
	Nullcheck(p_uworld);
	Nullcheck(*p_uworld);
	CG::UGameInstance* OwningGameInstance = (*p_uworld)->OwningGameInstance;
	Nullcheck(OwningGameInstance);
	auto GameState = (*p_uworld)->GameState;
	Nullcheck(GameState);
	CG::UWorld* gworld = CG::UWorld::GWorld[0];
	Nullcheck(gworld);
	auto persistent_level = gworld->PersistentLevel;
	Nullcheck(persistent_level);
	CG::ULocalPlayer* localplayer = gworld->OwningGameInstance->LocalPlayers[0];
	Nullcheck(localplayer);
	CG::APlayerController* local_controller = OwningGameInstance->LocalPlayers[0]->PlayerController;
	Nullcheck(local_controller);
	CG::AHDPlayerCharacter* SelfPlayer = static_cast<CG::AHDPlayerCharacter*>(local_controller->AcknowledgedPawn);
	Nullcheck(SelfPlayer);
	auto Character = reinterpret_cast<CG::AHDPlayerCharacter*>(SelfPlayer);
	Nullcheck(Character);
	
	if (Speedhack) {
		if (localplayer != nullptr && OwningGameInstance != nullptr && local_controller != nullptr && SelfPlayer != nullptr) {
			if (local_controller != nullptr && Character != nullptr) {
				Character->CustomTimeDilation = SpeedhackValue;
			}
		}
	}

	// Weapon Shit
	if (InfiniteAmmoHack) {
		if (localplayer != nullptr && OwningGameInstance != nullptr && local_controller != nullptr && SelfPlayer != nullptr && SelfPlayer->EquippedItem != nullptr) {
			auto BaseWeapon = reinterpret_cast<CG::AHDBaseWeapon*>(SelfPlayer->EquippedItem);
			if (local_controller != nullptr && BaseWeapon != nullptr) {
				Nullcheck(BaseWeapon);
				BaseWeapon->bUsesAmmo = false;
			}
		}
	}
	else {
		if (localplayer != nullptr && OwningGameInstance != nullptr && local_controller != nullptr && SelfPlayer != nullptr && SelfPlayer->EquippedItem != nullptr) {
			auto BaseWeapon = reinterpret_cast<CG::AHDBaseWeapon*>(SelfPlayer->EquippedItem);
			if (local_controller != nullptr && BaseWeapon != nullptr) {
				Nullcheck(BaseWeapon);
				BaseWeapon->bUsesAmmo = true;
			}
		}
	}

	if (NoRecoilHack) {
		if (localplayer != nullptr && OwningGameInstance != nullptr && local_controller != nullptr && SelfPlayer != nullptr && SelfPlayer->EquippedItem != nullptr) {
			auto BaseWeapon = reinterpret_cast<CG::AHDBaseWeapon*>(SelfPlayer->EquippedItem);
			if (local_controller != nullptr && BaseWeapon != nullptr) {
				Nullcheck(BaseWeapon);
				BaseWeapon->bNoRecoil = true;
			}
		}
	}
	else {
		if (localplayer != nullptr && OwningGameInstance != nullptr && local_controller != nullptr && SelfPlayer != nullptr && SelfPlayer->EquippedItem != nullptr) {
			auto BaseWeapon = reinterpret_cast<CG::AHDBaseWeapon*>(SelfPlayer->EquippedItem);
			if (local_controller != nullptr && BaseWeapon != nullptr) {
				Nullcheck(BaseWeapon);
				BaseWeapon->bNoRecoil = false;
			}
		}
	}
	
	if (FireRateHack) {
		if (localplayer != nullptr && OwningGameInstance != nullptr && local_controller != nullptr && SelfPlayer != nullptr && SelfPlayer->EquippedItem != nullptr) {
			auto BaseWeapon = reinterpret_cast<CG::AHDBaseWeapon*>(SelfPlayer->EquippedItem);
			if (local_controller != nullptr && BaseWeapon != nullptr) {
				Nullcheck(BaseWeapon);
				BaseWeapon->FireRate = 0.0001f;
			}
		}
	}
	else {
		if (localplayer != nullptr && OwningGameInstance != nullptr && local_controller != nullptr && SelfPlayer != nullptr && SelfPlayer->EquippedItem != nullptr) {
			auto BaseWeapon = reinterpret_cast<CG::AHDBaseWeapon*>(SelfPlayer->EquippedItem);
			if (local_controller != nullptr && BaseWeapon != nullptr) {
				Nullcheck(BaseWeapon);
				BaseWeapon->FireRate = 0.1f;
				
			}
		}
	}
	if (ShotsPerBurstHack) {
		if (localplayer != nullptr && OwningGameInstance != nullptr && local_controller != nullptr && SelfPlayer != nullptr && SelfPlayer->EquippedItem != nullptr) {
			auto BaseWeapon = reinterpret_cast<CG::AHDBaseWeapon*>(SelfPlayer->EquippedItem);
			if (local_controller != nullptr && BaseWeapon != nullptr) {
				Nullcheck(BaseWeapon);
				BaseWeapon->ShotsPerBurst = ShotsPerBurstValue;
			}
		}
	}
	else {
		if (localplayer != nullptr && OwningGameInstance != nullptr && local_controller != nullptr && SelfPlayer != nullptr && SelfPlayer->EquippedItem != nullptr) {
			auto BaseWeapon = reinterpret_cast<CG::AHDBaseWeapon*>(SelfPlayer->EquippedItem);
			if (local_controller != nullptr && BaseWeapon != nullptr) {
				Nullcheck(BaseWeapon);
				BaseWeapon->ShotsPerBurst = 3;

			}
		}
	}

	if (FullAutoHack) {
		if (localplayer != nullptr && OwningGameInstance != nullptr && local_controller != nullptr && SelfPlayer != nullptr && SelfPlayer->EquippedItem != nullptr) {
			auto BaseWeapon = reinterpret_cast<CG::AHDBaseWeapon*>(SelfPlayer->EquippedItem);
			if (local_controller != nullptr && BaseWeapon != nullptr) {
				auto Mode = CG::EFireMode::Auto;
				if (BaseWeapon->SelectedFireMode != Mode) {
					//BaseWeapon->SetFireMode(Mode, false, true);
					BaseWeapon->SelectedFireMode = Mode;
				}
			}
		}
	}
		
	if (DeleteNukeHack and KP(VK_DOWN)) {
		Nuker();
	}
}




void InitImGui()
{
	CG::InitSdk();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);
	FILE* fs;
	freopen_s(&fs, "CONIN$", "w+", stdin);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (KP(VK_INSERT)) {
		showWindow = !showWindow;
		Sleep(10);
	}
	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool init = false;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)& pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)& pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
			printf("Injected into game!\nJoin the discord for updates/more releases! | https://discord.gg/8T28TdwR5d\n");
			ShellExecute(0, 0, "https://discord.gg/8T28TdwR5d", 0, 0, SW_SHOW);
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}
	HackLoop();
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	const ImGuiWindowFlags windowFlags{ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar  | ImGuiWindowFlags_AlwaysAutoResize};
	ImGuiIO& io = ImGui::GetIO();

	if (showWindow) {
		ImGui::SetNextWindowSize(ImVec2(380, 278));
		ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
		ImGui::Begin("Operation: Harsh Doorstop - ArilisDev", nullptr, windowFlags);
		ImGui::Text("Weapon Cheeze");
		ImGui::Separator();
		ImGui::Checkbox("Full Auto", &FullAutoHack);
		ImGui::Checkbox("Infinite Ammo", &InfiniteAmmoHack);
		ImGui::Checkbox("No Recoil", &NoRecoilHack);
		ImGui::Checkbox("Fire Rate", &FireRateHack);
		ImGui::Checkbox("Enable Shots Per Burst", &ShotsPerBurstHack);
		ImGui::SliderInt("Shots Per Burst", &ShotsPerBurstValue, 3, 250, "%1.0f");
		ImGui::Separator();
		ImGui::Text("Misc");
		ImGui::Separator();
		ImGui::Checkbox("Nuker - Hold DOWN - DO NOT HOLD", &DeleteNukeHack);
		ImGui::Checkbox("Enable Speed", &Speedhack);
		ImGui::SliderFloat("Speed Factor", &SpeedhackValue, 1.0f, 5.0f, "%1.0f");
		ImGui::Text("Press INSERT to open/close the menu.");
		ImGui::End();
	}

	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)& oPresent, hkPresent);
			init_hook = true;
			
		}
	} while (!init_hook);
	return TRUE;
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}