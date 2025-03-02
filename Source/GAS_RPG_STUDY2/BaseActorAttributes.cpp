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

void UBaseActorAttributes::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UBaseActorAttributes, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseActorAttributes, Stamina, COND_None, REPNOTIFY_Always);
}
