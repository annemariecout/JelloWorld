// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightSwitchBP.generated.h"

UCLASS()
class GDP2_API ALightSwitchBP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALightSwitchBP();

	// Create point light component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "SwitchComponents")
	class UPointLightComponent* PointLight1;

	// Create sphere component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "SwitchComponents")
	class USphereComponent* Sphere1;

	/* Called when something enters sphere component */
	UFUNCTION(BlueprintNativeEvent, Category= "SwitchFunctions")
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void OnOverlapBegin_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/* Called when something leaves sphere component */
	UFUNCTION(BlueprintNativeEvent, Category= "SwitchFunctions")
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void OnOverlapEnd_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// Toggles light visibility
	UFUNCTION()
	void ToggleLight();

	// Sets desired intensity for light component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "SwitchVariables")
	float DesiredIntensity;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
