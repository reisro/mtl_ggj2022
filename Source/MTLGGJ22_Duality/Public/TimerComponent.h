// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TimerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTimerStarts);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTimerEnds);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MTLGGJ22_DUALITY_API UTimerComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Timer")
	float gameDuration = 5.0f;
	
	UPROPERTY(BlueprintAssignable, Category="Timer")
	FOnTimerStarts OnGameTimerStarts;

	UPROPERTY(BlueprintAssignable, Category="Timer")
	FOnTimerEnds OnGameTimerEnds;

	FTimerDelegate GameTimeFinishDel;
	
	FTimerHandle GameTimeFinishHandler;
	
	UTimerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void StartTimer(float duration);

	UFUNCTION(BlueprintCallable)
	void FinishTimer();
};
