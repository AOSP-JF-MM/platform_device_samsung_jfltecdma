#
# Copyright (C) 2015 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Device overlays
DEVICE_PACKAGE_OVERLAYS += device/samsung/jfltecdma/overlay

# Get non-open-source CDMA specific aspects if available
$(call inherit-product-if-exists, vendor/samsung/jf-cdma/jf-cdma-vendor-blobs.mk)

## Also get non-open-source specific common aspects if available
$(call inherit-product-if-exists, vendor/samsung/jf-common/jf-common-vendor.mk)

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit common device parts.
$(call inherit-product, device/samsung/jf-common/jf-common.mk)

# Set those variables here to overwrite the inherited values.
PRODUCT_NAME := full_jfltecdma
PRODUCT_DEVICE := jfltecdma
PRODUCT_BRAND := samsung
PRODUCT_MANUFACTURER := samsung
PRODUCT_MODEL := jfltecdma
