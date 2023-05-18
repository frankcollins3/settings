#include <stdio.h>
#include <objc/objc.h>
#include <objc/NSObjCRuntime.h>
#include <objc/NSObjCRuntime.h>
#include <AppKit/AppKit.h>

int main() {
    const char* imagePath = "/path/to/image.jpg";

    // Create an NSURL object from the image path
    id url = objc_msgSend(objc_getClass("NSURL"), sel_registerName("fileURLWithPath:"), imagePath);

    // Get the shared NSWorkspace object
    id workspace = objc_msgSend(objc_getClass("NSWorkspace"), sel_registerName("sharedWorkspace"));

    // Set the desktop image
    objc_msgSend(workspace, sel_registerName("setDesktopImageURL:forScreen:options:error:"), url, NULL, NULL, NULL);

    return 0;
}
