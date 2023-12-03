// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_pawn_base.h"
#include "Engine/Classes/Camera/CameraComponent.h"
#include "snake_base.h"
#include "Components/InputComponent.h"

// Sets default values
APlayer_pawn_base::APlayer_pawn_base()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pawn_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("pawn_camera"));
	RootComponent = pawn_camera;
}

// Called when the game starts or when spawned
void APlayer_pawn_base::BeginPlay()
{
	Super::BeginPlay();
	SetActorRotation(FRotator(-90, 0, 0));
	create_snake_actor();
}

// Called every frame
void APlayer_pawn_base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayer_pawn_base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Vertical", this, &APlayer_pawn_base::HandlePlayerVerticalInput);
	PlayerInputComponent->BindAxis("Horizontal", this, &APlayer_pawn_base::HandlePlayerHorizontalInput);
}

void APlayer_pawn_base::create_snake_actor()
{
	snake_actor = GetWorld()->SpawnActor<Asnake_base>(snake_actor_class, FTransform());
}

void APlayer_pawn_base::HandlePlayerVerticalInput(float value)
{
	if (IsValid(snake_actor)) {
		if (value > 0 && snake_actor->LastMoveDirection != EMovementDirection::DOWN) {
			snake_actor->LastMoveDirection = EMovementDirection::UP;
		}
		else if (value < 0 && snake_actor->LastMoveDirection != EMovementDirection::UP) {
			snake_actor->LastMoveDirection = EMovementDirection::DOWN;
		}
	}
}

void APlayer_pawn_base::HandlePlayerHorizontalInput(float value)
{
	if (IsValid(snake_actor)) {
		if (value > 0 && snake_actor->LastMoveDirection != EMovementDirection::LEFT) {
			snake_actor->LastMoveDirection = EMovementDirection::RIGHT;
		}
		else if (value < 0 && snake_actor->LastMoveDirection != EMovementDirection::RIGHT) {
			snake_actor->LastMoveDirection = EMovementDirection::LEFT;
		}
	}
}

