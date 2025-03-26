#include "agent.h"
#include <stdlib.h>
#define IND_TO_BIT(x) ((x+7)/8)
//точка - агент который постоянно кричит

//1 агент
//вокруг меня есть точка? да - сменить направление, кричать
//двигаться по напрвлению

//поле
//проверить наличие точек вокруг агентов
//дать каждому агенту новое направление в сторону минимального расстояние
//двинуть агентов
agent_field_t field_init(uint16_t len_x,uint16_t len_y){
	agent_field_t field;
	field.len_x = len_x;
	field.len_y = len_y;
	field.field = calloc( len_y * IND_TO_BIT(len_x) ,1);
	return field;
}
uint8_t field_read_value(agent_field_t field, uint16_t x,uint16_t y){
	uint8_t res = (field.field)[y*IND_TO_BIT(field.len_x)+IND_TO_BIT(x)];
	res &= (1<<x%8);
	res = !!res;
	return res;
}
void field_write_value(uint8_t data, agent_field_t field, uint16_t x,uint16_t y){
	if(data)
		(field.field)[
			y*IND_TO_BIT(field.len_x) +
			IND_TO_BIT(x)
		] |= (uint8_t)  1<<(x%8);
	else
		(field.field)[
			y*IND_TO_BIT(field.len_x) +
			IND_TO_BIT(x)
		] &= (uint8_t)~(1<<(x%8));
	return res;
}