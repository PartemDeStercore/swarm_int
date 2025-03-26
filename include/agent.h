#ifndef AGENT_H
#define AGENT_H
#include <stdint.h>
typedef struct {
	uint16_t x;
	uint16_t y;
	long double rotate;
	uint16_t distance;
}agent_position_t;

typedef struct{//поле которое содержит флаги наличия агентов
	uint16_t len_x;
	uint16_t len_y;
	uint8_t** field;
}agent_field_t;

agent_field_t field_init(uint16_t len_x,uint16_t len_y);
uint8_t field_read_value(agent_field_t field, uint16_t x,uint16_t y);
void field_write_value(uint8_t data, agent_field_t field, uint16_t x,uint16_t y);

#endif