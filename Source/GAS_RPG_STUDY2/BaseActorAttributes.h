// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BaseActorAttributes.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class GAS_RPG_STUDY2_API UBaseActorAttributes : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	// Health
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Actor Attributes", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UBaseActorAttributes, Health)

	// Stamina 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Actor Attributes", ReplicatedUsing = OnRep_Stamina)
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UBaseActorAttributes, Stamina)

	// Defence 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Actor Attributes", ReplicatedUsing = OnRep_Defence)
	FGameplayAttributeData Defence;
	ATTRIBUTE_ACCESSORS(UBaseActorAttributes, Defence)

	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UFUNCTION()
	virtual void OnRep_Stamina(const FGameplayAttributeData& OldStamina);
					
	UFUNCTION()
	virtual void OnRep_Defence(const FGameplayAttributeData& OldDefence);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	// Called before an attribute is changed.
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& Delta) override;
};
