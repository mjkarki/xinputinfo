#include <windows.h>
#include <xinput.h>
#include <stdio.h>

int main()
{
    XINPUT_STATE state;
    XINPUT_BATTERY_INFORMATION battery;

    for (DWORD i = 0; i < XUSER_MAX_COUNT; i++)
    {
        ZeroMemory(&state, sizeof(XINPUT_STATE));

        if (XInputGetState(i, &state) == ERROR_SUCCESS)
        {
            ZeroMemory(&battery, sizeof(XINPUT_BATTERY_INFORMATION));
            printf("Controller #%d found:\n", i);

            if (XInputGetBatteryInformation(i, BATTERY_DEVTYPE_GAMEPAD, &battery) == ERROR_SUCCESS)
            {
                printf("  Battery type: ");
                switch (battery.BatteryType)
                {
                    case BATTERY_TYPE_DISCONNECTED:
                        printf("disconnected.\n");
                        break;
                    case BATTERY_TYPE_WIRED:
                        printf("wired.\n");
                        break;
                    case BATTERY_TYPE_ALKALINE:
                        printf("alkaline.\n");
                        break;
                    case BATTERY_TYPE_NIMH:
                        printf("NIMH.\n");
                        break;
                    case BATTERY_TYPE_UNKNOWN:
                        printf("unknown.\n");
                        break;
                    default:
                        printf("???\n");
                }

                printf("  Battery level: ");
                switch (battery.BatteryLevel)
                {
                    case BATTERY_LEVEL_EMPTY:
                        printf("empty.\n");
                        break;
                    case BATTERY_LEVEL_LOW:
                        printf("low.\n");
                        break;
                    case BATTERY_LEVEL_MEDIUM:
                        printf("medium.\n");
                        break;
                    case BATTERY_LEVEL_FULL:
                        printf("full.\n");
                        break;
                    default:
                        printf("???\n");
                }
            }
        }
    }

    return 0;
}

/*
BSD 3-Clause License

Copyright (c) 2017, Matti J. Kärki
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of the copyright holder nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
