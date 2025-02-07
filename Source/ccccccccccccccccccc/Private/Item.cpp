#include "Item.h"



AItem::AItem()
{
	SceneRoot = CreateOptionalDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateEditorOnlyDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Potion_A.SM_Potion_A"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Heart.M_Heart"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
		RotationSpeed = 90.f;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(300.0f, 200.0f, 100.0f));
	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	SetActorScale3D(FVector(2.0f));
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0F, RotationSpeed, 0.0f));
	}

}

// ������ - �޸𸮿� ����. �� �ѹ� ȣ��.
// PostInitializeComponents() - ������Ʈ�� �ϼ��� ���� ȣ��. ������Ʈ���� ������ �ְ�ޱ�, ��ȣ�ۿ�
// BeginPlay() - ��ġ (Spawn) ����
// Tick(float DeltaTime) - �� �����Ӹ��� ȣ���.
// Destoyed() - ���� �Ǳ� ������ ȣ��ȴ�.
// EndPlay() - ���� ����, �ı� (Destroyed()), ���� ��ȯ
