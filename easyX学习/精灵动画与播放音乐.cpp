#include<stdio.h>
#include<easyx.h>
#include <ctime>

/*
int main()
{
	initgraph(640, 480, EX_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	setbkmode(TRANSPARENT);

	//FPS 60f
	const clock_t FPS = 1000 / 60;  //1秒/60帧=16.6 每一帧应该花费的时间
	int startTime = 0;
	int freamTime = 0;


	int score = 0;
	char str[50] = "";
	while (true)
	{
		startTime = clock();  //50ms

		sprintf(str, "Score:%d", score++);
		settextcolor(BLACK);


		//双缓冲防闪屏
		BeginBatchDraw();

		cleardevice();//用设置的背景颜色填充整个窗口



		outtextxy(20, 20, str);

		EndBatchDraw();


		freamTime = clock() - startTime;
		if (freamTime > 0)
		{
			Sleep(FPS - freamTime);
		}

		//getchar();
	}
	return 0;
}
*/



#include<stdio.h>
#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

void playBackgroundMusic(const char* music, bool repeat = false, int volume = -1)
{
	static int i = 0;
	char cmd[100] = { 0 };
	sprintf(cmd, "open %s alias bgm%d", music, i);
	MCIERROR ret = mciSendString(cmd, NULL, 0, NULL);
	if (ret != 0)
	{
		//获取一下错误信息
		char err[100] = { 0 };
		mciGetErrorString(ret, err, sizeof(err));
		printf("[open]:%s", err);
	}
	sprintf(cmd, "play bgm%d %s", i, repeat ? "repeat" : "");
	ret = mciSendString(cmd, NULL, 0, NULL);
	if (ret != 0)
	{
		//获取一下错误信息
		char err[100] = { 0 };
		mciGetErrorString(ret, err, sizeof(err));
		printf("[open]:%s", err);
	}
	if (volume != -1)
	{
		sprintf(cmd, "setaudio bgm%d volume to %d", i, volume);
		ret = mciSendString(cmd, NULL, 0, NULL);
		if (ret != 0)
		{
			//获取一下错误信息
			char err[100] = { 0 };
			mciGetErrorString(ret, err, sizeof(err));
			printf("[open]:%s", err);
		}
	}
	i++;
}


int main()
{
	while (true)
	{
		PlaySound("assets/video_call.wav", NULL, SND_FILENAME | SND_ASYNC);
	}

	getchar();
	return 0;
}