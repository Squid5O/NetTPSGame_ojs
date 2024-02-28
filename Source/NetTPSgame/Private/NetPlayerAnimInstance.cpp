// Fill out your copyright notice in the Description page of Project Settings.


#include "NetPlayerAnimInstance.h"
#include "NetTPSgameCharacter.h"
#include "GameFramework/PawnMovementComponent.h"

void UNetPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	//player �� ����ϰ� �ʹ�.  //player = TryGetPawnOwner()
	player = Cast<ANetTPSgameCharacter>(GetOwningActor());
}

void UNetPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	//speed, direction ���� ä��� �ʹ�

	if (nullptr == player)  //�𸮾� ������ ȣ���� ����
		return;

	const FVector velocity = player->GetVelocity();  // get velocity�� �Լ��� ���� cnonst


	//Speed = player->GetMovementComponent()->Velocity, player->GetActorForwardVector() ����
	Speed = FVector::DotProduct(velocity, player->GetActorForwardVector());
	//Speed = FVector::DotProduct(player->GetVelocity(), player->GetActorForwardVector());

	Direction = FVector::DotProduct(velocity, player->GetActorRightVector());
	//Direction = FVector::DotProduct(player->GetVelocity(), player->GetActorRightVector());


	bHasPistol = player->bHasPistol;

}
