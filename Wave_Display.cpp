#include "Wave_Display.h"
#include "Wave_Component.h"
#include "Game.h"

WAVE_DISPLAY_COMPONENT::WAVE_DISPLAY_COMPONENT() : Component(eComponentTypes::WAVE_DISPLAY_COMPONENT)
{
    
}
WAVE_DISPLAY_COMPONENT::~WAVE_DISPLAY_COMPONENT()
{
    
}
void WAVE_DISPLAY_COMPONENT::Initialize()
{
    wave_status = new Object;
    wave_status->transform.position.Set(500, -300, 0);
    wave_status->transform.rotation = 0;
    wave_status->transform.SetScale(200, 100);
    wave_status->sprite.color = { 255,255,0,255 };
    wave_status->text.font = asd;
    wave_status->text.isHud = true;
    wave_status->text.color = { 255,0,0,255 };
    wave_status->text.SetText("Wave: %d", wave);

    //TTF_CloseFont(asd);
    wave_sprite = wave_status;
    wave_sprite_once = true;
}
void WAVE_DISPLAY_COMPONENT::Update(float dt)
{
    (dt);
    wave_status->text.SetText("Wave: %d", wave);
	
}