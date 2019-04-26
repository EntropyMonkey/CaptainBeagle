/*******************************************************************************
The content of this file includes portions of the AUDIOKINETIC Wwise Technology
released in source code form as part of the SDK installer package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use this file in accordance with the end user license agreement provided 
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Apache License Usage

Alternatively, this file may be used under the Apache License, Version 2.0 (the 
"Apache License"); you may not use this file except in compliance with the 
Apache License. You may obtain a copy of the Apache License at 
http://www.apache.org/licenses/LICENSE-2.0.

Unless required by applicable law or agreed to in writing, software distributed
under the Apache License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
OR CONDITIONS OF ANY KIND, either express or implied. See the Apache License for
the specific language governing permissions and limitations under the License.

  Version: v2019.1.0  Build: 6590
  Copyright (c) 2006-2019 Audiokinetic Inc.
*******************************************************************************/

#pragma once

#include <jni.h>

namespace AKPLATFORM
{
	/// Utility class for acquiring a pointer to a valid JNI environment attached to the current thread (with proper cleanup in destructor)
	class CAkJNIThread
	{
	public:
		CAkJNIThread(JavaVM* jvm) : m_jvm(jvm), m_jEnv(NULL), m_mustDetachExplicitely(false)
		{
			if (!jvm)
				return;

			jvm->GetEnv((void**)&m_jEnv, JNI_VERSION_1_6);
			if (m_jEnv == NULL)
			{
				JavaVMAttachArgs lJavaVMAttachArgs;
				lJavaVMAttachArgs.version = JNI_VERSION_1_6;
				lJavaVMAttachArgs.name = "NativeThread";
				lJavaVMAttachArgs.group = NULL;

				jvm->AttachCurrentThread(&m_jEnv, &lJavaVMAttachArgs);
				m_mustDetachExplicitely = true;
			}
		}

		~CAkJNIThread()
		{
			if (m_jvm != NULL && m_jEnv != NULL && m_mustDetachExplicitely)
			{
				m_jvm->DetachCurrentThread();
				m_mustDetachExplicitely = false;
			}
		}

		JNIEnv *getEnv()
		{
			return m_jEnv;
		}

		bool isAttached()
		{
			return m_jEnv != NULL;
		}

	private:
		JavaVM * m_jvm;
		JNIEnv * m_jEnv;
		bool m_mustDetachExplicitely;
	};
}
