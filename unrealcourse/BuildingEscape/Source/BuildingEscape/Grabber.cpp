// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty!\n"));


	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get player view point this tick
	FVector v;
	FRotator r;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(v, r);
	//UE_LOG(LogTemp, Warning, TEXT("Player point of view %s %s\n"), *v.ToString(), *r.ToString());

	FVector lineTraceEnd = v + r.Vector() * Reach;

	DrawDebugLine(
		GetWorld(),
		v,
		lineTraceEnd,
		FColor(0, 255, 0),
		false,
		0.f,
		0.f,
		10.f
		);

	// Ray-cast out to reach distance

	// See what we hit
}

