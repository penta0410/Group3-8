#include "DxLib.h"
#include "Transparent.h"

//‰Šú‰»
int Flag = true;

//“§‰ßŠÖ”
int Transparent(int alpha, int speed)
{
	//“§‰ßˆ—
	//BottanAlphaFlag‚ªtrue‚Ì‚É“§‰ß‚·‚é
	if (Flag)
	{
		alpha -= speed;
		
		//BottanAlpha‚ª0ˆÈ‰º‚ÌBottanAlphaFlag‚ğfalse‚É‚·‚é
		if (alpha <= 0)
		{
			Flag = false;
		}
		
	}
	//BottanAlphaFlag‚ªfalse‚Ì‚É’Êí‚É–ß‚·
	if (!Flag)
	{
		alpha += speed;

		//BottanAlpha‚ª100ˆÈã‚ÌBottanAlphaFlag‚ğtrue‚É‚·‚é
		if (alpha >= 100)
		{
			Flag = true;
		}
		
	}
	return alpha;
	
}
