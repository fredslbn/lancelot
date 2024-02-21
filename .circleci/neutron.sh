#!/usr/bin/env bash
 #
 # Script For Building Android Kernel
 #

##----------------------------------------------------------##
# Specify Kernel Directory
KERNEL_DIR="$(pwd)"

##----------------------------------------------------------##
# Device Name and Model
MODEL=POCO
DEVICE=chime

# Kernel Defconfig
DEFCONFIG=${DEVICE}_defconfig

# Files
IMAGE=$(pwd)/out/arch/arm64/boot/Image.gz
#DTBO=$(pwd)/out/arch/arm64/boot/dtbo.img
#DTB=$(pwd)/out/arch/arm64/boot/dts/mediatek

# Verbose Build
VERBOSE=0

# Date and Time
DATE=$(TZ=Asia/Jakarta date +"%Y%m%d-%T")
TANGGAL=$(date +"%F%S")

# Specify Final Zip Name
ZIPNAME="SUPER.KERNEL-CHIME-(neutron)-$(TZ=Asia/Jakarta date +"%Y%m%d-%H%M").zip"
FINAL_ZIP=${ZIPNAME}-${DEVICE}-${TANGGAL}.zip

##----------------------------------------------------------##
# Specify compiler.

COMPILER=neutron

##----------------------------------------------------------##
# Specify Linker
LINKER=ld.lld

##----------------------------------------------------------##

##----------------------------------------------------------##
# Clone ToolChain
function cloneTC() {
        
    if [ $COMPILER = "neutron" ];
    then
    mkdir Neutron
    curl -s https://api.github.com/repos/Neutron-Toolchains/clang-build-catalogue/releases/latest \
    | grep "browser_download_url.*tar.zst" \
    | cut -d : -f 2,3 \
    | tr -d \" \
    | wget --output-document=Neutron.tar.zst -qi -
    tar -xvf Neutron.tar.zst -C Neutron/
    
    export KERNEL_CLANG="clang"
    export KERNEL_CLANG_PATH="${KERNEL_DIR}/Neutron"
    export PATH="$KERNEL_CLANG_PATH/bin:$PATH"
   
   fi
	
}

##------------------------------------------------------##
# Export Variables
function exports() {

        # Export ARCH and SUBARCH
        export ARCH=arm64
        export SUBARCH=arm64
        
        # KBUILD HOST and USER
        export KBUILD_BUILD_HOST=Pancali
        export KBUILD_BUILD_USER="unknown"
        
	    export PROCS=$(nproc --all)
	    export DISTRO=$(source /etc/os-release && echo "${NAME}")
	    
	}
        
##----------------------------------------------------------------##

# Speed up build process
MAKE="./makeparallel"

##----------------------------------------------------------##
# Compilation
function compile() {
START=$(date +"%s")
			       
	# Compile
	make O=out ARCH=arm64 ${DEFCONFIG}
	       
	if [ -d ${KERNEL_DIR}/Neutron ];
	   then
	       make -j$(nproc --all) O=out \
	       ARCH=arm64 \
	       CC=$KERNEL_CLANG \
	       CROSS_COMPILE=aarch64-linux-gnu- \
	       CLANG_TRIPLE=aarch64-linux-gnu- \
	       #LD=${LINKER} \
	       #LLVM=1 \
	       #LLVM_IAS=1 \
	       AR=llvm-ar \
	       NM=llvm-nm \
	       OBJCOPY=llvm-objcopy \
	       OBJDUMP=llvm-objdump \
	       STRIP=llvm-strip \
	       V=$VERBOSE 2>&1 | tee error.log
	       
    fi
    	
}

##----------------------------------------------------------------##
function zipping() {
	# Copy Files To AnyKernel3 Zip
	cp $IMAGE AnyKernel3
	# cp $DTBO AnyKernel3
	# find $DTB -name "*.dtb" -exec cat {} + > AnyKernel3/dtb
	# find $MODULE -name "*.ko" -exec cat {} + > AnyKernel3/wtc2.ko
	# find . -name '*.ko' -exec cp '{}' AnyKernel3/modules/system/lib/modules \;
	
	# Zipping and Push Kernel
	cd AnyKernel3 || exit 1
        zip -r9 ${ZIPNAME} *
        MD5CHECK=$(md5sum "$ZIPNAME" | cut -d' ' -f1)
        echo "Zip: $ZIPNAME"
        # curl -T $ZIPNAME temp.sh; echo
        curl -T $ZIPNAME https://oshi.at
        # curl --upload-file $ZIPNAME https://free.keep.sh
    cd ..
    
}

    
##----------------------------------------------------------##

cloneTC
exports
compile
zipping

##----------------*****-----------------------------##