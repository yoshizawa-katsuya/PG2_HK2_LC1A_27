#pragma once
#include "Struct.h"

int CapsuleCollision(Vector2 capsuleA, Vector2 capsuleB, Vector2 CircleC, float radiusC, float radiusA);

int BoxCollision(Vector2 boxA, int boxAwidht, int boxAhight, Vector2 boxB, int boxBwidht, int boxBhight);
