#pragma once
#include "GraphicsEngine/Component.h"
#include "GraphicsEngine/Input.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/Time.h"
#include "GraphicsEngine/Vector3.h"


class CameraController : public Component
{
	Vector3* mousePos;

public:
	CameraController()
	{
		mousePos = nullptr;
	}

	virtual ~CameraController() {}

	virtual void Update() 
	{
		Transform * pTransform = m_pObject->m_pTransform;
        Vector3 forward	= pTransform->GetForward();
        Vector3 right	= pTransform->GetRight();
        Vector3 up	= pTransform->GetUp();
		// Camera Translation
		{
			double dt = Time::GetDeltaTime();

			double speed = 1.0;
			Vector3 direction;


			if (Input::GetKey(KEY_CODE_W) || Input::GetKey(KEY_CODE_UP_ARROW))
			{
                direction.z=1;
				// TODO: Task08
				// Move forward
			}
			else if (Input::GetKey(KEY_CODE_S) || Input::GetKey(KEY_CODE_DOWN_ARROW))
			{
                direction.z=-1;
				// TODO: Task08
				// Move backward
			}

			if (Input::GetKey(KEY_CODE_D) || Input::GetKey(KEY_CODE_RIGHT_ARROW))
			{
                direction.x=1;
				// TODO: Task08
				// Move right
			}
			else if (Input::GetKey(KEY_CODE_A) || Input::GetKey(KEY_CODE_LEFT_ARROW))
			{
                direction.x=-1;
				// TODO: Task08
				// Move left
			}


            if (Input::GetKey(KEY_CODE_LEFT_SHIFT) || Input::GetKey(KEY_CODE_RIGHT_SHIFT))
            {
                speed *= 10;
                // TODO: Task08
                // Move speed up (multiply speed by 10)
            }

            pTransform->Translate( speed * dt * direction );
		}

		// Camera Rotation
		{
			Vector3 newMousePos = Input::GetMousePosition();
			const double speedAngle = 0.3;
			if (Input::GetMouseButton(1))
			{
                if (mousePos) {
//                    float cosRight = static_cast<float>(Vector3::Dot(right, Vector3(1, 0, 0)));
//                    float sinRight = sqrt(1 - cosRight * cosRight);
//                    float cosUp = static_cast<float>(Vector3::Dot(up, Vector3(0, 1, 0)));
//                    float sinUp = sqrt(1 - cosUp * cosUp);
//                    float cosForward = static_cast<float>(Vector3::Dot(up, Vector3(0, 0, 1)));
//                    float sinForward = sqrt(1 - cosForward * cosForward);
                    float vertical = static_cast<float>((newMousePos - *mousePos).y * speedAngle);
                    float horizontal = static_cast<float>((newMousePos - *mousePos).x * speedAngle);
                    pTransform->Rotate(0.0, horizontal, 0.0);
                    pTransform->Rotate(vertical, 0.0, 0.0);
                    *mousePos = newMousePos;
                } else {
                    mousePos = new Vector3(newMousePos);
                }
				// TODO: Task08
				// Rotate pTransform
			}else {
                delete mousePos;
                mousePos = nullptr;
            }
		}
	}
};
