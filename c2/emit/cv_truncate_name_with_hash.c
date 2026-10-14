void __fastcall cv_truncate_name_with_hash(uint8_t *out,char *name,uint32_t len)

{
  uint uVar1;
  uint8_t *puVar2;
  uint8_t *puVar3;
  int iVar4;
  uint uVar5;
  
  uVar1 = SigForPbCb(name,len,0);
  if (len < 0x100) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\emit.c",0x2fe);
  }
  puVar2 = out + 1;
  for (iVar4 = 0x3d; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)puVar2 = *(undefined4 *)name;
    name = name + 4;
    puVar2 = puVar2 + 4;
  }
  *(undefined2 *)puVar2 = *(undefined2 *)name;
  puVar2[2] = name[2];
  *out = 0xff;
  iVar4 = 8;
  puVar2 = out + 0xff;
  do {
    uVar5 = uVar1 & 0xf;
    puVar3 = puVar2 + -1;
    uVar1 = uVar1 >> 4;
    iVar4 = iVar4 + -1;
    *puVar2 = "0123456789abcdef"[uVar5];
    puVar2 = puVar3;
  } while (iVar4 != 0);
  if (puVar3 != out + 0xf7) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\emit.c",0x30e);
  }
  return;
}

