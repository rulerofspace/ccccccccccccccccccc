#include "FirstGameMode.h"
#include "FirstCharacter.h"
#include "MyPlayerController.h"

AFirstGameMode::AFirstGameMode()
{
	DefaultPawnClass = AFirstCharacter::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
}
