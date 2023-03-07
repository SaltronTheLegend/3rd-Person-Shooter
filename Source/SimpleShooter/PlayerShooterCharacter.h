

#pragma once

#include "CoreMinimal.h"
#include "ShooterCharacter.h"
#include "PlayerShooterCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API APlayerShooterCharacter : public AShooterCharacter
{
	GENERATED_BODY()
	
public:
    // Constructor
    APlayerShooterCharacter();
	
    // Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    void TogglePerspective();
	void Aim();

	UPROPERTY()
	bool Perspective;
};
