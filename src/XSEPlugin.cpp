#include "Papyrus.h"
#include "hitStop.h"
#include "onHitEventHandler.h"

void MessageHandler(SKSE::MessagingInterface::Message* a_msg)
{
	switch (a_msg->type) {
	case SKSE::MessagingInterface::kDataLoaded:
		onHitEventHandler::Register();
		dataHandler::readSettings();
		AnimSpeedManager::init();
		break;
	case SKSE::MessagingInterface::kPostLoad:
		break;
	case SKSE::MessagingInterface::kPostLoadGame:
		break;
	}
}

void onSKSEInit()
{
	Papyrus::Register();
	SKSE::AllocTrampoline(1 << 5);
	MainUpdateHook::InstallHook();
}

void Load()
{	
	SKSE::GetMessagingInterface()->RegisterListener("SKSE", MessageHandler);
	onSKSEInit();
}
