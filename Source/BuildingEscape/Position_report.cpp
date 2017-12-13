// Fill out your copyright notice in the Description page of Project Settings.

#include "Position_report.h"
#include "Gameframework/Actor.h"


// Sets default values for this component's properties
UPosition_report::UPosition_report()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
}


// Called when the game starts
void UPosition_report::BeginPlay()
{
	Super::BeginPlay();

	// ...
	FString ObjectName = GetOwner()->GetName();
	FString ObjectPos = "X = " + GetOwner()->GetTransform().GetLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("Hellow %s is %s"), *ObjectName, *ObjectPos);
}


// Called every frame
void UPosition_report::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

