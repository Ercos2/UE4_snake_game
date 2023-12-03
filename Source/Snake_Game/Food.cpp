// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include "snake_base.h"
#include "Bonus.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFood::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead) {
		auto Snake = Cast<Asnake_base>(Interactor);
		if (IsValid(Snake)) {
			Snake->AddSnakeElement();
			
			FVector NewLocation;
			srand(time(0));

			int32 spawn_start = -400;
			int32 spawn_end = 400;
			NewLocation.X = rand() % (spawn_end - spawn_start + 1) + spawn_start;
			NewLocation.Y = rand() % (spawn_end - spawn_start + 1) + spawn_start;
			
			this->SetActorLocation(NewLocation);
			
		}
	}
}

