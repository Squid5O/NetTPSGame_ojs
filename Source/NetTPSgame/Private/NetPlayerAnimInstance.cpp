// Fill out your copyright notice in the Description page of Project Settings.


#include "NetPlayerAnimInstance.h"
#include "NetTPSgameCharacter.h"
#include "GameFramework/PawnMovementComponent.h"

void UNetPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	//player 를 기억하고 싶다.  //player = TryGetPawnOwner()
	player = Cast<ANetTPSgameCharacter>(GetOwningActor());
}

void UNetPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	//speed, direction 값을 채우고 싶다

	if (nullptr == player)  //언리얼 에디터 호출을 방지
		return;

	const FVector velocity = player->GetVelocity();  // get velocity에 함수가 있음 cnonst


	//Speed = player->GetMovementComponent()->Velocity, player->GetActorForwardVector() 실패
	Speed = FVector::DotProduct(velocity, player->GetActorForwardVector());
	//Speed = FVector::DotProduct(player->GetVelocity(), player->GetActorForwardVector());

	Direction = FVector::DotProduct(velocity, player->GetActorRightVector());
	//Direction = FVector::DotProduct(player->GetVelocity(), player->GetActorRightVector());


	bHasPistol = player->bHasPistol;

}
