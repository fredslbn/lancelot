#!/bin/bash

DEFCONFIG="lava_defconfig"
DEFCONFIG_1="merlin_defconfig"

make -j"$(nproc --all)" O=out ARCH=arm64 SUBARCH=arm64 "$DEFCONFIG"
cp -af out/.config arch/arm64/configs/"$DEFCONFIG"
make -j"$(nproc --all)" O=out ARCH=arm64 SUBARCH=arm64 "$DEFCONFIG_1"
cp -af out/.config arch/arm64/configs/"$DEFCONFIG_1"
git add arch/arm64/configs
git commit -m "XM6768:defconfig:Regenerate"
echo -e "\nSuccessfully regenerated defconfig at $DEFCONFIG"
