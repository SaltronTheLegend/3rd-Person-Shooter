// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

// Called when the game starts or when spawned
void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();

    HUD = CreateWidget(this, HUDClass);
    if (HUD != nullptr)
    {
        HUD->AddToViewport();
    }
	
}

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner )
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    HUD->RemoveFromViewport(); 
    UE_LOG(LogTemp, Warning, TEXT("Game Has Ended."));

    if (bIsWinner)
    {
        UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);

        if (WinScreen != nullptr)
        {
            WinScreen->AddToViewport();
        }
    }
    else
    {
        UUserWidget* LooseScreen = CreateWidget(this, LooseScreenClass);

        if (LooseScreen != nullptr)
        {
            LooseScreen->AddToViewport();
        }
    }

    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}