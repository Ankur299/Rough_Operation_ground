// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mweapon.generated.h"

UCLASS()
class AMweapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMweapon();


	UPROPERTY(EditAnywhere,  Category = Structure)
		class UStaticMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Structure)
		class UBoxComponent*  BoxComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	




public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = Action)
		bool bPicked;
	UPROPERTY(EditAnywhere, Category = Type)
		int32 Type;
	bool bOverlapAllowed;

};
