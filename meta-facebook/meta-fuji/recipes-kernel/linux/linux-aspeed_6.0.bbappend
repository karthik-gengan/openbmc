#Copyright 2022-present Facebook. All Rights Reserved.
#
# This program file is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; version 2 of the License.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
# for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program in a file named COPYING; if not, write to the
# Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor,
# Boston, MA 02110-1301 USA

FILESEXTRAPATHS:prepend := "${THISDIR}/patches:"

#
# Include patch files from meta-aspeed layer
#

#
# Include fuji-specific patches
#
SRC_URI += "file://1002-fuji-remove-adm1278-from-dts-and-let-pro.patch \
	    file://1003-ARM-dts-aspeed-fuji-enable-jtag-Spi.patch \
	    file://1011-hwmon-add-net_brcm-driver.patch \
	    file://1021-hwmon-mp2975-add-compatible-for-mp2978-1025.patch \
	    file://1031-Added-Facebook-mfd-usmc-driver.patch \
	    file://1032-Added-Facebook-fboss-usmc-driver.patch \
	    file://1033-Include-spidev-into-SPI-ID-table.patch \
	    file://1034-remove-i2c-mux-bus.patch \
      file://1035-fuji-disable-all-i2c-bus-expect-bus12.patch \
           "

