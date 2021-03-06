/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void gsm_properties();
void cdma_properties(char cdma_sub[]);
void r970_properties();

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform);
    if (!rc || strncmp(platform, ANDROID_TARGET, PROP_VALUE_MAX))
        return;

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "R970C")) {
        /* jfltecri */
        cdma_properties("0");
        r970_properties();
        property_set("ro.build.fingerprint", "samsung/jfltecri/jfltecri:4.2.2/JDQ39/R970CVVUAME4:user/release-keys");
        property_set("ro.build.description", "jfltecri-user 4.2.2 JDQ39 R970CVVUAME4 release-keys");
        property_set("ro.product.model", "SCH-R970C");
        property_set("ro.product.device", "jfltecri");
        property_set("ro.cdma.home.operator.alpha", "Cricket");
        property_set("ro.cdma.home.operator.numeric", "310090");
    } else if (strstr(bootloader, "R970X")) {
        /* jfltecsp */
        cdma_properties("0");
        r970_properties();
        property_set("ro.build.fingerprint", "samsung/jfltecsp/jfltecsp:4.2.2/JDQ39/R970XWWUAMFA:user/release-keys");
        property_set("ro.build.description", "jfltecsp-user 4.2.2 JDQ39 R970XWWUAMFA release-keys");
        property_set("ro.product.model", "SCH-R970X");
        property_set("ro.product.device", "jfltecsp");
        property_set("telephony.sms.pseudo_multipart", "1");
    } else if (strstr(bootloader, "L720")) {
        /* jfltespr */
        cdma_properties("1");
        property_set("ro.build.fingerprint", "samsung/jfltespr/jfltespr:4.2.2/JDQ39/L720VPUAMDL:user/release-keys");
        property_set("ro.build.description", "jfltespr-user 4.2.2 JDQ39 L720VPUAMDL release-keys");
        property_set("ro.product.model", "SPH-L720");
        property_set("ro.product.device", "jfltespr");
        property_set("ro.cdma.home.operator.numeric", "310120");
        property_set("ro.cdma.home.operator.alpha", "Sprint");
        property_set("ro.telephony.default_network", "8");
        property_set("ro.telephony.get_imsi_from_sim", "true");
        property_set("telephony.sms.pseudo_multipart", "1");
    } else if (strstr(bootloader, "R970")) {
        /* jflteusc */
        cdma_properties("0");
        r970_properties();
        property_set("ro.build.fingerprint", "samsung/jflteusc/jflteusc:4.2.2/JDQ39/R970VXUAMD9:user/release-keys");
        property_set("ro.build.description", "jflteusc-user 4.2.2 JDQ39 R970VXUAMD9 release-keys");
        property_set("ro.product.model", "SCH-R970");
        property_set("ro.product.device", "jflteusc");
        property_set("ro.cdma.home.operator.alpha", "U.S.Cellular");
        property_set("ro.cdma.home.operator.numeric", "311580");
    } else if (strstr(bootloader, "I545")) {
        /* jfltevzw */
        cdma_properties("0");
        property_set("ro.build.fingerprint", "Verizon/jfltevzw/jfltevzw:5.0.1/LRX22C/I545VRUGOC1:user/release-keys");
        property_set("ro.build.description", "jfltevzw-user 5.0.1 LRX22C I545VRUGOC1 release-keys");
        property_set("ro.product.model", "SCH-I545");
        property_set("ro.product.device", "jfltevzw");
        property_set("ro.cdma.home.operator.alpha", "Verizon");
        property_set("ro.cdma.home.operator.numeric", "311480");
        property_set("ro.telephony.default_network", "10");
        property_set("ro.telephony.get_imsi_from_sim", "true");
        property_set("ro.config.multimode_cdma", "1");
        property_set("ro.config.combined_signal", "true");
        property_set("ro.gsm.data_retry_config", "max_retries=infinite,5000,5000,60000,120000,480000,900000");
        property_set("DEVICE_PROVISIONED", "1");
        property_set("ro.com.google.clientidbase", "android-verizon");
    } 

    property_get("ro.product.device", device);
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, device);

}

void cdma_properties(char cdma_sub[])
{
    property_set("ro.telephony.default_cdma_sub", cdma_sub);
    property_set("ro.gps.set_privacy", "1");
    property_set("persist.eons.enabled", "false");
    property_set("persist.radio.snapshot_enabled", "1");
    property_set("persist.radio.snapshot_timer", "22");
    property_set("telephony.lteOnCdmaDevice", "1");
}

void r970_properties()
{
    property_set("ro.telephony.default_network", "8");
    property_set("ril.subscription.types", "NV,RUIM");
    property_set("telephony.sms.pseudo_multipart", "1");
    property_set("ro.config.combined_signal", "true");
    property_set("ro.gsm.data_retry_config", "max_retries=infinite,0,0,60000,120000,480000,900000");
    property_set("DEVICE_PROVISIONED", "1");
}
