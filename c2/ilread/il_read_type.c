ushort il_read_type(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = il_read_byte();
  if ((uVar1 & 0x80) == 0) {
    return (short)(char)uVar1;
  }
  iVar2 = il_read_byte();
  return CONCAT11((char)uVar1,(char)iVar2) & 0x7fff;
}

