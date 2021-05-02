#pragma once

#include "GraphicsCore.h"
#include "..\Vendor\glm\glm.hpp"
#include "..\Vendor\glm\gtx\transform.hpp"
using namespace glm;

namespace vtx::gfx 
{
	// --------------------------------------
	// Abstract Camera Class
	// --------------------------------------
	class Camera 
	{
	public:
		mat4 VORTEX_API GetViewMatrix() const;
		virtual void VORTEX_API Rotate(float yaw, float pitch) {}

	protected:
		VORTEX_API Camera();

		vec3 mPosition;
		vec3 mTargetPos;
		vec3 mUp;

		float mYaw, mPitch;
	};

	class OrbitCamera : public Camera
	{
	private:
		float mRadius;

		void UpdateCameraVectors();
	public:
		VORTEX_API OrbitCamera();

		virtual void VORTEX_API Rotate(float yaw, float pitch);

		void VORTEX_API SetLookAt(const vec3& target);
		void VORTEX_API SetRadius(float radius);
	};
}
