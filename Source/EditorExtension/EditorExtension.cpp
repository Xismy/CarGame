#include "EditorExtension.h"

IMPLEMENT_GAME_MODULE(FMyGameEditorModule, MyGameEditor);

DEFINE_LOG_CATEGORY(MyGameEditor)

#define LOCTEXT_NAMESPACE "Editor"

void FMyGameEditorModule::StartupModule()
{
	UE_LOG(MyGameEditor, Warning, TEXT("Editor: Log Started"));
}

void FMyGameEditorModule::ShutdownModule()
{
	UE_LOG(MyGameEditor, Warning, TEXT("Editor: Log Ended"));
}

#undef LOCTEXT_NAMESPACE