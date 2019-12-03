// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MCharacter.generated.h"



UCLASS()
class AMCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float val);
	void  MoveRight(float val);
	void Crouching();
	void UnCrouching();
	
	void WeaponEquip();
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);



	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Structure)
		class USpringArmComponent* CameraBoom;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Structure)
		class UCameraComponent* Camera;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Movement)
		float SpeedMultiplier;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Movement)
		bool Test;

	bool bOverlapedWithWeapon; //Checks if Overlaping happed with an weapon or not
	
	class AMweapon* Weapon;
	class AMweapon* CurrentWeapon;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Weapon)
		bool bEquippedRifle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Weapon)
		bool bEquippedGun;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Weapon)
		bool bFullSlot;

};