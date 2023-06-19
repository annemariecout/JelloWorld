// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightSwitch.generated.h"

UCLASS()
class GDP2_API ALightSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALightSwitch();

	// Add a point light component
	UPROPERTY(VisibleAnywhere, Category= "SwitchComponent")
	class UPointLightComponent* PointLight1;

	// Add a sphere collider for overlaps
	UPROPERTY(VisibleAnywhere, Category= "SwitchLightComponent")
	class USphereComponent* Sphere1;

	// On overlap function
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// End overlap function
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// Toggle light function
	UFUNCTION()
	void ToggleLight();

	// Define intensity
	UPROPERTY(VisibleAnywhere, Category= "SwitchVariables")
	float DesiredIntensity;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
