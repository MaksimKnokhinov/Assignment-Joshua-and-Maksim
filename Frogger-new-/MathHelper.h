#ifndef _MATHHELPER_H
#define _MATHHELPER_H
#include <math.h>

//Building a structure
#define PI 3.1415926535
#define DEG_TO_RAD PI / 180.0f

namespace SDLFramework {
	struct Vector2 {
		float x;
		float y;

		Vector2(float _x = 0.0f, float _y = 0.0f) : x{ _x }, y{ _y } {}

		float MagnitudeSqr() {
			return x * x + y * y;
		}

		float Magnitude() {
			return(float)sqrt(x * x + y * y);
		}

		Vector2 Normalized() {
			float mag = Magnitude();
			return Vector2(x / mag, y / mag);

		}
		Vector2& operator+=(const Vector2& rightHandSide) {
			x += rightHandSide.x;
			y += rightHandSide.y;
			return *this;
		}
		Vector2& operator-=(const Vector2& rightHandSide) {
			x -= rightHandSide.x;
			y -= rightHandSide.y;
			return *this;
		}

		Vector2 operator-() const {
			return Vector2(-x, -y);
		}
	};

	// by multiplying these by -1 we can get the opposite of these
	const Vector2 Vec2_Zero = { 0.0f, 0.0f };
	const Vector2 Vec2_One = { 1.0f, 1.0f };
	const Vector2 Vec2_Up = { 0.0f, 1.0f };
	const Vector2 Vec2_Right = { 1.0f, 0.0f };

	inline Vector2 operator+(const Vector2& leftHandSide, const Vector2& rightHandSide) {
		return Vector2(leftHandSide.x + rightHandSide.x, leftHandSide.y + rightHandSide.y);
	}

	inline Vector2 operator-(const Vector2& leftHandSide, const Vector2& rightHandSide) {
		return Vector2(leftHandSide.x - rightHandSide.x, leftHandSide.y - rightHandSide.y);

	}

	inline Vector2 operator*(const Vector2& leftHandSide, float rightHandSide) {
		return Vector2(leftHandSide.x * rightHandSide, leftHandSide.y * rightHandSide);
	}

	inline Vector2 operator*(float leftHandSide, const Vector2& rightHandSide) {
		return Vector2(leftHandSide * rightHandSide.x, leftHandSide * rightHandSide.y);
	}


	//controls the smooth arc of an object
	inline Vector2 Lerp(const Vector2& start, const Vector2& end, float time) {
		if (time <= 0.0f) {
			return start;
		}

		if (time >= 1.0f) {
			return end;
		}

		Vector2 dir = (end - start).Normalized();
		float mag = (end - start).Magnitude();

		return start + dir * mag * time;
	}
	//this for rotating objects
	inline Vector2 RotateVector(const Vector2 vec, float angle) {
		float radAngle = (float)(angle * DEG_TO_RAD);

		return Vector2(
			(float)(vec.x * cos(radAngle) - vec.y * sin(radAngle)),
			(float)(vec.x * sin(radAngle) + vec.y * cos(radAngle))
		);

	}

	inline float Dot(const Vector2& vec1, const Vector2& vec2) {
		return vec1.x * vec2.x + vec1.y * vec2.y;
	}

	inline float Clamp(const float& value, const float& min, const float& max) {
		if (value > max) {
			return max;
		}

		if (value < min) {
			return min;
		}
		return value;
	}
}


#endif // !_MATHHELPER_H

