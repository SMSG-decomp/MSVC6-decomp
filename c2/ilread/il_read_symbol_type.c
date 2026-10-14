void __fastcall il_read_symbol_type(c2_fe_symbol *fs)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  
  uVar2 = il_read_type();
  uVar3 = (uint)((byte)uVar2 & 0x1f);
  if (((uVar2 & 0x10) != 0) && (bVar1 = (byte)uVar2 & 0xf, uVar3 = (uint)bVar1, bVar1 == 6)) {
    fs->storage = fs->storage | 0x4000;
  }
  fs->storage = uVar3 & 0xf | fs->storage & 0xfffffff0;
  return;
}

