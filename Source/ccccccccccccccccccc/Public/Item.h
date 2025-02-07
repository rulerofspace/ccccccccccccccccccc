#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"


UCLASS()
class CCCCCCCCCCCCCCCCCCC_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();

protected:
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};

// ������ - �޸𸮿� ����. �� �ѹ� ȣ��.
// PostInitializeComponents() - ������Ʈ�� �ϼ��� ���� ȣ��. ������Ʈ���� ������ �ְ�ޱ�, ��ȣ�ۿ�
// BeginPlay() - ��ġ (Spawn) ����
// Tick(float DeltaTime) - �� �����Ӹ��� ȣ���.
// Destoyed() - ���� �Ǳ� ������ ȣ��ȴ�.
// EndPlay() - ���� ����, �ı� (Destroyed()), ���� ��ȯ
