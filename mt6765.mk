#
# Copyright (C) 2024 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Enable updating of APEXes
$(call inherit-product, $(SRC_TARGET_DIR)/product/updatable_apex.mk)

# Inherit the proprietary files
$(call inherit-product, vendor/lenovo/mt6765-common/mt6765-common-vendor.mk)
