// �ȉ��� ifdef �u���b�N�� DLL ����ȒP�ɃG�N�X�|�[�g������}�N�����쐬����W���I�ȕ��@�ł��B 
// ���� DLL ���̂��ׂẴt�@�C���̓R�}���h���C���Œ�`���ꂽ ATS_EXPORTS �V���{��
// �ŃR���p�C������܂��B���̃V���{���͂��� DLL ���g�p����ǂ̃v���W�F�N�g��ł�����`�łȂ�
// ��΂Ȃ�܂���B���̕��@�ł̓\�[�X�t�@�C���ɂ��̃t�@�C�����܂ނ��ׂẴv���W�F�N�g�� DLL 
// ����C���|�[�g���ꂽ���̂Ƃ��� ATS_API �֐����Q�Ƃ��A���̂��߂��� DLL �͂��̃}�N 
// ���Œ�`���ꂽ�V���{�����G�N�X�|�[�g���ꂽ���̂Ƃ��ĎQ�Ƃ��܂��B
//#pragma data_seg(".shared")
//#pragma data_seg()

int g_emgBrake; // ���m�b�`
int g_svcBrake; // ��p�ő�m�b�`
int g_brakeNotch; // �u���[�L�m�b�`
int g_powerNotch; // �͍s�m�b�`
int g_reverser; // ���o�[�T
bool g_pilotlamp; // �p�C���b�g�����v
float g_speed; // ���x�v�̑��x[km/h]

int signalcode;//BVE����󂯂�M��
int speedlimit;//�������x
bool emgbraketrigger;//���u���[�L����
bool svcbraketrigger;//��p�u���[�L����
int brakeoutput;//�u���[�L�o��
void trysetintvalue(int*, int);

ATS_HANDLES g_output; // �o��
doorCloseingSecurity g_doorCloseingSecurity; // �˕ۈ�

