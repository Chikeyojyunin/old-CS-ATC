//=============================
// BVE ATS �v���O�C�� �w�b�_�[ �t�@�C��
//
//             Rock_On, mackoy
//=============================

#ifdef ATS_EXPORTS
#define ATS_API __declspec(dllexport)
#else
#define ATS_API __declspec(dllimport)
#endif

// ATS �v���O�C�� �o�[�W����
#define ATS_VERSION	0x00020000

// ATS �L�[
#define ATS_KEY_S	0	// �X�y�[�X Key
#define ATS_KEY_A1	1	// �C���T�[�g Key
#define ATS_KEY_A2	2	// �f���[�g Key
#define ATS_KEY_B1	3	// �z�[�� Key
#define ATS_KEY_B2	4	// �G���h Key
#define ATS_KEY_C1	5	// �y�[�W�A�b�v Key
#define ATS_KEY_C2	6	// �y�[�W�_�E�� Key
#define ATS_KEY_D	7	// 2 Key
#define ATS_KEY_E	8	// 3 Key
#define ATS_KEY_F	9	// 4 Key
#define ATS_KEY_G	10	// 5 Key
#define ATS_KEY_H	11	// 6 Key
#define ATS_KEY_I	12	// 7 Key
#define ATS_KEY_J	13	// 8 Key
#define ATS_KEY_K	14	// 9 Key
#define ATS_KEY_L	15	// 0 Key

// �Q�[���J�n���̃u���[�L�ق̏�Ԃł��B���̂����ꂩ�̒l��Ԃ��܂��B
#define ATS_INIT_REMOVED	2	// ��p�ʒu
#define ATS_INIT_EMG		1	// ���ʒu
#define ATS_INIT_SVC		0	// 	������� (�ʏ�A�ۈ����u������)

// �T�E���h�R���g���[���w��
#define ATS_SOUND_STOP			-10000	// ��~
#define ATS_SOUND_PLAY			1		// 1 ��Đ�
#define ATS_SOUND_PLAYLOOPING	0		// �J��Ԃ��Đ�
#define ATS_SOUND_CONTINUE		2		// ���݂̏�Ԃ��ێ�����

// �x�J������ꂽ�Ƃ��ɌĂяo�����֐��ł��B
#define ATS_HORN_PRIMARY	0	// �x�J1
#define ATS_HORN_SECONDARY	1	// �x�J2
#define ATS_HORN_MUSIC		2	// �~���[�W�b�N�z�[��

// �葬����̏�ԁB
#define ATS_CONSTANTSPEED_CONTINUE	0	// �N��
#define ATS_CONSTANTSPEED_ENABLE	1	// ��~
#define ATS_CONSTANTSPEED_DISABLE	2	// ���݂̏�Ԃ��ێ�����

// �ԗ�����
struct ATS_VEHICLESPEC
{
	int BrakeNotches;	// �u���[�L�m�b�`���B
	int PowerNotches;	// �͍s�m�b�`���B
	int AtsNotch;		// ATS�m�F�m�b�`�B
	int B67Notch;		// �u���[�L�� 67 �x�ɑ�������m�b�`�B
	int Cars;			// �Ґ������B
};

// �ԗ��̏�ԗ�
struct ATS_VEHICLESTATE
{
	double Location;	// ��Ԉʒu [m]�B
	float Speed;		// ��ԑ��x [km/h]�B
	int Time;			// ���ݎ��� [ms]�B
	float BcPressure;	// �u���[�L�V�����_���� [kPa]�B
	float MrPressure;	// ����C�_������ [kPa]�B
	float ErPressure;	// �ނ荇����C�_������ [kPa]�B
	float BpPressure;	// �u���[�L�ǈ��� [kPa]�B
	float SapPressure;	// ���ʊǈ��� [kPa]�B
	float Current;		// �d�� [A]�B
};

// �ԏ�q�Ŏ󂯎�������
struct ATS_BEACONDATA
{
	int Type;		// �n��q��ʁB
	int Signal;		// �΂ƂȂ�Z�N�V�����̐M���B
	float Distance;	// �΂ƂȂ�Z�N�V�����܂ł̋��� [m]�B
	int Optional;	// �n��q�ɐݒ肳�ꂽ�C�ӂ̒l�B
};

// Bve trainsim �ɓn���n���h������l
struct ATS_HANDLES
{
	int Brake;				// �u���[�L�m�b�`�B
	int Power;				// �͍s�m�b�`�B
	int Reverser;			// ���o�[�T�[�ʒu�B
	int ConstantSpeed;		// �葬����̏�ԁB
};

// �v���O�C�����ǂݍ��܂ꂽ�Ƃ��ɌĂяo�����֐��ł��B
ATS_API void WINAPI Load(void);

// �v���O�C����������ꂽ�Ƃ��ɌĂяo�����֐��ł��B
ATS_API void WINAPI Dispose(void);

// ���� ATS �v���O�C���������Ă���t�H�[�}�b�g��Ԃ��֐��ł��B
ATS_API int WINAPI GetPluginVersion(void);

// �ԗ��ǂݍ��ݎ��ɌĂяo�����֐��ł��B
ATS_API void WINAPI SetVehicleSpec(ATS_VEHICLESPEC);

// �Q�[���J�n ([�J��] �܂��� [�͂��߂���] �I��) ���ɌĂяo�����֐��ł��B
ATS_API void WINAPI Initialize(int);

// 1 �t���[�����ƂɌĂяo�����֐��ł��B
ATS_API ATS_HANDLES WINAPI Elapse(ATS_VEHICLESTATE, int *, int *);

// ��n���h��������ꂽ�Ƃ��ɌĂяo�����֐��ł��B
ATS_API void WINAPI SetPower(int);

// �u���[�L������ꂽ�Ƃ��ɌĂяo�����֐��ł��B
ATS_API void WINAPI SetBrake(int);

// ���o�[�T�[������ꂽ�Ƃ��ɌĂяo�����֐��ł��B
ATS_API void WINAPI SetReverser(int);

// ATS �L�[�������ꂽ�Ƃ��ɌĂяo�����֐��ł��B
ATS_API void WINAPI KeyDown(int);

// ATS �L�[�������ꂽ�Ƃ��ɌĂяo�����֐��ł��B
ATS_API void WINAPI KeyUp(int);

// �x�J������ꂽ�Ƃ��ɌĂяo�����֐��ł��B
ATS_API void WINAPI HornBlow(int);

// �q���h�A���J�����Ƃ��ɌĂяo�����֐��ł��B
ATS_API void WINAPI DoorOpen(void);

// �q���h�A���܂����Ƃ��ɌĂяo�����֐��ł��B
ATS_API void WINAPI DoorClose(void);

// ���݂̕����̐M�����ω������Ƃ��ɌĂяo�����֐��ł�
ATS_API void WINAPI SetSignal(int);

// �n��q���z�����Ƃ��ɌĂяo�����֐��ł��B
ATS_API void WINAPI SetBeaconData(ATS_BEACONDATA);

// ���̃v���O�C����BVE�ɂ���ēǂݍ��܂ꂽ���ɌĂяo�����B
ATS_API void WINAPI Load();

// ���̃v���O�C����BVE���������ꂽ���ɌĂяo�����B
ATS_API void WINAPI Dispose();