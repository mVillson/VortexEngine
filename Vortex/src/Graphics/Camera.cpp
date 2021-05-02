#include "Camera.h"

namespace vtx::gfx
{
	Camera::Camera()
		:mPosition(vec3(0.0f, 0.0f, 0.0f)), mTargetPos(vec3(0.0f, 0.0f, 0.0f)), mUp(vec3(0.0f, 1.0f, 0.0f)),
		mYaw(0.0f), mPitch(0.0f)
	{

	}

	mat4 Camera::GetViewMatrix() const
	{
		return lookAt(mPosition, mTargetPos, mUp);
	}

	// Orbit Camera
	OrbitCamera::OrbitCamera()
		:mRadius(10.0f)
	{

	}

	void OrbitCamera::SetLookAt(const vec3& target)
	{
		mTargetPos = target;
	}

	void OrbitCamera::SetRadius(float radius)
	{
		mRadius = clamp(radius, 2.0f, 80.0f);
	}

	void OrbitCamera::Rotate(float yaw, float pitch)
	{
		mYaw = radians(yaw);
		mPitch = radians(pitch);

		mPitch = clamp(mPitch, -pi<float>() / 2.0f + 0.1f, pi<float>() / 2.0f - 0.1f);

		UpdateCameraVectors();
	}

	void OrbitCamera::UpdateCameraVectors()
	{
		mPosition.x = mTargetPos.x + mRadius * cosf(mPitch) * sinf(mYaw);
		mPosition.y = mTargetPos.y + mRadius * sinf(mPitch);
		mPosition.z = mTargetPos.z + mRadius * cosf(mPitch) * cosf(mYaw);
	}
}
