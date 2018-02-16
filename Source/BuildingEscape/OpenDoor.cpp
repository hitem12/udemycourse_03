// TPP 2017

#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	AActor* Owner = GetOwner();

}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
		LastDoorOPenTome = GetWorld()->GetTimeSeconds();
		
	}
	else
	{
		if ((GetWorld()->GetTimeSeconds()-LastDoorOPenTome) > 1.0f)
		{
		//	CloseDoor();
		//	LastDoorOPenTome = 0;
		}
	}
}

void UOpenDoor::OpenDoor()
{
	FRotator NewRotator = FRotator(0.0f, 90.0f, 0.0f);
	Owner->SetActorRotation(NewRotator);
}

void UOpenDoor::CloseDoor()
{
	FRotator NewRotator = FRotator(0.0f, 0.0f, 0.0f);
	Owner->SetActorRotation(NewRotator);
}