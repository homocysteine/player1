#include "Block.h"



Block::Block()
{
	setRect(0, 0, blockSize, blockSize);
	QBrush brush_block(QImage(":/Player_1/Resources/Block.png"));
	setBrush(brush_block);
}

Block::~Block()
{

}
