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

