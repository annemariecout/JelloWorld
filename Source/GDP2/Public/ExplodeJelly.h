// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Sound/SoundCue.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "ExplodeJelly.generated.h"

UCLASS(Blueprintable)
class GDP2_API AExplodeJelly : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExplodeJelly();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Components")
	UStaticMeshComponent* JellyMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Exploding Jelly")
	float HitPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Exploding Jelly")
	float ExplosionDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Exploding Jelly")
	float ExplosionRadius;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Exploding Jelly")
	USoundCue* ExplosionSound;
	
	UPROPERTY(EditAnywhere, Category= "Effects")
	UParticleSystem* ExplosionParticle; 

	UPROPERTY(VisibleAnywhere, Category= "Effects")
	UParticleSystemComponent* FireParticleSystemComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Exploding Jelly")
	UParticleSystem* FireParticle; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Effects")
	URadialForceComponent* RadialForce;


	UFUNCTION()
	void OnDamageTaken(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	FTimerHandle CountdownTimerHandle;
	void Countdown();
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
