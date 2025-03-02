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

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BaseActorAttributes->GetHealthAttribute()).AddUObject(this, &APanCharacter::HealthChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BaseActorAttributes->GetStaminaAttribute()).AddUObject(this, &APanCharacter::StaminaChanged);
	}
	
}

void APanCharacter::HealthChanged(const FOnAttributeChangeData& Data)
{
	float Health = Data.NewValue;
	UpdateHealth(Health);
}

void APanCharacter::StaminaChanged(const FOnAttributeChangeData& Data)
{
	float Stamina = Data.NewValue;
	UpdateStamina(Stamina);
}

void APanCharacter::UpdateHealth_Implementation(const float NewHealth)
{
}

void APanCharacter::UpdateStamina_Implementation(const float NewStamina)
{
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