﻿#pragma once

/**
 * Name: Operation__Harsh_Doorstop
 * Version: 1
 */

#ifdef _MSC_VER
	#pragma pack(push, 0x01)
#endif

namespace CG
{
	// --------------------------------------------------
	// # Enums
	// --------------------------------------------------
	/**
	 * Enum MovieSceneTracks.MovieScene3DPathSection_Axis
	 */
	enum class EMovieScene3DPathSection_Axis : uint8_t
	{
		MovieScene3DPathSection_AxisX                           = 0,
		MovieScene3DPathSection_AxisY                           = 1,
		MovieScene3DPathSection_AxisZ                           = 2,
		MovieScene3DPathSection_AxisNEG_X                       = 3,
		MovieScene3DPathSection_AxisNEG_Y                       = 4,
		MovieScene3DPathSection_AxisNEG_Z                       = 5,
		MovieScene3DPathSection_AxisMovieScene3DPathSection_MAX = 6
	};

	/**
	 * Enum MovieSceneTracks.EFireEventsAtPosition
	 */
	enum class EFireEventsAtPosition : uint8_t
	{
		AtStartOfEvaluation = 0,
		AtEndOfEvaluation   = 1,
		AfterSpawn          = 2,
		MAX                 = 3
	};

	/**
	 * Enum MovieSceneTracks.ELevelVisibility
	 */
	enum class ELevelVisibility : uint8_t
	{
		Visible = 0,
		Hidden  = 1,
		MAX     = 2
	};

	/**
	 * Enum MovieSceneTracks.EParticleKey
	 */
	enum class EParticleKey : uint8_t
	{
		Activate   = 0,
		Deactivate = 1,
		Trigger    = 2,
		MAX        = 3
	};

