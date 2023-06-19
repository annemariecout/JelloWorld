// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileJelly.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProjectileJelly::AProjectileJelly()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize the projectile mesh
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	RootComponent = ProjectileMesh;

	// Initialize the projectile movement component
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->InitialSpeed = 3000.0f;
	ProjectileMovementComponent->MaxSpeed = 3000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;

	Damage = 5;

}

// Called when the game starts or when spawned
void AProjectileJelly::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectileJelly::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectileJelly::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	if(Other!=nullptr)
	{
		UGameplayStatics::ApplyPointDamage(Other, Damage, GetActorLocation() - Other->GetActorLocation(), Hit, nullptr, this, nullptr);
	}
}
