#!/usr/bin/env bash

set -e
set -x
shopt -s dotglob

readonly name="visit-databases"
readonly ownership="VisIt Upstream <kwrobot@kitware.com>"
readonly subtree="databases/readers"
readonly repo="https://gitlab.kitware.com/third-party/visit.git"
readonly tag="for/paraview-20191122-trunk-r34006"

readonly paths="
COPYRIGHT
.gitattributes
README.kitware.md

databases/ANSYS
databases/AUXFile
databases/BOV
databases/Boxlib3D
databases/CEAucd
databases/CMAT
databases/CTRL
databases/Chombo
databases/Claw
databases/Curve2D
databases/DDCMD
databases/Dyna3D
databases/Enzo
databases/ExtrudedVol
databases/FLASH
databases/Fluent
databases/GGCM
databases/GTC
databases/GULP
databases/Gadget
databases/H5Nimrod
databases/Image
databases/LAMMPS
databases/Lines
databases/M3D
databases/M3DC1
databases/MFIX
databases/MFIXCDF
databases/MM5
databases/Mili
databases/Miranda
databases/NASTRAN
databases/NETCDF
databases/Nek5000
databases/OVERFLOW
databases/OpenFOAM
databases/PATRAN
databases/PFLOTRAN
databases/PLOT3D
databases/Pixie
databases/Point3D
databases/ProteinDataBank
databases/RAW
databases/SAMRAI
databases/SAR
databases/SAS
databases/Silo
databases/Spheral
databases/TFT
databases/TSurf
databases/Tecplot
databases/Tetrad
databases/UNIC
databases/VASP
databases/Velodyne
databases/Vs
databases/XYZ
databases/Xmdv
databases/paraDIS
databases/paraDIS_tecplot
"

database_cleanup () {
    local reader="$1"
    readonly reader
    shift

    local kind
    case "$reader" in
        Chombo|FLASH|GGCM|M3DC1|MFIXCDF|MFIX|Miranda|NASTRAN|Nek5000|OpenFOAM|paraDIS|Pixie|PLOT3D|ProteinDataBank|Vs)
            kind="reader_options"
            ;;
        BOV|Curve2D|ExtrudedVol|Image|Silo|Tecplot|Xmdv)
            kind="writer"
            ;;
        *)
            kind="reader"
            ;;
    esac
    readonly kind

    rm -v *MDServerPluginInfo.C

    case "$kind" in
        reader)
            rm -vf *PluginInfo.* avt*Options.* avt*Writer.*
            ;;
        reader_options)
            rm -vf *Writer.*
            ;;
        writer)
            ;;
    esac
}

cleanup_LAMMPS () {
    # This just abstracts over the other sub-formats.
    rm -v avtLAMMPSFileFormat.*
}

cleanup_H5Nimrod () {
    # Remove the PDF file describing the format.
    rm -v nimrod.pdf
}

cleanup_PLOT3D () {
    # Documentation tarball.
    rm -v plot3d_html.tar
}

cleanup_VASP () {
    # Unwrapped VASP readers.
    rm -v avtVASPFileFormat.*
    rm -v avtXDATFileFormat.*
}

cleanup_Vs () {
    # Unused files.
    rm -v VsStaggeredField.*
}

cleanup_paraDIS () {
    rm -v RC_cpp_lib/RC_c_lib/gethostname.c
    rm -v RC_cpp_lib/RC_c_lib/gprof-helper.c
    rm -v RC_cpp_lib/RC_c_lib/signals.c
    rm -v RC_cpp_lib/ComboBoxManager.*
    rm -v RC_cpp_lib/RCLibConstants.h
    rm -v RC_cpp_lib/cppFileUtils.h
    rm -v RC_cpp_lib/debugutil-qt.*
    rm -v RC_cpp_lib/test.C
    rm -v paraDIS_tecplot.*
}

cleanup_paraDIS_tecplot () {
    rm -vrf RC_cpp_lib
    rm -vrf RC_c_lib
}

extract_source () {
    git_archive
    pushd "$extractdir/$name-reduced"
    mv --target-directory=. databases/*
    find . -name "*.code" -delete
    find . -name "*.xml" -delete
    for reader in *; do
        [ -d "$reader" ] || continue
        pushd "$reader"
        mv "CMakeLists.paraview.txt" "CMakeLists.txt"
        database_cleanup "$reader"
        if type "cleanup_$reader" >/dev/null 2>/dev/null; then
            "cleanup_$reader"
        fi
        popd
    done
    popd
}

. "${BASH_SOURCE%/*}/update-common.sh"