	// --------------------------------------------------
	// # Structs
	// --------------------------------------------------
	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneTransformMask
	 * Size -> 0x0004
	 */
	struct FMovieSceneTransformMask
	{
	public:
		uint32_t                                                   Mask;                                                    // 0x0000(0x0004) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneActorReferenceKey
	 * Size -> 0x0028
	 */
	struct FMovieSceneActorReferenceKey
	{
	public:
		struct FMovieSceneObjectBindingID                          Object;                                                  // 0x0000(0x0018) Edit, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		class FName                                                ComponentName;                                           // 0x0018(0x0008) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		class FName                                                SocketName;                                              // 0x0020(0x0008) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneActorReferenceData
	 * Size -> 0x00A8 (FullSize[0x00B0] - InheritedSize[0x0008])
	 */
	struct FMovieSceneActorReferenceData : public FMovieSceneChannel
	{
	public:
		TArray<struct FFrameNumber>                                KeyTimes;                                                // 0x0008(0x0010) ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
		unsigned char                                              UnknownData_6RUA[0x28];                                  // 0x0018(0x0028) MISSED OFFSET (FIX SPACE BETWEEN PREVIOUS PROPERTY)
		TArray<struct FMovieSceneActorReferenceKey>                KeyValues;                                               // 0x0040(0x0010) ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
		unsigned char                                              UnknownData_U7FY[0x60];                                  // 0x0050(0x0060) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneCameraAnimSectionData
	 * Size -> 0x0020
	 */
	struct FMovieSceneCameraAnimSectionData
	{
	public:
		class UCameraAnim*                                         CameraAnim;                                              // 0x0000(0x0008) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		float                                                      PlayRate;                                                // 0x0008(0x0004) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		float                                                      PlayScale;                                               // 0x000C(0x0004) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		float                                                      BlendInTime;                                             // 0x0010(0x0004) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		float                                                      BlendOutTime;                                            // 0x0014(0x0004) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		bool                                                       bLooping;                                                // 0x0018(0x0001) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_B8EF[0x7];                                   // 0x0019(0x0007) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneCameraShakeSectionData
	 * Size -> 0x0020
	 */
	struct FMovieSceneCameraShakeSectionData
	{
	public:
		class UClass*                                              ShakeClass;                                              // 0x0000(0x0008) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic
		float                                                      PlayScale;                                               // 0x0008(0x0004) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		ECameraAnimPlaySpace                                       PlaySpace;                                               // 0x000C(0x0001) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_RWKW[0x3];                                   // 0x000D(0x0003) MISSED OFFSET (FIX SPACE BETWEEN PREVIOUS PROPERTY)
		struct FRotator                                            UserDefinedPlaySpace;                                    // 0x0010(0x000C) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_17VT[0x4];                                   // 0x001C(0x0004) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneEventPtrs
	 * Size -> 0x0028
	 */
	struct FMovieSceneEventPtrs
	{
	public:
		class UFunction*                                           Function;                                                // 0x0000(0x0008) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              BoundObjectProperty[0x20];                               // 0x0008(0x0020) UNKNOWN PROPERTY: FieldPathProperty
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneEvent
	 * Size -> 0x0028
	 */
	struct FMovieSceneEvent
	{
	public:
		struct FMovieSceneEventPtrs                                Ptrs;                                                    // 0x0000(0x0028) NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneEventParameters
	 * Size -> 0x0028
	 */
	struct FMovieSceneEventParameters
	{
	public:
		unsigned char                                              UnknownData_0X39[0x28];                                  // 0x0000(0x0028) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.EventPayload
	 * Size -> 0x0030
	 */
	struct FEventPayload
	{
	public:
		class FName                                                EventName;                                               // 0x0000(0x0008) Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		struct FMovieSceneEventParameters                          Parameters;                                              // 0x0008(0x0028) Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneEventSectionData
	 * Size -> 0x0080 (FullSize[0x0088] - InheritedSize[0x0008])
	 */
	struct FMovieSceneEventSectionData : public FMovieSceneChannel
	{
	public:
		TArray<struct FFrameNumber>                                Times;                                                   // 0x0008(0x0010) ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
		TArray<struct FEventPayload>                               KeyValues;                                               // 0x0018(0x0010) ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
		unsigned char                                              UnknownData_TJQQ[0x60];                                  // 0x0028(0x0060) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneEventChannel
	 * Size -> 0x0080 (FullSize[0x0088] - InheritedSize[0x0008])
	 */
	struct FMovieSceneEventChannel : public FMovieSceneChannel
	{
	public:
		TArray<struct FFrameNumber>                                KeyTimes;                                                // 0x0008(0x0010) ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
		TArray<struct FMovieSceneEvent>                            KeyValues;                                               // 0x0018(0x0010) ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
		unsigned char                                              UnknownData_53M2[0x60];                                  // 0x0028(0x0060) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.BoolParameterNameAndCurve
	 * Size -> 0x0098
	 */
	struct FBoolParameterNameAndCurve
	{
	public:
		class FName                                                ParameterName;                                           // 0x0000(0x0008) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		struct FMovieSceneBoolChannel                              ParameterCurve;                                          // 0x0008(0x0090) NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.ScalarParameterNameAndCurve
	 * Size -> 0x00A8
	 */
	struct FScalarParameterNameAndCurve
	{
	public:
		class FName                                                ParameterName;                                           // 0x0000(0x0008) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		struct FMovieSceneFloatChannel                             ParameterCurve;                                          // 0x0008(0x00A0) NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.Vector2DParameterNameAndCurves
	 * Size -> 0x0148
	 */
	struct FVector2DParameterNameAndCurves
	{
	public:
		class FName                                                ParameterName;                                           // 0x0000(0x0008) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		struct FMovieSceneFloatChannel                             XCurve;                                                  // 0x0008(0x00A0) NativeAccessSpecifierPublic
		struct FMovieSceneFloatChannel                             YCurve;                                                  // 0x00A8(0x00A0) NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.VectorParameterNameAndCurves
	 * Size -> 0x01E8
	 */
	struct FVectorParameterNameAndCurves
	{
	public:
		class FName                                                ParameterName;                                           // 0x0000(0x0008) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		struct FMovieSceneFloatChannel                             XCurve;                                                  // 0x0008(0x00A0) NativeAccessSpecifierPublic
		struct FMovieSceneFloatChannel                             YCurve;                                                  // 0x00A8(0x00A0) NativeAccessSpecifierPublic
		struct FMovieSceneFloatChannel                             ZCurve;                                                  // 0x0148(0x00A0) NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.ColorParameterNameAndCurves
	 * Size -> 0x0288
	 */
	struct FColorParameterNameAndCurves
	{
	public:
		class FName                                                ParameterName;                                           // 0x0000(0x0008) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		struct FMovieSceneFloatChannel                             RedCurve;                                                // 0x0008(0x00A0) NativeAccessSpecifierPublic
		struct FMovieSceneFloatChannel                             GreenCurve;                                              // 0x00A8(0x00A0) NativeAccessSpecifierPublic
		struct FMovieSceneFloatChannel                             BlueCurve;                                               // 0x0148(0x00A0) NativeAccessSpecifierPublic
		struct FMovieSceneFloatChannel                             AlphaCurve;                                              // 0x01E8(0x00A0) NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.TransformParameterNameAndCurves
	 * Size -> 0x05A8
	 */
	struct FTransformParameterNameAndCurves
	{
	public:
		class FName                                                ParameterName;                                           // 0x0000(0x0008) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		struct FMovieSceneFloatChannel                             Translation[0x3];                                        // 0x0008(0x01E0) NativeAccessSpecifierPublic
		struct FMovieSceneFloatChannel                             Rotation[0x3];                                           // 0x01E8(0x01E0) NativeAccessSpecifierPublic
		struct FMovieSceneFloatChannel                             Scale[0x3];                                              // 0x03C8(0x01E0) NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneParticleChannel
	 * Size -> 0x0000 (FullSize[0x0098] - InheritedSize[0x0098])
	 */
	struct FMovieSceneParticleChannel : public FMovieSceneByteChannel
	{	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneSkeletalAnimationParams
	 * Size -> 0x00D8
	 */
	struct FMovieSceneSkeletalAnimationParams
	{
	public:
		class UAnimSequenceBase*                                   Animation;                                               // 0x0000(0x0008) Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		struct FFrameNumber                                        FirstLoopStartFrameOffset;                               // 0x0008(0x0004) Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		struct FFrameNumber                                        StartFrameOffset;                                        // 0x000C(0x0004) Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		struct FFrameNumber                                        EndFrameOffset;                                          // 0x0010(0x0004) Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		float                                                      PlayRate;                                                // 0x0014(0x0004) Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		bool                                                       bReverse : 1;                                            // 0x0018(0x0001) BIT_FIELD Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_3NJE[0x3];                                   // 0x0019(0x0003) MISSED OFFSET (FIX SPACE BETWEEN PREVIOUS PROPERTY)
		class FName                                                SlotName;                                                // 0x001C(0x0008) Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_R8SJ[0x4];                                   // 0x0024(0x0004) MISSED OFFSET (FIX SPACE BETWEEN PREVIOUS PROPERTY)
		struct FMovieSceneFloatChannel                             Weight;                                                  // 0x0028(0x00A0) NativeAccessSpecifierPublic
		bool                                                       bSkipAnimNotifiers;                                      // 0x00C8(0x0001) Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		bool                                                       bForceCustomMode;                                        // 0x00C9(0x0001) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_9P2M[0x2];                                   // 0x00CA(0x0002) MISSED OFFSET (FIX SPACE BETWEEN PREVIOUS PROPERTY)
		float                                                      StartOffset;                                             // 0x00CC(0x0004) ZeroConstructor, Deprecated, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		float                                                      EndOffset;                                               // 0x00D0(0x0004) ZeroConstructor, Deprecated, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_BP4F[0x4];                                   // 0x00D4(0x0004) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneStringChannel
	 * Size -> 0x0098 (FullSize[0x00A0] - InheritedSize[0x0008])
	 */
	struct FMovieSceneStringChannel : public FMovieSceneChannel
	{
	public:
		TArray<struct FFrameNumber>                                Times;                                                   // 0x0008(0x0010) ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
		TArray<class FString>                                      Values;                                                  // 0x0018(0x0010) ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
		class FString                                              DefaultValue;                                            // 0x0028(0x0010) ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
		bool                                                       bHasDefaultValue;                                        // 0x0038(0x0001) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
		unsigned char                                              UnknownData_PZUM[0x67];                                  // 0x0039(0x0067) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieScene3DAttachSectionTemplate
	 * Size -> 0x0030 (FullSize[0x0050] - InheritedSize[0x0020])
	 */
	struct FMovieScene3DAttachSectionTemplate : public FMovieSceneEvalTemplate
	{
	public:
		struct FMovieSceneObjectBindingID                          AttachBindingID;                                         // 0x0020(0x0018) NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		class FName                                                AttachSocketName;                                        // 0x0038(0x0008) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		class FName                                                AttachComponentName;                                     // 0x0040(0x0008) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		EAttachmentRule                                            AttachmentLocationRule;                                  // 0x0048(0x0001) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		EAttachmentRule                                            AttachmentRotationRule;                                  // 0x0049(0x0001) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		EAttachmentRule                                            AttachmentScaleRule;                                     // 0x004A(0x0001) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		EDetachmentRule                                            DetachmentLocationRule;                                  // 0x004B(0x0001) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		EDetachmentRule                                            DetachmentRotationRule;                                  // 0x004C(0x0001) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		EDetachmentRule                                            DetachmentScaleRule;                                     // 0x004D(0x0001) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_95CQ[0x2];                                   // 0x004E(0x0002) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieScene3DPathSectionTemplate
	 * Size -> 0x00C0 (FullSize[0x00E0] - InheritedSize[0x0020])
	 */
	struct FMovieScene3DPathSectionTemplate : public FMovieSceneEvalTemplate
	{
	public:
		struct FMovieSceneObjectBindingID                          PathBindingID;                                           // 0x0020(0x0018) NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		struct FMovieSceneFloatChannel                             TimingCurve;                                             // 0x0038(0x00A0) NativeAccessSpecifierPublic
		EMovieScene3DPathSection_Axis                              FrontAxisEnum;                                           // 0x00D8(0x0001) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		EMovieScene3DPathSection_Axis                              UpAxisEnum;                                              // 0x00D9(0x0001) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_A3WE[0x2];                                   // 0x00DA(0x0002) MISSED OFFSET (FIX SPACE BETWEEN PREVIOUS PROPERTY)
		bool                                                       bFollow : 1;                                             // 0x00DC(0x0001) BIT_FIELD NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		bool                                                       bReverse : 1;                                            // 0x00DC(0x0001) BIT_FIELD NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		bool                                                       bForceUpright : 1;                                       // 0x00DC(0x0001) BIT_FIELD NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_KQX3[0x3];                                   // 0x00DD(0x0003) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieScene3DTransformKeyStruct
	 * Size -> 0x0040 (FullSize[0x0048] - InheritedSize[0x0008])
	 */
	struct FMovieScene3DTransformKeyStruct : public FMovieSceneKeyStruct
	{
	public:
		struct FVector                                             Location;                                                // 0x0008(0x000C) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		struct FRotator                                            Rotation;                                                // 0x0014(0x000C) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic
		struct FVector                                             Scale;                                                   // 0x0020(0x000C) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		struct FFrameNumber                                        Time;                                                    // 0x002C(0x0004) Edit, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_ACZT[0x18];                                  // 0x0030(0x0018) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieScene3DScaleKeyStruct
	 * Size -> 0x0028 (FullSize[0x0030] - InheritedSize[0x0008])
	 */
	struct FMovieScene3DScaleKeyStruct : public FMovieSceneKeyStruct
	{
	public:
		struct FVector                                             Scale;                                                   // 0x0008(0x000C) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		struct FFrameNumber                                        Time;                                                    // 0x0014(0x0004) Edit, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_DS07[0x18];                                  // 0x0018(0x0018) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieScene3DRotationKeyStruct
	 * Size -> 0x0028 (FullSize[0x0030] - InheritedSize[0x0008])
	 */
	struct FMovieScene3DRotationKeyStruct : public FMovieSceneKeyStruct
	{
	public:
		struct FRotator                                            Rotation;                                                // 0x0008(0x000C) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic
		struct FFrameNumber                                        Time;                                                    // 0x0014(0x0004) Edit, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_XS0X[0x18];                                  // 0x0018(0x0018) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieScene3DLocationKeyStruct
	 * Size -> 0x0028 (FullSize[0x0030] - InheritedSize[0x0008])
	 */
	struct FMovieScene3DLocationKeyStruct : public FMovieSceneKeyStruct
	{
	public:
		struct FVector                                             Location;                                                // 0x0008(0x000C) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		struct FFrameNumber                                        Time;                                                    // 0x0014(0x0004) Edit, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_9A8Y[0x18];                                  // 0x0018(0x0018) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieScene3DTransformTemplateData
	 * Size -> 0x0650
	 */
	struct FMovieScene3DTransformTemplateData
	{
	public:
		struct FMovieSceneFloatChannel                             TranslationCurve[0x3];                                   // 0x0000(0x01E0) NativeAccessSpecifierPublic
		struct FMovieSceneFloatChannel                             RotationCurve[0x3];                                      // 0x01E0(0x01E0) NativeAccessSpecifierPublic
		struct FMovieSceneFloatChannel                             ScaleCurve[0x3];                                         // 0x03C0(0x01E0) NativeAccessSpecifierPublic
		struct FMovieSceneFloatChannel                             ManualWeight;                                            // 0x05A0(0x00A0) NativeAccessSpecifierPublic
		EMovieSceneBlendType                                       BlendType;                                               // 0x0640(0x0001) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_K038[0x3];                                   // 0x0641(0x0003) MISSED OFFSET (FIX SPACE BETWEEN PREVIOUS PROPERTY)
		struct FMovieSceneTransformMask                            Mask;                                                    // 0x0644(0x0004) NoDestructor, NativeAccessSpecifierPublic
		bool                                                       bUseQuaternionInterpolation;                             // 0x0648(0x0001) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_GAMQ[0x7];                                   // 0x0649(0x0007) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneComponentTransformSectionTemplate
	 * Size -> 0x0650 (FullSize[0x0670] - InheritedSize[0x0020])
	 */
	struct FMovieSceneComponentTransformSectionTemplate : public FMovieSceneEvalTemplate
	{
	public:
		struct FMovieScene3DTransformTemplateData                  TemplateData;                                            // 0x0020(0x0650) NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneActorReferenceSectionTemplate
	 * Size -> 0x00D8 (FullSize[0x00F8] - InheritedSize[0x0020])
	 */
	struct FMovieSceneActorReferenceSectionTemplate : public FMovieSceneEvalTemplate
	{
	public:
		struct FMovieScenePropertySectionData                      PropertyData;                                            // 0x0020(0x0028) NativeAccessSpecifierPrivate
		struct FMovieSceneActorReferenceData                       ActorReferenceData;                                      // 0x0048(0x00B0) NativeAccessSpecifierPrivate
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneAudioSectionTemplate
	 * Size -> 0x0008 (FullSize[0x0028] - InheritedSize[0x0020])
	 */
	struct FMovieSceneAudioSectionTemplate : public FMovieSceneEvalTemplate
	{
	public:
		class UMovieSceneAudioSection*                             AudioSection;                                            // 0x0020(0x0008) ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneAdditiveCameraAnimationTemplate
	 * Size -> 0x0000 (FullSize[0x0020] - InheritedSize[0x0020])
	 */
	struct FMovieSceneAdditiveCameraAnimationTemplate : public FMovieSceneEvalTemplate
	{	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneCameraShakeSectionTemplate
	 * Size -> 0x0028 (FullSize[0x0048] - InheritedSize[0x0020])
	 */
	struct FMovieSceneCameraShakeSectionTemplate : public FMovieSceneAdditiveCameraAnimationTemplate
	{
	public:
		struct FMovieSceneCameraShakeSectionData                   SourceData;                                              // 0x0020(0x0020) NoDestructor, NativeAccessSpecifierPrivate
		struct FFrameNumber                                        SectionStartTime;                                        // 0x0040(0x0004) NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
		unsigned char                                              UnknownData_H5W4[0x4];                                   // 0x0044(0x0004) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneCameraAnimSectionTemplate
	 * Size -> 0x0028 (FullSize[0x0048] - InheritedSize[0x0020])
	 */
	struct FMovieSceneCameraAnimSectionTemplate : public FMovieSceneAdditiveCameraAnimationTemplate
	{
	public:
		struct FMovieSceneCameraAnimSectionData                    SourceData;                                              // 0x0020(0x0020) NoDestructor, NativeAccessSpecifierPrivate
		struct FFrameNumber                                        SectionStartTime;                                        // 0x0040(0x0004) NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
		unsigned char                                              UnknownData_14M4[0x4];                                   // 0x0044(0x0004) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneCameraCutSectionTemplate
	 * Size -> 0x0060 (FullSize[0x0080] - InheritedSize[0x0020])
	 */
	struct FMovieSceneCameraCutSectionTemplate : public FMovieSceneEvalTemplate
	{
	public:
		struct FMovieSceneObjectBindingID                          CameraBindingID;                                         // 0x0020(0x0018) NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_99YV[0x8];                                   // 0x0038(0x0008) MISSED OFFSET (FIX SPACE BETWEEN PREVIOUS PROPERTY)
		struct FTransform                                          CutTransform;                                            // 0x0040(0x0030) IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic
		bool                                                       bHasCutTransform;                                        // 0x0070(0x0001) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		bool                                                       bIsFinalSection;                                         // 0x0071(0x0001) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_P78V[0xE];                                   // 0x0072(0x000E) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneColorKeyStruct
	 * Size -> 0x0030 (FullSize[0x0038] - InheritedSize[0x0008])
	 */
	struct FMovieSceneColorKeyStruct : public FMovieSceneKeyStruct
	{
	public:
		struct FLinearColor                                        Color;                                                   // 0x0008(0x0010) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		struct FFrameNumber                                        Time;                                                    // 0x0018(0x0004) Edit, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_GZ2D[0x1C];                                  // 0x001C(0x001C) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneColorSectionTemplate
	 * Size -> 0x0288 (FullSize[0x02D0] - InheritedSize[0x0048])
	 */
	struct FMovieSceneColorSectionTemplate : public FMovieScenePropertySectionTemplate
	{
	public:
		struct FMovieSceneFloatChannel                             Curves[0x4];                                             // 0x0048(0x0280) NativeAccessSpecifierPublic
		EMovieSceneBlendType                                       BlendType;                                               // 0x02C8(0x0001) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_XJP6[0x7];                                   // 0x02C9(0x0007) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneEventPayloadVariable
	 * Size -> 0x0010
	 */
	struct FMovieSceneEventPayloadVariable
	{
	public:
		class FString                                              Value;                                                   // 0x0000(0x0010) ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneEventTemplateBase
	 * Size -> 0x0018 (FullSize[0x0038] - InheritedSize[0x0020])
	 */
	struct FMovieSceneEventTemplateBase : public FMovieSceneEvalTemplate
	{
	public:
		TArray<struct FMovieSceneObjectBindingID>                  EventReceivers;                                          // 0x0020(0x0010) ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		bool                                                       bFireEventsWhenForwards : 1;                             // 0x0030(0x0001) BIT_FIELD NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		bool                                                       bFireEventsWhenBackwards : 1;                            // 0x0030(0x0001) BIT_FIELD NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_B6IE[0x7];                                   // 0x0031(0x0007) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneEventRepeaterTemplate
	 * Size -> 0x0028 (FullSize[0x0060] - InheritedSize[0x0038])
	 */
	struct FMovieSceneEventRepeaterTemplate : public FMovieSceneEventTemplateBase
	{
	public:
		struct FMovieSceneEventPtrs                                EventToTrigger;                                          // 0x0038(0x0028) NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneEventTriggerTemplate
	 * Size -> 0x0020 (FullSize[0x0058] - InheritedSize[0x0038])
	 */
	struct FMovieSceneEventTriggerTemplate : public FMovieSceneEventTemplateBase
	{
	public:
		TArray<struct FFrameNumber>                                EventTimes;                                              // 0x0038(0x0010) ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		TArray<struct FMovieSceneEventPtrs>                        Events;                                                  // 0x0048(0x0010) ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneEventSectionTemplate
	 * Size -> 0x0088 (FullSize[0x00C0] - InheritedSize[0x0038])
	 */
	struct FMovieSceneEventSectionTemplate : public FMovieSceneEventTemplateBase
	{
	public:
		struct FMovieSceneEventSectionData                         EventData;                                               // 0x0038(0x0088) NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneFadeSectionTemplate
	 * Size -> 0x00B8 (FullSize[0x00D8] - InheritedSize[0x0020])
	 */
	struct FMovieSceneFadeSectionTemplate : public FMovieSceneEvalTemplate
	{
	public:
		struct FMovieSceneFloatChannel                             FadeCurve;                                               // 0x0020(0x00A0) NativeAccessSpecifierPrivate
		struct FLinearColor                                        FadeColor;                                               // 0x00C0(0x0010) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
		bool                                                       bFadeAudio : 1;                                          // 0x00D0(0x0001) BIT_FIELD NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
		unsigned char                                              UnknownData_0UQT[0x7];                                   // 0x00D1(0x0007) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneLevelVisibilitySectionTemplate
	 * Size -> 0x0018 (FullSize[0x0038] - InheritedSize[0x0020])
	 */
	struct FMovieSceneLevelVisibilitySectionTemplate : public FMovieSceneEvalTemplate
	{
	public:
		ELevelVisibility                                           Visibility;                                              // 0x0020(0x0001) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
		unsigned char                                              UnknownData_HTAW[0x7];                                   // 0x0021(0x0007) MISSED OFFSET (FIX SPACE BETWEEN PREVIOUS PROPERTY)
		TArray<class FName>                                        LevelNames;                                              // 0x0028(0x0010) ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneParameterSectionTemplate
	 * Size -> 0x0060 (FullSize[0x0080] - InheritedSize[0x0020])
	 */
	struct FMovieSceneParameterSectionTemplate : public FMovieSceneEvalTemplate
	{
	public:
		TArray<struct FScalarParameterNameAndCurve>                Scalars;                                                 // 0x0020(0x0010) ZeroConstructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected
		TArray<struct FBoolParameterNameAndCurve>                  Bools;                                                   // 0x0030(0x0010) ZeroConstructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected
		TArray<struct FVector2DParameterNameAndCurves>             Vector2Ds;                                               // 0x0040(0x0010) ZeroConstructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected
		TArray<struct FVectorParameterNameAndCurves>               Vectors;                                                 // 0x0050(0x0010) ZeroConstructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected
		TArray<struct FColorParameterNameAndCurves>                Colors;                                                  // 0x0060(0x0010) ZeroConstructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected
		TArray<struct FTransformParameterNameAndCurves>            Transforms;                                              // 0x0070(0x0010) ZeroConstructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneMaterialParameterCollectionTemplate
	 * Size -> 0x0008 (FullSize[0x0088] - InheritedSize[0x0080])
	 */
	struct FMovieSceneMaterialParameterCollectionTemplate : public FMovieSceneParameterSectionTemplate
	{
	public:
		class UMaterialParameterCollection*                        MPC;                                                     // 0x0080(0x0008) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneObjectPropertyTemplate
	 * Size -> 0x00C0 (FullSize[0x0108] - InheritedSize[0x0048])
	 */
	struct FMovieSceneObjectPropertyTemplate : public FMovieScenePropertySectionTemplate
	{
	public:
		struct FMovieSceneObjectPathChannel                        ObjectChannel;                                           // 0x0048(0x00C0) NativeAccessSpecifierPrivate
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneComponentMaterialSectionTemplate
	 * Size -> 0x0008 (FullSize[0x0088] - InheritedSize[0x0080])
	 */
	struct FMovieSceneComponentMaterialSectionTemplate : public FMovieSceneParameterSectionTemplate
	{
	public:
		int32_t                                                    MaterialIndex;                                           // 0x0080(0x0004) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
		unsigned char                                              UnknownData_79TM[0x4];                                   // 0x0084(0x0004) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneParticleParameterSectionTemplate
	 * Size -> 0x0000 (FullSize[0x0080] - InheritedSize[0x0080])
	 */
	struct FMovieSceneParticleParameterSectionTemplate : public FMovieSceneParameterSectionTemplate
	{	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneParticleSectionTemplate
	 * Size -> 0x0098 (FullSize[0x00B8] - InheritedSize[0x0020])
	 */
	struct FMovieSceneParticleSectionTemplate : public FMovieSceneEvalTemplate
	{
	public:
		struct FMovieSceneParticleChannel                          ParticleKeys;                                            // 0x0020(0x0098) NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieScenePrimitiveMaterialTemplate
	 * Size -> 0x00C8 (FullSize[0x00E8] - InheritedSize[0x0020])
	 */
	struct FMovieScenePrimitiveMaterialTemplate : public FMovieSceneEvalTemplate
	{
	public:
		int32_t                                                    MaterialIndex;                                           // 0x0020(0x0004) ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate
		unsigned char                                              UnknownData_1UMU[0x4];                                   // 0x0024(0x0004) MISSED OFFSET (FIX SPACE BETWEEN PREVIOUS PROPERTY)
		struct FMovieSceneObjectPathChannel                        MaterialChannel;                                         // 0x0028(0x00C0) NativeAccessSpecifierPrivate
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneEulerTransformPropertySectionTemplate
	 * Size -> 0x0650 (FullSize[0x0698] - InheritedSize[0x0048])
	 */
	struct FMovieSceneEulerTransformPropertySectionTemplate : public FMovieScenePropertySectionTemplate
	{
	public:
		struct FMovieScene3DTransformTemplateData                  TemplateData;                                            // 0x0048(0x0650) Protected, NativeAccessSpecifierProtected
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneTransformPropertySectionTemplate
	 * Size -> 0x0650 (FullSize[0x0698] - InheritedSize[0x0048])
	 */
	struct FMovieSceneTransformPropertySectionTemplate : public FMovieScenePropertySectionTemplate
	{
	public:
		struct FMovieScene3DTransformTemplateData                  TemplateData;                                            // 0x0048(0x0650) Protected, NativeAccessSpecifierProtected
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneVectorPropertySectionTemplate
	 * Size -> 0x0288 (FullSize[0x02D0] - InheritedSize[0x0048])
	 */
	struct FMovieSceneVectorPropertySectionTemplate : public FMovieScenePropertySectionTemplate
	{
	public:
		struct FMovieSceneFloatChannel                             ComponentCurves[0x4];                                    // 0x0048(0x0280) Protected, NativeAccessSpecifierProtected
		int32_t                                                    NumChannelsUsed;                                         // 0x02C8(0x0004) ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected
		EMovieSceneBlendType                                       BlendType;                                               // 0x02CC(0x0001) ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected
		unsigned char                                              UnknownData_T5T2[0x3];                                   // 0x02CD(0x0003) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneStringPropertySectionTemplate
	 * Size -> 0x00A0 (FullSize[0x00E8] - InheritedSize[0x0048])
	 */
	struct FMovieSceneStringPropertySectionTemplate : public FMovieScenePropertySectionTemplate
	{
	public:
		struct FMovieSceneStringChannel                            StringCurve;                                             // 0x0048(0x00A0) Protected, NativeAccessSpecifierProtected
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneIntegerPropertySectionTemplate
	 * Size -> 0x0098 (FullSize[0x00E0] - InheritedSize[0x0048])
	 */
	struct FMovieSceneIntegerPropertySectionTemplate : public FMovieScenePropertySectionTemplate
	{
	public:
		struct FMovieSceneIntegerChannel                           IntegerCurve;                                            // 0x0048(0x0090) Protected, NativeAccessSpecifierProtected
		EMovieSceneBlendType                                       BlendType;                                               // 0x00D8(0x0001) ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected
		unsigned char                                              UnknownData_JEZ1[0x7];                                   // 0x00D9(0x0007) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneEnumPropertySectionTemplate
	 * Size -> 0x0098 (FullSize[0x00E0] - InheritedSize[0x0048])
	 */
	struct FMovieSceneEnumPropertySectionTemplate : public FMovieScenePropertySectionTemplate
	{
	public:
		struct FMovieSceneByteChannel                              EnumCurve;                                               // 0x0048(0x0098) Protected, NativeAccessSpecifierProtected
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneBytePropertySectionTemplate
	 * Size -> 0x0098 (FullSize[0x00E0] - InheritedSize[0x0048])
	 */
	struct FMovieSceneBytePropertySectionTemplate : public FMovieScenePropertySectionTemplate
	{
	public:
		struct FMovieSceneByteChannel                              ByteCurve;                                               // 0x0048(0x0098) Protected, NativeAccessSpecifierProtected
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneFloatPropertySectionTemplate
	 * Size -> 0x00A8 (FullSize[0x00F0] - InheritedSize[0x0048])
	 */
	struct FMovieSceneFloatPropertySectionTemplate : public FMovieScenePropertySectionTemplate
	{
	public:
		struct FMovieSceneFloatChannel                             FloatFunction;                                           // 0x0048(0x00A0) Protected, NativeAccessSpecifierProtected
		EMovieSceneBlendType                                       BlendType;                                               // 0x00E8(0x0001) ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected
		unsigned char                                              UnknownData_4ZW1[0x7];                                   // 0x00E9(0x0007) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneBoolPropertySectionTemplate
	 * Size -> 0x0090 (FullSize[0x00D8] - InheritedSize[0x0048])
	 */
	struct FMovieSceneBoolPropertySectionTemplate : public FMovieScenePropertySectionTemplate
	{
	public:
		struct FMovieSceneBoolChannel                              BoolCurve;                                               // 0x0048(0x0090) Protected, NativeAccessSpecifierProtected
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneSkeletalAnimationSectionTemplateParameters
	 * Size -> 0x0008 (FullSize[0x00E0] - InheritedSize[0x00D8])
	 */
	struct FMovieSceneSkeletalAnimationSectionTemplateParameters : public FMovieSceneSkeletalAnimationParams
	{
	public:
		struct FFrameNumber                                        SectionStartTime;                                        // 0x00D8(0x0004) NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		struct FFrameNumber                                        SectionEndTime;                                          // 0x00DC(0x0004) NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneSkeletalAnimationSectionTemplate
	 * Size -> 0x00E0 (FullSize[0x0100] - InheritedSize[0x0020])
	 */
	struct FMovieSceneSkeletalAnimationSectionTemplate : public FMovieSceneEvalTemplate
	{
	public:
		struct FMovieSceneSkeletalAnimationSectionTemplateParameters Params;                                                  // 0x0020(0x00E0) NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneSlomoSectionTemplate
	 * Size -> 0x00A0 (FullSize[0x00C0] - InheritedSize[0x0020])
	 */
	struct FMovieSceneSlomoSectionTemplate : public FMovieSceneEvalTemplate
	{
	public:
		struct FMovieSceneFloatChannel                             SlomoCurve;                                              // 0x0020(0x00A0) NativeAccessSpecifierPrivate
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneSpawnSectionTemplate
	 * Size -> 0x0090 (FullSize[0x00B0] - InheritedSize[0x0020])
	 */
	struct FMovieSceneSpawnSectionTemplate : public FMovieSceneEvalTemplate
	{
	public:
		struct FMovieSceneBoolChannel                              Curve;                                                   // 0x0020(0x0090) Protected, NativeAccessSpecifierProtected
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneVectorKeyStructBase
	 * Size -> 0x0020 (FullSize[0x0028] - InheritedSize[0x0008])
	 */
	struct FMovieSceneVectorKeyStructBase : public FMovieSceneKeyStruct
	{
	public:
		struct FFrameNumber                                        Time;                                                    // 0x0008(0x0004) Edit, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_3E4T[0x1C];                                  // 0x000C(0x001C) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneVector4KeyStruct
	 * Size -> 0x0018 (FullSize[0x0040] - InheritedSize[0x0028])
	 */
	struct FMovieSceneVector4KeyStruct : public FMovieSceneVectorKeyStructBase
	{
	public:
		unsigned char                                              UnknownData_OHW6[0x8];                                   // 0x0028(0x0008) MISSED OFFSET (FIX SPACE BETWEEN PREVIOUS PROPERTY)
		struct FVector4                                            Vector;                                                  // 0x0030(0x0010) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneVectorKeyStruct
	 * Size -> 0x0010 (FullSize[0x0038] - InheritedSize[0x0028])
	 */
	struct FMovieSceneVectorKeyStruct : public FMovieSceneVectorKeyStructBase
	{
	public:
		struct FVector                                             Vector;                                                  // 0x0028(0x000C) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
		unsigned char                                              UnknownData_H6TU[0x4];                                   // 0x0034(0x0004) MISSED OFFSET (PADDING)
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneVector2DKeyStruct
	 * Size -> 0x0008 (FullSize[0x0030] - InheritedSize[0x0028])
	 */
	struct FMovieSceneVector2DKeyStruct : public FMovieSceneVectorKeyStructBase
	{
	public:
		struct FVector2D                                           Vector;                                                  // 0x0028(0x0008) Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	};

	/**
	 * ScriptStruct MovieSceneTracks.MovieSceneVisibilitySectionTemplate
	 * Size -> 0x0000 (FullSize[0x00D8] - InheritedSize[0x00D8])
	 */
	struct FMovieSceneVisibilitySectionTemplate : public FMovieSceneBoolPropertySectionTemplate
	{	};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
