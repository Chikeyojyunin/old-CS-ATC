// 以下の ifdef ブロックは DLL から簡単にエクスポートさせるマクロを作成する標準的な方法です。 
// この DLL 内のすべてのファイルはコマンドラインで定義された ATS_EXPORTS シンボル
// でコンパイルされます。このシンボルはこの DLL が使用するどのプロジェクト上でも未定義でなけ
// ればなりません。この方法ではソースファイルにこのファイルを含むすべてのプロジェクトが DLL 
// からインポートされたものとして ATS_API 関数を参照し、そのためこの DLL はこのマク 
// ロで定義されたシンボルをエクスポートされたものとして参照します。
//#pragma data_seg(".shared")
//#pragma data_seg()

int g_emgBrake; // 非常ノッチ
int g_svcBrake; // 常用最大ノッチ
int g_brakeNotch; // ブレーキノッチ
int g_powerNotch; // 力行ノッチ
int g_reverser; // レバーサ
bool g_pilotlamp; // パイロットランプ
float g_speed; // 速度計の速度[km/h]

int signalcode;//BVEから受ける信号
int speedlimit;//制限速度
bool emgbraketrigger;//非常ブレーキ動作
bool svcbraketrigger;//常用ブレーキ動作
int brakeoutput;//ブレーキ出力
void trysetintvalue(int*, int);

ATS_HANDLES g_output; // 出力
doorCloseingSecurity g_doorCloseingSecurity; // 戸閉保安

