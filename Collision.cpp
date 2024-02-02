#include <math.h>
#include "Collision.h"

int CapsuleCollision(Vector2 capsuleA, Vector2 capsuleB, Vector2 CircleC, float radiusC, float radiusA) {
	float length;

	float dot;

	float t;

	Vector2 d;
	Vector2 ba;
	Vector2 e = { 0, 0 };
	Vector2 f;

	d.x = CircleC.x - capsuleA.x;
	d.y = CircleC.y - capsuleA.y;

	ba.x = capsuleB.x - capsuleA.x;
	ba.y = capsuleB.y - capsuleA.y;

	length = sqrtf(ba.x * ba.x + ba.y * ba.y);

	if (length == 0.0f) {
		length = sqrtf(d.x * d.x + d.y * d.y);

		if (length < radiusC + radiusA) {
			return 1;
		}
		else {
			return 0;
		}
	}

	if (length != 0.0f) {
		e.x = ba.x / length;
		e.y = ba.y / length;
	}

	dot = d.x * e.x + d.y * e.y;

	t = dot / length;

	if (t < 0) {
		t = 0;
	}
	if (t > 1) {
		t = 1;
	}

	f.x = (1.0f - t) * capsuleA.x + t * capsuleB.x;
	f.y = (1.0f - t) * capsuleA.y + t * capsuleB.y;

	length = sqrtf((CircleC.x - f.x) * (CircleC.x - f.x) + (CircleC.y - f.y) * (CircleC.y - f.y));

	if (length < radiusC + radiusA) {
		return 1;
	}
	else {
		return 0;
	}

}

int BoxCollision(Vector2 boxA, int boxAwidht, int boxAhight, Vector2 boxB, int boxBwidht, int boxBhight)
{

	if (boxA.x - (boxAwidht / 2) <= boxB.x + (boxBwidht / 2)) {
		if (boxA.x + (boxAwidht / 2) >= boxB.x - (boxBwidht / 2)) {
			if (boxA.y - (boxAhight / 2) <= boxB.y + (boxBhight / 2)) {
				if (boxA.y + (boxAhight / 2) >= boxB.y - (boxBhight / 2)) {
					return 1;
				}
			}
		}
	}

	return 0;

}