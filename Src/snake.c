#include "SSD1331.h"//biblioteka wyswietlacza OLED
#include "snake.h"

static void initPlay(void)
{	ssd1331_init();
    ssd1331_clear_screen(GREEN_BACKGROUND);
    	ssd1331_display_string(20, 0, "Sssnake", FONT_1608, GREEN);
    	ssd1331_draw_circle(37,23,SNAKE_RAD, GREEN_SNAKE);
    	ssd1331_draw_circle(41,23,SNAKE_RAD, GREEN_SNAKE);
    	ssd1331_draw_circle(45,23,SNAKE_RAD, GREEN_SNAKE);
    	ssd1331_draw_circle(49,23,SNAKE_RAD, GREEN_SNAKE);
    	ssd1331_draw_circle(53,23,SNAKE_RAD, GREEN_SNAKE);
    	ssd1331_draw_circle(57,23,SNAKE_RAD, GREEN_SNAKE);
    	ssd1331_draw_circle(57,27,SNAKE_RAD, GREEN_SNAKE);
    	ssd1331_draw_circle(57,31,SNAKE_RAD, GREEN_SNAKE);
    	ssd1331_draw_circle(57,35,SNAKE_RAD, GREEN_SNAKE);
    	ssd1331_draw_circle(53,35,SNAKE_RAD, GREEN_SNAKE);
    	ssd1331_draw_circle(49,35,SNAKE_RAD, YELLOW);
    	ssd1331_draw_circle(37,35,SNAKE_RAD, RED);
        ssd1331_display_string(20, 39, "Click blue", FONT_1206, GREEN);
        ssd1331_display_string(5, 51, "button to play", FONT_1206, GREEN);
}
//Funkcja inicjalizujaca oraz wyswietlajaca weza na ekranie
static void initSnake(void)
{
	uint8_t i;
	snake.size = SNAKE_INIT_SIZE;
	snake.head.x = SNAKE_START_X_POSITION;
	snake.head.y = SNAKE_START_Y_POSITION;
	//Rysuj glowe
	ssd1331_draw_circle(snake.head.x,snake.head.y,SNAKE_RAD,YELLOW);
	for(i=1;i<snake.size;i++)
	{
		snake.snakeParts[i].x = SNAKE_START_X_POSITION + (i*SNAKE_STEP);
		snake.snakeParts[i].y = SNAKE_START_Y_POSITION;
		ssd1331_draw_circle(snake.snakeParts[i].x,snake.snakeParts[i].y,SNAKE_RAD, GREEN_SNAKE);
	}
}
static void MoveSnake(uint8_t direction)
{
	uint8_t i, partsCount = snake.size,pom_x,pom_y;
	pom_x=snake.head.x;
	pom_y=snake.head.y;
	//ssd1331_clear_screen(BLACK);
	snake.snakeParts[0].x=pom_x;
	snake.snakeParts[0].y=pom_y;
	ssd1331_draw_circle(snake.snakeParts[partsCount-1].x,snake.snakeParts[partsCount-1].y,SNAKE_RAD, GREEN_BACKGROUND);
	//ssd1331_fill_rect(snake.snakeParts[partsCount-1].x,snake.snakeParts[partsCount-1].y,SNAKE_STEP+1,SNAKE_STEP+1,BLACK);
	for(i=partsCount-1;i>0;i--)
	{
			snake.snakeParts[i].x=snake.snakeParts[i-1].x;
			snake.snakeParts[i].y=snake.snakeParts[i-1].y;
	}
    /*
	for(i=partsCount-1;i>0;i--)
	{
		snake.snakeParts[i].x=snake.snakeParts[i-1].x;
		snake.snakeParts[i].y=snake.snakeParts[i-1].y;
	}
	ssd1331_draw_circle(snake.snakeParts[partsCount-1].x,snake.snakeParts[partsCount-1].y,BLUE);*/
	switch (direction)
	{
	    case left:
	    	snake.head.x -= SNAKE_STEP;
	    	ssd1331_draw_circle(snake.head.x,snake.head.y,SNAKE_RAD,YELLOW);
	    	for(i=1;i<partsCount;i++)
	    	{
	    		//snake.snakeParts[i].x -= SNAKE_STEP;
	    		ssd1331_draw_circle(snake.snakeParts[i].x,snake.snakeParts[i].y,SNAKE_RAD,GREEN_SNAKE);
	    	}
	    break;
	    case right:
	   	    snake.head.x += SNAKE_STEP;
	   	    ssd1331_draw_circle(snake.head.x,snake.head.y,SNAKE_RAD,YELLOW);
	   	 	for(i=1;i<partsCount;i++)
	   	 	{
	   	 		//snake.snakeParts[i].x += SNAKE_STEP;
	   	 		ssd1331_draw_circle(snake.snakeParts[i].x,snake.snakeParts[i].y,SNAKE_RAD,GREEN_SNAKE);
	   	 	}
	   	break;
	    case up:
	   	    snake.head.y -= SNAKE_STEP;
	   	    ssd1331_draw_circle(snake.head.x,snake.head.y,SNAKE_RAD,YELLOW);
	   	 	for(i=1;i<partsCount;i++)
	   	 	{
	   	 		//snake.snakeParts[i].y -= SNAKE_STEP;
	   	 		ssd1331_draw_circle(snake.snakeParts[i].x,snake.snakeParts[i].y,SNAKE_RAD,GREEN_SNAKE);
	   	 	}
	   	break;
	    case down:
	   	    snake.head.y += SNAKE_STEP;
	   	    ssd1331_draw_circle(snake.head.x,snake.head.y,SNAKE_RAD,YELLOW);
	   	 	for(i=1;i<partsCount;i++)
	   	 	{
	   	 		//snake.snakeParts[i].y += SNAKE_STEP;
	   	 		ssd1331_draw_circle(snake.snakeParts[i].x,snake.snakeParts[i].y,SNAKE_RAD,GREEN_SNAKE);
	   	 	}
	   	break;
	}

}