// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseActorAttributes.h"
#include "Net/UnrealNetwork.h"

void UBaseActorAttributes::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseActorAttributes, Health, OldHealth);
}

void UBaseActorAttributes::OnRep_Stamina(const FGameplayAttributeData& OldStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseActorAttributes, Stamina, OldStamina);
}

void UBaseActorAttributes::OnRep_Defence(const FGameplayAttributeData& OldDefence)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseActorAttributes, Defence, OldDefence);
}

void UBaseActorAttributes::OnRep_XPPoints(const FGameplayAttributeData& OldXPPoints)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseActorAttributes, XPPoints, OldXPPoints);
}

void UBaseActorAttributes::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UBaseActorAttributes, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseActorAttributes, Stamina, COND_None, REPNOTIFY_Always);
}

void UBaseActorAttributes::PreAttributeChange(const FGameplayAttribute& Attribute, float& Delta)
{
	Super::PreAttributeChange(Attribute, Delta);

	if (Attribute == GetHealthAttribute())
	{
		float Def = FMath::Clamp(Defence.GetCurrentValue(), 0.f, 100.f);
		Delta = Delta * (200 - Def) / 200;
		UE_LOG(LogTemp, Warning, TEXT("Defence : %f"), Def);
	}
}