// Fill out your copyright notice in the Description page of Project Settings.


#include "PanCharacter.h"
#include "BaseActorAttributes.h"

// Sets default values
APanCharacter::APanCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbiliitySystemComponent"));
}

// Called when the game starts or when spawned
void APanCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(AbilitySystemComponent))
	{
		BaseActorAttributes = AbilitySystemComponent->GetSet<UBaseActorAttributes>();
	}
	
}

// Called every frame
void APanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

