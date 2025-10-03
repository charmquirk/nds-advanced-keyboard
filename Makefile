# SPDX-License-Identifier: CC0-1.0
#
# SPDX-FileContributor: Antonio Niño Díaz, 2024

BLOCKSDS	?= /opt/blocksds/core

# User config

NAME		:= advanced_keyboards
GAME_TITLE	:= Advanced Custom Keyboards
GAME_SUBTITLE	:= Charm Quirk 2025

# Source code paths

GFXDIRS		:= graphics

include $(BLOCKSDS)/sys/default_makefiles/rom_arm9/Makefile
