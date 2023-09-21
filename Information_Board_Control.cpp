#include "Information_Board_Control.h"
#include "Application.h"


void INFORMATION_BOARD_CONTROL::Helper_Convert_Mouse_Pos()
{
    mouse_pos = State::m_input->GetMousePos();
    mouse_pos.x -= State::m_width / 2;
    mouse_pos.y -= State::m_height / 2;
    mouse_pos.y *= -1;
}
INFORMATION_BOARD_CONTROL::INFORMATION_BOARD_CONTROL() : Component(eComponentTypes::INFORMATION_BOARD_CONTROL)
{
}
INFORMATION_BOARD_CONTROL::~INFORMATION_BOARD_CONTROL()
{
}
void INFORMATION_BOARD_CONTROL::Initialize()
{
    my_map = static_cast<Map*>(GetOwner());
}
void INFORMATION_BOARD_CONTROL::Check_Mouse_Interaction_Board()
{
    float normalize_information_board_x_left;
    float normalize_information_board_x_right;
    float normalize_information_board_y_up;
    float normalize_information_board_y_down;

    normalize_information_board_x_left = current_inforamtion_board->transform.position.x - (current_inforamtion_board->transform.GetScale().x / 2);
    normalize_information_board_x_right = current_inforamtion_board->transform.position.x + (current_inforamtion_board->transform.GetScale().x / 2);
    normalize_information_board_y_up = current_inforamtion_board->transform.position.y + (current_inforamtion_board->transform.GetScale().y / 2);
    normalize_information_board_y_down = current_inforamtion_board->transform.position.y - (current_inforamtion_board->transform.GetScale().y / 2);

    if(mouse_pos.x > normalize_information_board_x_left && mouse_pos.x < normalize_information_board_x_right &&
        mouse_pos.y < normalize_information_board_y_up && mouse_pos.y > normalize_information_board_y_down)
    {
    }

}
void INFORMATION_BOARD_CONTROL::Check_Mouse_Pos()
{
    
}
void INFORMATION_BOARD_CONTROL::Update(float dt)
{
    (dt);
}
