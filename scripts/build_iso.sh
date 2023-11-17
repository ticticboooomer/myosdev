#!/bin/bash

grub-file --is-x86-multiboot build/kernel.bin

mkdir -p iso/boot/grub
cp os1 iso/boot/os1
cp ./src/grub.cfg iso/boot/grub/grub.cfg
grub-mkrescue -o os1.iso iso
