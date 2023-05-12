
// mac
#include <stdio.h>
#include <CoreAudio/CoreAudio.h>
#include <AudioToolbox/AudioToolbox.h> // include the AudioToolbox framework

int main() {
    AudioObjectPropertyAddress propertyAddress = {
        kAudioHardwareServiceDeviceProperty_VirtualMasterVolume,
        kAudioObjectPropertyScopeGlobal,
        kAudioObjectPropertyElementMaster
    };
    Float32 volume;
    UInt32 dataSize = sizeof(Float32);

    // get the master volume
    AudioObjectGetPropertyData(
        kAudioObjectSystemObject,
        &propertyAddress,
        0,
        NULL,
        &dataSize,
        &volume
    );

    printf("Current Master Volume: %f\n", volume);
    return 0;
}

// windows
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>

int main() {
    // Get the current master volume level
    DWORD volume;
    if (!waveOutGetVolume(NULL, &volume)) {
        printf("Current master volume: %ld\n", LOWORD(volume));
    }
    
    // Set the master volume to 50%
    DWORD newVolume = (DWORD)(0xFFFF * 0.5) + ((DWORD)(0xFFFF * 0.5) << 16);
    if (!waveOutSetVolume(NULL, newVolume)) {
        printf("Master volume set to 50%%.\n");
    }
    
    return 0;
}
