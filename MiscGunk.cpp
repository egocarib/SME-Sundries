#include "SME_Prefix.h"
#include "MiscGunk.h"

namespace SME
{
	namespace MiscGunk
	{
		ElapsedTimeCounter::ElapsedTimeCounter()
		{
			QueryPerformanceCounter(&ReferenceFrame);
			QueryPerformanceFrequency(&TimerFrequency);

			Update();
		}

		void ElapsedTimeCounter::Update(void)
		{
			QueryPerformanceCounter(&FrameBuffer);
			TimePassed = ((FrameBuffer.QuadPart - ReferenceFrame.QuadPart ) * 1000.0 / TimerFrequency.QuadPart);
			ReferenceFrame = FrameBuffer;
		}

		long double ElapsedTimeCounter::GetTimePassed( void ) const
		{
			return TimePassed;
		}

		const char* GetTimeString( char* Out, size_t Size, const char* FormatString )
		{
			__time32_t TimeData;
			tm LocalTime;

			_time32(&TimeData);
			_localtime32_s(&LocalTime, &TimeData);
			strftime(Out, Size, FormatString, &LocalTime);
			return Out;
		}

		const char* GetTimeString(std::string& Out, const char* FormatString)
		{
			char Buffer[0x100] = {0};
			GetTimeString(Buffer, sizeof(Buffer), FormatString);
			Out = Buffer;

			return Out.c_str();
		}

		void ToggleFlag(UInt8* Flag, UInt32 Mask, bool State)
		{
			if (State)
				*Flag |= Mask;
			else
				*Flag &= ~Mask;
		}

		void ToggleFlag(UInt16* Flag, UInt32 Mask, bool State)
		{
			if (State)
				*Flag |= Mask;
			else
				*Flag &= ~Mask;
		}

		void ToggleFlag(UInt32* Flag, UInt32 Mask, bool State)
		{
			if (State)
				*Flag |= Mask;
			else
				*Flag &= ~Mask;
		}
	}
}