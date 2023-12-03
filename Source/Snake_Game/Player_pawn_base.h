// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Player_pawn_base.generated.h"

class UCameraComponent;
class Asnake_base;

UCLASS()
class SNAKE_GAME_API APlayer_pawn_base : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayer_pawn_base();

	UPROPERTY(BlueprintReadWrite)
		UCameraComponent* pawn_camera;

	UPROPERTY(BlueprintReadWrite)
		Asnake_base* snake_actor;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<Asnake_base> snake_actor_class;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void create_snake_actor();

	UFUNCTION()
		void HandlePlayerVerticalInput(float value);
	UFUNCTION()
		void HandlePlayerHorizontalInput(float value);

};
